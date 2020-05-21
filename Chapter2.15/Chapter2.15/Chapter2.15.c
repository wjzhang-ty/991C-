/*
	已知链表第一个节点指针为list
	请写一算法，交换p所指节点与其下一个节点的位置（p不是最后一个节点）
*/

typedef struct node {
	int data;
	struct node* next;
}LNode,*LinkList;

void INITLIST(LinkList* list, int len); // 初始化
void PRINTLIST(LinkList list); // 打印
void EXCHANGELIST(LinkList* list, int index); // 交换第index项和后一项


#include <stdio.h>
#include <stdlib.h>

int main()
{
	LinkList list = (LinkList)malloc(sizeof(LNode));
	INITLIST(&list,10);
	PRINTLIST(list);
	EXCHANGELIST(&list, 3);
	PRINTLIST(list);
}

void INITLIST(LinkList* list, int len) {
	LinkList lastnode,temp;
	(*list)->data = 0;
	(*list)->next = NULL;
	lastnode = (*list);
	for (int i = 1; i < len; i++) {
		temp = (LinkList)malloc(sizeof(LNode));
		temp->data = i;
		temp->next = lastnode->next;
		lastnode->next = temp;
		lastnode = temp;
	}
}

void PRINTLIST(LinkList list) {
	while (list!=NULL)
	{
		printf("%d ", list->data);
		list = list->next;
	}
	printf("\n");
}

void EXCHANGELIST(LinkList* list, int index) {
	LinkList temp = (LinkList)malloc(sizeof(LNode)),curlist;
	if (index <= 1) {
		temp = (*list);
		(*list) = temp->next;
		temp->next = temp->next->next;
		(*list)->next = temp;
	}
	else {
		curlist = (LinkList)malloc(sizeof(LNode));
		curlist = (*list);
		while (index-->1)
		{
			curlist = curlist->next;
		}
		temp = curlist->next; // 此项暂存，先处理其他的
		curlist->next = temp->next;
		temp->next = curlist->next->next;
		curlist->next->next = temp;
	}
}