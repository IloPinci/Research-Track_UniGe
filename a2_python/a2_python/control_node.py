#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from a2_interfaces_python.msg import ObstacleInfo
from a2_interfaces_python.srv import GetVelocityStats, SetSafetyThreshold

class ControlNode(Node):

    def __init__(self):
        super().__init__('control_node') # Best practice: lowercase node names

        # internal State
        self.safety_threshold = 0.5
        self.safety_active = False
        self.backup_counter = 0  # Fixed typo: conter -> counter
        self.max_backup_iterations = 10
        self.last_log_time = self.get_clock().now()

        # subscribers
        self.create_subscription(Twist, '/cmd_vel_input', self.input_callback, 10)
        self.create_subscription(LaserScan, '/scan', self.scan_callback, 10)

        # publishers
        self.publish_cmd = self.create_publisher(Twist, '/cmd_vel', 10)
        self.publish_info = self.create_publisher(ObstacleInfo, '/obstacle_info', 10)

        # service
        self.create_service(SetSafetyThreshold, 'set_safety_threshold', self.set_threshold_callback)
        
        self.get_logger().info("Control Node Started")


    def input_callback(self, msg):
        self.get_logger().info(f"INPUT RECEIVED: {msg.linear.x}")  # <--- ADD THIS

        if not self.safety_active:
            self.publish_cmd.publish(msg)
        else:
            self.get_logger().info("BLOCKED BY SAFETY") # <--- ADD THIS


    def scan_callback(self, msg):
        min_value = 100.0 # Initialize with a safe high float, not integer 10000
        index = -1

        # Determine closest point
        # Optimization: enumerate is cleaner than range(len())
        for i, val in enumerate(msg.ranges):
            # we need to ignore the 0 and infinite values
            if val == 0.0 or val == float('inf'):
                continue

            if val < min_value:
                min_value = val
                index = i
        
        # --- Backup Logic ---
        if self.safety_active and self.backup_counter > 0:
            reverse_cmd = Twist()
            reverse_cmd.linear.x = -0.5
            # FIX 1: Use .publish()
            self.publish_cmd.publish(reverse_cmd)
            self.backup_counter -= 1

            if self.backup_counter == 0:
                stop = Twist() # defaults to 0.0
                self.publish_cmd.publish(stop)
                self.safety_active = False      

        # --- Obstacle Detection Logic ---
        elif min_value < self.safety_threshold and not self.safety_active:
            self.safety_active = True
            self.backup_counter = self.max_backup_iterations

            # FIX 2: Added parentheses () to instantiate the class
            reverse_cmd = Twist() 
            reverse_cmd.linear.x = -0.5
            self.publish_cmd.publish(reverse_cmd)

            # Throttle Logging
            now = self.get_clock().now()
            # FIX 3: variable name match (last_log_time vs last_log_time_)
            if (now - self.last_log_time).nanoseconds >= 1e9:
                self.get_logger().warn("\033[1;33mOBSTACLE! Backing up.\033[0m")
                self.last_log_time = now

        # --- Publish Info ---
        info = ObstacleInfo()
        info.min_distance = float(min_value)
        info.current_threshold = float(self.safety_threshold)

        mid = len(msg.ranges) // 2
        if index == -1:
            info.direction = "None"
        elif index > mid + 50:
            info.direction = "Left"
        elif index < mid - 50:
            info.direction = "Right"
        else:
            info.direction = "Front"

        # FIX 3: variable name match (publish_info vs pub_info_)
        self.publish_info.publish(info)

    
    def set_threshold_callback(self, request, response):
        self.safety_threshold = request.new_threshold
        response.success = True
        # FIX 3: variable name match (safety_threshold vs safety_threshold_)
        self.get_logger().info(f"Threshold updated to {self.safety_threshold:.2f}")
        return response

def main(args=None):
    rclpy.init(args=args)
    node = ControlNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

# FIX 4: Correct main check syntax (underscores required)
if __name__ == '__main__':
    main()