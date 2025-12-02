# Assignment 1 - ROS2 Turtlesim Multi-Turtle Control

## Description

This ROS2 package implements a two-turtle control system in turtlesim.

### What I've Implemented

1. **Interactive UI Node (`ui_node.py`)**
    - By using the terminal the node requests the user to select a specific turtle to command. 
    - Then for the selected turtle it requests the linear and angular velocities. These velocities are clamped so the turtle doesn't 'teleport' and in turn skip coordinates in the cases when the velocities inputed are too big.
    - As requested each command runs for 1 second, unless the turtle collides with a boundary or the other turtle.
    - If the user doesn't select a turtle but wants to quit he can press 'q'. In that calse all the other terminals also quit.

2. **Distance Monitoring Node (`distance_node.py`)**
    - Calculates and prints the distance between two turtles
    - Overrides user commands if there is collision of turtles with each other or if they hit the boundary.
    - *Collision Avoidance*: When the turtles get to close to each other (less then 1.0 units) they both back off so they can have more than one 1.0 units of distance. This is done to avoid the case where the two turtles collide and they ignore subsequent commands because they are stuck.
     - *Boundary Protection*: When a turtle hits the wind frame it rotates to face the center and moves inward. *Why it rotates toward the center?* This is done to avoid the case where the turtle is in a corner. Because in that case the turtle can back off and hit another boundary, causing it to 'back off' by going forward again, thus getting stuck in a loop where it hits different lips of the window frame.


3. **Turtle Spawner (`turtle_spawn.py`)**
   - Spawns the second turtle. (We got it from the assignement)

4. **Launch File (`run.py`)**
   - All nodes start at the same time
   - All nodes are shut down if 'q' is pressed on the UI node, or if CTRL+C is inputed.

## How to Build

Navigate to your ROS2 workspace (for me it is track) and build the package:
```bash
cd ~/track 
colcon build --packages-select assignment1_rt
source install/setup.bash
```

## How to Run

Launch everything with one command:
```bash
ros2 launch assignment1_rt run.py
```

## Package Structure
```
assignment1_rt/
├── assignment1_rt/
│   ├── __init__.py
│   ├── distance_node.py       # Distance monitoring and safety node
│   ├── turtle_spawn.py        # Spawns second turtle
│   └── ui_node.py             # User interface for control
├── launch/
│   └── run.py                 # Launch file to start all nodes
├── resource/
│   └── assignment1_rt
├── test/
│   ├── test_copyright.py
│   ├── test_flake8.py
│   └── test_pep257.py
├── package.xml                # Package dependencies
├── setup.cfg                  # Setup configuration
└── setup.py                   # Python package setup
```


## Dependencies

- ROS2 (Humble or compatible version)
- turtlesim
- Python 3
- konsole (for terminal windows)

If konsole is not installed:
```bash
sudo apt install konsole
```
