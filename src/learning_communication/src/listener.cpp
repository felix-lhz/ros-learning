#include "ros/ros.h"
#include "std_msgs/String.h"

// This function will be called every time a new message arrives on the chatter topic
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    // Print the message to the console
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
    // Initialize the node
    ros::init(argc, argv, "listener");
    // Create a node handle
    ros::NodeHandle n;
    // Create a subscriber object, which will listen for messages of type std_msgs::String on the topic "chatter"
    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
    // Spin, waiting for messages to arrive
    ros::spin();

    return 0;
}