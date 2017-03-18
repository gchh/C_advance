/*
题目内容：
输入2个字符串S1和S2，要求删除字符串S1中出现的所有子串S2，即结果字符串中不能包含S2。
提示：输入数据的设计使得不可能出现输出为空的情况。

输入格式:
输入分别给出2个每个不超过80个字符长度的不带空格的非空字符串，对应S1和S2。

输出格式：
在一行中输出删除字符串S1中出现的所有子串S2后的结果字符串。

输入样例：
Thisisatest is

输出样例：
Thatest
*/ 
#include <stdio.h> 
#include <string.h>

int main()
{
	char a[81],b[81],c[81];
	char *p;
	scanf("%s %s",a,b);//如输入Thisisatest is，则a="Thisisatest"，b="is" 
	while((p=strstr(a,b)) != NULL)//strstr 找不到返回 NULL，*p="isisatest" 
	{
		*p = '\0';//指定连接下一步（连接函数）之前 a 的终止位置，*p="\0sisatest"，因为字符串遇到\0结束，所以a="Th" 
		strcpy (c, p+strlen(b));//strcat 函数中的两个传入参数的内存地址不能重叠，所以这里用 c 当作 temp，c="isatest" 
		strcat (a, c);//a="Thisatest"
	}
	printf("%s\n",a);
	return 0;
}
