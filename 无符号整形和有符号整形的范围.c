#include <stdio.h>

int main()
{
	unsigned int a=0;
	int b=0;
	int c=-1;
	while(++a>0);
	printf("unsigned int���͵���С���ǣ�%u\n",a);
	printf("unsigned int���͵�������ǣ�%u\n",a-1);
	
	while(b>-1)b++;
	printf("int���͵���С���ǣ�%d\n",b);
	printf("int���͵�������ǣ�%d\n",b-1);
	
	while(c<0)c--;
	printf("int���͵�������ǣ�%d\n",c);
	printf("int���͵���С���ǣ�%d\n",c+1);

	return 0;
} 
