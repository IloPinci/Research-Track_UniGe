#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from a2_interfaces_python.srv import GetVelocityStats
from collections import deque

class StatsNode(Node):

    def __init__(self):
        super().__init__('stats_node')

        self.history_linear = deque(maxlen=5)
        self.history_angular = deque(maxlen=5)

        self.create_subscription(Twist, '/cmd_vel', self.vel_callback, 10)
        self.create_service(GetVelocityStats, 'get_velocity_stats', self.get_stats_callback)

        self.get_logger().info("The stats node has started")

    def vel_callback(self, msg):
        self.history_linear.append(msg.linear.x)
        self.history_angular.append(msg.angular.z)

    def get_stats_callback(self, request, response):
        # --- Linear ---
        if len(self.history_linear) == 0:
            response.avg_linear_vel = 0.0
        else:
            avg_lin = sum(self.history_linear) / len(self.history_linear)
            response.avg_linear_vel = float(avg_lin)
        
        # --- Angular ---
        if len(self.history_angular) == 0:
            response.avg_angular_vel = 0.0
        else:
            avg_ang = sum(self.history_angular) / len(self.history_angular)
            # FIX: You were overwriting linear_vel here!
            response.avg_angular_vel = float(avg_ang) 

        self.get_logger().info(
            f"Stats - Linear: {response.avg_linear_vel:.2f}, Angular: {response.avg_angular_vel:.2f}"
        )

        return response

def main(args=None):
    rclpy.init(args=args)
    node = StatsNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()