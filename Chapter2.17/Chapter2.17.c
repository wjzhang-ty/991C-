/*
	请写一算法找到倒数k个节点，若有返回地址，若无返回NULL
	限制：不得求出链表长度，不允许使用指针变量和控制变量以外的辅助空间
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}LNode,*LinkList;

LinkList INITLIST(int len);
void PRINTLIST(LinkList list);
LinkList FINDK(LinkList list,int k);

int main()
{
	LinkList list,k;
	list = INITLIST(10);
	PRINTLIST(list);
	k = FINDK(list,10);
	if (k != NULL) {
		printf("k is %d", k->data);
	}
	else {
		printf("超长了");
	}
}

LinkList INITLIST(int len) {
	LinkList temp, lastnode, list = (LinkList)malloc(sizeof(LNode));
	list->data = 0;
	list->next = NULL;
	lastnode = list;
	for ( int i = 1; i < len; i++)
	{
		temp = (LinkList)malloc(sizeof(LNode));
		temp->data = i;
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
	1、构建一个长度为n的子链
		index为左结点，list为右结点
		在此期间有null说明长度不够
	2、构建完成之后判断list是否为末尾结点
		如果不是，左右结点后移
*/
LinkList FINDK(LinkList list, int k) {
	LinkList index = list;
	for (; k > 0; k--) {
		if (list == NULL) {
			return NULL;
		}
		if (k == 1 && list->next != NULL) {
			k++;
			index = index->next;
		}
		list = list->next; // 先判断后位移
	}
	return index;
}