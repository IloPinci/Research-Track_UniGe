import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node

def generate_launch_description():
    # package Directories
    pkg_controller = get_package_share_directory('a2_controller')
    pkg_gazebo = get_package_share_directory('bme_gazebo_sensors')

    # include Robot Spawn Launch - here also the rviz world is opened so no need to declare is as a node down
    spawn_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_gazebo, 'launch', 'spawn_robot.launch.py')
        )
    )

    # controller node
    control_node = Node(
        package='a2_controller',
        executable='control_node',
        name='control_node'
    )

    # stats node
    stat_node = Node(
        package='a2_controller',
        executable='stat_node',
        name='stat_node'
    )

    return LaunchDescription([
        spawn_launch,
        control_node,
        stat_node,
    ])