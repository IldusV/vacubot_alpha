# 🧹 Vacubot Alpha Setup Guide

📥 Clone the Repository

```bash
git clone git@github.com:IldusV/vacubot_alpha.git
```
🧪 Run the Robot in Simulated Environment (PC)

Open the software/ros2_ws folder in VSCode.
Select "Reopen in Container" when prompted.
```bash
colcon build --symlink-install
source install/setup.bash
ros2 launch vacuum_bot launch_sim.launch.py
ros2 run teleop_twist_keyboard teleop_twist_keyboard
```

🤖 Run the Robot on Physical Hardware (Raspberry Pi)

🛠️ Flash Arduino via PlatformioCLI
```bash
cd software/arduino
source ~/.platformio-env/bin/activate
pio run
pio run -t upload
```

🚀 Run ROS 2 on Raspberry Pi
```bash
cd software/ros2_ws
colcon build --symlink-install
source install/setup.bash
ros2 launch vacuum_bot launch_robot.launch.py
```

