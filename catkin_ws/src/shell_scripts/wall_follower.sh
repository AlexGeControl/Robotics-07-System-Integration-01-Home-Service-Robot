#!/bin/bash

# a. turtlebot world:
xterm  -name "Turtlebot World" -e "roslaunch home_service_robot turtlebot_world.launch" &
sleep 5

# b. gmapping demo:
xterm  -name "Gmapping" -e  "roslaunch home_service_robot gmapping_fine_tuned.launch" &
sleep 5

# c. navigation:
xterm  -name "Navigation" -e  "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5

# d. teleop:
xterm  -name "TeleOp" -e  "rosrun wall_follower wall_follower"