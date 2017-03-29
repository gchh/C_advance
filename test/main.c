#include <stdio.h>
#include "acllib.h"

int Setup()
{
	initConsole();
	printf("输入宽度：\n");
	int width;
	scanf("%d",&width);
	printf("输入高度：\n"); 
	int height;
	scanf("%d",&height); 
	//生成一个窗口 
	initWindow("test",DEFAULT,DEFAULT,width,height);
	beginPaint();
	//线 
	setPenColor(GREEN); //线颜色 
	setPenWidth(1);	//线宽 
	setPenStyle(PEN_STYLE_DASHDOT); //线样式 
	line(0,0,width,height);
	//点 
	putPixel(10,5,RGB(255,0,0));
	//文字 
	setTextColor(BLUE);
	setTextBkColor(BLACK);
	setTextSize(50);
	paintText(20,0,"HELLO");
	//面
	setBrushColor(RED);
	setBrushStyle(BRUSH_STYLE_DIAGCROSS);
	chrod((width-DEFAULT)/2,(height-DEFAULT)/2,width,height,width,0,0,height);
	//弧
	arc(20,50,100,200,20,50,100,200);	
	//chrod(20,50,100,200,20,50,100,200);	
	lineTo(400,0);
	lineRel(0,400);
	//贝塞尔曲线 
	POINT p[]=
	{
		{0,0},
		{150,0},
		{0,150},
		{150,150},
		{150,300},
		{150,150},
		{300,300},
	};
	polyBezier(p,7);
	//椭圆
	ellipse(300,0,500,100); 
	//扇形 
	pie(0,300,200,400,0,350,200,350);
	//多边形 
	POINT lp[]=
	{
		{0,200},
		{200,200},
		{0,400},
		{200,400},
	};
	polygon(lp,4);
	//圆角矩形
	setPenColor(EMPTY); 
	roundrect(600,100,800,300,100,100); 
	endPaint();
	return 0;
}
