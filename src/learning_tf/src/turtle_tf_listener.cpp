#include "ros/ros.h"
#include "tf/transform_listener.h"
#include "geometry_msgs/Twist.h"
#include <turtlesim/Spawn.h>

int main(int argc, char** argv){
    // Initialize ROS
    ros::init(argc, argv, "my_tf_listener");
    ros::NodeHandle node;
    // 通过服务调用，产生第二只乌龟turtle2
    ros::service::waitForService("spawn");
    ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("spawn");
    turtlesim::Spawn srv;
    add_turtle.call(srv);

    tf::TransformListener listener;
    // 定义turtle2的速度控制发布器
    ros::Publisher turtle_vel =
        node.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 10);

    ros::Rate rate(10.0);
    while (node.ok()){
        tf::StampedTransform transform;
        try{
            //查找turtle2与turtle1的坐标变换
            listener.waitForTransform("/turtle2", "/turtle1",
                                    ros::Time(0), ros::Duration(10.0));
            listener.lookupTransform("/turtle2", "/turtle1",
                                    ros::Time(0), transform);
        }
        catch (tf::TransformException &ex) {
            ROS_ERROR("%s",ex.what());
            ros::Duration(1.0).sleep();
            continue;
        }
        //根据turtle1和turtle2之间的坐标变换，发布turtle2的速度控制指令
        geometry_msgs::Twist vel_msg;
        vel_msg.angular.z = 4.0 * atan2(transform.getOrigin().y(),
                                        transform.getOrigin().x());
        vel_msg.linear.x = 0.5 * sqrt(pow(transform.getOrigin().x(), 2) +
                                    pow(transform.getOrigin().y(), 2));
        turtle_vel.publish(vel_msg);

        rate.sleep();
    }
    return 0;
}