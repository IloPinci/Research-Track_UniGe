# Research Track UniGe: Assignment-2

## Overview
A ROS2 package implementing autonomous collision avoidance and velocity statistical monitoring. The package manages velocity inputs through a safety controller and tracks command history statistics.

## Nodes

### 1. `control_node`
Acts as a safety filter for velocity commands.
- **Functionality**: 
  - Relays commands from `/cmd_vel_input` to `/cmd_vel` if safe.
  - Monitors `/scan` data; if an obstacle is closer than the safety threshold, it halts and reverses the robot for approximately 1 second, then stops.
  - Publishes obstacle metadata (distance, direction, current threshold).
  - Displays yellow warning messages when obstacles are detected.
- **Subscribers**:
  - `/cmd_vel_input` (`geometry_msgs/msg/Twist`) - User velocity commands
  - `/scan` (`sensor_msgs/msg/LaserScan`) - Laser scanner data
- **Publishers**:
  - `/cmd_vel` (`geometry_msgs/msg/Twist`) - Filtered velocity commands to robot
  - `/obstacle_info` (`a2_controller/msg/ObstacleInfo`) - Obstacle information
- **Services**:
  - `set_safety_threshold` (`a2_controller/srv/SetSafetyThreshold`) - Dynamically adjusts the obstacle detection distance

### 2. `stat_node`
Calculates velocity statistics based on command history.
- **Functionality**:
  - Monitors the command stream sent to the robot (`/cmd_vel`).
  - Maintains a moving average of the last 5 linear and angular velocity commands.
- **Subscribers**:
  - `/cmd_vel` (`geometry_msgs/msg/Twist`) - Robot velocity commands
- **Services**:
  - `get_velocity_stats` (`a2_controller/srv/GetVelocityStats`) - Returns the computed averages

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

- `rclcpp`
- `geometry_msgs`
- `sensor_msgs`
- `std_msgs`
- `bme_gazebo_sensors` (for simulation environment)
- `teleop_twist_keyboard` (for manual robot control)
- `xterm` (for separate terminal windows)

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
git clone <your-repository-url> a2_controller
```

3. **Install dependencies:**
```bash
cd ~/ros2_ws
rosdep install --from-paths src --ignore-src -r -y
```

4. **Install xterm (for separate node terminals):**
```bash
sudo apt-get install xterm
```

5. **Build the package with symlink install (allows editing launch files without rebuilding):**
```bash
cd ~/ros2_ws
colcon build --packages-select a2_controller --symlink-install
```

6. **Source the workspace:**
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
ros2 launch a2_controller controller.launch.py
```

This will open:
- Gazebo simulation window
- RViz visualization window
- Two xterm windows showing output from `control_node` and `stat_node`

### Method 2: Manual Node Execution

If you prefer to run nodes individually:

**Terminal 1 - Start simulation:**
```bash
ros2 launch bme_gazebo_sensors spawn_robot.launch.py
```

**Terminal 2 - Start controller:**
```bash
ros2 run a2_controller control_node
```

**Terminal 3 - Start statistics node:**
```bash
ros2 run a2_controller stat_node
```

## Usage

### 1. Control the Robot

In a new terminal, run the keyboard teleop (remapped to send commands to `/cmd_vel_input`):

```bash
ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args --remap cmd_vel:=cmd_vel_input
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
ros2 service call /set_safety_threshold a2_controller/srv/SetSafetyThreshold "{new_threshold: 1.0}"
```

### 3. Get Velocity Statistics

Retrieve average velocities of the last 5 commands:

```bash
ros2 service call /get_velocity_stats a2_controller/srv/GetVelocityStats
```

### 4. Monitor Obstacle Information

View real-time obstacle data:

```bash
ros2 topic echo /obstacle_info
```

## Testing the System

1. **Launch the system:**
```bash
ros2 launch a2_controller controller.launch.py
```

2. **Start keyboard control:**
```bash
ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args --remap cmd_vel:=cmd_vel_input
```

3. **Drive toward a wall** - The robot should automatically back up when it gets too close (yellow warning appears)

4. **Test velocity statistics** - Drive around, then check averages:
```bash
ros2 service call /get_velocity_stats a2_controller/srv/GetVelocityStats
```

5. **Adjust threshold** - Make the robot more/less sensitive:
```bash
ros2 service call /set_safety_threshold a2_controller/srv/SetSafetyThreshold "{new_threshold: 0.8}"
```

## Troubleshooting

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
│     control_node            │
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
│      stat_node              │
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
a2_controller/
├── CMakeLists.txt
├── package.xml
├── README.md
├── launch/
│   └── controller.launch.py
├── msg/
│   └── ObstacleInfo.msg
├── srv/
│   ├── GetVelocityStats.srv
│   └── SetSafetyThreshold.srv
└── src/
    ├── control_node.cpp
    └── stat_node.cpp
```
