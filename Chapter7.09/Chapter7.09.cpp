/*
    已知二叉树采用二叉链表存储结构，根节点的地址为T
    写出求P所直接点所在层次的递归算法
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left, * right;
}TNode, * TLinkList;

typedef struct snode {
    TLinkList data;
    struct snode* next;
}SNode, * SLinkList;

TLinkList CreateTree(int arr[], int index, int len); // 创建
void DLR(TLinkList tree); // 前序遍历
int WhichFloor(TLinkList tree, TLinkList p, int d); // 判断p在那层

int main()
{
    TLinkList tree,p;
    int arr[] = { 1,2,3,4,0,6,7,8,9,0,0,12,0,0,15 };
    tree = CreateTree(arr, 0, 15);
    DLR(tree);

    p = tree->left->left;

    printf("\n所在层%d：", WhichFloor(tree, p, 1));
}

TLinkList CreateTree(int arr[], int index, int len) {
    TLinkList temp;
    if (index >= len||arr[index]==0) return NULL;
    temp = (TLinkList)malloc(sizeof(TNode));
    temp->data = arr[index];
    temp->left = CreateTree(arr, 2 * index + 1, len);
    temp->right = CreateTree(arr, 2 * index + 2, len);
    return temp;
}
void DLR(TLinkList tree) {
    SLinkList top=NULL,temp;
    do
    {
        while (tree!=NULL)
        {
            printf("%d ", tree->data);
            temp = (SLinkList)malloc(sizeof(SNode));
            temp->data = tree;
            temp->next = top;
            top = temp;
            tree = tree->left;
        }
        tree = top->data->right;
        temp = top;
        top = top->next;
        free(temp);
    } while (!(top == NULL && tree == NULL));
}

/*
    不要考虑某一层，考虑某点->层
*/
int WhichFloor(TLinkList tree, TLinkList p, int d) {
    int floor;
    if (tree == NULL) return 0;
    if (p == tree) return d;
    floor = WhichFloor(tree->left, p, d + 1);
    if (floor > 0) return floor;
    floor = WhichFloor(tree->right, p, d + 1);
    return floor;
}