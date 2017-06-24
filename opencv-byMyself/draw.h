//#include<iostream>
#include<opencv2\core\core.hpp>

using namespace cv;

// 不同角度，相同尺寸的椭圆
void DrawEllipse(Mat &img, double angle);  

// 实心圆
void DrawFilledCircle(Mat &img, Point center);

// 凹多边形: 多边形颜色白色
void DrawPolygon(Mat &img);

// 线：起点、终点，颜色黑色，线宽 2， 8连通
void DrawLine(Mat &img, Point start, Point end);

// 【1】 绘制化学中的原子图,  相关参数已经在文件中预设好
void drawAtom(Mat &img);

// 【2】绘制组合图
void drawRook(Mat &img);

