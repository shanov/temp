#include "ros/ros.h"
#include "my_service/AddString.h"

using namespace ros;

bool add(my_service::AddString::Request &req, my_service::AddString::Response &res)
{
	res.sum = req.first + req.second;
	//ROS_INFO("request: x = %d, y = %d", req.first, req.second);
	//ROS_INFO("sending back response: [%d]", res.sum);
	return true;
}

int main(int argc, char **argv) {
	init(argc, argv, "add_two_strings_server");
	NodeHandle n;
	ServiceServer service = n.advertiseService("add_two_strings", add);
	//ROS_INFO("Ready to add two ints.");
	spin();
	return 0;
}
