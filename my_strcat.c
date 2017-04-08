#include <stdio.h> 

//char *my_strcat(char *dest,const char *src)
void my_strcat(char *dest,const char *src)
{
	unsigned int a=0;
	char *result;
#if 1 
	result=dest;
	
	do{
		result++;
		a++;
	}while(*result!='\0');
#else  //不改变dest的内容 
	do{
		*result=*dest;
		result++;
		dest++;
		a++;
	}while(*dest!='\0');
#endif	
	do{
		*result=*src;
		result++;
		src++;
		a++;
	}while(*src!='\0');
	
	*result='\0';
	
	while(a>0)
	{
		result--;
		a--;
	};
	//return result;
}

int main()
{
	char a[20],b[20],*p;
	scanf("%s %s",a,b);
	my_strcat (a, b);
	//p=my_strcat (a, b);
	printf("%s\n",a);
	//printf("%s\n",p);
	return 0;
}
