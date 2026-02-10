import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node

def generate_launch_description():
    pkg_python = get_package_share_directory('a2_python')
    pkg_gazebo = get_package_share_directory('bme_gazebo_sensors')

    # 1. Spawn Robot (Includes World + RViz)
    spawn_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_gazebo, 'launch', 'spawn_robot.launch.py')
        )
    )

    # 2. Your Safety Controller
    control_node = Node(
        package='a2_python',
        executable='control_node',
        name='control_node',
        output='screen'
    )

    # 3. Your Stats Node
    stat_node = Node(
        package='a2_python',
        executable='stat_node',
        name='stat_node',
        output='screen'
    )

    # Note: RViz node removed to prevent duplication

    return LaunchDescription([
        spawn_launch,
        control_node,
        stat_node
    ])