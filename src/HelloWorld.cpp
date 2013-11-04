#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <CL/cl.h>
#include <opencv2/opencv.hpp>
#include "FreeImage.h"

#include <memory>
#include <vector>
#include <functional>
#include <iostream>
#include <sstream>
#include <time.h>
#include <stdio.h>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv/highgui.h>

#ifndef _CRT_SECURE_NO_WARNINGS
# define _CRT_SECURE_NO_WARNINGS
#endif

using namespace cv;


int main(int argc, char* argv[])
{
	cvWaitKey(0);
	int i;
	std::cin.get();
	Mat image = imread("xx1.jpg", CV_LOAD_IMAGE_COLOR);
	Size patternSize(9, 6);
	vector<Point2f> imagePoints;



	auto x = findChessboardCorners(image, patternSize, imagePoints);
	for (auto& p : imagePoints)
		circle(image, p, 4, Scalar(0, 200, 300), -1);

	vector<Point2f> patternPoints;
	Mat pattern = imread("pattern.png", CV_LOAD_IMAGE_COLOR);
	findChessboardCorners(pattern, patternSize, patternPoints);
	for (auto& item : patternPoints)
		circle(pattern, item, 4, Scalar(0, 200, 300), -1);


	Mat cameraMatrix = Mat::eye(3, 3, CV_64F);
	Mat distCoeffs = Mat::zeros(8, 1, CV_64F);
	imshow("W", image);
	
	vector<Mat> rvecs, tvecs;
	calibrateCamera(patternPoints, imagePoints, image.size(), cameraMatrix, distCoeffs, rvecs, tvecs, CALIB_FIX_K4 | CALIB_FIX_K5);

}



