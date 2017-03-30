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
	printf("�����ȣ�\n");
	int width;
	scanf("%d",&width);
	printf("����߶ȣ�\n"); 
	int height;
	scanf("%d",&height); 
	//����һ������ 
	initWindow("test",DEFAULT,DEFAULT,width,height);
	//��� 
	registerMouseEvent(mouseEvent);
	beginPaint();
	//�� 
	setPenColor(GREEN); //����ɫ 
	setPenWidth(1);	//�߿� 
	setPenStyle(PEN_STYLE_DASHDOT); //����ʽ 
	line(0,0,width,height);
	//�� 
	putPixel(10,5,RGB(255,0,0));
	//���� 
	setTextColor(BLUE);
	setTextBkColor(BLACK);
	setTextSize(50);
	setTextFont("STCaiyun"); 
	paintText(100,0,"��");
	//��
	setBrushColor(RED);
	setBrushStyle(BRUSH_STYLE_DIAGCROSS);
	chrod((width-DEFAULT)/2,(height-DEFAULT)/2,width,height,width,0,0,height);
	//��
	arc(20,50,100,200,20,50,100,200);	
	//chrod(20,50,100,200,20,50,100,200);	
	lineTo(400,0);
	lineRel(0,400);
	//���������� 
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
	//��Բ
	ellipse(300,0,500,100); 
	//���� 
	pie(0,300,200,400,0,350,200,350);
	//����� 
	POINT lp[]=
	{
		{0,200},
		{200,200},
		{0,400},
		{200,400},
	};
	polygon(lp,4);
	//Բ�Ǿ���
	setPenColor(EMPTY); 
	roundrect(600,100,800,300,100,100); 
	//ͼƬ
	loadImage("lena.jpg",&img); 
	//putImage(&img,0,400);
	putImageScale(&img,0,400,100,100);
	//putImageTransparent(&img,0,400,100,100,RED);
	//����
	loadSound("D:/Users/atdo/Desktop/C_advance/test/drip_drop.wav",&sound);
	playSound(sound,1);	
	//stopSound(sound);
	endPaint();
	return 0;
}
#else

#include <stdio.h>
#include "acllib.h"

ACL_Sound sound;

#define MLEN 64
int len = 0,i=0;
char str[MLEN];
void charEvent(char c)
{
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
    endPaint();
}

//int kx=200,ky=200;
int kx,ky;
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
 	{
  		beginPaint();
     	rectangle(mx-10,my-10,mx+10,my+10);
  		endPaint(); 
 	}   
}
int Setup()
{
	/*
	initConsole();
	printf("�����ȣ�\n");
	int width;
	scanf("%d",&width);
	printf("����߶ȣ�\n"); 
	int height;
	scanf("%d",&height); */
	int width=700;
	int height=700;
	initWindow("test",DEFAULT,DEFAULT,width,height);
	registerMouseEvent(mouseEvent);
	kx=getX()+20;
	ky=getY()+20;
	registerKeyboardEvent(keyEvent);
	registerCharEvent(charEvent);
	beginPaint();
	rectangle(kx-10,ky-10,kx+10,ky+10);
	loadSound("D:/Users/atdo/Desktop/C_advance/test/������.mp3",&sound);
	playSound(sound,1);	
	endPaint();
	return 0;
}
#endif
