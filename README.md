# Research Track UniGe: Assignment-2 (Python Implementation)

## Overview
A ROS2 package implementing autonomous collision avoidance and velocity statistical monitoring using **Python**. This project features a safety-aware controller that overrides user input when obstacles are detected by Lidar, and a statistics node that tracks velocity metrics.

**Note:** This assignment has been implemented in both **C++ and Python**. This README covers the Python implementation.

## Package Structure
This project is split into two packages to separate logic from interface definitions:

1. **`a2_python`**: Contains the source code for the nodes (`control_node`, `stat_node`) and launch files.
2. **`a2_interfaces_python`**: Contains the custom message (`ObstacleInfo`) and service definitions (`GetVelocityStats`, `SetSafetyThreshold`).

## Nodes

### 1. `control_node`
Acts as a safety middleware between the user and the robot.
- **Functionality**: 
  - Listens to `/cmd_vel_input` (user commands) and `/scan` (Lidar data).
  - **Safety Check**: If an obstacle is closer than `safety_threshold` (default: 0.5m), it overrides the user command, stops the robot, and performs a backup maneuver.
  - **Passthrough**: If safe, forwards commands to `/cmd_vel`.
  - Publishes obstacle metadata (distance, direction, current threshold).
- **Subscribers**:
  - `/cmd_vel_input` (`geometry_msgs/msg/Twist`) - User velocity commands
  - `/scan` (`sensor_msgs/msg/LaserScan`) - Laser scanner data
- **Publishers**:
  - `/cmd_vel` (`geometry_msgs/msg/Twist`) - Filtered velocity commands to robot
  - `/obstacle_info` (`a2_interfaces_python/msg/ObstacleInfo`) - Obstacle information
- **Services**:
  - `set_safety_threshold` (`a2_interfaces_python/srv/SetSafetyThreshold`) - Dynamically adjusts the obstacle detection distance

### 2. `stat_node`
Monitors the robot's actual commands and calculates moving averages.
- **Functionality**:
  - Maintains a sliding window (queue) of the last 5 velocity commands.
  - Provides a service to fetch the average linear and angular velocity.
- **Subscribers**:
  - `/cmd_vel` (`geometry_msgs/msg/Twist`) - Robot velocity commands
- **Services**:
  - `get_velocity_stats` (`a2_interfaces_python/srv/GetVelocityStats`) - Returns the computed averages

## Custom Interfaces

### Messages
**`ObstacleInfo.msg`**
```text
float32 min_distance
string direction
float32 current_threshold
```

### Services

**`SetSafetyThreshold.srv`**
```text
float32 new_threshold
---
bool success
```

**`GetVelocityStats.srv`**
```text
---
float32 avg_linear_vel
float32 avg_angular_vel
```

## Dependencies

- `rclpy` (ROS2 Python client library)
- `geometry_msgs`
- `sensor_msgs`
- `std_msgs`
- `bme_gazebo_sensors` (for simulation environment)
- `teleop_twist_keyboard` (for manual robot control)

## Installation & Setup

### Prerequisites
Ensure you have ROS2 Humble installed. If not, follow the official [ROS2 Humble installation guide](https://docs.ros.org/en/humble/Installation.html).

### Clone and Build

1. **Create a workspace (if you don't have one):**
```bash
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src
```

2. **Clone this repository:**
```bash
git clone <your-repository-url> a2_python
```

3. **Build the Interface Package First**
The interfaces must be generated before the Python nodes can import them.
```bash
cd ~/ros2_ws
colcon build --packages-select a2_interfaces_python
source install/setup.bash
```

4. **Build the Python Controller:**
```bash
colcon build --packages-select a2_python --symlink-install
source install/setup.bash
```

**Note:** If you encounter an error saying "Is a directory", clean your build artifacts:
```bash
rm -rf build/ install/ log/
```
Then rebuild.

5. **Source the workspace:**
```bash
source install/setup.bash
```

**Note:** You need to source ROS2 and your workspace in every new terminal:
```bash
source /opt/ros/humble/setup.bash
source ~/ros2_ws/install/setup.bash
```

**Optional - Auto-source on terminal startup:**
Add these lines to your `~/.bashrc` to avoid manual sourcing:
```bash
echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
echo "source ~/ros2_ws/install/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

## How to Run

### Method 1: Using Launch File (Recommended)

Launch everything (Gazebo, RViz, control_node, stat_node) with a single command:

```bash
ros2 launch a2_python system.launch.py
```

This will open:
- Gazebo simulation window
- RViz visualization window
- Both controller and statistics nodes

### Method 2: Manual Node Execution

If you prefer to run nodes individually:

**Terminal 1 - Start simulation:**
```bash
ros2 launch bme_gazebo_sensors spawn_robot.launch.py
```

**Terminal 2 - Start controller:**
```bash
ros2 run a2_python control_node
```

**Terminal 3 - Start statistics node:**
```bash
ros2 run a2_python stat_node
```

## Usage

### 1. Control the Robot

In a new terminal, run the keyboard teleop (remapped to send commands to `/cmd_vel_input`):

```bash
ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args --remap cmd_vel:=/cmd_vel_input
```

Use the keyboard controls displayed in the terminal to drive the robot:
- `i` - Move forward
- `j` - Turn left
- `l` - Turn right
- `k` - Stop
- `,` - Move backward
- `q/z` - Increase/decrease max speeds

The controller will automatically stop and reverse the robot if it gets too close to an obstacle.

### 2. Change Safety Threshold

Set a new safety threshold (default is 0.5 meters):

```bash
ros2 service call /set_safety_threshold a2_interfaces_python/srv/SetSafetyThreshold "new_threshold: 1.0"
```

### 3. Get Velocity Statistics

Retrieve average velocities of the last 5 commands:

```bash
ros2 service call /get_velocity_stats a2_interfaces_python/srv/GetVelocityStats "{}"
```

### 4. Monitor Obstacle Information

View real-time obstacle data:

```bash
ros2 topic echo /obstacle_info
```

**Expected Output:**
```yaml
min_distance: 0.45
current_threshold: 0.5
direction: "Front"
```

## Testing the System

1. **Launch the system:**
```bash
ros2 launch a2_python system.launch.py
```

2. **Start keyboard control:**
```bash
ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args --remap cmd_vel:=/cmd_vel_input
```

3. **Drive toward a wall** - The robot should automatically back up when it gets too close

4. **Test velocity statistics** - Drive around, then check averages:
```bash
ros2 service call /get_velocity_stats a2_interfaces_python/srv/GetVelocityStats "{}"
```

5. **Adjust threshold** - Make the robot more/less sensitive:
```bash
ros2 service call /set_safety_threshold a2_interfaces_python/srv/SetSafetyThreshold "new_threshold: 0.8"
```

## Troubleshooting

**Issue: "Service not found" / "Type not found"**
- Solution: You likely forgot to source the setup file in the new terminal:
```bash
source install/setup.bash
```

**Issue: Robot does not move**
- Check: Ensure Gazebo is not paused (Play button in bottom left)
- Check: Ensure you remapped the teleop node correctly (see "How to Run")
- Check: If the robot is backing up automatically, you might be too close to a wall

**Issue: `ImportError: cannot import name 'ObstacleInfo'`**
- Solution: The interface package was not built or sourced correctly. Re-run the installation steps in order:
```bash
cd ~/ros2_ws
colcon build --packages-select a2_interfaces_python
source install/setup.bash
colcon build --packages-select a2_python --symlink-install
source install/setup.bash
```

**Issue: "Package not found" errors**
- Solution: Make sure you've sourced both ROS2 and your workspace:
```bash
source /opt/ros/humble/setup.bash
source ~/ros2_ws/install/setup.bash
```

## Architecture

```
┌─────────────────┐
│  User (Teleop)  │
└────────┬────────┘
         │ /cmd_vel_input
         ▼
┌─────────────────────────────┐
│     control_node (Python)   │
│  ┌──────────────────────┐   │
│  │ Safety Filter        │   │──► /cmd_vel ──► Robot
│  │ - Obstacle Detection │   │
│  │ - Auto Backup        │   │──► /obstacle_info
│  └──────────────────────┘   │
└─────────────────────────────┘
         │
         │ /cmd_vel (monitored)
         ▼
┌─────────────────────────────┐
│      stat_node (Python)     │
│  ┌──────────────────────┐   │
│  │ Statistics Tracker   │   │
│  │ - Last 5 velocities  │   │
│  │ - Moving average     │   │
│  └──────────────────────┘   │
└─────────────────────────────┘
         │
         └──► get_velocity_stats service
```

## Repository Structure

```
a2_python/
├── package.xml
├── setup.py
├── README.md
├── launch/
│   └── system.launch.py
├── a2_python/
│   ├── __init__.py
│   ├── control_node.py
│   └── stat_node.py
└── resource/
    └── a2_python

a2_interfaces_python/
├── CMakeLists.txt
├── package.xml
├── msg/
│   └── ObstacleInfo.msg
└── srv/
    ├── GetVelocityStats.srv
    └── SetSafetyThreshold.srv
```
