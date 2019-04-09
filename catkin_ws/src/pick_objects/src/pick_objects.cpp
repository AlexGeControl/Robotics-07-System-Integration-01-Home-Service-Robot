#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <geometry_msgs/Pose.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

bool send_goal(MoveBaseClient &ac, const char *name, const geometry_msgs::Pose &pose) {
  // init goal message:
  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose = pose;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending %s goal", name);
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  bool isSucceeded = false;
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
    ROS_INFO("Hooray, the base reached %s zone!", name);
    isSucceeded = true;
  } else {
    ROS_INFO("The base failed to reache %s zone. Mission failed.", name);	
  }
  
  return isSucceeded;
}

int main(int argc, char** argv){
  // initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");

  // tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  
  // init pose container:
  geometry_msgs::Pose pose;
  
  // send pick up target:
  // a. position:
  pose.position.x = 0.0332638211612;
  pose.position.y = -6.43857849954;
  pose.position.z = 0.0;
  // b. orientation:
  pose.orientation.x = 0.0;
  pose.orientation.y = 0.0;
  pose.orientation.z = -0.614050122525;
  pose.orientation.w = 0.789267031509;  
  // c. send out:
  if (!send_goal(ac, "Pick Up", pose)) {
    return 0;
  }
  
  ros::Duration(5.0).sleep();
  
  // send drop off target:
  // a. position:
  pose.position.x = 5.87073985563;
  pose.position.y = -0.125673435014;
  pose.position.z = 0.0;
  // b. orientation:
  pose.orientation.x = 0.0;
  pose.orientation.y = 0.0;
  pose.orientation.z = 0.596425667204;
  pose.orientation.w = 0.802668314748;  
  // c. send out:
  send_goal(ac, "Drop Off", pose);
  
  return 0;
}