#include <stdio.h> 

char *my_strcat(char *dest,const char *src)
{
	unsigned int a=0;
	char *result;
	result=dest;
	
	do{
		result++;
		a++;
	}while(*result!='\0');
	
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
	return result;
}

int main()
{
	char a[20],b[20];
	scanf("%s %s",a,b);
	my_strcat (a, b);
	printf("%s\n",a);
	return 0;
}
