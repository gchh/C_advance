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
	endPaint();
	return 0;
}
