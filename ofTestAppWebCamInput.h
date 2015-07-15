#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include "WebCamInput.h"


using namespace cv;
using namespace std;


class ofTestAppWebCamInput : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		Mat					image;
		ofxCvColorImage		ofxImage;
		ofxCvColorImage     ofxImageConverted;
		ofVideoGrabber 		vidGrabber;

		WebCamInput			camera;

		
};

