/*
    请写一算法，依次输出通过键盘输入一组整形数据中的最后k个元素
    ctrl+z结束，假设k<=输入的数据元素个数。
    限制：算法中不允许使用数组，不允许有计算输入数据个数的过程
*/

// 注：ctrl+z是终止当前语句（会使scanf输入失败）
// int scanf()返回值为录入成功的数量，没有成功为0
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>;
#include <stdlib.h>;

typedef struct node {
    int data;
    struct node* next;
}LNode,*LinkList;

LinkList InitList(int len); // 生成循环链表
void PrintList(LinkList list,int len); // 打印
LinkList ScanfList(LinkList list,int len); // 循环输入


int main()
{
    int list, len = 4;
    list = InitList(len);
    PrintList(list,len);
    list = ScanfList(list,len);
    PrintList(list, len);
}

// 长度为k的循环链表只能保存最后k个元素
LinkList InitList(int len) {
    LinkList temp, lastnode, list = (LinkList)malloc(sizeof(LNode));
    lastnode = list;
    lastnode->data = 100;
    while (--len) // 快速判断：while(4--) 循环4次 
    {
        temp = (LinkList)malloc(sizeof(LNode));
        temp->next = temp;
        temp->data = len;
        lastnode->next = temp;
        lastnode = lastnode->next;
    }
    lastnode->next = list; // 将末尾指回头
    return list;
}

void PrintList(LinkList list,int len) {
    while (list!=NULL&&len--)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

// 因为要有序，所以第一轮存完后头节点也要跟着后移
LinkList ScanfList(LinkList list,int len) {
    LinkList head = list;
    while (scanf("%d", &list->data)>0) {
        list = list->next;

        if ((--len)<0) { // 第二轮开始时，head跟着后移
            head = head->next;
        }
    }
    return head;
}