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

        # if to close we stop
        if dist < THRESHOLD:
            stop_msg = Twist()
            self.cmd_pub_turtle1.publish(stop_msg)
            self.cmd_pub_turtle2.publish(stop_msg)

        # stop if going outside the window
        for pose, pub in [(self.pose1, self.cmd_pub_turtle1), (self.pose2, self.cmd_pub_turtle2)]:
            if pose.x < BOUNDARY_MIN or pose.x > BOUNDARY_MAX or pose.y < BOUNDARY_MIN or pose.y > BOUNDARY_MAX:
                pub.publish(Twist())


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
