#include "ofTestAppWebCamInput.h"


//--------------------------------------------------------------
void ofTestAppWebCamInput::setup(){
	camera.initCamera();
}

//--------------------------------------------------------------
void ofTestAppWebCamInput::update(){
	camera.updateFrame();
}

//--------------------------------------------------------------
void ofTestAppWebCamInput::draw(){
	camera.drawFrame(0,0);
	camera.drawFrame(640,0,320,240);
}

//--------------------------------------------------------------
void ofTestAppWebCamInput::keyPressed(int key){

}

//--------------------------------------------------------------
void ofTestAppWebCamInput::keyReleased(int key){

}

//--------------------------------------------------------------
void ofTestAppWebCamInput::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofTestAppWebCamInput::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofTestAppWebCamInput::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofTestAppWebCamInput::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofTestAppWebCamInput::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofTestAppWebCamInput::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofTestAppWebCamInput::dragEvent(ofDragInfo dragInfo){ 

}
