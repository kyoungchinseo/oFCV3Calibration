#include "CamCalibSingle.h"


CamCalibSingle::CamCalibSingle(void)
{
}


CamCalibSingle::~CamCalibSingle(void)
{
}

void CamCalibSingle::findGridPattern(Mat* srcImage ,Mat* destImage)
{
	Mat grayImage;
	Mat inputImage(srcImage->rows,srcImage->cols, CV_8UC3,srcImage->data);
	//IplImage *gSrcImage = cvCreateImage(cvGetSize(srcImage),IPL_DEPTH_8U, 1);
	cvtColor(inputImage, grayImage, CV_BGR2GRAY);

	cout << srcImage->rows << ":" << grayImage.rows << endl;

	//CvPoint2D32f *cornerPoints = new CvPoint2D32f[1000];  // 1000?
	//int corner_count = 0;

	//CV_EXPORTS_W bool findChessboardCorners( InputArray image, Size patternSize, OutputArray corners,
    //                                     int flags = CALIB_CB_ADAPTIVE_THRESH + CALIB_CB_NORMALIZE_IMAGE );

	//int found = cvFindChessboardCorners(srcImage, cvSize(10,10), cornerPoints, &corner_count, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS);

	//cvFindCornerSubPix(grayImage, cornerPoints, corner_count, cvSize(11,11), cvSize(-1, -1), cvTermCriteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1));

	//cvDrawChessboardCorners(destImage,cvSize(10,10),cornerPoints, corner_count, found);

	//delete [] cornerPoints;

	destImage = new Mat(srcImage->rows,srcImage->cols,CV_8SC3,srcImage->data);
	

	//return destImage;
}