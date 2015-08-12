#include "CalibSingleManager.h"


CalibSingleManager::CalibSingleManager(int imageWidth, int imageHeight)
{
	width = imageWidth;
	height= imageHeight;
}


CalibSingleManager::~CalibSingleManager(void)
{
}

void CalibSingleManager::init()
{
	// camera
	camInput = new WebCamInput();

	// calibration algorithm
	calibSingle = new CamCalibSingle(width, height, 10,7,25.0);

	// parameters initialize

	camInput->initCamera(width,height);

	image.allocate(width,height);

	bFindGrid = false;

	bRecordCorners = false;
}

void CalibSingleManager::update()
{
	camInput->updateFrame();

	if (bFindGrid) {
		findChessboardCorners(bRecordCorners);
	}
}

void CalibSingleManager::draw()
{
	
	camInput->drawFrame(0,0,width,height);
	if (bFindGrid) {
		image.draw(width,0,width,height);
	} 
}

void CalibSingleManager::findChessboardCorners(bool bRecord)
{
	Mat *destImage = new Mat(height,width,CV_8UC3);
	Mat *srcImage = camInput->getCurrentFrame();

	if (calibSingle->findGridPattern(srcImage, destImage, bRecord)) { // if one set of corners are successfully recorded
		bRecordCorners = false; 
	}
	image.setFromPixels(destImage->data,destImage->cols, destImage->rows);
}

void CalibSingleManager::recordCurrentCorners(void)
{
	bRecordCorners = true;
}

void CalibSingleManager::startFindCorners(void)
{
	bFindGrid = !bFindGrid;
}

void CalibSingleManager::calibateCamera(void)
{
	calibSingle->calibrateCamera();

	bFindGrid = false;
}
