#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "add_markers");

    plemma::MarkerDisplayer displayer;
    plemma::MarkerPose pickup{2.0, 1.0, 0.0}; // x, y, yaw_in_deg
    plemma::MarkerPose dropoff{0.0, 3.0, 45.0};
    displayer.Display(pickup, dropoff);

    return 0;
}
