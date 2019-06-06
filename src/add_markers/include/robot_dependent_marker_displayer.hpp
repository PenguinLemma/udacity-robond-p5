#pragma once

#include <nav_msgs/Odometry.h>

#include "marker_displayer.hpp"

class RobotDependentMarkerDisplayer : public MarkerDisplayer
{
public:
    RobotDependentMarkerDisplayer(SimplifiedPose const & pickup,
                                  SimplifiedPose const & dropoff);
    virtual ~RobotDependentMarkerDisplayer() override = default;

private:
    virtual void WaitUntilPickUpMarkerShouldBeRemoved() override;
    virtual void WaitUntilDropOffMarkerShouldBeShown() override;
    void TrackRobot();
    void TrackingCallback(nav_msgs::Odometry const & odom);
    bool IsRobotInPose(nav_msgs::Odometry const & odom,
                       SimplifiedPose const & pose);

    ros::Publisher marker_publisher_;
    ros::Subscriber odometry_subscriber_;
    SimplifiedPose pickup_pose_;
    SimplifiedPose dropoff_pose_;
    bool has_robot_reached_pickup_zone_;
    bool has_robot_reached_dropoff_zone_;
};

