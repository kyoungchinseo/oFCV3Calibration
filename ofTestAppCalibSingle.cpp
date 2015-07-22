#include "ofTestAppCalibSingle.h"


//--------------------------------------------------------------
void ofTestAppCalibSingle::setup(){

	calibManager = new CalibSingleManager();
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
	calibManager->bFindGrid = true;
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
