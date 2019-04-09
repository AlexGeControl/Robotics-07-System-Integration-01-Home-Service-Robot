#!/bin/bash

# a. launch gazebo:
xterm  -e  " gazebo " &
sleep 5
# b. launch ROS core:
xterm  -e  " source /opt/ros/kinetic/setup.bash; roscore" & 
sleep 5
# c. launch RViz
xterm  -e  " rosrun rviz rviz" 
