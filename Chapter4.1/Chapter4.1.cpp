/*
    使用链接栈（非递归算法），输入任意10进制数字，打印出对应的r([2,9])进制整数
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}LNode, * LinkList;

void Change(int num, int r, LinkList list); // 转换打印

int main()
{
    LinkList list = (LinkList)malloc(sizeof(LNode));
    list->data = 0;
    list->next = NULL;

    int num, r;
    printf("\n请输入一个十进制整数：");
    scanf("%d", &num);
    printf("\n请输入将要转换的进制：");
    scanf("%d", &r);

    Change(num, r, list);
}

/*
    1、带有头节点，头结点中存放长度。数据从下标1处开始
    2、取余转置为最终结果，所以先算后进，后算先进
        将lastnode当最末尾结点，循环向前插入
*/
void Change(int num, int r, LinkList list) {
    LinkList temp, lastnode = NULL, head;
    while (num)
    {
        temp = (LinkList)malloc(sizeof(LNode));
        temp->data = num % r;
        temp->next = lastnode;
        //lastnode->next = temp;
        lastnode = temp;
        list->data++;
        list->next = lastnode;
        num /= r;
    }
    head = list->next;
    if (head == NULL) return;
    printf("转换结果：");
    for (int i = 1; i <= list->data; i++)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");

}