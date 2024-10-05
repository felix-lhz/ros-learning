#include "ros/ros.h"
#include "learning_communication/addTwoInts.h"

// Callback function
bool add(learning_communication::addTwoInts::Request &req,
         learning_communication::addTwoInts::Response &res)
{
    res.sum = req.a + req.b;
    ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
    ROS_INFO("sending back response: [%ld]", (long int)res.sum);
    return true;
}

int main(int argc, char **argv)
{
    // Initialize the node
    ros::init(argc, argv, "add_two_ints_server");
    ros::NodeHandle n;

    // Create a service server
    ros::ServiceServer service = n.advertiseService("add_two_ints", add);
    ROS_INFO("Ready to add two ints.");
    ros::spin();

    return 0;
}