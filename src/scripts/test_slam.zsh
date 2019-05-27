#!/bin/zsh

xterm -e " source devel/setup.zsh; roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 5
xterm -e " source devel/setup.zsh; roslaunch gmapping slam_gmapping_pr2.launch " &
sleep 5
xterm -e " source devel/setup.zsh; roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5
xterm -e " source devel/setup.zsh; roslaunch turtlebot_teleop keyboard_teleop.launch "