#include "ros/ros.h"
#include "geometry_msgs/Point.h"
#include <iostream>

using namespace std;
using namespace ros;

int main(int argc, char **argv)
{
	init(argc, argv, "node");
	NodeHandle n;
	Publisher pub = n.advertise<geometry_msgs::Point>("/input", 10);
	Rate loop_rate(1);
	
	geometry_msgs::Point pnt;

	loop_rate.sleep();
	while (ok())
	{
		//ROS_INFO("Input value: %i\n", a);
		//int_pub = a;
		//int_pub.data = a;

		cin >> pnt.x;
		cin >> pnt.y;
		cin >> pnt.z;

		pub.publish(pnt);
		loop_rate.sleep();
	}
	
	spinOnce();
	
	return 0;
}
