#include "ros/ros.h"
#include "std_msgs/Int32.h"


int input_num;


ros::Subscriber int_sub;

void int_Callback(const std_msgs::Int32::ConstPtr& msg)
{
  msg->data;
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "int_subscriber node");

  ros::NodeHandle n;

 int_sub = n.subscribe("int_chatter", 1000, int_Callback);

   
  ros::spin();


  return 0;
}