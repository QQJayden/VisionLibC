/*
【1】--------------//colorReduce.h  颜色缩减 //------------  
     测试函数test_colorReduce(srcImage,dstImage,32,1); //显示运行时间
*/

/*
【2】--------------//draw.h  绘图//------------------
    涉及到Opencv中函数: line, ellipse, rectangle, circle, fillPoly
	函数包括：
	DrawEllipse(Mat img, double angle);
	DrawFilledCircle(Mat img, Point center);
    DrawPolygon(Mat img);
	DrawLine(Mat img, Point start, Point end)
    drawAtom(atomImage);  //绘制一个原子模型
	drawRook(rookImage);  //绘制组合图

	// 绘制图像
	Mat atomImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	Mat rookImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	drawAtom(atomImage);
	drawRook(rookImage);
*/


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include"myfeature2d.h"
#include"colorReduce.h"

#include "draw.h"

#define WINDOW_WIDTH 600

using namespace std;
using namespace cv;   // 只使用opencv中显示图像以及Mat数据结构等基本操作

int main()
{
	/*
	// 【1】创建原始图像并显示
	Mat srcImage = imread("photo/taylor1.jpg");
	imshow("原始图像", srcImage);
	
	// 【2】创建空图像
	Mat atomImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	Mat rookImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	
	// 【3】按原始图的参数规格来创建效果图
	Mat dstImage;
	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type()); // 大小类型
	*/

	
	// -------------**调用的测试函数**------------------
	//Mat srcImage = imread("D:/Jayden/GITHUB/photo/taylor1.jpg",0);
	//imshow("原始", srcImage);
	//myCornerHarris(srcImage);
	

	

	//--------------------------------------------------
	
	// 显示效果图: 尽量在函数里面完成
	
	
}
