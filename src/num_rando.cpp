/*First assignment_Giovanni Di Marco_5014077 */

#include "ros/ros.h"
#include "assignment1/Rando.h"
#include <math.h>

double randMToN(double M, double N){
	
     return M + (rand() / ( RAND_MAX / (N-M) ) ) ; 
	}
/**
 * @retval This function returns a boolean variable

 * @param  res exploited for receiving valòues about x and y coordinate
 * @param  req exploited for issuing the the minimum and the macimum avilable from the server	
**/
bool rando_rando (assignment1::Rando::Request &req, assignment1::Rando::Response &res){
	res.x= randMToN(req.min, req.max);
	res.y= randMToN(req.min, req.max);
	ROS_INFO("Random Target [%f, %f]", res.x, res.y);
	return true;
	}



int main(int argc, char **argv)
{
   ros::init(argc, argv, "num_rando"); //initialization of the node num_rando
   ros::NodeHandle n1;
   ros::ServiceServer service= n1.advertiseService("/rando", rando_rando); //definition of the service for the server
   ros::spin();

   return 0;
}
