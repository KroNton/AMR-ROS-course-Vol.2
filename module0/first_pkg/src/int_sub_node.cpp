#include "ros/ros.h"
#include "std_msgs/Int32.h"


void int_Callback(const std_msgs::Int32::ConstPtr& int_msg)
{
  int count=int_msg->data;
  
  std::cout<<"intger_data: "<<count<<std::endl;
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "integer_subscriber");

  ros::NodeHandle n;


  ros::Subscriber int_sub = n.subscribe("int_count", 1000, int_Callback);

  ros::spin();

  return 0;
}