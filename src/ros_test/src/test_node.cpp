#include "iostream"
#include "ros/ros.h"
#include "ros/service.h"
#include "ros/subscriber.h"
#include <actionlib/server/simple_action_server.h>

#include "std_msgs/Int8.h"
#include "std_srvs/SetBool.h"

class TestNode {
 public:
  TestNode(ros::NodeHandle& nh);
  ~TestNode();

 private:
  void handleTopic(const std_msgs::Int8ConstPtr& msg);
  bool TestService(std_srvs::SetBool::Request& request,
                   std_srvs::SetBool::Response& response);

  ros::NodeHandle& nh_;
  ros::Subscriber test_sub_;
  ros::ServiceServer test_srv_;
};

TestNode::TestNode(ros::NodeHandle& nh) : nh_(nh) {
  test_sub_ = nh_.subscribe("test/sub1", 3, &TestNode::handleTopic, this);
  test_srv_ =
      nh_.advertiseService("test/service1", &TestNode::TestService, this);
}
TestNode::~TestNode() {}

void TestNode::handleTopic(const std_msgs::Int8ConstPtr& msg) {
  ROS_WARN("topic recieved. id:%d", msg->data);
}
bool TestNode::TestService(std_srvs::SetBool::Request& request,
                           std_srvs::SetBool::Response& response) {
  ROS_WARN("service recieved. switch:%d", request.data);

  if (request.data) {
    ROS_INFO("TRUE");
  } else {
    ROS_INFO("FALSE");
  }
  return true;
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "test_node");
  ros::start();

  ros::NodeHandle nh;

  TestNode tn(nh);

  ROS_INFO("Test Node start.");

  //ros::MultiThreadedSpinner spinner(2);
  //spinner.spin();
  ros::spin();
  return 0;
}
