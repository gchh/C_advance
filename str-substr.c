/*
��Ŀ���ݣ�
����2���ַ���S1��S2��Ҫ��ɾ���ַ���S1�г��ֵ������Ӵ�S2��������ַ����в��ܰ���S2��
��ʾ���������ݵ����ʹ�ò����ܳ������Ϊ�յ������

�����ʽ:
����ֱ����2��ÿ��������80���ַ����ȵĲ����ո�ķǿ��ַ�������ӦS1��S2��

�����ʽ��
��һ�������ɾ���ַ���S1�г��ֵ������Ӵ�S2��Ľ���ַ�����

����������
Thisisatest is

���������
Thatest
*/ 
#include <stdio.h> 
#include <string.h>

int main()
{
	char a[81],b[81],c[81];
	char *p;
	scanf("%s %s",a,b);//������Thisisatest is����a="Thisisatest"��b="is" 
	while((p=strstr(a,b)) != NULL)//strstr �Ҳ������� NULL��*p="isisatest" 
	{
		*p = '\0';//ָ��������һ�������Ӻ�����֮ǰ a ����ֹλ�ã�*p="\0sisatest"����Ϊ�ַ�������\0����������a="Th" 
		strcpy (c, p+strlen(b));//strcat �����е���������������ڴ��ַ�����ص������������� c ���� temp��c="isatest" 
		strcat (a, c);//a="Thisatest"
	}
	printf("%s\n",a);
	return 0;
}
