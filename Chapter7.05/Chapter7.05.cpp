/*
    二叉树采用链式存储，根结点地址为T
    写一非递归算法，统计二叉树中度为1的结点的数目
    要求算法中用到的堆栈采用链式存储结构
*/

#include <stdio.h>
#include <stdlib.h>

// 二叉树
typedef struct tnode {
    int data;
    struct tnode* left, * right;
}TNode, * TLinkList;

// 链栈,用来保存二叉树
typedef struct snode {
    TLinkList data;
    struct snode* next;
}SNode, * SLinkList;

TLinkList CreateTree(int arr[], int i, int len); // 创建二叉树
void DRF(TLinkList tree); // 先序遍历
int CountOneChild(TLinkList tree); // 统计度为0的结点

int main()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    TLinkList tree = CreateTree(arr, 0, 10);
    DRF(tree);
    printf("\n度为1的结点有%d个", CountOneChild(tree));
}

TLinkList CreateTree(int arr[], int i, int len) {
    TLinkList temp;
    if (i >= len) return NULL;
    temp = (TLinkList)malloc(sizeof(TNode));
    temp->data = arr[i];
    temp->left = CreateTree(arr, 2 * i + 1, len);
    temp->right = CreateTree(arr, 2 * i + 2, len);
    return temp;
}

void DRF(TLinkList tree) {
    if (tree == NULL) return;
    printf("%d ", tree->data);
    DRF(tree->left);
    DRF(tree->right);
}

/*
    自己以前的一个误区
    链栈top指向刚进来，base指向最早的.指向方向：top->base
    ！记得非递归遍历二叉树用俩循环，一个循环没有找到明确的终止条件
    栈中存根节点，左右均被访问后需要出栈。树借助栈回退，左右跳比较活跃。
*/
int CountOneChild(TLinkList tree) {
    int num = 0;
    SLinkList top = NULL,temp;
    do
    {
        while (tree!=NULL)
        {
            if (tree->left != NULL && tree->right == NULL || tree->left == NULL && tree->right != NULL)
                num++;
            temp = (SLinkList)malloc(sizeof(SNode));
            temp->data = tree;
            temp->next = top;
            top = temp;
            tree = tree->left;
        }
        tree = top->data;
        temp = top;
        top = top->next;
        free(temp);
        tree = tree->right;
    } while (!(tree==NULL&&top==NULL));
    return num;
}