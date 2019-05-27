#!/bin/zsh

xterm  -e  " gazebo " &
sleep 5
xterm  -e  " source /opt/ros/kinetic/setup.zsh; roscore" &
sleep 5
xterm  -e  " rosrun rviz rviz"