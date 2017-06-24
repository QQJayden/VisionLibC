/* �漰��Opencv�к���:
 line, 
 ellipse, 
 rectangle, 
 circle, 
 fillPoly
*/
#include<opencv2\core\core.hpp>
#define WINDOW_WIDTH 600  //���崰�ڴ�С�ĺ꣬��ο��ƴ��ڵĴ�С��

using namespace cv;

// ��ͬ�Ƕȣ���ͬ�ߴ����Բ
void DrawEllipse(Mat &img, double angle)
{
	int thickness = 2;
	int lineType = 8;   // ����ͨ����

	ellipse(img, 
		Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),  //���ĵ� 
		Size(WINDOW_WIDTH / 4, WINDOW_WIDTH / 16),  // ��С
		angle,                //��Բ��ת�Ƕ�
		0,                     // ��չ����0��-360��
		360,
		Scalar(255,129,0),     //��ɫ
		thickness,
		lineType);
}

// ʵ��Բ
void DrawFilledCircle(Mat &img, Point center)
{
	int thickness = -1; //�ߴ�-1��ʵ��Ч��Ϊ���
	int lineType = 8;   //8��ͨ

	circle(img,
		center,
		WINDOW_WIDTH / 32,
		Scalar(0, 0, 255), //��ɫ
		thickness,
		lineType);
}

// �������: �������ɫ��ɫ
void DrawPolygon(Mat &img)
{
	int lineType = 8;

	// ����һЩ��, ����������ͼƬ��
	Point rookPoints[1][20];    //����һά����
	rookPoints[0][0]  = Point(   WINDOW_WIDTH / 4,   7*WINDOW_WIDTH / 8 );
	rookPoints[0][1]  = Point( 3*WINDOW_WIDTH / 4,   7*WINDOW_WIDTH / 8 );
	rookPoints[0][2]  = Point( 3*WINDOW_WIDTH / 4,  13*WINDOW_WIDTH / 16);
	rookPoints[0][3]  = Point(11*WINDOW_WIDTH / 16, 13*WINDOW_WIDTH / 16);
	rookPoints[0][4]  = Point(19*WINDOW_WIDTH / 32,  3*WINDOW_WIDTH / 8 );
	rookPoints[0][5]  = Point( 3*WINDOW_WIDTH / 4,   3*WINDOW_WIDTH / 8 );
	rookPoints[0][6]  = Point( 3*WINDOW_WIDTH / 4,     WINDOW_WIDTH / 8 );
	rookPoints[0][7]  = Point(26*WINDOW_WIDTH / 40,    WINDOW_WIDTH / 8 );
	rookPoints[0][8]  = Point(26*WINDOW_WIDTH / 40,    WINDOW_WIDTH / 4 );
	rookPoints[0][9]  = Point(22*WINDOW_WIDTH / 40,    WINDOW_WIDTH / 4 );
	rookPoints[0][10] = Point(22*WINDOW_WIDTH / 40,    WINDOW_WIDTH / 8 );
	rookPoints[0][11] = Point(18*WINDOW_WIDTH / 40,    WINDOW_WIDTH / 8 );
	rookPoints[0][12] = Point(18*WINDOW_WIDTH / 40,    WINDOW_WIDTH / 4 );
	rookPoints[0][13] = Point(14*WINDOW_WIDTH / 40,    WINDOW_WIDTH / 4 );
	rookPoints[0][14] = Point(14*WINDOW_WIDTH / 40,    WINDOW_WIDTH / 8 );
	rookPoints[0][15] = Point(   WINDOW_WIDTH / 4,     WINDOW_WIDTH / 8 );
	rookPoints[0][16] = Point(   WINDOW_WIDTH / 4,   3*WINDOW_WIDTH / 8 );
	rookPoints[0][17] = Point(13*WINDOW_WIDTH / 32,  3*WINDOW_WIDTH / 8 );
	rookPoints[0][18] = Point( 5*WINDOW_WIDTH / 16, 13*WINDOW_WIDTH / 16);
	rookPoints[0][19] = Point(   WINDOW_WIDTH / 4,  13*WINDOW_WIDTH / 16);

	const Point* ppt[1] = { rookPoints[0] }; //����εĶ��㼯
	int npt[] = { 20 };   // ������Ŀ

	fillPoly(img,
		ppt,
		npt,
		1,
		Scalar(255, 255, 255),   //��ɫ
		lineType);
}

// �ߣ���㡢�յ㣬��ɫ��ɫ���߿� 2�� 8��ͨ
void DrawLine(Mat &img, Point start, Point end)
{
	int thickness = 2;
	int lineType = 8;

	line(img,
		start,
		end,
		Scalar(0, 0, 0),  //��ɫ
		thickness,
		lineType);
}

// ��1�� ���ƻ�ѧ�е�ԭ��ͼ,  ��ز����Ѿ����ļ���Ԥ���
void drawAtom(Mat &img)
{
	//�Ȼ�����Բ
	DrawEllipse(img, 90);
	DrawEllipse(img, 0);
	DrawEllipse(img, 45);
	DrawEllipse(img, -45);

	// ����Բ��,ʵ��Բ
	DrawFilledCircle(img, Point (WINDOW_WIDTH/2,WINDOW_WIDTH/2));

}

// ��2���������ͼ
void drawRook(Mat &img)
{
	// �Ȼ��ư������
	DrawPolygon(img);

	//���ƾ���
	rectangle(img,
		Point(0, 7*WINDOW_WIDTH/8),
		Point(WINDOW_WIDTH,WINDOW_WIDTH),
		Scalar(0,255,255),
		-1,    //��ʾ���
		8);

	//���Ʋ����߶�
	DrawLine(img,
		Point(0, 15 * WINDOW_WIDTH / 16),
		Point(WINDOW_WIDTH, 15 * WINDOW_WIDTH / 16));
	DrawLine(img,
		Point(WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8),
		Point(WINDOW_WIDTH / 4, WINDOW_WIDTH));
	DrawLine(img,
		Point(WINDOW_WIDTH / 2, 7 * WINDOW_WIDTH / 8),
		Point(WINDOW_WIDTH / 2, WINDOW_WIDTH));
	DrawLine(img,
		Point(3 * WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8),
		Point(3 * WINDOW_WIDTH / 4, WINDOW_WIDTH));

}


