#include "ros/ros.h"
#include "learning_communication/addTwoInts.h"

int main(int argc, char **argv)
{
    // Initialize the node
    ros::init(argc, argv, "add_two_ints_client");
    // get two Ints from terminal
    if(argc != 3)
    {
        ROS_INFO("usage: add_two_ints_client X Y");
        return 1;
    }
    ros::NodeHandle n;

    // Create a client
    ros::ServiceClient client = n.serviceClient<learning_communication::addTwoInts>("add_two_ints");
    // Create a service object
    learning_communication::addTwoInts srv;

    // Assign values to the request object
    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);

    // Call the service
    if (client.call(srv))
    {
        ROS_INFO("Sum: %ld", (long int)srv.response.sum);
    }
    else
    {
        ROS_ERROR("Failed to call service add_two_ints");
        return 1;
    }

    return 0;
}