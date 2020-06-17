/*
    已知二叉树采用二叉链表存储结构，根结点为T
    写一算法判断是否为完全二叉树
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
void LDR(TLinkList tree); // 中序遍历
int CheckComplete(TLinkList tree); // 检查是否为完全二叉树

int main()
{
    TLinkList tree;
    //int arr[] = { 1,2,3,4,0,6,7,8,9,0,0,12,0,0,15 };
    int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,0 };
    tree = CreateTree(arr, 0, 15);
    LDR(tree);
    printf("\n检查是否为完全二叉树: %d", CheckComplete(tree));
}

TLinkList CreateTree(int arr[], int index, int len) {
    TLinkList temp;
    if (index >= len||arr[index]==0) return NULL;
    temp = (TLinkList)malloc(sizeof(TNode));
    temp->data = arr[index];
    temp->left = CreateTree(arr, index * 2 + 1, len);
    temp->right = CreateTree(arr, index * 2 + 2, len);
    return temp;
}

void LDR(TLinkList tree) {
    SLinkList temp, stack = NULL;
    do
    {
        while (tree!=NULL)
        {
            temp = (SLinkList)malloc(sizeof(SNode));
            temp->data = tree;
            temp->next = stack;
            stack = temp;
            tree = tree->left;
        }
        tree = stack->data;
        printf("%d ", tree->data);
        temp = stack;
        stack = stack->next;
        free(temp);
        tree = tree -> right;
    } while (!(tree == NULL && stack == NULL));
}

/*
    队列：一个数组，两个索引，一前一后。
        前索引所过之处皆为出，后索引所过之处均为为入
    1、当前一层由左到右，不要一次看一层，一次只看一个结点
    2、数组空间必须是树空间的两倍大，否则就别把NULL入队
*/
int CheckComplete(TLinkList tree) {
    int f = 0, front = -1, rear = -1;
    TLinkList arr[30], temp;
    if (tree != NULL) {
        arr[++rear] = tree;
        while (rear>front)
        {
            temp = arr[++front];
            if (f == 1) { // 如果找到第一个NULL
                if (temp != NULL)return 0; // 只要看到不是NULL的就不满足
            }
            else { // 如果还有找到NULL
                if (temp == NULL) { // 找到一个NULL
                    f = 1;
                    // NULL没有left 和 right 需要结束当前层循环。老哥，记着别用break
                    continue;
                }
                arr[++rear] = temp->left;
                arr[++rear] = temp->right;
            }
        }
    }
    return 1;
}