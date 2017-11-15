/**
 *  @file   talker.cpp
 *  @brief  a publisher to publish a given string. a service to       change the output string.
 *  @details
 *  @author     Jiawei Ge(SonamYeshe)
 *  @copyright  BSD, GNU Public License 2017 Jiawei Ge
 *  @disclaimer Jiawei Ge(SonamYeshe), hereby disclaims all copyright interest in the program `beginner_tutorials' (which makes passes at compilers) written by Jiawei Ge(SonamYeshe).
 <signature of Jiawei Ge>, 14 November 2017
 Jiawei Ge
 */

#include <tf/transform_broadcaster.h>
#include <sstream>
#include <string>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/ChangeOutputString.h"

/**
 *  define a global variable to store the output string.
 *  define integer to control publish frequency.
 *  define the output of the added service.
 */
std_msgs::String output_string;
int pub_frequency = 10;

bool change(beginner_tutorials::ChangeOutputString::Request &req,
            beginner_tutorials::ChangeOutputString::Response &res) {
  output_string.data = "change to string: " + req.new_string;
  res.output_string = output_string.data;
  return true;
}

/**
 *  @brief  continue to publish a string with a fied rate.  
 *  @param  integer of argument count
 *  @param  char pointer of argument value
 *  @return a bool value
 */

int main(int argc, char **argv) {
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "talker");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;
  ros::NodeHandle home("~");
  home.getParam("pub_frequency", pub_frequency);

  /**
   *  create a TransformBroadcaster object that we'll use later to send 
   *  the transformations over the wire.   create a transfprm object to 
   *  store the 3D transformation info.
   */
  tf::TransformBroadcaster br;
  tf::Transform transform;
  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */
  ros::ServiceServer service = n.advertiseService("change_output_string",
                                                  change);
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Rate loop_rate(pub_frequency);
  beginner_tutorials::ChangeOutputString::Response res2;
  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  int count = 0;
  output_string.data = "God gives you shoes, fits you.";
  while (ros::ok() && n.ok()) {
    /**
     * broadcast a fixed /talk frame with parent /world.
     */
    transform.setOrigin(tf::Vector3(0.0, 2.0, 0.0));
    transform.setRotation(tf::Quaternion(0, 0, 0, 1));
    br.sendTransform(
        tf::StampedTransform(transform, ros::Time::now(), "world", "talk"));
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    std_msgs::String msg;
    std::stringstream ss;
    ss << output_string.data << count;
    msg.data = ss.str();
    /*
     * %s stands for msg.data.c_str(), output is inside the double quotation mark
     */
    ROS_INFO("%s", msg.data.c_str());
    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }
  return 0;
}
