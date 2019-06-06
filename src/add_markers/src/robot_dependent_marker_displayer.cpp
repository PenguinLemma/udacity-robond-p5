#include "robot_dependent_marker_displayer.hpp"


RobotDependentMarkerDisplayer::RobotDependentMarkerDisplayer(SimplifiedPose const & pickup, SimplifiedPose const & dropoff) :
    MarkerDisplayer(pickup, dropoff),
    has_robot_reached_pickup_zone_{false},
    has_robot_reached_dropoff_zone_{false}
{
    TrackRobot();
}

void RobotDependentMarkerDisplayer::WaitUntilPickUpMarkerShouldBeRemoved()
{
    while(!has_robot_reached_pickup_zone_)
    {
        ros::Duration(0.5).sleep();
    }
}

void RobotDependentMarkerDisplayer::WaitUntilDropOffMarkerShouldBeShown()
{
    while(!has_robot_reached_dropoff_zone_)
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
    if(has_robot_reached_pickup_zone_)
    {
        if(has_robot_reached_dropoff_zone_)
            return;
        if(IsRobotInPose(odom, dropoff_pose_))
        {
            has_robot_reached_dropoff_zone_ = true;
            return;
        }
    }
    has_robot_reached_pickup_zone_ = IsRobotInPose(odom, pickup_pose_);
}

bool RobotDependentMarkerDisplayer::IsRobotInPose(
    nav_msgs::Odometry const & odom,
    SimplifiedPose const & pose)
{
    double diff_x = pose.x - odom.pose.pose.position.x;
    double diff_y = pose.y - odom.pose.pose.position.y;
    double sq_distance_to_pickup{diff_x * diff_x  + diff_y * diff_y};
    return sq_distance_to_pickup < constants::kSquaredDistanceThreshold;
}

