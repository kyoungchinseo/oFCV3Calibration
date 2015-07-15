#include "ofTestAppWebCamInput.h"


//--------------------------------------------------------------
void ofTestAppWebCamInput::setup(){
	camera.initCamera(640,480);

	ofxImageConverted.allocate(640,480);

}

//--------------------------------------------------------------
void ofTestAppWebCamInput::update(){
	camera.updateFrame();
}

//--------------------------------------------------------------
void ofTestAppWebCamInput::draw(){
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
