/*
    链表第一个节点指针为list
    写一去重算法。
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
}LNode,*LinkList;

LinkList INITLIST(int len); // 初始化
void PRINTLIST(LinkList list); // 打印
LinkList Deduplication(LinkList list); // 去重
// 代码是给人看的，表示自己看不懂全大写，所以不再使用全大写名称。

int main()
{
    LinkList list;
    list = INITLIST(10);
    PRINTLIST(list);
    list = Deduplication(list);
    PRINTLIST(list);
}

LinkList INITLIST(int len) {
    int arr[10] = { 1,1,2,4,5,1,7,2,3,9 };
    LinkList lastnode, temp, list = (LinkList)malloc(sizeof(LNode));
    list->data = arr[0];
    list->next = NULL;
    lastnode = list;
    for (int i = 1; i < len; i++)
    {
        temp = (LinkList)malloc(sizeof(LNode));
        temp->data = arr[i];
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

/*
    冒泡遍历
    右结点指向前一个（删除2结点，需要修改1节点的next）
*/
LinkList Deduplication(LinkList list) {
    LinkList left, right, temp;
    left = list;
    while (left!=NULL)
    {
        right = left;
        while (right->next!=NULL)
        {
            if (right->next->data == left->data) {
                temp = right->next;
                right->next = temp->next;
                free(temp);
                right = right->next;
            }
            right = right->next;
        }
        left = left->next;
    }
    return list;
}