#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;

static const std::string OPENCV_WINDOW1 = "rgb_image";
static const std::string OPENCV_WINDOW2 = "intensity_image";
static const std::string OPENCV_WINDOW3 = "noise_image";
static const std::string OPENCV_WINDOW4 = "range_image";


void rgb_image(const sensor_msgs::ImageConstPtr& msg) {
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
//      if (sensor_msgs::image_encodings::isColor(msg->encoding))
//        cv_ptr = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::BGR8);
//      else
//        cv_ptr = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::MONO8);

      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::MONO8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }

    // Draw an example circle on the video stream
    //if (cv_ptr->image.rows > 60 && cv_ptr->image.cols > 60)
    //  cv::circle(cv_ptr->image, cv::Point(50, 50), 10, CV_RGB(255,0,0));

    cout << "received new image" << endl;
    // Update GUI Window
    cv::imshow(OPENCV_WINDOW2, cv_ptr->image);
    cv::waitKey(50);
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "intensity_image");
  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Subscriber sub = it.subscribe("img_node/intensity_image", 1, rgb_image);
  ros::spin();
}
