#include <string>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/ChangeOutputString.h"
// #include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "change_output_string_client");
  if (argc != 2)
  {
    ROS_INFO("usage: change_output_string_client <newString>");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::ChangeOutputString>("change_output_string");
  beginner_tutorials::ChangeOutputString srv;
  srv.request.new_string = argv[1];
  if (client.call(srv))
  {
  // don't write a (std_msgs::string) in front of the srv.....
    ROS_INFO("New: %s", srv.response.output_string.c_str());
  }
  else
  {
    ROS_ERROR("Failed to call service change_output_string");
    return 1;
  }

  return 0;
}
