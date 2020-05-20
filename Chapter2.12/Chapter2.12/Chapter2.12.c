/*
    已知非空链表第一个节点的存储地址为list
    请写出删除链表中第i（包含）个开始的n条数据
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}LNode,*LinkList;

LinkList INITLIST(int len); // 初始化链表（无头）
void PRINTLIST(LinkList list); // 打印
LinkList DELRANGE(LinkList list, int start, int end); // 删除指定范围节点

int main()
{
    LinkList list;
    list = INITLIST(10);
    PRINTLIST(list);
    list = DELRANGE(list, 1, 2);
    PRINTLIST(list);
    
}

LinkList INITLIST(int len) {
    LinkList lastnode, temp, list = (LinkList)malloc(sizeof(LNode));
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

// 两种情况，是否从第一个开始
LinkList DELRANGE(LinkList list, int start, int end) {
    LinkList head, firstend=list, temp2;
    if (start <= 1) {
        for (int i = end; i >0; i--)
        {
            temp2 = list;
            list = list->next;
            free(temp2);

        }
    }
    else{
        // 例：删除第二项 需要操作第一项（下标0）的next
        for (int i= start; i - 2 > 0; i--) {
            firstend = firstend->next;
        }
        for (int j=end;j > 0; j--) {
            temp2 = firstend->next;
            if (temp2==NULL) { // 长度超限提前终止
                firstend->next = NULL;
                break;
            }
            firstend->next = temp2->next;
            free(temp2);
        }
    }
    return list;
}