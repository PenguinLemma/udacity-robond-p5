#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "add_markers");
    ros::NodeHandle nh;
    ros::Duration five(5.0);
    ros::Publisher marker_pub = nh.advertise<visualization_msgs::Marker>("visualization_marker", 1);

    // Set the shape we want to use for the marker
    uint8_t shape = visualization_msgs::Marker::CUBE;

    visualization_msgs::Marker marker;
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    marker.ns = "add_markers";
    marker.id = 0;
    marker.type = shape;
    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.position.x = 2.0;
    marker.pose.position.y = 1.0;
    marker.pose.position.z = 0.0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    marker.scale.x = 1.0;
    marker.scale.y = 1.0;
    marker.scale.z = 1.0;

    marker.color.r = 0.0;
    marker.color.g = 0.0;
    marker.color.b = 1.0;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    while (marker_pub.getNumSubscribers() < 1)
    {
        if(!ros::ok())
        {
            return 0;
        }
        ROS_WARN_ONCE("Please create a subscriber to the marker");
        sleep(1);
    }

    marker_pub.publish(marker);

    five.sleep();

    marker.action = visualization_msgs::Marker::DELETE;
    marker_pub.publish(marker);

    five.sleep();

    marker.id = 1;
    marker.pose.position.x = 0.0;
    marker.pose.position.y = 3.0;
    marker.pose.position.z = 0.0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    marker.action = visualization_msgs::Marker::ADD;
    marker_pub.publish(marker);
    return 0;
}
