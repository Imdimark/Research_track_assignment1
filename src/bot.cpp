/*First assignment_Giovanni Di Marco_5014077 */

#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/Twist.h"
#include "assignment1/Rando.h"
#include <math.h>



float Targetx =0; 
float Targety = 0; 
float Position;
float distance=0;
float k = 5;
float x =0;
float y=0;
//definition of the publisher and the client
ros::Publisher chatter_pub; 
ros::ServiceClient clie;

/**
 * @retval This function returns a void

 * @param  pointer to the message 
**/

void robot_Callback (const nav_msgs::Odometry::ConstPtr& msgs ){//called every time somethings is published in the topic

	x = msgs->pose.pose.position.x;
	y = msgs->pose.pose.position.y;
	
	distance = sqrt(pow(Targetx-x,2)+pow(Targety-y,2) );
	
	geometry_msgs::Twist linear;
	ROS_INFO("ROBOT POSITION:: %f %f", x, y);
	if (distance<=0.1){
	ROS_INFO("target reached");
	assignment1::Rando goal;
	goal.request.min = -6; //fill half part of message with the min value
	goal.request.max = 6;	
	clie.call(goal); //
	Targetx=goal.response.x;
	Targety=goal.response.y;
	}
	linear.linear.x = k*(Targetx-x);
	linear.linear.y = k*(Targety-y);
	chatter_pub.publish(linear);
		

}


int main(int argc, char **argv)
{
	ros::init(argc, argv, "bot"); //initialization of the node bot
	ros::NodeHandle n1;
	
	
	clie= n1.serviceClient<assignment1::Rando>("rando"); 
	chatter_pub = n1.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
	ros::Subscriber pose_bot = n1.subscribe("/odom", 1000, robot_Callback);	
	ros::spin();

   return 0;
}
