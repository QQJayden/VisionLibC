#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

void myCornerHarris(Mat& inputImage)
{
	imshow("ԭʼͼ", inputImage);

	// ���нǵ���
	/*cornerHarris:
	�����������������С
	���ĸ�������Sobel�����ӿ׾���С��
	�����������Harris����
	������������ͼ��ı߽�ģʽ
	*/
	Mat cornerStrength;
	cornerHarris(inputImage, cornerStrength, 2, 3, 0.01);

	// �ԻҶ�ͼ������ֵ����
	Mat harrisCorner;
	threshold(cornerStrength, harrisCorner, 0.00001, 255, THRESH_BINARY);
	imshow("�ǵ����Ķ�ֵЧ��ͼ", harrisCorner);

	waitKey(0);

}