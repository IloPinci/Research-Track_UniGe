#!/usr/bin/env python3
from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # turtlesim (no dedicated terminal, runs in background)
        Node(
            package='turtlesim',
            executable='turtlesim_node',
            output='screen'
        ),
        # spawn second turtle (no dedicated terminal)
        ExecuteProcess(
            cmd=['ros2', 'service', 'call', '/spawn', 'turtlesim/srv/Spawn', 
                 '{x: 2.0, y: 2.0, theta: 0.0, name: "turtle2"}'],
            output='screen'
        ),
        # ui_node (needs terminal for user input)
        ExecuteProcess(
            cmd=['konsole', '-e', 'ros2', 'run', 'assignment1_rt', 'ui_node'],
            output='screen'
        ),
        # distance_node (dedicated terminal)
        ExecuteProcess(
            cmd=['konsole', '-e', 'ros2', 'run', 'assignment1_rt', 'distance_node'],
            output='screen'
        ),
    ])