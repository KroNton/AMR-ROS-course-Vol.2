#include "ros/ros.h"
#include "std_msgs/Int32.h"

ros::Publisher int_pub;
std_msgs::Int32 int_msg;

int main(int argc, char **argv)
{

  ros::init(argc, argv, "int_publisher_node");


  ros::NodeHandle n;

  
  

    int_pub= n.advertise<std_msgs::Int32>("int_count", 50);

  ros::Rate loop_rate(100);
       
    
  int count = 0;
  while (ros::ok())
  {

 
   

    int_msg.data=count;

     int_pub.publish(int_msg);

    





    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}