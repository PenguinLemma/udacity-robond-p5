#!/bin/bash

xterm -e " source devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 5
xterm -e " source devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch " &
sleep 5
xterm -e " source devel/setup.bash; roslaunch add_markers view_navigation_and_markers.launch " &
sleep 5
xterm -e " source devel/setup.bash; roslaunch add_markers add_markers.launch "
