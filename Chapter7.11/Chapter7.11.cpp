/*
    已知二叉树采用二叉链表存储结构
    写一算法，按层次从上到下，每层从左到右的顺序依次列出所有节点的数据信息
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left, * right;
}TNode, * TLinkList;

TLinkList CreateTree(int arr[], int index, int len); // 创建二叉树
void LRD(TLinkList tree);
void LevelOrder(TLinkList tree); // 层次遍历

int main()
{
    TLinkList tree;
    int arr[] = { 1,2,3,4,5,6,7,8,9,10,0,12,0,0,15 };
    tree = CreateTree(arr, 0, sizeof(arr) / sizeof(int));
    LRD(tree);
    printf("\n层序遍历：");
    LevelOrder(tree);
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
    int temp2[20], top = -1,f;
    do
    {
        while (tree!=NULL) {
            temp1[++top] = tree;
            temp2[top] = 0;
            tree = tree->left;
        }
        tree = temp1[top];
        f = temp2[top--];
        if (f == 0) {
            printf("%d ", tree->data);
            temp1[++top] = tree;
            temp2[top] = 1;
            tree = tree->right;
        }
        else {
            tree = NULL;
        }

    } while (!(tree==NULL&&top<0));
}

/*
    用队列。
    每次入队左右结点，尾插头出
    注意队列空间
*/
void LevelOrder(TLinkList tree) {
    TLinkList queue[20];
    int head=0, rear=0;
    queue[rear++] = tree;
    do
    {
        if (queue[head] != NULL) {
            tree = queue[head];
            if (tree->left != NULL) //不加判空的话queue空间需要两倍
                queue[rear++] = tree->left;
            if (tree->right != NULL)
                queue[rear++] = tree->right;
            printf("%d ", queue[head++]->data);
        }
        else {
            head++;
        }
    } while (head<rear);
}