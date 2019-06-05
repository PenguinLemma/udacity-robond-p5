#include "robot_dependent_marker_displayer.hpp"

namespace plemma
{

RobotDependentMarkerDisplayer::RobotDependentMarkerDisplayer(MarkerPose const & pickup, MarkerPose const & dropoff) :
    pickup_pose_{pickup},
    dropoff_pose_{dropoff},
    has_robot_reached_pickup_zone{false},
    has_robot_reached_dropoff_zone{false}
{
    TrackRobot();
}

void RobotDependentMarkerDisplayer::WaitUntilPickUpMarkerShouldBeRemoved() override
{
    while(!has_robot_reached_pickup_zone)
    {
        ros::Duration(0.5).sleep();
    }
}

void RobotDependentMarkerDisplayer::WaitUntilDropOffMarkerShouldBeShown() override
{
    while(!has_robot_reached_dropoff_zone)
    {
        ros::Duration(0.5).sleep();
    }
}

void RobotDependentMarkerDisplayer::TrackRobot()
{
    ros::NodeHandle nh;
    odometry_subscriber_ = nh.subscribe("/odom", 1,
                            &RobotDependentMarkerDisplayer::TrackingCallback,
                            this);
}

void RobotDependentMarkerDisplayer::TrackingCallback(nav_msgs::Odometry const & odom)
{
    if(has_robot_reached_pickup_zone)
    {
        if(has_robot_reached_dropoff_zone)
            return;
        if(IsRobotInPose(odom, dropoff_pose_))
        {
            has_robot_reached_dropoff_zone = true;
            return;
        }
    }
    has_robot_reached_pickup_zone = IsRobotInPose(odom, pickup_pose_);
}

constexpr bool RobotDependentMarkerDisplayer::IsRobotInPose(
    nav_msgs::Odometry const & odom,
    MarkerPose const & pose)
{
    double diff_x = pose.x - odom.pose.pose.position.x;
    double diff_y = pose.y - odom.pose.pose.position.y;
    double sq_distance_to_pickup{diff_x * diff_x  + diff_y * diff_y};
    return sq_distance_to_pickup < constants::sq_distance_threshold;
}

} // namespace plemma
