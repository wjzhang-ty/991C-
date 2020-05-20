/*
    已知线性表第一个结点指针为list
    请写一算法，删除最大值
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}LNode, *LinkList;

LinkList INITLIST(int len); // 初始化
void PRINTLIST(LinkList list); // 打印
void DELMAX(LinkList* list); // 删除最大值


int main()
{
    LinkList list;
    list = INITLIST(10);
    PRINTLIST(list);
    DELMAX(&list);
    PRINTLIST(list);
}

LinkList INITLIST(int len) {
    LinkList temp, lastnode, list = (LinkList)malloc(sizeof(LNode));
    list->data = 0;
    list->next = NULL;
    lastnode = list;
    for (int i = 1; i < len; i++) {
        temp = (LinkList)malloc(sizeof(LNode));
        temp->data = i;
        temp->next = lastnode->next;
        lastnode->next = temp;
        lastnode = temp;
    }
    return list;
}

void PRINTLIST(LinkList list) {
    while (list!=NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

void DELMAX(LinkList* list) {
    LinkList* max = list,* forList = list,temp;
    int i = 0;
    while ((*forList)->next!=NULL) // *优先级低于->
    {
        if ((*forList)->next->data > (*max)->data) {
            i++;
            max = forList;
        }
        forList = &(*forList)->next;
    }
    if(i==0){
        list = (*list)->next;
        free(max);
    }
    else {
        temp = (*max)->next;
        (*max)->next = temp->next;
        free(temp);
    }
}