/*
    带头结点的双向循环链表头节点指针为list，数据域为整数
    写一算法，正数在负数前即可。如果仅有头节点返回 0，否则返回 -1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* pre;
    struct node* next;
}LNode,*LinkList;

LinkList InitList(); // 初始化
void PrintList(LinkList list); // 打印
int SortList(LinkList list); // 换位置+判空

int main()
{
    LinkList list;
    list = InitList();
    PrintList(list);
    printf("排序成功：%d，结果过：", SortList(list));
    PrintList(list);
}

LinkList InitList() {
    int len = 10;
    LinkList lastnode, temp, list = (LinkList)malloc(sizeof(LNode));
    list->data = 0;
    list->pre = NULL;
    list->next = NULL;
    lastnode = list;
    while (len--)
    {
        temp = (LinkList)malloc(sizeof(LNode));
        temp->data = rand() % 30 - 15;
        temp->next = lastnode->next;
        temp->pre = lastnode;
        lastnode->next = temp;
        lastnode = temp;
        list->data++;
    }
    lastnode->next = list;
    list->pre = lastnode;
    return list;
}

void PrintList(LinkList list) {
    LinkList last = list;
    do
    {
        printf("%d ", last->data);
        last = last->next;
    } while (last!=list);
    printf("\n");
}

/*
    自己的构思差了一点火候，参考书中思路。
    前后向中间遍历，前找<0，后找>0。交换
        *问题！ 这种遍历方式终止条件只能有一个：两个结点指向同一位置
            因为两个移动不是同步进行，所以最外层条件是无法正确判断的
*/
int SortList(LinkList list) {
    int temp;
    LinkList head = list->next,last = list->pre;
    if (list->next == NULL) {
        return 0;
    }
    while (head!=last) // 无法正确判断
    {
        while (head->data>0) 
        {
            if (head == last) { // 在两个二级循环中检测，确保在正确的时间结束
                return 1;
            }
            head = head->next;
        }
        while (last->data<0)
        {
            if (head == last) {
                return 1;
            }
            last = last->pre;
        }
        temp = head->data; // 只换数据域，又不是随机存取，不影响你用
        head->data = last->data;
        last->data = temp;
    }
    return 1;
}