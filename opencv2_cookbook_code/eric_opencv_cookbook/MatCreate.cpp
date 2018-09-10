/*
 *  创建图片Mat的几种方式：  
 *    1. 使用create方法：
 *      result.create(image.size(), image.type());
 *    2. 使用构造函数 
 *      cv::Mat kernel(3,3,CV_32F,cv::Scalar(0));
 *        CV_8U
 *        CV_8U3C
 *        CV_32F
 *      Scalar(0) 是图像的像素初始值；
 *
 */


#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


void sharpen2D(const cv::Mat &image, cv::Mat &result) {

	// Construct kernel (all entries initialized to 0)
	cv::Mat kernel(3,3,CV_32F,cv::Scalar(0));
	// assigns kernel values
	kernel.at<float>(1,1)= 5.0;
	kernel.at<float>(0,1)= -1.0;
	kernel.at<float>(2,1)= -1.0;
	kernel.at<float>(1,0)= -1.0;
	kernel.at<float>(1,2)= -1.0;

	//filter the image
	cv::filter2D(image,result,image.depth(),kernel);
}

void sharpen(const cv::Mat &image, cv::Mat &result) {

	result.create(image.size(), image.type()); // allocate if necessary

	for (int j= 1; j<image.rows-1; j++) { // for all rows (except first and last)

		const uchar* previous= image.ptr<const uchar>(j-1); // previous row
		const uchar* current= image.ptr<const uchar>(j);	// current row
		const uchar* next= image.ptr<const uchar>(j+1);		// next row

		uchar* output= result.ptr<uchar>(j);	// output row

		for (int i=1; i<image.cols-1; i++) {

			*output++= cv::saturate_cast<uchar>(5*current[i]-current[i-1]-current[i+1]-previous[i]-next[i]); 
//			output[i]= cv::saturate_cast<uchar>(5*current[i]-current[i-1]-current[i+1]-previous[i]-next[i]); 
		}
	}

	// Set the unprocess pixels to 0
	result.row(0).setTo(cv::Scalar(0));
	result.row(result.rows-1).setTo(cv::Scalar(0));
	result.col(0).setTo(cv::Scalar(0));
	result.col(result.cols-1).setTo(cv::Scalar(0));
}
