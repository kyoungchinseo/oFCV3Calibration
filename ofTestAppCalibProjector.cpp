#include "ofTestAppCalibProjector.h"


//--------------------------------------------------------------
void ofTestAppCalibProjector::setup(){

	calibManager = new CalibSingleManager(640,480);
	calibManager->init();

}

//--------------------------------------------------------------
void ofTestAppCalibProjector::update(){
	calibManager->update();

}

//--------------------------------------------------------------
void ofTestAppCalibProjector::draw(){
	calibManager->draw();
}

//--------------------------------------------------------------
void ofTestAppCalibProjector::keyPressed(int key){
	

}

//--------------------------------------------------------------
void ofTestAppCalibProjector::keyReleased(int key){
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
void ofTestAppCalibProjector::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofTestAppCalibProjector::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofTestAppCalibProjector::mousePressed(int x, int y, int button){
	calibManager->bFindGrid = true;
}

//--------------------------------------------------------------
void ofTestAppCalibProjector::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofTestAppCalibProjector::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofTestAppCalibProjector::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofTestAppCalibProjector::dragEvent(ofDragInfo dragInfo){ 

}
