/*
	线性链表第一个节点存贮地址为list。 p72/348
	请写一算法把链表中数据值为d的所有节点的数据域值修改为item
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkList CREATELINK(int len); // 创建链表

// 单链表结构
typedef struct node {
	int data;
	struct node* next;
}LNode, * LinkList;

int main()
{
	CREATELINK(10);
}

LinkList CREATELINK(int len){
	LinkList list = NULL, r, temp;
	for (int i = 1; i <= len; i++) {
		temp = (LinkList)malloc(sizeof(LNode));
		temp->data =i;
		temp->next = NULL;
		if (list == NULL) {
			list = temp;
		}
		else {
			r->next = temp;
		}
		r = temp;
	}

	return list;

}
