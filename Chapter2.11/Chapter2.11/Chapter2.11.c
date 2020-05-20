/*
	已知非空链表第1个节点的指针为list
	请写出删除链表中从第i个结点的算法
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct  node* next;
}LNode,*LinkList;

LinkList CREATELINK(int len); // 创建带头节点链表
void PRINTLIST(LinkList list); // 打印
LinkList DELLIST(LinkList list, int i); // 删除

int main()
{
	LinkList list;
	list = CREATELINK(10);
	PRINTLIST(list);
	list=DELLIST(list, 1);
	PRINTLIST(list);
}

// 不带头节点的链表
LinkList CREATELINK(int len) {
	LinkList temp, lastnode, list=(LinkList)malloc(sizeof(LNode));
	list->next = NULL;
	lastnode = list;
	for (int i = 0; i < len; i++) {
		temp = (LinkList)malloc(sizeof(LNode));
		temp->data = i;
		temp->next = lastnode -> next;
		if (i==0) { // 如果是头节点
			list = temp;
			lastnode = list;
		}
		else {
			lastnode->next = temp;
		}
		lastnode = temp;
	}
	return list;
}

void PRINTLIST(LinkList list) {
	while (list!=NULL)
	{
		printf("%d ", list->data);
		list = list->next;
	}
	printf("\n");
}

LinkList DELLIST(LinkList list, int i) {
	LinkList left = (LinkList)malloc(sizeof(LNode)), right=list;
	if (i <= 1) {
		list = list->next;
	}
	else {
		for (int k = 1; k < i; k++) {
			left = right;
			right = right->next;
			if (right == NULL) {
				return -1;
			}
		}
		left->next = right->next;
	}
	free(right);
	return list;
}