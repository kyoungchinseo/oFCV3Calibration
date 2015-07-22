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

	image.allocate(640,480);

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
		image.draw(0,240,320,240);
	}

}

void CalibSingleManager::findChessboardCorners(void)
{
	//Mat *destImage = new Mat(480,640,CV_8UC3);
	Mat *destImage = new Mat(480,640,CV_8UC1);
	Mat *srcImage = camInput->getCurrentFrame();
	calibSingle->findGridPattern(srcImage, destImage);
	
	//camInput->getCurrentFrame();
	
	//image.allocate(640,480);
	//image.setFromPixels(srcImage->data,srcImage->cols, srcImage->rows);
	image.setFromPixels(destImage->data,destImage->cols, destImage->rows);
	//image.setFromPixels(srcImage->data, 480, 640);
	//image.draw(0,240,320,240);


	//bFindGrid = false;
}
