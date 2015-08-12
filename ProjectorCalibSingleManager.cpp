#include "ProjectorCalibSingleManager.h"


ProjectorCalibSingleManager::ProjectorCalibSingleManager(int imageWidth, int imageHeight)
{
	width = imageWidth;
	height= imageHeight;
}


ProjectorCalibSingleManager::~ProjectorCalibSingleManager(void)
{
}

void ProjectorCalibSingleManager::init()
{
	// camera
	camInput = new WebCamInput();

	// calibration algorithm
	calibSingle = new ProjectorCamCalib(width, height, 10,7,25.0);

	// parameters initialize

	camInput->initCamera(width,height);

	image.allocate(width,height);

	bFindGrid = false;

	bRecordCorners = false;
}

void ProjectorCalibSingleManager::update()
{
	camInput->updateFrame();

	if (bFindGrid) {
		findChessboardCorners(bRecordCorners);
	}
}

void ProjectorCalibSingleManager::draw()
{
	
	camInput->drawFrame(0,0,width,height);
	if (bFindGrid) {
		image.draw(width,0,width,height);
	} 
}

void ProjectorCalibSingleManager::findChessboardCorners(bool bRecord)
{
	Mat *destImage = new Mat(height,width,CV_8UC3);
	Mat *srcImage = camInput->getCurrentFrame();

	if (calibSingle->findGridPattern(srcImage, destImage, bRecord)) { // if one set of corners are successfully recorded
		bRecordCorners = false; 
	}
	image.setFromPixels(destImage->data,destImage->cols, destImage->rows);
}

void ProjectorCalibSingleManager::recordCurrentCorners(void)
{
	bRecordCorners = true;
}

void ProjectorCalibSingleManager::startFindCorners(void)
{
	bFindGrid = !bFindGrid;
}

void ProjectorCalibSingleManager::calibateCamera(void)
{
	calibSingle->calibrateCamera();

	bFindGrid = false;
}
