/**
 *  @file 	change_output_string_client.cpp
 *  @brief	client to change the output string, not nessesary.
 *  @details	alternative way to change string.
 *  @author     Jiawei Ge(SonamYeshe)
 *  @copyright  BSD, GNU Public License 2017 Jiawei Ge
 *  @disclaimer	Jiawei Ge(SonamYeshe), hereby disclaims all copyright 			interest in the program
 		`beginner_tutorials' (which makes passes at compilers) 			written by Jiawei Ge(SonamYeshe).
 		<signature of Jiawei Ge>, 14 November 2017
 		Jiawei Ge
 */

#include <string>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/ChangeOutputString.h"

/**
 *  @brief	receive a string and update it to the talker.	
 *  @param	integer of argument count
 *  @param	char pointer of argument value
 *  @return	a bool value
 */
int main(int argc, char **argv) {
  /**
   *  instruction of using this client.
   */
  ros::init(argc, argv, "change_output_string_client");
  if (argc != 2) {
    ROS_INFO("usage: change_output_string_client <newString>");
    return 1;
  }

  /**
   *  build a srv to call the service in the talker.
   */
  ros::NodeHandle n;
  ros::ServiceClient client = n
      .serviceClient<beginner_tutorials::ChangeOutputString>(
      "change_output_string");
  beginner_tutorials::ChangeOutputString srv;
  srv.request.new_string = argv[1];
  if (client.call(srv)) {
    ROS_INFO("New: %s", srv.request.new_string.c_str());  /**don't write a (std_msgs::string) in front of the srv..... <*/
  } else {
    ROS_ERROR("Failed to call service change_output_string");
    return 1;
  }

  return 0;
}

