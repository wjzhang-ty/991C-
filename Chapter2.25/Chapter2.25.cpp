/*
    数据结构为(a1,e1)，通过scanf输入，生成有序链表
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a, e;
    struct node* next;
}LNode,*LinkList;

LinkList GenerateList(); // 生成链表
void PrintList(LinkList list); // 打印

int main()
{
    LinkList list;
    list = GenerateList();
    PrintList(list);
}

/*
    循环以前先创建一个空结点
    依照scanf是否成功为判断条件，scanf直接把值传给最后位置的空结点
    循环体内创建一个空结点接在链表末尾
    这样可以避免对首结点分类讨论
*/
LinkList GenerateList() {
    LinkList lastnode, list = (LinkList)malloc(sizeof(LNode)),temp;
    lastnode = list;
    while (scanf("%d%d",&lastnode->a,&lastnode->e)>0)
    {
        temp = (LinkList)malloc(sizeof(LNode));
        lastnode->next = temp;
        lastnode = lastnode->next;
    }
    lastnode->next = NULL;
    return list;
}

void PrintList(LinkList list) {
    while (list!=NULL)
    {
        printf("a:%d e:%d -> ", list->a, list->e);
        list = list->next;
    }
    printf("\n");
}