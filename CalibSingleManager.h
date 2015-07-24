#pragma once

#include "ofxOpenCv.h"
#include "WebCamInput.h"
#include "CamCalibSingle.h"

class CalibSingleManager
{
public:
	CalibSingleManager(int imageWidth, int imageHeight);
	~CalibSingleManager(void);

	// process (change the name)
	void init();
	void update();
	void draw();

	void startFindCorners(void);
	void findChessboardCorners(bool bRecord);
	void recordCurrentCorners(void);
	void calibateCamera(void);
	//void findGridPattern();
	//void processCalibration();
	//void showResult();

public:
	int width;
	int height;

	WebCamInput *camInput;
	CamCalibSingle *calibSingle;

	ofxCvColorImage image;
	bool bFindGrid;
	bool bRecordCorners;

};

