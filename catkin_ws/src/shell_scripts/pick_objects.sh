#!/bin/bash

# Test Navigation

# a. turtlebot world:
xterm  -name "Turtlebot World" -e "roslaunch home_service_robot turtlebot_world.launch" &
sleep 5

# b. amcl localization:
xterm  -name "Localization" -e "roslaunch home_service_robot amcl_with_home_map.launch" &
sleep 5

# c. navigation:
xterm  -name "Navigation" -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &

# d. pickup & dropoff:
xterm  -name "Pickup & Dropoff" -e "rosrun pick_objects pick_objects"
