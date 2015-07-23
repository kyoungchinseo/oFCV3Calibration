#include "CamCalibSingle.h"


CamCalibSingle::CamCalibSingle(int num_of_corners_horz, int num_of_corners_vert)
{
	numOfCornersHorz = num_of_corners_horz;
	numOfCornersVert = num_of_corners_vert;
	boardSize = cv::Size(numOfCornersHorz, numOfCornersVert);

	corners.clear();

}

CamCalibSingle::~CamCalibSingle(void)
{
}

void CamCalibSingle::findGridPattern(Mat* srcImage ,Mat* destImage)
{
	Mat grayImage;
	//Mat inputImage(srcImage->rows,srcImage->cols, CV_8UC3, srcImage->data);
	*(destImage) = *(srcImage);
	cvtColor(*(destImage), grayImage, CV_BGR2GRAY);
	corners.clear();
	
	bool found = findChessboardCorners(grayImage, boardSize, corners, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS | CV_CALIB_CB_NORMALIZE_IMAGE);
	if (found) {
		cout << "found corner!" << endl;
		cornerSubPix(grayImage, corners, cv::Size(5,5), cv::Size(-1,-1),TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.1));
		drawChessboardCorners(*(destImage), boardSize, corners, found);
	}
	
	//cv::namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
	//cv::imshow( "Display window", grayImage); // Show our image inside i
}

void CamCalibSingle::loadParameters()
{

}

