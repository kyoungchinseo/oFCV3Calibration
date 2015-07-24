#include "ofTestAppCalibSingle.h"


//--------------------------------------------------------------
void ofTestAppCalibSingle::setup(){

	calibManager = new CalibSingleManager(640,480);
	calibManager->init();

}

//--------------------------------------------------------------
void ofTestAppCalibSingle::update(){
	calibManager->update();

}

//--------------------------------------------------------------
void ofTestAppCalibSingle::draw(){
	calibManager->draw();
}

//--------------------------------------------------------------
void ofTestAppCalibSingle::keyPressed(int key){
	

}

//--------------------------------------------------------------
void ofTestAppCalibSingle::keyReleased(int key){
	switch(key) {
	case 's':
		calibManager->startFindCorners();
		break;
	case 'r': // record one set of corners
		calibManager->recordCurrentCorners();
		break;
	case 'c': // calibrate process
		calibManager->calibateCamera();
		break;
	case 'v': // save the result

		break;
	}
}

//--------------------------------------------------------------
void ofTestAppCalibSingle::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofTestAppCalibSingle::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofTestAppCalibSingle::mousePressed(int x, int y, int button){
	calibManager->bFindGrid = true;
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
