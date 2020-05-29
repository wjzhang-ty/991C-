/*
    通过键盘输入n个整数，建立一个带头结点的双向循环链表，然后反向输出
    写了无数遍了...
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* pre;
    struct node* next;
}LNode, * LinkList;

LinkList InitList(int len); // 生成双向循环链表
void PrintfList(LinkList list); // 打印

int main()
{
    LinkList list;
    list = InitList(7);
    PrintfList(list);
}

LinkList InitList(int len) {
	LinkList lastnode, temp, list = (LinkList)malloc(sizeof(LNode));
	list->data = 0;
	list->pre = NULL;
	list->next = NULL;
	lastnode = list;
	printf("输入%d个整数: ", len);
	for (size_t i = 0; i < len; i++)
	{
		temp = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &temp->data);
		temp->next = lastnode->next;
		temp->pre = lastnode;
		lastnode->next = temp;
		lastnode = temp;
		list->data++;
	}
	lastnode->next = list;
	list->pre = lastnode;
	return list;
}

void PrintfList(LinkList list) {
    LinkList lastnode = list;
    do
    {
        printf("%d ", lastnode->data);
        lastnode = lastnode->pre;
    } while (lastnode != list);
    printf("\n");
}