/*
	已知非空线性链表第一个节点由list指出
	请写一算法，将链表中数据域值最小的节点移动到最前面
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}LNode,*LinkList;

LinkList INITLIST(int len);
void PRINTLIST(LinkList list);
LinkList MOVEMIN(LinkList list);


int main()
{
	LinkList list;
	list = INITLIST(10);
	PRINTLIST(list);
	list = MOVEMIN(list);
	PRINTLIST(list);
}

LinkList INITLIST(int len) {
	int arr[10] = {9,5,3,4,6,7,8,1,2,0};
	LinkList lastnode, temp, list = (LinkList)malloc(sizeof(LNode));
	list->data = arr[0];
	list->next = NULL;
	lastnode = list;
	for (int i = 1; i < len; i++) {
		temp = (LinkList)malloc(sizeof(LNode));
		temp->data = arr[i];
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

LinkList MOVEMIN(LinkList list) {
	LinkList head = (LinkList)malloc(sizeof(LNode)), minNode,temp;
	// 先给他加个头节点，后面就不用分类讨论了
	head->data = list->data;
	head->next = list;
	minNode = head; // 最小项的前一项

	// 找到最小值
	while (list->next!=NULL)
	{
		if (list->next->data < minNode->next->data) {
			minNode = list; // 保存最小值的位置
			head->data = list->next->data; // 修改第一个节点的值
		}
		list = list->next;
	}

	// 删除
	temp = minNode->next;
	minNode->next = minNode->next->next;
	free(temp);

	return head;
}