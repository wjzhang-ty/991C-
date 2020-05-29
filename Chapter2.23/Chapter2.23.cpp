/*
    转置带头结点的循环链表
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}LNode,*LinkList;

LinkList InitList(int len); // 初始化
void PrintList(LinkList list); // 打印
void TransList(LinkList list); // 转置

int main()
{
    int len = 7;
    LinkList list;
    list = InitList(len);
    PrintList(list);
    TransList(list);
    PrintList(list);
}

LinkList InitList(int len) {
    LinkList lastnode, temp, list = (LinkList)malloc(sizeof(LNode));
    list->data = len;
    list->next = NULL;
    lastnode = list;
    while (len--)
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
void PrintList(LinkList list) {
    LinkList head = list;
    list = list->next;
    printf("总计：%d个：", head->data);
    while (list!=head)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

/*
    左中右三个变量
    换左中，利用右位移
*/
void TransList(LinkList list) {
    LinkList left=list, middle=list->next, right;
    while (middle!=list)
    {
        right = middle->next;   // L --> M -> R  --> ...
        middle->next = left;    // L <-> M    R  --> ...
        left = middle;          // ..<-- LM   R  --> ...
        middle = right;         // ..<-- L    MR --> ...
        right = right->next;    // ..<-- L    M  --> R --> ...
    }
    list->next = left;
}