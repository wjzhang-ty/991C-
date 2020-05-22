/*
	合并链表X和链表Y为（x1,y1,x2,y2....xn）
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}LNode, * LinkList;

LinkList INITLIST(int len);
void PRINTLIST(LinkList list);
LinkList MERGELIST(LinkList X, LinkList Y);

int main()
{
	LinkList X, Y, XY;
	X = INITLIST(2);
	Y = INITLIST(1);
	printf("X is: ");
	PRINTLIST(X);
	printf("Y is: ");
	PRINTLIST(Y);
	XY = MERGELIST(X, Y);
	printf("X+Y is: ");
	PRINTLIST(XY);
}

LinkList INITLIST(int len) {
	LinkList temp, lastnode, list = (LinkList)malloc(sizeof(LNode));
	list->data = rand() % 30;
	list->next = NULL;
	lastnode = list;
	for (int i = 1; i < len; i++) {
		temp = (LinkList)malloc(sizeof(LNode));
		temp->data= rand() % 30;
		temp->next = lastnode->next;
		lastnode->next = temp;
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

/*
	head 指向头用来返回
	temp 用做修改结点next时的缓存
	X 是链表的右侧
	Y 被整合对象
*/
LinkList MERGELIST(LinkList X, LinkList Y) {
	LinkList temp,head = X;
	while (X!=NULL && Y!=NULL) // 任一结点为空结束循环
	{
		temp = Y;	// 缓存Y的值，否则稍后找不到Y的next了
		Y = Y->next; // Y后移
		temp->next = X->next; 
		X->next = temp;
		/* 
			此时 |x1| -> y1 -> x2  需要将|i|移动到x2处
			但是x1可能是末尾所以需要判断
		*/
		if (X->next->next == NULL) {
			// 为空 需要将末尾结点指向剩余Y。结束循环、防止成环
			X = X->next;
			X->next = Y;
			break;
		}
		else { // 不空 后移
			X = X->next->next;
		}
	}
	return head;
}