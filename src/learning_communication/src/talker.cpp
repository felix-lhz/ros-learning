#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    // Initialize the node
    ros::init(argc, argv, "talker");
    // Create a node handle
    ros::NodeHandle n;
    // Create a publisher object, which will publish messages of type std_msgs::String on the topic "chatter"
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    // Set the loop rate to 10 Hz
    ros::Rate loop_rate(10);
    // Initialize the counter
    int count = 0;

    while (ros::ok())
    {
        // Create a message object
        std_msgs::String msg;
        // Create a string with the message
        std::stringstream ss;
        ss << "hello world " << count;
        // Set the message data
        msg.data = ss.str();
        // Publish the message
        ROS_INFO("%s", msg.data.c_str());
        chatter_pub.publish(msg);
        // Spin once
        ros::spinOnce();
        // Sleep for the time remaining to let us hit our 10 Hz publish rate
        loop_rate.sleep();
        // Increment the counter
        ++count;
    }

    return 0;
}