#include <stdio.h>
#include <stdlib.h>

int main(void)
{
/*
	int number;
	int* a;
	int i;
	printf("输入数量：");
	scanf("%d",&number);
	a=(int*)malloc(number*sizeof(int));
	if(malloc(number*sizeof(int))!=NULL)
	{
		for(i=0;i<number;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=number-1;i>=0;i--)
		{
			printf("%d ",a[i]);
		}21 
	}
	else printf("申请失败！\n");
	free(a);
*/
/* 
	//探测你能malloc得到多少内存 
	void *p;
	int cnt=0;
	while((p=malloc(100*1024*1024)))
	{
		cnt++;
	}
	printf("分配了%d00MB的空间\n",cnt);
*/	
	void *a;
	void *b;
	void *c;
	/*a=malloc(0);
	b=malloc(1);
	c=malloc(2);
	printf("a=%d\n",sizeof(a));
	printf("a=%p\n",a);
	printf("b=%d\n",sizeof(b));
	printf("b=%p\n",b);
	printf("c=%d\n",sizeof(c));
	printf("c=%p\n",c);		
	free(a);
	free(b);
	free(c);
	*/
	a=malloc(8);
	b=malloc(10);
	c=malloc(50);
	printf("a=%d\n",sizeof(a));
	printf("a=%p\n",a);
	printf("b=%d\n",sizeof(b));
	printf("b=%p\n",b);
	printf("c=%d\n",sizeof(c));
	printf("c=%p\n",c);		
	free(a);
	free(b);
	free(c);	
	return 0;
}
