#include <stdio.h>

enum color {red,yellow,green}; 

void f(enum color c);

int main()
{
	enum color t=red;
	f(red);
	scanf("%d",&t);
	f(t);
	f(red);
	return 0;
}

void f(enum color c)
{
	printf("%d\n",c);
}
