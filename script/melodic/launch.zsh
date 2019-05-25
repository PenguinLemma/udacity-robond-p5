#!/bin/zsh

xterm  -e  " gazebo " &
sleep 5
xterm  -e  " source /opt/ros/melodic/setup.zsh; roscore" &
sleep 5
xterm  -e  " rosrun rviz rviz"