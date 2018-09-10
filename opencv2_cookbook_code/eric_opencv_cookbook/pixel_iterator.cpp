/*
 * 遍历像素操作
 *  一般有两种方法： 
 *  1. 使用迭代器
 *    多通道图像：
 *       image.at<cv::Vec3b>(j,i)[0]
 *       image.at<cv::Vec3b>(j,i)[1]
 *       image.at<cv::Vec3b>(j,i)[2]
 *    单通道图像：
 *       image.at<cv::uchar>(j,i)[0]
 *  2. 使用行指针访问：
 *     image.ptr<uchar>(j)
 *     
 *	   int nc= image.cols * image.channels(); // total number of elements per line
 *     int nl= image.rows; // number of lines
 *    单通道图像：
 *     image.channels() = 1
 *    多通道图像：
 *     image.channels() = 3
 *
 */

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

void saltIter(cv::Mat &image, int div=64) {

	int nl= image.rows; // number of lines
	int nc= image.cols; // number of columns
	      
	for (int j=0; j<nl; j++) {
		for (int i=0; i<nc; i++) {

			// process each pixel ---------------------

			image.at<cv::Vec3b>(j,i)[0]= 255; 
			image.at<cv::Vec3b>(j,i)[1]= 255; 
			image.at<cv::Vec3b>(j,i)[2]= 255; 

			// end of pixel processing ----------------

		} // end of line                   
	}
}

void saltPtr(cv::Mat &image, int div=64) {

	  int nl= image.rows; // number of lines
	  int nc= image.cols * image.channels(); // total number of elements per line
              
      for (int j=0; j<nl; j++) {

		  uchar* data= image.ptr<uchar>(j);

          for (int i=0; i<nc; i++) {
 
            	// process each pixel ---------------------
                 
				data[i]= 255;
 
            	// end of pixel processing ----------------
 
            } // end of line                   
      }
}
