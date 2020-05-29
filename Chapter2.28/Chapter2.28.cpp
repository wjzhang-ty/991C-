/*
    已知不带头结点的双向循环链表第一个节点指针为list
    写一算法：判断该链表是否为对称链表。是 返回1，否 返回0
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* pre;
    struct node* next;
}LNode,*LinkList;

LinkList InitList(); // 生成双向循环链表
void PrintfList(LinkList list); // 打印
int IsSymmetry(LinkList list); // 是否对称


int main()
{
    LinkList list;
    list = InitList();
    PrintfList(list);
    printf("检查对称结果：%d", IsSymmetry(list));
}

// 两端向中间开始遍历
int IsSymmetry(LinkList list) {
    LinkList head = list, last = list->pre;
    while (head != last)
    {
        if (head->data != last->data) {
            return 0;
        }
        head = head->next;
        last = last->pre;
    }
    return 1;
}

// 初始化注意点，写错了贼坑
LinkList InitList() {
    int arr[11] = { 1,2,3,4,5,6,5,4,3,2,1 };
    LinkList temp, lastnode, list = (LinkList)malloc(sizeof(LNode));
    list->data = arr[0];
    list->next = NULL;
    list->pre = NULL;
    lastnode = list;
    for (int i = 1; i < sizeof(arr)/sizeof(int); i++)
    {
        temp = (LinkList)malloc(sizeof(LNode));
        temp->data = arr[i];
        temp->next = lastnode->next;
        temp->pre = lastnode;
        lastnode->next = temp;
        lastnode = temp;
    }
    lastnode->next = list;
    list->pre = lastnode;
    return list;
}

void PrintfList(LinkList list) {
    LinkList lastnode=list;
    do
    {
        printf("%d ", lastnode->data);
        lastnode = lastnode->next;
    } while (lastnode != list);
    printf("\n");
}