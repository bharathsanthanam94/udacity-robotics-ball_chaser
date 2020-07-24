**Go Chase it- Udacity Robotics Nanodegree**

A differentiated drive robot housed in a building simulated in gazebo. The robot is equipped with camera and Hokuyo laser sensor. If the robot finds a white ball , it drives towards it.

**Description**
There are two ROS packages inside the catkin_ws.

**1.my_robot:**
This package contains the robot designed using URDF( Unified Robot description format), a white ball and a building in a gazebo environment.

**2.ball chaser**:
Contains two C++ nodes, **drive_bot and process_image**

The nodes interact with the robot and make it chase the ball.

**ROS node : drive_bot**

Provides **ball_chaser/command_robot** service to drive the robot. Controls x velocity and angular z velocity.

**ROS node : process_image**

Reads the camera image, analyze if the ball is present,also detects the ball position in the image.
If the ball is detected, node requests service to drive the robot towards it.

**Steps to run the project**

**Step-1: Launch the robot inside the world**

$ cd catkin_ws

$ source devel/setup.bash

$ roslaunch my_robot world.launch

**Step-2: Run the C++ files drive_bot and process_image.cpp**

$ cd catkin_ws

$ source devel/setup.bash

$ roslaunch ball_chaser ball_chaser.launch

Place the white ball in front of the robot and robot will chase the ball!
