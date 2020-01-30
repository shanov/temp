#include "ros/ros.h"
#include "my_service/AddString.h"
#include <iostream>

using namespace std;
using namespace ros;

main (int argc, char **argv)
{
	init(argc, argv, "add_string_publisher");
	NodeHandle n;
	ServiceClient client = n.serviceClient<my_service::AddString>(this_node::getName());
	my_service::AddString srv;
	while (ok())
	{
		string a, b;
		//cout << "input the first integer: ";
		cin >> a;
		//cout << "input the second integer: ";
		cin >> b;
		srv.request.first = a;
		srv.request.second = b;
		if (client.call(srv))
		{
			cout << srv.response.sum << endl;
			//cout << "sum = " << srv.response.sum << endl;
		}
		else
		{
			//cout << "Failed to call service add_two_ints" << endl;
			return 1;
		}
	}
	return 0;
}
