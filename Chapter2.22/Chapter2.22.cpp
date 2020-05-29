/*
    将不带头结点的单链表分解为两个循环链表，循环链表的头节点存放链表的长度
    分解规则：你一个我一个
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}LNode,*LinkList;

LinkList InitList(int len); // 初始化
void PrintList(LinkList list); // 打印
void SplitList(LinkList list, LinkList* cycle1, LinkList* cycle2); // 拆解

int main()
{
    LinkList list, cycle1, cycle2;
    list = InitList(7);
    PrintList(list);
    SplitList(list, &cycle1, &cycle2);
    printf("循环表1：（第一项为长度）");
    PrintList(cycle1);
    printf("循环表2：（第一项为长度）");
    PrintList(cycle2);
}

LinkList InitList(int len) {
    LinkList lastnode, temp, list = (LinkList)malloc(sizeof(LNode));
    list->data = 0;
    list->next = NULL;
    lastnode = list;
    for (int i = 1; i < len; i++)
    {
        temp = (LinkList)malloc(sizeof(LNode));
        temp->data = i;
        temp->next = lastnode->next;
        lastnode->next = temp;
        lastnode = temp;
    }
    return list;
}

void PrintList(LinkList list) {
    while (list!=NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

void SplitList(LinkList list, LinkList* cycle1, LinkList* cycle2) {
    (*cycle1) = (LinkList)malloc(sizeof(LNode));
    (*cycle2) = (LinkList)malloc(sizeof(LNode));
    // 指针变量写起来不方便，所以用c1 c2替代。c1 c2为头结点
    LinkList c1 = (*cycle1), c2 = (*cycle2),lastnode1,lastnode2;
    c1->data = 0;
    c1->next = NULL;
    lastnode1 = c1;
    c2->data = 0;
    c2->next = NULL;
    lastnode2 = c2;
    while (list!=NULL)
    {
        if (c2->data < c1->data) { // 一人一次
            c2->data++;
            lastnode2->next = list;
            lastnode2 = lastnode2->next;
        }
        else {
            c1->data++;
            lastnode1->next = list;
            lastnode1 = lastnode1->next;
        }
        list = list->next;
    }
    lastnode1->next = NULL; // list中倒数二项会指向倒数一项，在新的链表中需要手动设置一下倒数二项的next
    lastnode2->next = NULL;
}