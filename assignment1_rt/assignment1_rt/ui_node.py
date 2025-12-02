#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool
import time
import math
import sys

class command_node(Node):
    def __init__(self):
        super().__init__('command_node')
        
        # Publishers for both turtles
        self.pub_turtle1 = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.pub_turtle2 = self.create_publisher(Twist, '/turtle2/cmd_vel', 10)
        
        # Publisher for shutdown signal
        self.shutdown_pub = self.create_publisher(Bool, '/shutdown_signal', 10)



    def run(self):
        while rclpy.ok():
            str = input("Select turtle (1/2) or 'q' to quit: ").strip()
            if str == 'q':
                print("\nExiting and shutting down all nodes...")
                # Publish shutdown signal
                shutdown_msg = Bool()
                shutdown_msg.data = True
                self.shutdown_pub.publish(shutdown_msg)
                time.sleep(0.5)  # Give time for message to be sent
                break

            if str not in ['1', '2']:
                print("Invalid turtle name")
                continue

            try:
                # we determine which turtle was chosen
                if str == '1':
                    pub = self.pub_turtle1
                else:
                    pub = self.pub_turtle2

                # now we determine the velocities 
                l = float(input("Linear between -2 to 2: "))
                a = float(input("Angular between -3 to 3 : "))

            except ValueError:
                print("Invalid velocity input")
                continue

            # we create and clamp values to a twist
            twist = Twist()

            if l < -2 or l > 2:
                print(f"Warning: Linear velocity clamped")
            if a < -3 or a > 3:
                print(f"Warning: Angular velocity clamped")

            l = max(-2.0, min(l, 2.0))
            a = max(-3.0, min(a, 3.0))

            twist.linear.x = l
            twist.angular.z = a

            # we send the command for only one second
            pub.publish(twist)
            time.sleep(1.0)

            # after that second we just make the twist values equal 0 to stop it
            twist.linear.x = 0.0
            twist.angular.z = 0.0
            pub.publish(twist)




def main(args=None):
    rclpy.init(args=args)
    node = command_node()

    try:
        node.run()

    except KeyboardInterrupt:
        print("\nExiting because of CTRL+C")
        # also publish shutdown signal on CTRL+C
        shutdown_msg = Bool()
        shutdown_msg.data = True
        node.shutdown_pub.publish(shutdown_msg)
        time.sleep(0.5)

    finally:
        node.destroy_node()
        rclpy.shutdown()
        sys.exit(0)

if __name__ == '__main__':
    main()