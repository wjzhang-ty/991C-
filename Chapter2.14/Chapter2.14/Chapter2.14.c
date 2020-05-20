/*
	已知链表第一个节点指针为list
	请写一算法，判断该链表是否有序？是1 否0
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
	int data;
	struct node* next;
}LNode,*LinkList;

LinkList INITLIST(int len); // 初始化
void PRINTLIST(LinkList list); // 打印
int CHECKSORT(LinkList list); // 检查排序

int main()
{
	LinkList list;
	list = INITLIST(10);
	PRINTLIST(list);
	printf("是否有序：%d", CHECKSORT(list));

}

LinkList INITLIST(int len) {
	int arr[10] = { 1,1,1,1,1,1,1,1,1,1 };
	LinkList temp, lastnode, list = (LinkList)malloc(sizeof(LNode));
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

/*
	判断条件 |count| == len?
	左右不等
		count 对比增减
		len	循环就要自增
	左右相等
		count和len都不增减
*/
int CHECKSORT(LinkList list) {
	int count=0, len=0;
	while (list->next!=NULL)
	{
		if (list->data > list->next->data) {
			count++;
		}
		else if (list->data == list->next->data) {
			len--; // 先减后增
		}
		else {
			count--;
		}
		len++;
		list = list->next;
		if (abs(count) != len) {
			return 0;
		}
	}
	return 1;
}