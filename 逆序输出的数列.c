/*
题目内容：
你的程序会读入一系列的正整数，预先不知道正整数的数量，一旦读到-1，就表示输入结束。然后，按照和输入相反的顺序输出所读到的数字，不包括最后标识结束的-1。

输入格式:
一系列正整数，输入-1表示结束，-1不是输入的数据的一部分。

输出格式：
按照与输入相反的顺序输出所有的整数，每个整数后面跟一个空格以与后面的整数区分，最后的整数后面也有空格。

输入样例：
1 2 3 4 -1

输出样例：
4 3 2 1
时间限制：2000ms内存限制：128000kb
*/ 
#include<stdio.h>
#include <stdlib.h>
struct node {
    unsigned int num;			/* 存放正整数 */
    struct node *next;
};
/*建立单向链表*/
struct node *createList(void) {
    struct node *head = NULL, *p, *q, *t;
    int num;
    unsigned int size = sizeof(struct node);
    scanf("%d", &num);
    while(num != -1) {
        t = (struct node *)malloc(size);    /* 建立新结点 */
        t->num = num;
        t->next = head;
        head = t;
        scanf("%d", &num);
    }
	return head;
}
/*输出单向链表*/
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
