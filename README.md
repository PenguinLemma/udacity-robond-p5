[![Udacity - Robotics NanoDegree Program](https://s3-us-west-1.amazonaws.com/udacity-robotics/Extra+Images/RoboND_flag.png)](https://www.udacity.com/robotics)

# udacity-robond-p5
Home Service Robot - Final project of the Udacity Robotics Software Engineer Nanodegree

## Set-up

Check out the setup for the Udacity Workspace [here](doc/UDACITY_WS_SETUP.md).

1. Clone the repository
```git
git clone https://github.com/PenguinLemma/udacity-robond-p5.git $PATH_TO_PARENT_DIR/penguin_lemma_hsr
```

2. Build all packages involved
```shell
cd $PATH_TO_PARENT_DIR/penguin_lemma_hsr
catkin_make
```

3. Install `xterminal`
The scripts that take care of launching all processes for each of the functional steps in this projects use `xterminal` as a mean to produce independent new terminals that will run a certain set of commands. To install it, one just needs to run
```shell
sudo apt install xterm
```

Note that to terminate correctly all processes open, it is necessary to do `Ctrl+C` in each of the `xterminal` open. Otherwise, even if we close all related windows, processes such as `gzserver` could still be running under the hood, and that would prevent us from running some other script or using `gazebo` for some other purpose.

4. Set-up environment
In every new terminal, it is necessary to
```shell
cd $PATH_TO_PARENT_DIR/penguin_lemma_hsr
source src/scripts/set_environment.$TERMINAL
```
where $TERMINAL can be `bash`, `sh` or `zsh`.

Paths are not relative to where the terminal is when you source that script, so you could also use the following commands
```shell
cd $PATH_TO_PARENT_DIR/penguin_lemma_hsr/src/scripts
source set_environment.$TERMINAL
```

5. Run a simple test
To check that `xterminal` is installed and can be run, open and setup a terminal as above and then run
```shell
chmod +x src/scripts/launch.$TERMINAL
./src/scripts/launch.$TERMINAL
```

As a result, `gazebo` and `rviz` should open and `roscore` will be up and running.

## Mapping

It is as simple as running the command
```shell
source src/scripts/test_slam.$TERMINAL
```
It can also be done as follows:
```shell
chmod +x src/scripts/test_slam.$TERMINAL
./src/scripts/test_slam.$TERMINAL
```

This script will launch:
 - Turtlebot inside the world in `src/world`.
 - `gmapping` demo
 - `rviz` with a configuration that will show navigation
 - `keyboard_teleop`, a node that will allow you to command the turtlebot with your keyboard

In order to map a different world, edit `src/scripts/test_slam.$TERMINAL` substituting the path to your `.world` file after `world_file:=`.

Drive the turtlebot around for a while and when you are happy with the map, before terminating `gmapping` node, use the following command in a new terminal (setting it up as explained above):
```shell
rosrun map_server map_saver -f /path/to/map/name
```
Do not include any extension, as this command will create both the `.pgm` file with the map and the `.yaml` configuration file.

## Localization and navigation

Now that we created a map for our world, our robot will be able to localize itself in the map and also navigate to any goal in its reach. In the case of the localization, we are using AMCL (Adaptive Monte Carlo Localization). For navigation, we rely on ROS Navigation stack, which is based on Dijkstra's algorithm. To see it in action:
```shell
chmod +x src/scripts/test_navigation.$TERMINAL
./src/scripts/test_navigation.$TERMINAL
```
In the case we are using another world, we would only need to edit `src/scripts/test_navigation.$TERMINAL` substituting the path to the target `.world` file after `world_file:=` and the location of the configuration for the map we created in the previous section after `map_file:=`. In this case, we need to explicitely add the extension `.yaml` to the command.

Now go to the `xterminal` that is running `rviz`, select `2D Nav Goal` and locate it wherever in the map you want the robot to move.

## ROS nodes

Let's now introduce the two nodes that were written for this project: `pick_objects` and `add_markers`.

### `pick_objects`

Instead of adding the goals manually, we would like to have a node that does this for us. `pick_objects` will command our robot to:
- Go to a pick-up location in our map
- Wait for 5 seconds (simulating picking up a virtual object)
- Go to a drop-off location in our map
- Inform us at every stage

Both pick-up and drop-off targets can be customized as parameters in `src/pick_objects/launch/pick_objects.launch`.

To test this node, we need to run:
```shell
chmod +x src/scripts/pick_objects.$TERMINAL
./src/scripts/pick_objects.$TERMINAL
```
in a properly set up terminal.

### `add_markers`

This node serves us as visual aid to show what the robot is asked to do. The node will publish markers (so that `rviz` can display them) related to the actions commanded by `pick_objects`. There are two modes for this node:

1. Robot independent

This mode is basically the testing phase of our node. The behaviour expected is:
- Show marker in pick-up zone for 5 seconds
- Hide marker
- Wait 5 seconds
- Show marker in drop-off zone

To test it, run
```shell
chmod +x src/scripts/add_markers.$TERMINAL
./src/scripts/add_markers.$TERMINAL
```

2. Robot dependent

In this case, the node is tracking the robot and will:
- Show marker in pick-up zone
- Hide marker once robot reaches pick-up zone
- Show marker in drop-off zone once the roboto reaches it

We will test this node in the next and last step, as we will need to integrate it with `pick_objects`.

Pick-up and drop-off zones for both modes can be set through parameters in `src/add_markers/launch/add_markers.launch` and `src/add_markers/add_markers_tracking_robot.launch` respectively.

## Home Service Robot

Finally, we integrate all the previous parts to achieve the following:

- Robot can localize itself and navigate through the map
- It goes to the pick up zone, marked with a blue marker visible in `rviz`
- Once there, the marker disappears and the robot waits for 5 seconds, simulating picking up the virtual object
- The robot goes then to the drop-off zone
- Once there, a blue marker is displayed

Run the following commands to see this process:
```shell
chmod +x src/scripts/home_service.$TERMINAL
./src/scripts/home_service.$TERMINAL
```

## License
Original version of the license of this repository can be found here:
https://gist.github.com/laramartin/7796d730bba8cf689f628d9b011e91d8
