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
	DrawLine(Mat img, Point start, Point end);
    drawAtom(atomImage);  //����һ��ԭ��ģ��
	drawRook(rookImage);  //�������ͼ
*/


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
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

	// ��2�������հ׵�Matͼ��
	Mat atomImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	Mat rookImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);

	// ��3����ԭʼͼ�Ĳ������������Ч��ͼ
	Mat dstImage;
	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type()); // ��С����
	
	*/

	// -------------**���õĲ��Ժ���**------------------





	//--------------------------------------------------
	
	// ��ʾЧ��ͼ
	imshow("ԭ��ʾ��ͼ", atomImage);
	imshow("���ͼ", rookImage);
	waitKey(0);
	
}
