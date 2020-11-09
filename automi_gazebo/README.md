## darwin_gazebo

ROS package providing Gazebo simulation of the AUTOMI robot.

These have been tested in simulation and need some work to be used on the real robot, do not use as-is.

![AUTOMI model in Gazebo](./automi_gazebo.png?raw=true "Darwin model in Gazebo")

## Tutorial

A tutorial describing how to use this package can be found at:

http://www.generationrobots.com/en/content/83-carry-out-simulations-and-make-your-darwin-op-walk-with-gazebo-and-ros

## Install

Clone in your catkin workspace and catkin_make it.
Make sure you also have the following packages in your workspace
* automi_description: https://github.com/humanoid-iitk/automi_simulation/tree/master/automi_description
* automi_control: https://github.com/humanoid-iitk/automi_simulation/tree/master/automi_control
    
## Usage

You can launch the simulation with:

    roslaunch automi_gazebo automi_gazebo.launch
    
PRESS PLAY IN GAZEBO ONLY WHEN EVERYTHING IS LOADED (wait for controllers)

## ROS API

All topics are provided in the /automi namespace.

Sensors:

    /automi/joint_states

Actuators (radians for position control):

    /automi/master_controller/command

## Dependencies

The following ROS packages have to be installed:
* gazebo_ros_control

## License

This software is provided by Génération Robots http://www.generationrobots.com and HumaRobotics http://www.humarobotics.com under the Simplified BSD license