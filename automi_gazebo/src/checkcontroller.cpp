#include <ros/ros.h>
#include<trajectory_msgs/JointTrajectoryPoint.h>
#include<trajectory_msgs/JointTrajectory.h>

int main(int argc, char** argv)
{
    ros::init(argc,argv,"checkcontroller");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<trajectory_msgs::JointTrajectory>("/automi/master_controller/command",10);
    ros::Rate loopRate(10);
    while(ros::ok)
    {
        // ros::spinOnce();
        trajectory_msgs::JointTrajectory ans;
        trajectory_msgs::JointTrajectoryPoint point;
        
        ans.joint_names.push_back("r_knee"); 
        ans.joint_names.push_back("l_elbow");
        
        point.positions.push_back(1.57);
        point.positions.push_back(3.14);
        point.time_from_start.sec = 2;
        ans.points.push_back(point);
        
        ans.header.stamp = ros::Time::now();
        
        pub.publish(ans);
        
        loopRate.sleep();
    }
}