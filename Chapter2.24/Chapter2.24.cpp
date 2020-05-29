/*
    将循环链表（a1 a2 a3）改造为（a1 a2 a3 a2 a1）

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}LNode,*LinkList;

LinkList InitList(int len); // 初始化循环链表
void PrintList(LinkList list,int len); // 打印
void ExpendList(LinkList list); // 拓展

int main()
{
    LinkList list;
    int len = 7;
    list = InitList(len);
    PrintList(list,len);
    ExpendList(list);
    PrintList(list, len*3);

}

LinkList InitList(int len) {
    LinkList temp, lastnode, list = (LinkList)malloc(sizeof(LNode));
    list->data = 0;
    list->next = NULL;
    lastnode = list;
    for (int i = 1; i < len; i++)
    {
        temp = (LinkList)malloc(sizeof(LNode));
        temp->data = i;
        temp->next = list->next;
        lastnode->next = temp;
        lastnode = temp;
    }
    lastnode->next = list;
    return list;
}
void PrintList(LinkList list,int len) {
    while (len--)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

/*
    从头到尾遍历一下
    不改变原表的前提下，复制一个结点，依次指向头
    最后将原表的末尾指向拓展表的头
*/
void ExpendList(LinkList list) {
    LinkList last = list,tempL,tempR=list;
    while (last->next!=list) // 最后一个的next为头结束循环
    {
        tempL = (LinkList)malloc(sizeof(LNode));
        tempL->data = last->data;
        tempL->next = tempR;
        tempR = tempL; // 新表缓存向前移动
        last = last->next;
    }
    last->next = tempR;
}