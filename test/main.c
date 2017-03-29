#include <stdio.h>
#include "acllib.h"

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
	paintText(20,0,"HELLO");
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
	endPaint();
	return 0;
}
