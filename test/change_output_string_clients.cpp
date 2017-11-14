#include <ros/ros.h>
#include <ros/service_client.h>
#include <gtest/gtest.h>
#include <string>
#include "beginner_tutorials/ChangeOutputString.h"

std::shared_ptr<ros::NodeHandle> n;

// Declare a test
/**
TEST(TestSuite, broadcastTfFrameTalk)
{
  ros::ServiceClient client = n->serviceClient<beginner_tutorials::BroadcastTfFrameTalk>(
      "broadcast_tf_frame_talk");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  beginner_tutorials::BroadcastTfFrameTalk srv;
  srv.request.;
  client.call(srv);

  EXPECT_EQ(srv.response.sum, srv.request.a + srv.request.b);
}
*/
// Declare another test
TEST(TestSuite, changeOutputString)
{
  ros::ServiceClient client = n->serviceClient<beginner_tutorials::ChangeOutputString>(
      "change_output_string");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  beginner_tutorials::ChangeOutputString srv;
  srv.request.new_string = "what is the hell.";
  client.call(srv);

  EXPECT_EQ(srv.response.output_string, "change to string: " + srv.request.new_string);
}


// Run all the tests that were declared with TEST()
int main(int argc, char **argv){
  ros::init(argc, argv, "change_output_string_clients");
  n.reset(new ros::NodeHandle);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
