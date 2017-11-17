#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

void myCornerHarris(Mat& inputImage)
{
	imshow("原始图", inputImage);

	// 进行角点检测
	/*cornerHarris:
	第三个参数：邻域大小
	第四个参数：Sobel（算子孔径大小）
	第五个参数：Harris参数
	第六个参数：图像的边界模式
	*/
	Mat cornerStrength;
	cornerHarris(inputImage, cornerStrength, 2, 3, 0.01);

	// 对灰度图进行阈值操作
	Mat harrisCorner;
	threshold(cornerStrength, harrisCorner, 0.00001, 255, THRESH_BINARY);
	imshow("角点检测后的二值效果图", harrisCorner);

	waitKey(0);

}