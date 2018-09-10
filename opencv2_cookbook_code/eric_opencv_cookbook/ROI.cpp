/*------------------------------------------------------------------------------------------*\
 *
 *  图像3通道---单通道合成/分割
 *    // create vector of 3 images
	std::vector<cv::Mat> planes;
	// split 1 3-channel image into 3 1-channel images
	cv::split(image1,planes);
	cv::merge(planes,result);
 *  
 *
 *
 *
 *
 *
 *
\*------------------------------------------------------------------------------------------*/


#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


int main()
{
	cv::Mat image1;
	
	image1= cv::imread("boldt.jpg");
	// define image ROI
	cv::Mat imageROI;
	imageROI= image(cv::Rect(385,270,logo.cols,logo.rows));

	// add logo to image 
	cv::addWeighted(imageROI,1.0,logo,0.3,0.,imageROI);

	// split 3-channel image into 3 1-channel images
	std::vector<cv::Mat> channels;
	cv::split(image1,channels);

	imageROI= channels.at(1);

	cv::addWeighted(imageROI(cv::Rect(385,270,logo.cols,logo.rows)),1.0,
			        logo,0.5,0.,imageROI(cv::Rect(385,270,logo.cols,logo.rows)));

	cv::merge(channels,image1);

	cv::namedWindow("with logo");
	cv::imshow("with logo",image1);

	cv::waitKey();

	return 0;
}


deb http://mirrors.163.com/ubuntu/ trusty main restricted universe multiverse
deb http://mirrors.163.com/ubuntu/ trusty-security main restricted universe multiverse
deb http://mirrors.163.com/ubuntu/ trusty-updates main restricted universe multiverse
deb http://mirrors.163.com/ubuntu/ trusty-proposed main restricted universe multiverse
deb http://mirrors.163.com/ubuntu/ trusty-backports main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ trusty main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ trusty-security main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ trusty-updates main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ trusty-proposed main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ trusty-backports main restricted universe multiverse