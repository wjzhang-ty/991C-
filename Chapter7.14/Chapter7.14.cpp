/*
    已知非空二叉树采用二叉链表结构
    利用二叉树遍历的非递归算法写出求二叉树中由指针q（非根）所指结点的兄弟结点的算法
    若二叉树中存在该兄弟结点，算法给出该兄弟结点的位置，否则算法给出NULL
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct tnode {
    int data;
    struct tnode* left, * right;
}TNode,*TLinkList;

typedef struct snode {
    TLinkList data;
    int index;
    struct snode* next;
}SNode, * SLinkList;

TLinkList CreateTree(int arr[], int index, int len); // 创建二叉树
int FindBro(TLinkList tree, TLinkList p);

int main()
{
    TLinkList tree, p;
    int arr[] = { 1,2,3,4,5,6,7,8,9,10,0,12,0,0,15 };
    tree = CreateTree(arr, 0, sizeof(arr) / sizeof(int));
    p = tree->right->right;
    printf("\n%d",FindBro(tree,p));
}

TLinkList CreateTree(int arr[], int index, int len) {
    TLinkList tree;
    if (index >= len || arr[index] == 0)return NULL;
    tree = (TLinkList)malloc(sizeof(TNode));
    tree->data = arr[index];
    tree->left = CreateTree(arr, 2 * index + 1, len);
    tree->right = CreateTree(arr, 2 * index + 2, len);
    return tree;
}

/*
    别脑子一抽就知道前序遍历，前序遍历无法正确找到父节点
    兄弟组件用层遍历
    head++ 删
    rear++ 增
*/
int FindBro(TLinkList tree, TLinkList p) {
    TLinkList queue[30];
    int head = 0, rear=0;
    queue[rear++] = tree;
    do
    {
        if(queue[head]!=NULL){
            tree = queue[head];
            if (tree == p) { 
                /* 注意：
                    返回值（第几个）从1开始
                    head（下标）从0开始
                */
                if (head % 2 == 0 && head < rear) return head;
                else if (head % 2 == 1 && (head + 2) < rear) return head + 2;
                else return NULL;
            }
            if (tree->left != NULL) queue[rear++] = tree->left;
            if (tree->right != NULL) queue[rear++] = tree->right;
            head++; // 左右已入队，当前结点出队
        }
        else {
            head++;
        }

    } while (head<rear);
    return NULL;
}