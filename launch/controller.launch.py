import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node

def generate_launch_description():
    # Package Directories
    pkg_controller = get_package_share_directory('a2_controller')
    pkg_gazebo = get_package_share_directory('bme_gazebo_sensors')

    # Include World Launch (Gazebo)
    world_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_gazebo, 'launch', 'world.launch.py')
        )
    )

    # Include Robot Spawn Launch
    spawn_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_gazebo, 'launch', 'spawn_robot.launch.py')
        )
    )

    # Controller Nodes
    control_node = Node(
        package='a2_controller',
        executable='control_node',
        name='control_node'
    )

    stat_node = Node(
        package='a2_controller',
        executable='stat_node',
        name='stat_node'
    )

    # RViz2 Node
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', os.path.join(pkg_gazebo, 'rviz', 'rviz.rviz')]
    )

    return LaunchDescription([
        world_launch,
        spawn_launch,
        control_node,
        stat_node,
        rviz_node
    ])