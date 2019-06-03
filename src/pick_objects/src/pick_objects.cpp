#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv)
{
    // Initialize a ROS node
    ros::init(argc, argv, "pick_objects");

    // Create action client to communicate with action "move_base" and instruct
    // it to start a thread to call ros::spin() (instead of us having to call it
    // manually)
    MoveBaseClient action_client("move_base", true);

    // Wait for the action server to come up
    while(!action_client.waitForServer(ros::Duration(5.0)))
    {
        ROS_INFO("Waiting for the move_base action server to come up");
    }

    move_base_msgs::MoveBaseGoal pickup_goal;

    pickup_goal.target_pose.header.frame_id = "map";
    pickup_goal.target_pose.header.stamp = ros::Time::now();
    pickup_goal.target_pose.pose.position.x = 4.0;
    pickup_goal.target_pose.pose.position.y = 6.0;
    pickup_goal.target_pose.pose.orientation.w = 1.0;

    ROS_INFO("Sending pick-up position as first goal");
    action_client.sendGoal(pickup_goal);

    action_client.waitForResult();

    if(action_client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    {
        ROS_INFO("The robot reached the pick-up point");
    }
    else
    {
        ROS_INFO("The robot failed to reach the pick-up point. All goals cancelled");
        action_client.cancelAllGoals();
    }

    ros::Duration(5.0).sleep();
    ROS_INFO("Virtual object picked up");

    move_base_msgs::MoveBaseGoal dropoff_goal;

    dropoff_goal.target_pose.header.frame_id = "map";
    dropoff_goal.target_pose.header.stamp = ros::Time::now();
    dropoff_goal.target_pose.pose.position.x = 4.0;
    dropoff_goal.target_pose.pose.position.y = 6.0;
    dropoff_goal.target_pose.pose.orientation.w = 1.0;

    ROS_INFO("Sending drop-off position as second goal");
    action_client.sendGoal(dropoff_goal);

    action_client.waitForResult();

    if(action_client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    {
        ROS_INFO("The robot reached the drop-off point");
    }
    else
    {
        ROS_INFO("The robot failed to reach the drop-off point");
    }
    return 0;
}
