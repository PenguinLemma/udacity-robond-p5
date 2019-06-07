#!/bin/zsh

xterm -e " source devel/setup.zsh; roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 5
xterm -e " source devel/setup.zsh; roslaunch turtlebot_gazebo amcl_demo.launch " &
sleep 5
xterm -e " source devel/setup.zsh; roslaunch add_markers view_navigation_and_markers.launch " &
sleep 5
xterm -e " source devel/setup.zsh; roslaunch add_markers add_markers_tracking_robot.launch " &
sleep 5
xterm -e " source devel/setup.zsh; roslaunch pick_objects pick_objects.launch "
