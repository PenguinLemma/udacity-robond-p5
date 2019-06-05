#pragma once

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

namespace plemma
{

namespace constants
{
constexpr double kPi = 3.14159265358979323846;
constexpr double kMarkerRedComponent = 0.0;
constexpr double kMarkerGreenComponent = 0.0;
constexpr double kMarkerBlueComponent = 1.0;
constexpr double kMarkerColorAlpha = 1.0;
} // namespace constants

struct MarkerPose
{
    double x;
    double y;
    double yaw_in_deg;
};

class MarkerDisplayer
{
public:
    virtual MarkerDisplayer(){}
    virtual ~MarkerDisplayer(){}
    void Display(MarkerPose const & pickup, MarkerPose const & dropoff);
    void FillInMarker(MarkerPose const & pose, visualization_msgs::Marker & marker);
private:
    virtual void WaitUntilPickUpMarkerShouldBeRemoved();
    virtual void WaitUntilDropOffMarkerShouldBeShown();
};

// namespace plemma
