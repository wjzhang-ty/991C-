/*
	带有头节点的双向循环链表中头结点的指针为list
	请写一算法：删除并释放数据域内容为x的所有结点
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* pre;
	struct node* next;
}LNode,*LinkList;

LinkList InitList(int len); // 生成双向循环链表
void PrintList(LinkList list); // 打印
void DelList(LinkList list,int k); // 删除指定结点


int main()
{
	int len = 7;
	LinkList list;
	list = InitList(len);
	PrintList(list);
	DelList(list, rand() % 6);
	PrintList(list);
}

void DelList(LinkList list, int k) {
	LinkList lastnode = list->next,temp;
	while (lastnode!=list)
	{
		if (k == lastnode->data) {
			temp = lastnode;
			lastnode->pre->next = lastnode->next;
			lastnode->next->pre = lastnode->pre;
			lastnode = temp->pre;
			free(temp);
			list->data--;
		}
		lastnode = lastnode->next;
	}
}

LinkList InitList(int len) {
	LinkList lastnode, temp, list = (LinkList)malloc(sizeof(LNode));
	list->data = 0;
	list->pre = NULL;
	list->next = NULL;
	lastnode = list;
	for (size_t i = 0; i < len; i++)
	{
		temp = (LinkList)malloc(sizeof(LNode));
		temp->data = i;
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
void PrintList(LinkList list) {
	LinkList lastnode = list;
	printf("%d_ ", lastnode->data);
	lastnode = lastnode->next;
	while (lastnode!=list)
	{
		printf("%d ", lastnode->data);
		lastnode = lastnode->next;
	}
	printf("\n");
}
