#include "ofMain.h"
#include "ofApp.h"

#include "ofTestAppWebCamInput.h"
#include "ofTestAppCalibSingle.h"
#include "ofTestAppCalibProjector.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1280,960,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	//ofRunApp(new ofApp());
	
	// test for webcam class
	//ofRunApp(new ofTestAppWebCamInput());

	// test for single camera calibration
	//ofRunApp(new ofTestAppCalibSingle());

	//
	ofRunApp(new ofTestAppCalibProjector());

}
