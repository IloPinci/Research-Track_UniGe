import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node

def generate_launch_description():
    # Package Directories
    pkg_controller = get_package_share_directory('a2_controller')
    pkg_gazebo = get_package_share_directory('bme_gazebo_sensors')

    # Include Robot Spawn Launch (this already includes the world)
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

    # RViz2 Node (already included in spawn_robot, remove if duplicated)
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', os.path.join(pkg_gazebo, 'rviz', 'rviz.rviz')]
    )

    return LaunchDescription([
        spawn_launch,
        control_node,
        stat_node,
        rviz_node
    ])