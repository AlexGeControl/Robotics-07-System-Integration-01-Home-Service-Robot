#!/bin/bash

# Test SLAM

# a. turtlebot world:
xterm  -name "Turtlebot World" -e "roslaunch home_service_robot turtlebot_world.launch" &
sleep 5

# b. gmapping demo:
xterm  -name "Gmapping" -e  "roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 5

# c. navigation:
xterm  -name "Navigation" -e  "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5

# d. teleop:
xterm  -name "TeleOp" -e  "roslaunch turtlebot_teleop keyboard_teleop.launch"