#pragma once
#include "vision/VisionPipeline.h"

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <math.h>

namespace grip {

/**
* A representation of the different types of blurs that can be used.
*
*/
enum BlurType {
	BOX, GAUSSIAN, MEDIAN, BILATERAL
};
/**
* FilterAndProcess class.
* 
* An OpenCV pipeline generated by GRIP.
*/
class FilterAndProcess : public frc::VisionPipeline {
	private:
		cv::Mat cvCvtcolorOutput;
		cv::Mat blurOutput;
		cv::Mat hsvThresholdOutput;
		std::vector<std::vector<cv::Point> > findContoursOutput;
		void cvCvtcolor(cv::Mat &, int , cv::Mat &);
		void blur(cv::Mat &, BlurType &, double , cv::Mat &);
		void hsvThreshold(cv::Mat &, double [], double [], double [], cv::Mat &);
		void findContours(cv::Mat &, bool , std::vector<std::vector<cv::Point> > &);

	public:
		FilterAndProcess();
		void Process(cv::Mat& source0) override;
		cv::Mat* GetCvCvtcolorOutput();
		cv::Mat* GetBlurOutput();
		cv::Mat* GetHsvThresholdOutput();
		std::vector<std::vector<cv::Point> >* GetFindContoursOutput();
};


} // end namespace grip


