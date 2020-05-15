/*
	线性链表第一个节点存贮地址为list。 p72/348
	请写一算法把链表中数据值为d的所有节点的数据域值修改为item
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 单链表结构
typedef struct node {
	int data;
	struct node* next;
}LNode, * LinkList;

LinkList CREATELINK(int len); // 创建链表

int main()
{
	CREATELINK(10);
}

LinkList CREATELINK(int len){
	LinkList  r, temp, list = NULL;
	for (int i = 1; i <= len; i++) {
		temp = (LinkList)malloc(sizeof(LNode));
		r = (LinkList)malloc(sizeof(LNode));
		temp->data = 1;
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
