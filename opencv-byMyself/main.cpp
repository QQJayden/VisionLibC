/*
��1��--------------//colorReduce.h  ��ɫ���� //------------  
     ���Ժ���test_colorReduce(srcImage,dstImage,32,1); //��ʾ����ʱ��
*/

/*
��2��--------------//draw.h  ��ͼ//------------------
    �漰��Opencv�к���: line, ellipse, rectangle, circle, fillPoly
	����������
	DrawEllipse(Mat img, double angle);
	DrawFilledCircle(Mat img, Point center);
    DrawPolygon(Mat img);
	DrawLine(Mat img, Point start, Point end)
    drawAtom(atomImage);  //����һ��ԭ��ģ��
	drawRook(rookImage);  //�������ͼ

	// ����ͼ��
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
using namespace cv;   // ֻʹ��opencv����ʾͼ���Լ�Mat���ݽṹ�Ȼ�������

int main()
{
	/*
	// ��1������ԭʼͼ����ʾ
	Mat srcImage = imread("photo/taylor1.jpg");
	imshow("ԭʼͼ��", srcImage);
	
	// ��2��������ͼ��
	Mat atomImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	Mat rookImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	
	// ��3����ԭʼͼ�Ĳ������������Ч��ͼ
	Mat dstImage;
	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type()); // ��С����
	*/

	
	// -------------**���õĲ��Ժ���**------------------
	//Mat srcImage = imread("D:/Jayden/GITHUB/photo/taylor1.jpg",0);
	//imshow("ԭʼ", srcImage);
	//myCornerHarris(srcImage);
	

	

	//--------------------------------------------------
	
	// ��ʾЧ��ͼ: �����ں����������
	
	
}
