#pragma once

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

#include "home_service_robot_common.hpp"

class MarkerDisplayer
{
public:
    MarkerDisplayer(SimplifiedPose const & pickup, SimplifiedPose const & dropoff);

    virtual ~MarkerDisplayer() = default;
    void Display();
    void FillInMarker(SimplifiedPose const & pose, visualization_msgs::Marker & marker);
private:
    virtual void WaitUntilPickUpMarkerShouldBeRemoved();
    virtual void WaitUntilDropOffMarkerShouldBeShown();

    ros::Publisher marker_publisher_;
    SimplifiedPose pickup_pose_;
    SimplifiedPose dropoff_pose_;
};

