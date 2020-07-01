#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ball_chaser/DriveToTarget.h"
#include <std_msgs/Float64.h>


ros::Publisher motor_command_publisher;

// Define callback function that executes whenever the service is called


bool handle_move_robot_request(ball_chaser::DriveToTarget::Request&req, ball_chaser::DriveToTarget::Response& res)

{

   geometry_msgs:: Twist move_command;



move_command.linear.x= req.linear_x;
move_command.angular.z=req.angular_z;

motor_command_publisher.publish(move_command);


//wait for 2 seconds for robot to settle
ros::Duration(2).sleep();

//Return a response message
res.msg_feedback = "robot movement parameteres set-linear_x:" + std :: to_string(req.linear_x) + " , angular_z:" + std :: to_string(req.angular_z);
ROS_INFO_STREAM(res.msg_feedback);

return true;

}

 




int main(int argc, char** argv)
{
    
    //Initialize a ROS node
    ros::init(argc,argv,"drive_bot");

    //create a nodehandle object
    ros::NodeHandle n;

    motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);


    ros::ServiceServer service = n.advertiseService("/ball_chaser/command_robot", handle_move_robot_request);


     ros::spin();
     return 0;


}
    
    




