#include "ros/ros.h"
#include "mastering_ros_demo_pkg/demo_srv.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv){

	ros::init(argc, argv, "demo_service_client");
	ros::NodeHandle node_obj;
	ros::ServiceClient client = node_obj.serviceClient<mastering_ros_demo_pkg::demo_srv>("demo_service");
	ros::Rate loop_rate(10);

	while(ros::ok()){

		mastering_ros_demo_pkg::demo_srv srv;
		srv.request.in = "Sending from Here";
		if(client.call(srv)){
			ROS_INFO("From Client [%s], Server says [%s]", srv.request.in.c_str(), srv.response.out.c_str());
		}
		else{
			ROS_ERROR("Failed t call service");
			return 1;			
		}

		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
