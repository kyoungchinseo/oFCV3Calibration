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
	calibSingle = new CamCalibSingle(10,7);

	// parameters initialize

	camInput->initCamera(width,height);

	image.allocate(width,height);

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
	camInput->drawFrame(0,0,width,height);
	if (bFindGrid) {
		image.draw(width,0,width,height);
	}

}

void CalibSingleManager::findChessboardCorners(void)
{
	Mat *destImage = new Mat(height,width,CV_8UC3);
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
