#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>


int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");


  ros::NodeHandle n;

  
  ros::Publisher string_pub;

   string_pub= n.advertise<std_msgs::String>("chatter", 50);

  ros::Rate loop_rate(100);

    
  int count = 0;
  while (ros::ok())
  {

    std_msgs::String msg;

    std::stringstream ss;
 
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());


  string_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}