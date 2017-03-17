#include <stdio.h>

int main()
{
	unsigned int a=0;
	int b=0;
	int c=-1;
	while(++a>0);
	printf("unsigned int类型的最小数是：%u\n",a);
	printf("unsigned int类型的最大数是：%u\n",a-1);
	
	while(b>-1)b++;
	printf("int类型的最小数是：%d\n",b);
	printf("int类型的最大数是：%d\n",b-1);
	
	while(c<0)c--;
	printf("int类型的最大数是：%d\n",c);
	printf("int类型的最小数是：%d\n",c+1);

	return 0;
} 
