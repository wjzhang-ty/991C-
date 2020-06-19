/*
    已知二叉树采用二叉链表存储结构
    写一算法，打印该二叉树所有左子树的根节点的数据信息
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

TLinkList CreateTree(int arr[], int index, int len); // 创建二叉树
void LRD(TLinkList tree);
void PrintLeft(TLinkList tree);

int main()
{
    TLinkList tree;
    int arr[] = { 1,2,3,4,5,6,7,8,9,10,0,12,0,0,15 };
    tree = CreateTree(arr, 0, sizeof(arr) / sizeof(int));
    LRD(tree);
    printf("\n");
    PrintLeft(tree);
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
        while (tree!=NULL)
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

    } while (!(top<0&&tree==NULL));
}

void PrintLeft(TLinkList tree) {
    SLinkList temp , top = NULL;
    int f = 0;
    if (tree == NULL) return;
    do
    {
        while (tree!=NULL)
        {
            if(f) printf("%d ", tree->data);
            temp = (SLinkList)malloc(sizeof(SNode));
            temp->data = tree;
            temp->next = top;
            top = temp;
            tree = tree->left;
            f = 1;
        }
        tree = top->data->right;
        f = 0;
        temp = top;
        top = top->next;
        free(temp);
    } while (!(top==NULL&&tree==NULL));
}