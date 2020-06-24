/*
    节点的祖先定义为从根节点到该节点的所有分支上经过的结点
    已知非空二叉排序树采用二叉链表存储
    写一非递归算法，依次打印数据信息为item的节点的祖先结点
    设节点信息为整数，并假设祖先节点存在
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left, * right;
}TNode, * TLinkList;

TLinkList CreateTree(int arr[], int index, int len);
void DLR(TLinkList tree); // 前续非递归
void PrintParent(TLinkList tree, int item);

int main()
{
    TLinkList tree;
    //int arr[] = { 1,2,3,4,5,6,7,8,9,10,0,12,0,0,15 };
    int arr[] = { 20,15,25,10,18,22,27,0,0,17,0,0,0,0,30 };
    tree = CreateTree(arr, 0, sizeof(arr) / sizeof(int));
    DLR(tree);
    printf("\n");
    PrintParent(tree, 30);

}

TLinkList CreateTree(int arr[], int index, int len) {
    TLinkList tree;
    if (index >= len || arr[index] == 0) return NULL;
    tree = (TLinkList)malloc(sizeof(TNode));
    tree->data = arr[index];
    tree->left = CreateTree(arr, 2 * index + 1, len);
    tree->right = CreateTree(arr, 2 * index + 2, len);
    return tree;
}

// 前序遍历用线性栈实现
void DLR(TLinkList tree) {
    TLinkList stack[20];
    int top = -1;
    do
    {
        while (tree != NULL) {
            printf("%d ", tree->data);
            stack[++top] = tree;
            tree = tree->left;
        }
        tree = stack[top--];
        tree = tree->right;

    } while (!(top<0&&tree==NULL));
}

/*
    注意审题：二叉排序树
    tree->data < item 就要找大的，才可以趋向于item
*/
void PrintParent(TLinkList tree,int item) {
    while (tree!=NULL)
    {
        if (tree->data == item) break;
        if (tree->data < item) {
            printf("%d ", tree->data);
            tree = tree->right;
        }
        else {
            printf("%d ", tree->data);
            tree = tree->left;
        }
    }
}