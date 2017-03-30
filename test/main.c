#if 0
#include <stdio.h>
#include "acllib.h"

ACL_Image img;

ACL_Sound sound;

int bt_old,event_old;

void mouseEvent(int x,int y,int bt,int event)
{
	//printf("%d,%d ",bt_old,event_old);
	if(bt==LEFT_BUTTON||bt==RIGHT_BUTTON)
	{
		bt_old=bt;
		event_old=event;
	}
	if(event==BUTTON_DOWN)
	{
		beginPaint();
		setBrushStyle(BRUSH_STYLE_SOLID);
	    if(bt==LEFT_BUTTON)setBrushColor(RED);
	    else if(bt==RIGHT_BUTTON)setBrushColor(BLUE);
	    rectangle(x-10,y-10,x+10,y+10);
		endPaint();
	}
    else if(event==MOUSEMOVE&&(bt_old==LEFT_BUTTON||bt_old==RIGHT_BUTTON)&&event_old==BUTTON_DOWN)
	{
		beginPaint();
	    rectangle(x-10,y-10,x+10,y+10);
		endPaint();	
	} 	 
}


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
	//鼠标 
	registerMouseEvent(mouseEvent);
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
	setTextFont("STCaiyun"); 
	paintText(100,0,"好");
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
	//图片
	loadImage("lena.jpg",&img); 
	//putImage(&img,0,400);
	putImageScale(&img,0,400,100,100);
	//putImageTransparent(&img,0,400,100,100,RED);
	//声音
	loadSound("D:/Users/atdo/Desktop/C_advance/test/drip_drop.wav",&sound);
	playSound(sound,1);	
	//stopSound(sound);
	endPaint();
	return 0;
}
#else

#include <stdio.h>
#include "acllib.h"
int bt_old,event_old;
void mouseEvent(int x,int y,int bt,int event)
{
	//printf("%d,%d ",bt_old,event_old);
 	if(bt==LEFT_BUTTON||bt==RIGHT_BUTTON)
 	{
  		bt_old=bt;
  		event_old=event;
 	}
 	if(event==BUTTON_DOWN)
 	{
  		beginPaint();
  		setBrushStyle(BRUSH_STYLE_SOLID);
     	if(bt==LEFT_BUTTON)
		{
			setPenColor(RED); 
			setBrushColor(RED);
		}
     	else if(bt==RIGHT_BUTTON)
		{
			setPenColor(BLUE);
			setBrushColor(BLUE);
		}
     	rectangle(x-10,y-10,x+10,y+10);
  		endPaint();
 	}
    else if(event==MOUSEMOVE&&(bt_old==LEFT_BUTTON||bt_old==RIGHT_BUTTON)&&event_old==BUTTON_DOWN)
 	{
  		beginPaint();
     	rectangle(x-10,y-10,x+10,y+10);
  		endPaint(); 
 	}   
}
int Setup()
{
	initConsole();
	printf("输入宽度：\n");
	int width;
	scanf("%d",&width);
	printf("输入高度：\n"); 
	int height;
	scanf("%d",&height); 
	initWindow("test",DEFAULT,DEFAULT,width,height);
	registerMouseEvent(mouseEvent);
	return 0;
}
#endif
