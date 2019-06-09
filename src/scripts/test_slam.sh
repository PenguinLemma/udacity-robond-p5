#!/bin/sh

xterm -e " source set_environment.sh; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$ROOT_HSR_REPO_PATH/src/world/home_service_robot_test.world " &
sleep 5
xterm -e " source set_environment.sh; roslaunch gmapping slam_gmapping_pr2.launch " &
sleep 5
xterm -e " source set_environment.sh; roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5
xterm -e " source set_environment.sh; roslaunch turtlebot_teleop keyboard_teleop.launch "
