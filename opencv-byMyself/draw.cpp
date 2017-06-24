/* 涉及到Opencv中函数:
 line, 
 ellipse, 
 rectangle, 
 circle, 
 fillPoly
*/
#include<opencv2\core\core.hpp>
#define WINDOW_WIDTH 600  //定义窗口大小的宏，如何控制窗口的大小？

using namespace cv;

// 不同角度，相同尺寸的椭圆
void DrawEllipse(Mat &img, double angle)
{
	int thickness = 2;
	int lineType = 8;   // 八连通线形

	ellipse(img, 
		Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),  //中心点 
		Size(WINDOW_WIDTH / 4, WINDOW_WIDTH / 16),  // 大小
		angle,                //椭圆旋转角度
		0,                     // 扩展弧度0度-360度
		360,
		Scalar(255,129,0),     //蓝色
		thickness,
		lineType);
}

// 实心圆
void DrawFilledCircle(Mat &img, Point center)
{
	int thickness = -1; //线粗-1，实际效果为填充
	int lineType = 8;   //8连通

	circle(img,
		center,
		WINDOW_WIDTH / 32,
		Scalar(0, 0, 255), //红色
		thickness,
		lineType);
}

// 凹多边形: 多边形颜色白色
void DrawPolygon(Mat &img)
{
	int lineType = 8;

	// 创建一些点, 见最终象棋图片？
	Point rookPoints[1][20];    //创建一维数组
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

	const Point* ppt[1] = { rookPoints[0] }; //多边形的顶点集
	int npt[] = { 20 };   // 顶点数目

	fillPoly(img,
		ppt,
		npt,
		1,
		Scalar(255, 255, 255),   //白色
		lineType);
}

// 线：起点、终点，颜色黑色，线宽 2， 8连通
void DrawLine(Mat &img, Point start, Point end)
{
	int thickness = 2;
	int lineType = 8;

	line(img,
		start,
		end,
		Scalar(0, 0, 0),  //黑色
		thickness,
		lineType);
}

// 【1】 绘制化学中的原子图,  相关参数已经在文件中预设好
void drawAtom(Mat &img)
{
	//先绘制椭圆
	DrawEllipse(img, 90);
	DrawEllipse(img, 0);
	DrawEllipse(img, 45);
	DrawEllipse(img, -45);

	// 绘制圆心,实心圆
	DrawFilledCircle(img, Point (WINDOW_WIDTH/2,WINDOW_WIDTH/2));

}

// 【2】绘制组合图
void drawRook(Mat &img)
{
	// 先绘制凹多边形
	DrawPolygon(img);

	//绘制矩形
	rectangle(img,
		Point(0, 7*WINDOW_WIDTH/8),
		Point(WINDOW_WIDTH,WINDOW_WIDTH),
		Scalar(0,255,255),
		-1,    //表示填充
		8);

	//绘制部分线段
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


