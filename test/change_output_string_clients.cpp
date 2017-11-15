/**
 *  @file   change_output_string_clients.cpp
 *  @brief  test file for the accuracy of the output string
 *  @details
 *  @author     Jiawei Ge(SonamYeshe)
 *  @copyright  BSD, GNU Public License 2017 Jiawei Ge
 *  @disclaimer Jiawei Ge(SonamYeshe), hereby disclaims all copyright interest in the program `beginner_tutorials' (which makes passes at compilers) written by Jiawei Ge(SonamYeshe).
 <signature of Jiawei Ge>, 14 November 2017
 Jiawei Ge
 */

#include <ros/ros.h>
#include <ros/service_client.h>
#include <gtest/gtest.h>
#include <string>
#include "beginner_tutorials/ChangeOutputString.h"

std::shared_ptr<ros::NodeHandle> n;

/**
 *  set the input string to be "what is the hell.", 
 *  check if the output satisfy our expectations.
 */

TEST(TestSuite, changeOutputString) {
  ros::ServiceClient client = n
      ->serviceClient<beginner_tutorials::ChangeOutputString>(
      "change_output_string");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  beginner_tutorials::ChangeOutputString srv;
  srv.request.new_string = "what is the hell.";
  client.call(srv);

  EXPECT_EQ(srv.response.output_string,
            "change to string: " + srv.request.new_string);
}

/**
 *  @brief  Run all the tests that were declared with TEST()  
 *  @param  integer of argument count
 *  @param  char pointer of argument value
 *  @return all tests results
 */

int main(int argc, char **argv) {
  ros::init(argc, argv, "change_output_string_clients");
  n.reset(new ros::NodeHandle);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

