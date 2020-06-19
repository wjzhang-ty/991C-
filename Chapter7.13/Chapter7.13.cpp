/*
    已知二叉树采用二叉链表存储结构
    写一算法，求p所指节点的双亲节点的递归算法
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left, * right;
}TNode, * TLinkList;

TLinkList CreateTree(int arr[], int index, int len); // 创建二叉树
void LRD(TLinkList tree);
TLinkList FindParent(TLinkList tree, TLinkList p);

int main()
{
    TLinkList tree, p;
    int arr[] = { 1,2,3,4,5,6,7,8,9,10,0,12,0,0,15 };
    tree = CreateTree(arr, 0, sizeof(arr) / sizeof(int));
    LRD(tree);
    p = tree->right;

    p = FindParent(tree, p);
    printf("\n双亲（父）结点为：%d", p->data);
}

TLinkList CreateTree(int arr[], int index, int len) {
    TLinkList temp;
    if (index >= len || arr[index] == 0)return NULL;
    temp = (TLinkList)malloc(sizeof(TNode));
    temp->data = arr[index];
    temp->left = CreateTree(arr, 2 * index + 1, len);
    temp->right = CreateTree(arr, 2 * index + 2, len);
    return temp;
}

void LRD(TLinkList tree) {
    TLinkList temp1[20];
    int temp2[20], f, top = -1;
    do
    {
        while (tree != NULL)
        {
            temp1[++top] = tree;
            temp2[top] = 0;
            tree = tree->left;
        }
        tree = temp1[top];
        f = temp2[top--];
        if (f) tree = NULL;
        else {
            printf("%d ", tree->data);
            temp1[++top] = tree;
            temp2[top] = 1;
            tree = tree->right;
        }

    } while (!(top < 0 && tree == NULL));
}

TLinkList FindParent(TLinkList tree, TLinkList p) {
    TLinkList temp;
    if (tree == NULL) return NULL;
    if (tree->left == p || tree->right == p) return tree;
    temp = FindParent(tree->left, p);
    if (temp != NULL) return temp;
    return FindParent(tree->right, p);
}