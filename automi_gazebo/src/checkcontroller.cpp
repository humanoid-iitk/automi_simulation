#include<ros/ros.h>
#include<trajectory_msgs/JointTrajectoryPoint.h>
#include<trajectory_msgs/JointTrajectory.h>
#include<std_msgs/Duration.h>

const double PI = 3.14519;

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
        
        ans.joint_names.push_back("l_hip_p"); 
        ans.joint_names.push_back("l_knee");
        ans.joint_names.push_back("l_ankle_p");
        ans.joint_names.push_back("r_hip_p"); 
        ans.joint_names.push_back("r_knee");
        ans.joint_names.push_back("r_ankle_p");

        ans.joint_names.push_back("l_shoulder_p"); 
        ans.joint_names.push_back("l_elbow");
        ans.joint_names.push_back("r_shoulder_p");
        ans.joint_names.push_back("r_elbow"); 
        
        point.positions.push_back(-PI/10);
        point.positions.push_back(2*PI/10);
        point.positions.push_back(-PI/10);
        point.positions.push_back(PI/10);
        point.positions.push_back(-2*PI/10);
        point.positions.push_back(PI/10);

        point.positions.push_back(PI/10 - PI/6);
        point.positions.push_back(-2*PI/10);
        point.positions.push_back(-PI/10 + PI/6);
        point.positions.push_back(2*PI/10);

       point.time_from_start = ros::Duration(0, (int)1e8);
        ans.points.push_back(point);
        
        ans.header.stamp = ros::Time::now();
        
        pub.publish(ans);
        
        loopRate.sleep();
    }
}