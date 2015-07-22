#include "WebCamInput.h"


WebCamInput::WebCamInput(void)
{
}

WebCamInput::~WebCamInput(void)
{
}

void WebCamInput::initCamera(int camera_width, int camera_height)
{
	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(60);
	vidGrabber.initGrabber(camera_width,camera_height);

	width = vidGrabber.width;
	height= vidGrabber.height;

	//ocvImage.create(height,width,CV_8UC3);
	ocvImage = new Mat(height,width,CV_8UC3);

	ofxColorImage.allocate(width, height);
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

Mat* WebCamInput::getCurrentFrame()
{
	if (vidGrabber.isFrameNew()){
		ocvImage->data = vidGrabber.getPixels();
	}
	return ocvImage;
}

ofxCvColorImage WebCamInput::getCurrentColorFrame()
{
	ofxColorImage.setFromPixels(vidGrabber.getPixels(), width, height);
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