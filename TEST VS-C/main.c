#include <stdio.h>
#include "acllib.h"

int Setup()
{
	initConsole();
	printf("�����ȣ�\n");
	int width;
	scanf_s("%d",&width);
	printf("����߶ȣ�\n"); 
	int height;
	scanf_s("%d",&height); 
	//����һ������ 
	//initWindow("test",DEFAULT,DEFAULT,width,height);
	initWindow("test", -100, -100, width, height);
	beginPaint();
	//moveRel(100, 100);
	//moveTo(100, 100);
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
	printf("%d\n",getWidth());
	printf("%d\n", getHeight());
	printf("%d\n", getX());
	printf("%d\n", getY());
	endPaint();
	return 0;
}
