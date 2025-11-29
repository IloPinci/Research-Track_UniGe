#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import time
import math

class command_node(Node):
    def __init__(self):
        super().__init__('command_node')

        # Publishers for both turtles
        self.pub_turtle1 = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.pub_turtle2 = self.create_publisher(Twist, '/turtle2/cmd_vel', 10)



    def run(self):
        while rclpy.ok():
            str = input("Select turtle (1/2) or 'q' to quit: ").strip()
            if str == 'q':
                print("\nExiting...")
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
                l = float(input("Enter linear velocity: "))
                a = float(input("Enter angular velocity: "))

            except ValueError:
                print("Invalid velocity input")
                continue

            # we create and assing values to a twist
            twist = Twist()
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
        pass

    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
