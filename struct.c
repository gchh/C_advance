/*
#include <stdio.h>
int main()
{
 struct test{
  char a;
  char b;
  char c;
 }t;
 printf("%d\n",sizeof(t.a));
 printf("%d\n",sizeof(t.b));
 printf("%d\n",sizeof(t.c));
 printf("%d\n",sizeof(t));
 
 printf("%d\n",&t.a);
 printf("%d\n",&t.b);
 printf("%d\n",&t.c);
 return 0;
}
1
1
1
3
6487616
6487617
6487618
--------------------------------
Process exited after 0.01734 seconds with return value 0
请按任意键继续. . .
#include <stdio.h>
int main()
{
 struct test{
  char a;
  int b;
  double c;
 }t;
 printf("%d\n",sizeof(t.a));
 printf("%d\n",sizeof(t.b));
 printf("%d\n",sizeof(t.c));
 printf("%d\n",sizeof(t));
 
 printf("%d\n",&t.a);
 printf("%d\n",&t.b);
 printf("%d\n",&t.c);
 return 0;
}
1
4
8
16
6487616
6487620
6487624
--------------------------------
Process exited after 0.007051 seconds with return value 0
请按任意键继续. . .
*/
#include <stdio.h>

int main()
{
	struct test{
		char a;
		int b;
		double c;
	}t;
	printf("%d\n",sizeof(t.a));
	printf("%d\n",sizeof(t.b));
	printf("%d\n",sizeof(t.c));
	printf("%d\n",sizeof(t));
	
	printf("%d\n",&t.a);
	printf("%d\n",&t.b);
	printf("%d\n",&t.c);
	return 0;
}
