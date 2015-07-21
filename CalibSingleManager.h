#pragma once

#include "WebCamInput.h"
#include "CamCalibSingle.h"

class CalibSingleManager
{
public:
	CalibSingleManager(void);
	~CalibSingleManager(void);

	// process (change the name)
	void initCamera();
	void findGridPattern();
	void processCalibration();
	void showResult();

public:
	WebCamInput *camInput;
	CamCalibSingle *calibSingle;

};

