cmake_minimum_required(VERSION 3.8)
project(a2_controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find and determine the dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# generate the messages and the required services
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/ObstacleInfo.msg"
  "srv/SetSafetyThreshold.srv"
  "srv/GetVelocityStats.srv"
  DEPENDENCIES geometry_msgs std_msgs
)

# build the control node
add_executable(control_node src/control_node.cpp)
ament_target_dependencies(control_node rclcpp geometry_msgs sensor_msgs std_msgs)
# link the node to the custom messages we created
rosidl_target_interfaces(control_node ${PROJECT_NAME} "rosidl_typesupport_cpp")

# build the statistics node
add_executable(stat_node src/stat_node.cpp)
ament_target_dependencies(stat_node rclcpp geometry_msgs)
rosidl_target_interfaces(stat_node ${PROJECT_NAME} "rosidl_typesupport_cpp")

# we install them so the ros2 run can find them 
install(TARGETS
  control_node
  stat_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files WITH SYMLINK (no rebuild needed for changes!)
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
  USE_SOURCE_PERMISSIONS
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()