#!/bin/sh

xterm -e " source devel/setup.sh; roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 5
xterm -e " source devel/setup.sh; roslaunch gmapping slam_gmapping_pr2.launch " &
sleep 5
xterm -e " source devel/setup.sh; roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5
xterm -e " source devel/setup.sh; roslaunch turtlebot_teleop keyboard_teleop.launch "
