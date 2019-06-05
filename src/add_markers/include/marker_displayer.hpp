#pragma once

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

#include "home_service_robot_common.hpp"

namespace plemma::hsr
{

class MarkerDisplayer
{
public:
    MarkerDisplayer(SimplifiedPose const & pickup, SimplifiedPose const & dropoff);

    virtual ~MarkerDisplayer(){}
    void Display();
    void FillInMarker(SimplifiedPose const & pose, visualization_msgs::Marker & marker);
private:
    virtual void WaitUntilPickUpMarkerShouldBeRemoved();
    virtual void WaitUntilDropOffMarkerShouldBeShown();

    ros::Publisher marker_publisher_;
    SimplifiedPose pickup_pose_;
    SimplifiedPose dropoff_pose_;
};

} // namespace plemma::hsr
