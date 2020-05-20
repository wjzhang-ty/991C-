/*
	线性链表第一个节点存贮地址为list。
	请写一算法把链表中数据值为d的所有节点的数据域值修改为item
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 单链表结构
typedef struct node {
	char data[10];
	struct node* next;
}LNode, * LinkList;

LinkList CREATELINK(int len); // 创建带头节点链表
void PRINTLIST(LinkList list); // 打印
void UPDATALIST(LinkList list); // 修改


char str[][4] = {{'a','b','c'},{'c'},{'d','a','t','a'}}; // ["",""]有bug

int main()
{
	LinkList list;
	list = CREATELINK(10);
	PRINTLIST(list);
	UPDATALIST(list);
	PRINTLIST(list);
}

LinkList CREATELINK(int len){
  // 定义三个节点：缓存节点，末尾节点（新增用），头节点（返回此节点）
	LinkList  temp, lastnode, list = (LinkList)malloc(sizeof(LNode));
	list->next=NULL; // 第一个节点废掉他，循环简单点
	lastnode = list; // 首尾相同
	for (int i = 1; i <= len; i++) {
		temp = (LinkList)malloc(sizeof(LNode));
		strcpy(temp->data,str[rand()%3]);
		temp->next = lastnode->next;
		lastnode->next = temp;
		lastnode = temp; // lastnode指向最后一个节点
	}
	return list;
}

void PRINTLIST(LinkList list){
    while(list!=NULL){
        printf("%s ",list->data);
        list=list->next;
    }  
    printf("\n");
}

// 修改指定值,链表本身用地址来连接无需用地址变量接参
void UPDATALIST(LinkList list){
    while(list->next!=NULL){
        if(!strcmp(list->data, "data")){ // 比较，同0异1
            strcpy(list->data,"item"); // 左值=右值
        }
        list=list->next;
    }  
    
}