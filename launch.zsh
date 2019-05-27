#!/bin/zsh

if [ $# -eq 0 ]
then
    echo "No arguments supplied. Melodic assumed as default ROS distribution."
    ROS_DISTRO="kinetic"
else
    ROS_DISTRO=$1
fi

ROS_DISTRO="$(echo $ROS_DISTRO | tr '[A-Z]' '[a-z]')"

if [ "$ROS_DISTRO" != "melodic" -a "$ROS_DISTRO" != "kinetic" ]
then
    echo "ROS Distribution not supported"
    return 1
fi

LAUNCHER="src/scripts/$ROS_DISTRO/launch.zsh"
chmod +x "$LAUNCHER"
./"$LAUNCHER"