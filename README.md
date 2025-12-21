# Research Track UniGe: Assignement-2

## Overview
A ROS2 package implementing autonomous collision avoidance and velocity statistical monitoring. The package manages velocity inputs through a safety controller and tracks command history statistics.

## Nodes

### 1. `control_node`
Acts as a safety filter for velocity commands.
- **Functionality**: 
  - Relays commands from `/cmd_vel_input` to `/cmd_vel` if safe.
  - Monitors `/scan` data; if an obstacle is closer than the safety threshold, it halts and reverses the robot.
  - Publishes obstacle metadata (distance, direction).
- **Subscribers**:
  - `/cmd_vel_input` (`geometry_msgs/msg/Twist`)
  - `/scan` (`sensor_msgs/msg/LaserScan`)
- **Publishers**:
  - `/cmd_vel` (`geometry_msgs/msg/Twist`)
  - `/obstacle_info` (`a2_controller/msg/ObstacleInfo`)
- **Services**:
  - `set_safety_threshold` (`a2_controller/srv/SetSafetyThreshold`): Dynamically adjusts the obstacle detection distance.

### 2. `stat_node`
Calculates velocity statistics based on command history.
- **Functionality**:
  - Monitors the command stream to the robot.
  - Maintains a moving average of the last 5 linear and angular velocity commands.
- **Subscribers**:
  - `/cmd_vel` (`geometry_msgs/msg/Twist`)
- **Services**:
  - `get_velocity_stats` (`a2_controller/srv/GetVelocityStats`): Returns the computed averages.

## Custom Interfaces

### Messages
* **`ObstacleInfo.msg`**
  ```text
  float32 min_distance
  string direction
  float32 current_threshold
## Services

* ### SetSafetyThreshold.srv

```plaintext
float32 new_threshold
---
bool success
```

* ### GetVelocityStats.srv

```plaintext
---
float32 avg_linear_vel
float32 avg_angular_vel
```


## Dependencies

* `rclcpp`
* `geometry_msgs`
* `sensor_msgs`
* `std_msgs`



## Build & Run

### Build

```plaintext
colcon build --packages-select a2_controller
source install/setup.bash
```

### Execution

Run the controller:
```plaintext
ros2 run a2_controller control_node
```

Run the statistics node:
```plaintext
ros2 run a2_controller stat_node
```