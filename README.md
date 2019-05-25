[![Udacity - Robotics NanoDegree Program](https://s3-us-west-1.amazonaws.com/udacity-robotics/Extra+Images/RoboND_flag.png)](https://www.udacity.com/robotics)

# udacity-robond-p5
Home Service Robot - Final project of the Udacity Robotics Software Engineer Nanodegree

## Description

## Instructions

1. Launching
```shell
source launch.$TERMINAL $ROS_DISTRO
```
where `TERMINAL` can be `bash`, `sh` or `zsh` and `ROS_DISTRO` can be `melodic` or `kinetic`.
In the case of not giving any arguments, `melodic` will be taken as default. `ROS_DISTRO` is not case-sensitive.

Launching can also be done as follows:
```shell
chmod +x launch.$TERMINAL
./launch.$TERMINAL
```

2. Terminating

All terminals that open when executing `launch.$TERMINAL` can be closed by doing `Ctrl + C` in the terminal where we executed it, in the case the command was `./launch.$TERMINAL`. In that case, `gazebo` will stay active, and even if we close the window, the process `gzserver` will stay active.

For that reason, it is recommended to interrupt processes in each one of the external terminals (by doing `Ctrl + C`).

## License
Original version of the license of this repository can be found here:
https://gist.github.com/laramartin/7796d730bba8cf689f628d9b011e91d8
