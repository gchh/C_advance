/*
��Ŀ���ݣ�
��ĳ�������һϵ�е���������Ԥ�Ȳ�֪����������������һ������-1���ͱ�ʾ���������Ȼ�󣬰��պ������෴��˳����������������֣�����������ʶ������-1��

�����ʽ:
һϵ��������������-1��ʾ������-1������������ݵ�һ���֡�

�����ʽ��
�����������෴��˳��������е�������ÿ�����������һ���ո����������������֣�������������Ҳ�пո�

����������
1 2 3 4 -1

���������
4 3 2 1
ʱ�����ƣ�2000ms�ڴ����ƣ�128000kb
*/ 
#include<stdio.h>
#include <stdlib.h>
struct node {
    unsigned int num;			/* ��������� */
    struct node *next;
};
/*������������*/
struct node *createList(void) {
    struct node *head = NULL, *p, *q, *t;
    int num;
    unsigned int size = sizeof(struct node);
    scanf("%d", &num);
    while(num != -1) {
        t = (struct node *)malloc(size);    /* �����½�� */
        t->num = num;
        t->next = head;
        head = t;
        scanf("%d", &num);
    }
	return head;
}
/*�����������*/
void printList(struct node *head) {
    struct node *p = head;
    if(p != NULL) {
    	for(; p->next != NULL; p = p->next)
        	printf("%u ", p->num);
    	printf("%u\n", p->num);
	}
}
int main(void) {
    struct node *head = NULL;
    head = createList();
    printList(head);
    return 0;
}
