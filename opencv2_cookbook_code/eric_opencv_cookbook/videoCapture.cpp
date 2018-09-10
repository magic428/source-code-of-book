/*
 * 读取视频流操作
 *   1. 获取图片的每一帧：capture >> frame;
 *    或： capture.read(frame)
 *   2. 释放videoCapture：capture.release();。
 *   3. 获取视频的帧数：capture.get(CV_CAP_PROP_FPS)
 */

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture capture("Video.avi");
	string name = "jpg/000";
	static int i = 0;
	stringstream ss;
	
	
	Mat frame;
	capture >> frame;

	// Get the frame rate
	double rate = capture.get(CV_CAP_PROP_FPS);
	vector<int> compression_params;
	compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
	compression_params.push_back(100);

	//while (frame.data)
	while (capture.read(frame))
	{
		//capture >> frame;
		i++;

		name = "";
		name = "jpg/000";
		ss << i;
		name = name + ss.str();
		ss.str("");
		name += ".jpg";

		capture >> frame;

		if (i%20 == 0)
			imwrite(name, frame, compression_params);
		cv::imshow("Extracted Frame", frame);
		

		char c = cvWaitKey(33);
	
	}

	// Close the video file
	capture.release();
	
	waitKey();

	return 0;
}