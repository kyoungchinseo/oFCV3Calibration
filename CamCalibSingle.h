#pragma once

#include "ofxOpenCv.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class CamCalibSingle
{
public:
	CamCalibSingle(void);
	~CamCalibSingle(void);

	void loadParameters(void);
	void findGridPattern(Mat* srcImage, Mat *destImage);
	void calibrateCamera(void);
public:
	
};

