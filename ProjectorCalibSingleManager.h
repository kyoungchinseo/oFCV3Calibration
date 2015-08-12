#pragma once

#include "ofxOpenCv.h"
#include "WebCamInput.h"
#include "ProjectorCamCalib.h"

class ProjectorCalibSingleManager
{
public:
	ProjectorCalibSingleManager(int imageWidth, int imageHeight);
	~ProjectorCalibSingleManager(void);

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
	ProjectorCamCalib *calibSingle;

	ofxCvColorImage image;
	bool bFindGrid;
	bool bRecordCorners;

};

