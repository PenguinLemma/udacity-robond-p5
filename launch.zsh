#!/bin/zsh

if [ $# -eq 0 ]
then
    echo "No arguments supplied. Melodic assumed as default ROS distribution."
    ROS_DISTRO="melodic"
else
    ROS_DISTRO=$1
fi

ROS_DISTRO="$(echo $ROS_DISTRO | tr '[A-Z]' '[a-z]')"

if [ "$ROS_DISTRO" != "melodic" -a "$ROS_DISTRO" != "kinetic" ]
then
    echo "ROS Distribution not supported"
    return 1
fi

LAUNCHER="script/$ROS_DISTRO/launch.zsh"
chmod +x "$LAUNCHER"
./"$LAUNCHER"