#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"

ros::Publisher divider_pub;
ros::Subscriber int_sub;

std_msgs::Float32 divided_msg;

int input_data=0;

void int_Callback(const std_msgs::Int32::ConstPtr& int_msg)
{
  input_data=int_msg->data;
  
}



int main(int argc, char **argv)
{

  ros::init(argc, argv, "divider_node");


  ros::NodeHandle n;

  
  
    int_sub = n.subscribe("int_count", 1000, int_Callback);

    divider_pub= n.advertise<std_msgs::Float32>("dived_value", 50);

  ros::Rate loop_rate(100);
       
    

  while (ros::ok())
  {

 
   
    float output_data=float(input_data)/2;

    divided_msg.data=output_data;

     divider_pub.publish(divided_msg);

    





    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}