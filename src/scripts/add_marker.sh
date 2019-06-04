#!/bin/sh

xterm -e " source devel/setup.sh; roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 5
xterm -e " source devel/setup.sh; roslaunch turtlebot_gazebo amcl_demo.launch " &
sleep 5
xterm -e " source devel/setup.sh; roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5
xterm -e " source devel/setup.sh; rosrun add_markers add_markers_node "
