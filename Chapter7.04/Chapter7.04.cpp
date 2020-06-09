/*
    已知二叉树采用二叉链表存储结构，根结点的地址为T。
    写一递归算法，释放该二叉树中所有结点占用的空间
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left, * right;
}LNode,*LinkList;

LinkList Create(int arr[], int i, int len); // 创建
void LRD(LinkList tree); // 后续遍历
void CleanTree(LinkList &tree); // 清空

int main()
{
    int one[10] = { 1,2,3,4,5,6,7,8,9,10 };
    LinkList tree;
    tree = Create(one, 0, 10);
    printf("后续遍历LRD：");
    LRD(tree);
    CleanTree(tree); 
    //printf("\n后续遍历LRD：");
    //LRD(tree);
}

// 又把2*i忘了
LinkList Create(int arr[], int i, int len) {
    if (i < len) {
        LinkList temp = (LinkList)malloc(sizeof(LNode));
        temp->data = arr[i];
        temp->left = Create(arr, 2 * i + 1, len);
        temp->right = Create(arr, 2 * i + 2, len);
        return temp;
    }
    else {
        return NULL;
    }
}

void LRD(LinkList tree) {
    if (tree != NULL)
    {
        LRD(tree->left);
        LRD(tree->right);
        printf("%d ", tree->data);
    }
}
void CleanTree(LinkList &tree) {
    if (tree != NULL)
    {
        CleanTree(tree->left);
        CleanTree(tree->right);
        free(tree);
    }
}