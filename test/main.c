#if 0
#include <stdio.h>
#include "acllib.h"

ACL_Image img;
ACL_Sound sound;

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
	loadSound("drip_drop.wav",&sound);
	playSound(sound,1);	
	//stopSound(sound);
	endPaint();
	return 0;
}
#else

#include <stdio.h>
#include "acllib.h"
#include <math.h>
#include <time.h>

ACL_Sound sound;

#define RAD(x) ((x)/360.0*2*3.1415926535)//角度转换成弧度
int h = 0;
int m = 0;
int s = 0;
typedef struct
{
	int tm_hour;
	int tm_min;
	int tm_sec;
}tm;
void timerEvent(int tid)
{
#if 0
	++s;
	if(s==60)
	{
		s = 0;
		++m;
	}
	if(m==60)
	{
		m = 0;
		++h;
	}
	if(h==12)
		h = 0;
#endif
    // 获取本地时间
    time_t timer = time(NULL);
    struct tm *timel = localtime(&timer);
	h=timel->tm_hour%12;
	m=timel->tm_min;
	s=timel->tm_sec;
			
	static const int ox = 150;
	static const int oy = 150;

	static const int hl = 46;
	static const int ml = 74;
	static const int sl = 120;

	int i;

	beginPaint();

	//clearDevice();

	// circle
	setPenWidth(3);
	setPenColor(MAGENTA);//(BLACK);
	setBrushColor(YELLOW);//(WHITE);
	ellipse(25,25,275,275);

	// label
	//setPenWidth(1);
	//setPenColor(BLUE);
	//for(i=0;i<12;++i)
	//{
	//	moveTo(ox+115*sin(RAD(180-i*30)),oy+115*cos(RAD(180-i*30)));
	//	lineTo(ox+125*sin(RAD(180-i*30)),oy+125*cos(RAD(180-i*30)));
	//}
	for(i=0;i<60;++i)
	{
		if(i%15==0)setPenWidth(3);
		else setPenWidth(1);
		if(i%5==0)
		{
			setPenColor(BROWN);
			moveTo(ox+105*sin(RAD(180-i*6)),oy+105*cos(RAD(180-i*6)));
		}
		else 
		{
			setPenColor(BLUE);
			moveTo(ox+115*sin(RAD(180-i*6)),oy+115*cos(RAD(180-i*6)));
		}
		lineTo(ox+125*sin(RAD(180-i*6)),oy+125*cos(RAD(180-i*6)));
	}

	// hour
	setPenWidth(8);
	setPenColor(BLACK);
	moveTo(ox,oy);
	lineTo(ox+hl*sin(RAD(180-h*30)),oy+hl*cos(RAD(180-h*30)));

	// minute
	setPenWidth(4);
	setPenColor(GREEN);
	moveTo(ox,oy);
	lineTo(ox+ml*sin(RAD(180-m*6)),oy+ml*cos(RAD(180-m*6)));

	// second
	setPenWidth(2);
	setPenColor(RED);
	moveTo(ox,oy);
	lineTo(ox+sl*sin(RAD(180-s*6)),oy+sl*cos(RAD(180-s*6)));

	endPaint();
}

#define MLEN 9//64 汉字2个字节，英文字母1个字节 
int len = 0,i=0;
char str[MLEN];
void charEvent(char c)
{
	printf("%d\n",len); 
    if(len+1>=MLEN)
    {
        memset(str,0,sizeof(str));
        len = 0;
    }
    str[len] = c;
    ++len;
    
    beginPaint();
    setTextSize(16);
    paintText(0,50,str);
    setCaretSize(3,20);
    setCaretPos(len*9,50);
    showCaret();    
    endPaint();
}

//int kx=200,ky=200;
int kx,ky,first_point=0;
void keyEvent(int key,int event)
{
    if(event!=KEY_DOWN)
        return;
    switch(key)
    {
    case VK_UP:
        ky-=10;
        break;
    case VK_DOWN:
        ky+=10;
        break;
    case VK_LEFT:
        kx-=10;
        break;
    case VK_RIGHT:
        kx+=10;
        break;
    }	
    beginPaint();
    //clearDevice();
    setPenColor(EMPTY); 
    setBrushColor(BLACK);
    rectangle(kx-10,ky-10,kx+10,ky+10);
    endPaint();	
}

int bt_old,event_old;
void mouseEvent(int mx,int my,int bt,int event)
{
	//printf("%d,%d ",bt_old,event_old);
 	if(bt==LEFT_BUTTON||bt==RIGHT_BUTTON)
 	{
  		bt_old=bt;
  		event_old=event;
 	}
#if 0
 	if(event==BUTTON_DOWN)
 	{
  		beginPaint();
  		setBrushStyle(BRUSH_STYLE_SOLID);
  		setPenColor(EMPTY); 
     	if(bt==LEFT_BUTTON)
		{
			//setPenColor(RED); 
			setBrushColor(RED);
		}
     	else if(bt==RIGHT_BUTTON)
		{
			//setPenColor(BLUE);
			setBrushColor(BLUE);
		}
     	rectangle(mx-10,my-10,mx+10,my+10);
  		endPaint();
 	}
    else if(event==MOUSEMOVE&&(bt_old==LEFT_BUTTON||bt_old==RIGHT_BUTTON)&&event_old==BUTTON_DOWN)
#endif
 	//if(first_point==0&&event==BUTTON_DOWN)
	//{
	//	kx=mx;
	//	ky=my;  
	//	first_point=1;
	//}
	if(event==MOUSEMOVE&&(bt_old==LEFT_BUTTON||bt_old==RIGHT_BUTTON)&&event_old==BUTTON_DOWN||event==BUTTON_DOWN)
 	{
	 	if(first_point==0)
		{
			kx=mx;
			ky=my;  
			first_point=1;
		}
  		beginPaint();
  		setBrushStyle(BRUSH_STYLE_SOLID);
  		setPenColor(EMPTY);   	
     	if(bt_old==LEFT_BUTTON)
		{
			//setPenColor(RED); 
			setBrushColor(RED);
		}
     	else if(bt_old==RIGHT_BUTTON)
		{
			//setPenColor(BLUE);
			setBrushColor(BLUE);
		}		  	
     	rectangle(mx-10,my-10,mx+10,my+10);
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
	//int width=700;
	//int height=700;
	initWindow("test",DEFAULT,DEFAULT,width,height);
	registerMouseEvent(mouseEvent);
	registerKeyboardEvent(keyEvent);
	registerCharEvent(charEvent);
	registerTimerEvent(timerEvent);
	startTimer(0,1000);	
	beginPaint();
    setCaretSize(3,20);
    setCaretPos(0,50);
    showCaret(); 
	//kx=getX()+20;
	//ky=getY()+20;
	//rectangle(kx-10,ky-10,kx+10,ky+10);
	loadSound("白噪音.mp3",&sound);
	playSound(sound,0);	
	endPaint();
	return 0;
}
#endif
