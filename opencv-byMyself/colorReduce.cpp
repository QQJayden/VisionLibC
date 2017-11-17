#include "colorReduce.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

// 方法1 用指针访问像素
void colorReduce1(Mat& inputImage, Mat& outputImage, int div)
{
	//参数准备
	outputImage = inputImage.clone();//复制实参到临时变量
	int rowNumber = outputImage.rows; //行数
	int colNumber = outputImage.cols*outputImage.channels();//列数*通道数 = 每一行的元素个数

	//遍历所有像素
	for (int i = 0; i < rowNumber; i++)
	{
		uchar* data = outputImage.ptr<uchar>(i); // 获取第i行的首元素
		for (int j = 0; j < colNumber; j++)
		{
			//开始处理每一个元素
			data[j] = data[j] / div*div + div / 2;
		}

	}

	imshow("CoclorReduce1", outputImage);
	waitKey(0);
}

// 方法2 用迭代器操作图像 (STL)
void colorReduce2(Mat& inputImage, Mat& outputImage, int div)
{
	outputImage = inputImage.clone();  //复制实参
	
	//获取迭代器
	Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>(); //初时位置的迭代器
	Mat_<Vec3b>::iterator itend = outputImage.end<Vec3b>(); //终止位置的迭代器

	//存取彩色图像像素
	for (; it != itend; ++it)
	{
		//------【开始处理每个像素】-------------
		(*it)[0] = (*it)[0] / div*div + div / 2;
		(*it)[1] = (*it)[1] / div*div + div / 2;
		(*it)[2] = (*it)[2] / div*div + div / 2;
	}
	imshow("CoclorReduce2", outputImage);
	waitKey(0);
}

// 方法3 动态地址计算,配合at
void colorReduce3(Mat& inputImage, Mat& outputImage, int div)
{
	outputImage = inputImage.clone();  //复制实参到临时变量
	int rowNumber = outputImage.rows; 
	int colNumber = outputImage.cols;

	//存取彩色图像像素
	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < colNumber; j++)
		{
			//------------【开始处理每个像素】----------
			outputImage.at<Vec3b>(i, j)[0] = outputImage.at<Vec3b>(i, j)[0] / div*div + div / 2; //蓝色通道
			outputImage.at<Vec3b>(i, j)[1] = outputImage.at<Vec3b>(i, j)[1] / div*div + div / 2; //绿色色通道
			outputImage.at<Vec3b>(i, j)[2] = outputImage.at<Vec3b>(i, j)[2] / div*div + div / 2; //红色通道
		}
	}
	imshow("CoclorReduce3", outputImage);
	waitKey(0);
}


// 测试函数：显示运行时间
void test_colorReduce(Mat& inputImage, Mat& outputImage, int div, int func_type)
{
	// 【2】记录起始时间
	double time0 = static_cast<double>(getTickCount());
	
	// 【3】调用颜色空间缩短函数
	switch (func_type)
	{
	case 1:
		colorReduce1(inputImage, outputImage, div);
		break;
	case 2:
		colorReduce2(inputImage, outputImage, div);
		break;
	case 3:
		colorReduce3(inputImage, outputImage, div);
		break;
	default:
		cout << "wrong func_type" << endl;
		break;
	}

	// 【4】计算运行时间并输出
	time0 = ((double)getTickCount() - time0) / getTickFrequency();
	cout << "此方法的运行时间为：" << time0 << "秒" << endl;  //输出运行时间


}