#include "marker_displayer.hpp"

namespace plemma
{

void MarkerDisplayer::Display(MarkerPose const & pickup, MarkerPose const & dropoff)
{
    ros::NodeHandle nh;
    ros::Publisher marker_pub =
        nh.advertise<visualization_msgs::Marker>("visualization_marker", 1);

    // Wait until there is some subscriber
    while (marker_pub.getNumSubscribers() < 1)
    {
        if(!ros::ok())
        {
            return 0;
        }
        ROS_WARN_ONCE("Please create a subscriber to the marker");
        sleep(1);
    }

    // Create and fill in marker for pick-up zone
    visualization_msgs::Marker pickup_marker;
    FillInMarker(pickup, pickup_marker);

    pickup_marker.action = visualization_msgs::Marker::ADD;
    marker_pub.publish(pickup_marker);

    WaitUntilPickUpMarkerShouldBeRemoved();

    pickup_marker.action = visualization_msgs::Marker::DELETE;
    marker_pub.publish(pickup_marker);

    // Wait while the pretended pick-up process happens
    ros::Duration(5.0).sleep();

    WaitUntilDropOffMarkerShouldBeShown();
    // Create and fill in marker for drop-off zone
    visualization_msgs::Marker dropoff_marker;
    FillInMarker(dropoff, dropoff_marker);

    dropoff_marker.action = visualization_msgs::Marker::ADD;
    marker_pub.publish(dropoff_marker);
}

void MarkerDisplayer::FillInMarker(MarkerPose const & pose, visualization_msgs::Marker & marker)
{
    marker.ns = "pickup_marker";
    marker.id = 0;
    marker.type = visualization_msgs::Marker::CUBE;

    marker.target_pose.header.frame_id = "map";
    marker.target_pose.header.stamp    = ros::Time::now();

    marker.target_pose.pose.position.x = pose.x;
    marker.target_pose.pose.position.y = pose.y;
    marker.target_pose.pose.position.z = 0.0;

    double yaw_in_rad = 2.0 * pose.yaw_in_deg * constants::kPi / 180.0;

    marker.target_pose.pose.orientation.x = 0.0;
    marker.target_pose.pose.orientation.y = 0.0;
    marker.target_pose.pose.orientation.z = std::sin(0.5 * yaw_in_rad);
    marker.target_pose.pose.orientation.w = std::cos(0.5 * yaw_in_rad);

    marker.scale.x = 1.0;
    marker.scale.y = 1.0;
    marker.scale.z = 1.0;

    marker.color.r = constants::kMarkerRedComponent;
    marker.color.g = constants::kMarkerGreenComponent;
    marker.color.b = constants::kMarkerBlueComponent;
    marker.color.a = constants::kMarkerColorAlpha;

    marker.lifetime = ros::Duration();
}

void MarkerDisplayer::WaitUntilPickUpMarkerShouldBeRemoved()
{
    ros::Duration(5.0).sleep();
}

// In this case, there is no waiting to be done
void MarkerDisplayer::WaitUntilDropOffMarkerShouldBeShown()
{
}

} // namespace plemma
