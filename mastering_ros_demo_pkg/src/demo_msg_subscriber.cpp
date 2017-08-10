#include "ros/ros.h"
#include "mastering_ros_demo_pkg/demo_msg.h"
#include <iostream>
#include <string>

void msg_callback(const mastering_ros_demo_pkg::demo_msg::ConstPtr& msg){
	
	ROS_INFO("Recieved greeting [%s]", msg->greeting.c_str());
	ROS_INFO("Recieved [%d]", msg->number);
}

int main(int argc, char** argv){

	ros::init(argc, argv, "demo_mag_subscriber");
	ros::NodeHandle node_obj;
	ros::Subscriber msg_subscriber = node_obj.subscribe("/demo_msg_topic", 10, msg_callback);
	ros::spin();

	return 0;
}
