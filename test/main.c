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
	endPaint();
	return 0;
}
