#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist
from std_msgs.msg import Float32
import math

# global vars
THRESHOLD = 1.0
BOUNDARY_MIN = 1.0
BOUNDARY_MAX = 10.0
BACKUP_SPEED = 0.5  # the speed for backing off

class distance_node(Node):
    def __init__(self):
        super().__init__('distance_node')

        # store the initial poses (in the first iteration they are null ofc)
        self.pose1 = None
        self.pose2 = None

        # we declare the subsrcribers to both of the turtles that are created
        self.create_subscription(Pose, '/turtle1/pose', self.pose1_callback, 10) 
        self.create_subscription(Pose, '/turtle2/pose', self.pose2_callback, 10)

        # now we declare the publishers
        self.dist_pub = self.create_publisher(Float32, '/turtle_distance', 10)
        self.cmd_pub_turtle1 = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.cmd_pub_turtle2 = self.create_publisher(Twist, '/turtle2/cmd_vel', 10)

        # we declare a timer which will determine the frequency that we check the state
        self.timer = self.create_timer(0.1, self.check_distance)

    def pose1_callback(self, msg):
        self.pose1 = msg

    def pose2_callback(self, msg):
        self.pose2 = msg

    def move_away_from_boundary(self, pose, pub, turtle_name):
        """Make turtle move away from the nearest boundary"""
        backup = Twist()
        
        # calculate distances to each boundary
        dist_to_left = pose.x - BOUNDARY_MIN
        dist_to_right = BOUNDARY_MAX - pose.x
        dist_to_bottom = pose.y - BOUNDARY_MIN
        dist_to_top = BOUNDARY_MAX - pose.y
        
        # find which boundary is closest
        min_dist = min(dist_to_left, dist_to_right, dist_to_bottom, dist_to_top)
        
        # determine direction to move (towards center)
        target_angle = None
        if min_dist == dist_to_left:
            # too close to left, move right (angle = 0)
            target_angle = 0.0
            print(f"WARNING: {turtle_name} too close to LEFT boundary!")
        elif min_dist == dist_to_right:
            # too close to right, move left (angle = pi)
            target_angle = math.pi
            print(f"WARNING: {turtle_name} too close to RIGHT boundary!")
        elif min_dist == dist_to_bottom:
            # too close to bottom, move up (angle = pi/2)
            target_angle = math.pi / 2
            print(f"WARNING: {turtle_name} too close to BOTTOM boundary!")
        else:
            # too close to top, move down (angle = -pi/2)
            target_angle = -math.pi / 2
            print(f"WARNING: {turtle_name} too close to TOP boundary!")
        
        # calculate angle difference between current heading and target
        angle_diff = target_angle - pose.theta
        
        # normalize angle
        while angle_diff > math.pi:
            angle_diff -= 2 * math.pi
        while angle_diff < -math.pi:
            angle_diff += 2 * math.pi
        
        # if we're facing roughly the right direction, move forward towards center (if not rot to face the center)
        if abs(angle_diff) < math.pi / 4:  # Within 45 degrees
            backup.linear.x = BACKUP_SPEED
        else:
            # rotate towards center
            backup.angular.z = 2.0 if angle_diff > 0 else -2.0
        
        pub.publish(backup)

    def check_distance(self):
        if self.pose1 is None or self.pose2 is None:    # if initial poses are nonexistent do nothing
            return

        #else calc the distance as the norm 
        dx = self.pose1.x - self.pose2.x
        dy = self.pose1.y - self.pose2.y

        dist = math.sqrt(dx*dx + dy*dy)

        # we show the distance
        distance_msg = Float32()
        distance_msg.data = dist
        self.dist_pub.publish(distance_msg)
        print(f"Distance between turtles: {dist:.2f}")

        # if too close, make them back away from each other
        if dist < THRESHOLD:
            print("WARNING: Turtles too close! Backing away...")
            
            # make both turtles move backwards
            backup1 = Twist()
            backup1.linear.x = -BACKUP_SPEED
            self.cmd_pub_turtle1.publish(backup1)
            
            backup2 = Twist()
            backup2.linear.x = -BACKUP_SPEED
            self.cmd_pub_turtle2.publish(backup2)
            
            return  # skip boundary check if handling collision

        # check if frst turtle is going outside the window
        if (self.pose1.x < BOUNDARY_MIN or self.pose1.x > BOUNDARY_MAX or 
            self.pose1.y < BOUNDARY_MIN or self.pose1.y > BOUNDARY_MAX):
            self.move_away_from_boundary(self.pose1, self.cmd_pub_turtle1, "Turtle1")

        # check if scnd is going outside the window
        if (self.pose2.x < BOUNDARY_MIN or self.pose2.x > BOUNDARY_MAX or 
            self.pose2.y < BOUNDARY_MIN or self.pose2.y > BOUNDARY_MAX):
            self.move_away_from_boundary(self.pose2, self.cmd_pub_turtle2, "Turtle2")


def main(args=None):

    rclpy.init(args=args)
    node = distance_node()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        print("\nExiting because of CTRL+C")
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()