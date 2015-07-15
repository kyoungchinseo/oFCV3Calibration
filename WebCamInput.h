#pragma once

#include "ofxOpenCv.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class WebCamInput
{
public:
	WebCamInput(void);
	~WebCamInput(void);
	void initCamera(void);
	void updateFrame(void);
	void drawFrame(int x, int y, int w, int h);
	void drawFrame(int x, int y);
	Mat getCurrentFrame();
	ofxCvColorImage getCurrentColorFrame();
	ofxCvGrayscaleImage getCurrentGrayFrame();
	int getVideoHeight();
	int getVideoWidth();
private:
	ofVideoGrabber 		vidGrabber;
	Mat					ocvImage;
	ofxCvColorImage		ofxColorImage;
};

