#include <iostream>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

void colorReduce1(Mat& inputImage, Mat& outputImage, int div);
void colorReduce2(Mat& inputImage, Mat& outputImage, int div);
void colorReduce3(Mat& inputImage, Mat& outputImage, int div);

void test_colorReduce(Mat& inputImage, Mat& outputImage, int div, int func_type);