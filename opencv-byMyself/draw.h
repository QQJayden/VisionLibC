//#include<iostream>
#include<opencv2\core\core.hpp>

using namespace cv;

// ��ͬ�Ƕȣ���ͬ�ߴ����Բ
void DrawEllipse(Mat &img, double angle);  

// ʵ��Բ
void DrawFilledCircle(Mat &img, Point center);

// �������: �������ɫ��ɫ
void DrawPolygon(Mat &img);

// �ߣ���㡢�յ㣬��ɫ��ɫ���߿� 2�� 8��ͨ
void DrawLine(Mat &img, Point start, Point end);

// ��1�� ���ƻ�ѧ�е�ԭ��ͼ,  ��ز����Ѿ����ļ���Ԥ���
void drawAtom(Mat &img);

// ��2���������ͼ
void drawRook(Mat &img);

