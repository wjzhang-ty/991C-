/*
    已知一个不带头节点也无头指针变量，并且长度大于1的循环链表
    请写一算法，删除p所指结点的直接前驱结点
*/

#include <stdio.h>;
#include <stdlib.h>;

typedef struct node{
    int data;
    struct node* next;
}LNode,*LinkList;

LinkList InitList(int len); // 生成循环链表
void PrintList(LinkList list, int len); // 打印
void DelPro(LinkList list); // 删除前驱结点

int main()
{
    LinkList list;
    int len = 4;
    list = InitList(len);
    PrintList(list, len);
    list = list->next;
    DelPro(list);
    PrintList(list, len-1);
}

LinkList InitList(int len) {
    LinkList lastnode, temp, list = (LinkList)malloc(sizeof(LNode));;
    list->data = len;
    list->next = NULL;
    lastnode = list;
    while (--len)
    {
        temp = (LinkList)malloc(sizeof(LNode));
        temp->data = len;
        temp->next = lastnode->next;
        lastnode->next = temp;
        lastnode = temp;
    }
    lastnode->next = list;
    return list;
}

void PrintList(LinkList list, int len) {
    while (len--)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

// 删除list结点
void DelPro(LinkList list) {
    LinkList left=list, right;
    right = left->next;
    while (right->next!=list)
    {
        left = left->next;
        right = right->next;
    }
    left->next = right->next;
    free(right);
}