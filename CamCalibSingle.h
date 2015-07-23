#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class CamCalibSingle
{
public:
	CamCalibSingle(int num_of_corners_horz, int num_of_corners_vert);
	~CamCalibSingle(void);

	void loadParameters(void);
	void findGridPattern(Mat* srcImage, Mat *destImage);
	void calibrateCamera(void);
public:
	int numOfCornersHorz;
	int numOfCornersVert;
	cv::Size boardSize;

	vector<Point2f> corners;

};

