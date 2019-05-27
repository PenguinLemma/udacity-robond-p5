# Setup for ros-melodic

## Setting up gmapping package:

Folder src in this repo contains `ros-perception/gmapping`(https://github.com/ros-perception/slam_gmapping) source code together with `ros-perception/openslam_gmapping`(https://github.com/ros-perception/openslam_gmapping). The second package is necessary to be able to build the first in melodic.

## Setting up `turtlebot_teleop`

Folder `src` in this repo contains `turtlebot/turtlebot/turtlebot_teleop`(https://github.com/turtlebot/turtlebot) source code together with `ros-drivers/joystick_drivers/joy` (https://github.com/ros-drivers/joystick_drivers). The second package is necessary to be able to build the first in melodic.

## Setting up `turtlebot_gazebo`

You just need the source code of `turtlebot/turtlebot_simulator/turtlebot_gazebo`. It can be found here: https://github.com/turtlebot/turtlebot_simulator

## Setting up `turtlebot_rviz_launchers`

You just need the source code of `turtlebot/turtlebot_interactions/turtlebot_rviz_launchers`. It can be found here: https://github.com/turtlebot/turtlebot_interactions

### Further reading

https://github.com/turtlebot/turtlebot/issues/272

Check answers from @bunchofcoders and @ProfJust.