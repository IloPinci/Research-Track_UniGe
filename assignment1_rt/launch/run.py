#!/usr/bin/env python3
from launch import LaunchDescription
from launch.actions import ExecuteProcess, RegisterEventHandler, EmitEvent
from launch.event_handlers import OnProcessExit
from launch.events import Shutdown
from launch_ros.actions import Node

def generate_launch_description():
    
    # turtlesim node
    turtlesim_node = Node(
        package='turtlesim',
        executable='turtlesim_node',
        output='screen'
    )
    
    # spawn second turtle
    spawn_turtle = ExecuteProcess(
        cmd=['ros2', 'service', 'call', '/spawn', 'turtlesim/srv/Spawn', 
             '{x: 7.0, y: 7.0, theta: 0.0, name: "turtle2"}'],
        output='screen'
    )
    
    # ui_node (needs terminal for user input)
    ui_node = ExecuteProcess(
        cmd=['konsole', '-e', 'ros2', 'run', 'assignment1_rt', 'ui_node'],
        output='screen'
    )
    
    # distance_node (dedicated terminal)
    distance_node = ExecuteProcess(
        cmd=['konsole', '-e', 'ros2', 'run', 'assignment1_rt', 'distance_node'],
        output='screen'
    )
    
    # when the ui exits we close all the others
    ui_exit_handler = RegisterEventHandler(
        OnProcessExit(
            target_action=ui_node,
            on_exit=[
                EmitEvent(event=Shutdown())
            ]
        )
    )
    
    return LaunchDescription([
        turtlesim_node,
        spawn_turtle,
        ui_node,
        distance_node,
        ui_exit_handler,
    ])