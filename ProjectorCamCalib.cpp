#include "ProjectorCamCalib.h"


ProjectorCamCalib::ProjectorCamCalib(int imgWidth, int imgHeight, int num_of_corners_horz, int num_of_corners_vert, float square_size)
{
	numOfCornersHorz = num_of_corners_horz;
	numOfCornersVert = num_of_corners_vert;
	squareSize = square_size;
	boardSize = cv::Size(numOfCornersHorz, numOfCornersVert);
	imageSize = cv::Size(imgWidth, imgHeight);

	intrinsicMatrix = Mat::eye(3,3,CV_64F);
	distortionMatrix = Mat::zeros(8,1,CV_64F);
	

	corners.clear();
	imagePoints.clear();
}

ProjectorCamCalib::~ProjectorCamCalib(void)
{
}

bool ProjectorCamCalib::findGridPattern(Mat* srcImage ,Mat* destImage, bool record)
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
		if (record) {
			// record
			cout << "RECORD: " << corners.at(0).x << ":" << corners.at(0).y << endl;
			imagePoints.push_back(corners);
			cout << "=======> " << imagePoints.size() << endl;
			return true;
		}
	}

	return false;
}

void ProjectorCamCalib::loadParameters()
{

}

void ProjectorCamCalib::saveParameters()
{
	
}

void ProjectorCamCalib::calibrateCamera()
{
	generateObjectPoints();

	double rms = cv::calibrateCamera(objectPoints, imagePoints, imageSize, 
		intrinsicMatrix, distortionMatrix, rvecs, tvecs, CV_CALIB_FIX_K4 | CV_CALIB_FIX_K5);

	cout << "calibration finished: " << rms <<  endl;

	showResultMatrix();
}

void ProjectorCamCalib::generateObjectPoints(void) 
{
	vector <Point3f> objectCorners;
	objectCorners.clear();
	for(int i=0;i<boardSize.height;i++) {
		for(int j=0;j<boardSize.width;j++) {
			objectCorners.push_back(Point3f(float(j*1), float(i*1),0.0));
		}
	}

	objectPoints.clear();
	for(int i=0;i<imagePoints.size();i++) {
		objectPoints.push_back(objectCorners);
	}


}

void ProjectorCamCalib::showResultMatrix(void) {
	cout << "Camera Intrinsic Matrix: " << endl;
	cout << intrinsicMatrix << endl;

	cout << "Lens Distortion Matrix" << endl;
	cout << distortionMatrix << endl;
}