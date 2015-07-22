#include "CalibSingleManager.h"


CalibSingleManager::CalibSingleManager(void)
{
}


CalibSingleManager::~CalibSingleManager(void)
{
}

void CalibSingleManager::init()
{
	// camera
	camInput = new WebCamInput();

	// calibration algorithm
	calibSingle = new CamCalibSingle();

	// parameters initialize

	camInput->initCamera(640,480);

	
	bFindGrid = false;
}

void CalibSingleManager::update()
{
	camInput->updateFrame();

	if (bFindGrid) {
		findChessboardCorners();
	}
}

void CalibSingleManager::draw()
{
	camInput->drawFrame(0,0,320,240);
	if (bFindGrid) {
		
	}

}

void CalibSingleManager::findChessboardCorners(void)
{
	Mat *destImage = new Mat();
	calibSingle->findGridPattern(camInput->getCurrentFrame()	, destImage);

	cout << "try to find: " << endl;
	//camInput->getCurrentFrame();
	ofxCvColorImage image;
	image.setFromPixels(destImage->data,destImage->cols, destImage->rows);
	image.draw(0,240,320,240);

	bFindGrid = false;
}
