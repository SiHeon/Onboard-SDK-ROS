/** @file main.cpp
 *  @version 3.3
 *  @date May, 2017
 *
 *  @brief
 *  DJISDKNode
 *
 *  @copyright 2017 DJI. All rights reserved.
 *
 */

#include <dji_sdk/dji_sdk_node.h>
#include <geometry_msgs/PointStamped.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "dji_sdk");
  ros::NodeHandle nh;
  ros::NodeHandle nh_private("~");
  DJISDKNode* dji_sdk_node = new DJISDKNode(nh, nh_private);

  tf::TransformBroadcaster broadcaster;

  broadcaster.sendTransform(
  tf::StampedTransform(
  tf::Transform(tf::Quaternion(0, 0, 0, 1),
                tf::Vector3(0, 0, 0)),
  ros::Time::now(),"odometry", "velo"));


  ros::AsyncSpinner spinner(5); // Use 4 threads
  spinner.start();
  ros::waitForShutdown();

  delete dji_sdk_node;
  dji_sdk_node = NULL;
  return 0;
}
