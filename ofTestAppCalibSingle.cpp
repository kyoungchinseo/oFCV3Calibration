#include "ofTestAppCalibSingle.h"


//--------------------------------------------------------------
void ofTestAppCalibSingle::setup(){
	camera.initCamera(640,480);

	ofxImageConverted.allocate(640,480);

}

//--------------------------------------------------------------
void ofTestAppCalibSingle::update(){
	camera.updateFrame();
}

//--------------------------------------------------------------
void ofTestAppCalibSingle::draw(){
	//camera.drawFrame(0,0);
	camera.drawFrame(0,0,320,240);

	ofxImage = camera.getCurrentColorFrame();
	ofxImage.draw(320,0,320,240);

	image = camera.getCurrentFrame();
	//cout << image.rows << " " << image.cols << endl;

	ofxImageConverted.setFromPixels(image.data,image.cols, image.rows);
	ofxImageConverted.draw(0,240,320,240);
}

//--------------------------------------------------------------
void ofTestAppCalibSingle::keyPressed(int key){

}

//--------------------------------------------------------------
void ofTestAppCalibSingle::keyReleased(int key){

}

//--------------------------------------------------------------
void ofTestAppCalibSingle::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofTestAppCalibSingle::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofTestAppCalibSingle::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofTestAppCalibSingle::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofTestAppCalibSingle::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofTestAppCalibSingle::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofTestAppCalibSingle::dragEvent(ofDragInfo dragInfo){ 

}
