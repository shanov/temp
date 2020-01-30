#include "ros/ros.h"
#include <visualization_msgs/Marker.h>
#include <iostream>

using namespace ros;

visualization_msgs::Marker mrk;
Publisher pub;

void callback(const geometry_msgs::Point &msg)
{
	ROS_INFO("Get point.");
	std::cout << "Get point: " << msg << "\n";
	mrk.points.push_back(msg);
}

int main(int argc, char **argv)
{
	init(argc, argv, "transform");
	NodeHandle n;

	pub = n.advertise<visualization_msgs::Marker>("/output", 10, true);

	Subscriber subscriber = n.subscribe("/input", 10, callback);

	mrk.header.frame_id = "/point_on_map";
	mrk.header.stamp = Time::now();
	mrk.ns = "there_is_point";
	mrk.id = 0;
	mrk.action = visualization_msgs::Marker::ADD;
	mrk.type = visualization_msgs::Marker::POINTS;
	mrk.scale.x = 0.5;
	mrk.scale.y = 0.5;
	mrk.color.r = 1.0;
	mrk.color.g = 0.0;
	mrk.color.b = 0.0;
	mrk.color.a = 1.0;

	Rate loop_rate(10);

	while (ok()) 
	{
		pub.publish(mrk);		
		loop_rate.sleep();
		spinOnce();
	}
	spin();
	return 0;
}
