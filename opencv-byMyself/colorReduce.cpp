#include "colorReduce.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

// ����1 ��ָ���������
void colorReduce1(Mat& inputImage, Mat& outputImage, int div)
{
	//����׼��
	outputImage = inputImage.clone();//����ʵ�ε���ʱ����
	int rowNumber = outputImage.rows; //����
	int colNumber = outputImage.cols*outputImage.channels();//����*ͨ���� = ÿһ�е�Ԫ�ظ���

	//������������
	for (int i = 0; i < rowNumber; i++)
	{
		uchar* data = outputImage.ptr<uchar>(i); // ��ȡ��i�е���Ԫ��
		for (int j = 0; j < colNumber; j++)
		{
			//��ʼ����ÿһ��Ԫ��
			data[j] = data[j] / div*div + div / 2;
		}

	}

	imshow("CoclorReduce1", outputImage);
	waitKey(0);
}

// ����2 �õ���������ͼ�� (STL)
void colorReduce2(Mat& inputImage, Mat& outputImage, int div)
{
	outputImage = inputImage.clone();  //����ʵ��
	
	//��ȡ������
	Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>(); //��ʱλ�õĵ�����
	Mat_<Vec3b>::iterator itend = outputImage.end<Vec3b>(); //��ֹλ�õĵ�����

	//��ȡ��ɫͼ������
	for (; it != itend; ++it)
	{
		//------����ʼ����ÿ�����ء�-------------
		(*it)[0] = (*it)[0] / div*div + div / 2;
		(*it)[1] = (*it)[1] / div*div + div / 2;
		(*it)[2] = (*it)[2] / div*div + div / 2;
	}
	imshow("CoclorReduce2", outputImage);
	waitKey(0);
}

// ����3 ��̬��ַ����,���at
void colorReduce3(Mat& inputImage, Mat& outputImage, int div)
{
	outputImage = inputImage.clone();  //����ʵ�ε���ʱ����
	int rowNumber = outputImage.rows; 
	int colNumber = outputImage.cols;

	//��ȡ��ɫͼ������
	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < colNumber; j++)
		{
			//------------����ʼ����ÿ�����ء�----------
			outputImage.at<Vec3b>(i, j)[0] = outputImage.at<Vec3b>(i, j)[0] / div*div + div / 2; //��ɫͨ��
			outputImage.at<Vec3b>(i, j)[1] = outputImage.at<Vec3b>(i, j)[1] / div*div + div / 2; //��ɫɫͨ��
			outputImage.at<Vec3b>(i, j)[2] = outputImage.at<Vec3b>(i, j)[2] / div*div + div / 2; //��ɫͨ��
		}
	}
	imshow("CoclorReduce3", outputImage);
	waitKey(0);
}


// ���Ժ�������ʾ����ʱ��
void test_colorReduce(Mat& inputImage, Mat& outputImage, int div, int func_type)
{
	// ��2����¼��ʼʱ��
	double time0 = static_cast<double>(getTickCount());
	
	// ��3��������ɫ�ռ����̺���
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

	// ��4����������ʱ�䲢���
	time0 = ((double)getTickCount() - time0) / getTickFrequency();
	cout << "�˷���������ʱ��Ϊ��" << time0 << "��" << endl;  //�������ʱ��


}