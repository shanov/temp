#include "ros/ros.h"
#include "my_service/AddString.h"
#include <string>

using namespace ros;

bool add(my_service::AddString::Request &req, my_service::AddString::Response &res)
{
	res.sum = req.first + req.second;
	//ROS_INFO("request: x = %d, y = %d", req.first, req.second);
	//ROS_INFO("sending back response: [%d]", res.sum);
	return true;
}

int main(int argc, char **argv) {
	init(argc, argv, "add_two_strings_server1");
	NodeHandle n;
	//std::string name = this_node::getName();
	ServiceServer service = n.advertiseService(this_node::getName(), add);
	//ROS_INFO("Ready to add two ints.");
	spin();
	return 0;
}
