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
	CamCalibSingle(int imgWidth, int imgHeight, int num_of_corners_horz, int num_of_corners_vert, float square_size);
	~CamCalibSingle(void);

	void loadParameters(void);
	bool findGridPattern(Mat* srcImage, Mat *destImage, bool record);
	void generateObjectPoints(void);
	void calibrateCamera(void);
	void showResultMatrix(void);
public:
	int numOfCornersHorz;
	int numOfCornersVert;
	float squareSize;
	cv::Size boardSize;
	cv::Size imageSize;

	vector<Point2f> corners;
	vector<vector<Point2f>> imagePoints;


	vector<vector<Point3f>> objectPoints;

	Mat intrinsicMatrix;
	Mat distortionMatrix;
	vector<Mat> rvecs;
	vector<Mat> tvecs;
	vector<float> repojectionError;
	double totalError;
};

