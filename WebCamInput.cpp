#include "WebCamInput.h"


WebCamInput::WebCamInput(void)
{
}


WebCamInput::~WebCamInput(void)
{
}

void WebCamInput::initCamera(void)
{
	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(60);
	vidGrabber.initGrabber(640,480);
}
void WebCamInput::updateFrame(void)
{
	vidGrabber.update();



}


void WebCamInput::drawFrame(int x, int y, int w, int h)
{
	ofSetHexColor(0xffffff);
	vidGrabber.draw(x,y,w,h);
}

void WebCamInput::drawFrame(int x, int y)
{
	ofSetHexColor(0xffffff);
	vidGrabber.draw(x,y);
}

Mat WebCamInput::getCurrentFrame()
{
	return ocvImage;
}

ofxCvColorImage WebCamInput::getCurrentColorFrame()
{
	return ofxColorImage;
}

ofxCvGrayscaleImage WebCamInput::getCurrentGrayFrame()
{
	ofxCvGrayscaleImage image;


	return image;
}

int WebCamInput::getVideoHeight()
{
	return vidGrabber.height;
}

int WebCamInput::getVideoWidth() 
{
	return vidGrabber.width;
}