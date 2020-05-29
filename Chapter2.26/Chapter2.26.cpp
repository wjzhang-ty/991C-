/*
    已知不带头节点的双向链表第一个结点指针为list,结点中有数据域、前驱、后驱、访问频度（初始值为0）
    设计一个算法，将指定数据域的频度+1，并保证链表的有序递减
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    int freq;
    struct node* pre;
    struct node* next;
}LNode,*LinkList;

LinkList InitList(int len); // 生成双向链表
void PrintList(LinkList list); // 打印
LinkList IncreaseList(LinkList list,int k); // 频度递增 排序

int main()
{
    LinkList list;
    int loop = 5;
    list = InitList(7);
    PrintList(list);
    while (loop--)
    {
        list = IncreaseList(list, rand() % 7);
    }
    PrintList(list);
}

/* 
    答案的解法思路更好，个人感觉差不多太多
    简述：向后遍历找到匹配项位置，再往前遍历找到插入位置
*/
LinkList IncreaseList(LinkList list, int k) {
    LinkList lastnode = list,freqnode = list;
    
    // 循环找到此项
    while (lastnode->data!=k)
    {
        if (lastnode->next == NULL) {
            printf("查无此项");
            return list;
        }
        lastnode = lastnode->next;
    }

    // 前驱连接后驱
    lastnode->freq++;
    lastnode->pre->next = lastnode->next;
    // 如果lasnode不是末尾结点才可以给下一结点设置前驱
    if (lastnode->next != NULL) {
        lastnode->next->pre = lastnode->pre;
    }

    // 找到插入位置
    while (freqnode->freq>lastnode->freq)
    {
        freqnode = freqnode->next;
    }
    // 如果要插入首结点
    if (freqnode->pre == NULL) {
        lastnode->pre = NULL;
        lastnode->next = freqnode;
        freqnode->pre = lastnode;
        list = lastnode;
    }
    else {
        freqnode->pre->next = lastnode;
        lastnode->pre = freqnode->pre;
        lastnode->next = freqnode;
        freqnode->pre = lastnode;
    }
    return list;
}

LinkList InitList(int len) {
    LinkList lastnode, temp, list = (LinkList)malloc(sizeof(LNode));
    list->data = 0;
    list->freq = 0;
    list->next = NULL;
    list->pre = NULL;
    lastnode = list;
    for (int i = 1; i < len; i++)
    {
        temp = (LinkList)malloc(sizeof(LNode));
        temp->freq = 0;
        temp->data = i;
        temp->pre = lastnode;
        temp->next = lastnode->next;
        lastnode->next = temp;
        lastnode = temp;
    }
    return list;
}

void PrintList(LinkList list) {
    while (list!=NULL)
    {
        printf("%d_%d ", list->data,list->freq);
        list = list->next;
    }
    printf("\n");
}