/*
    已知两颗二叉树都采用二叉链表存储结构，根节点的地址分别为T1和T2。
    写一算法，判断两颗二叉树是否相似（相同形态），并给出相应信息
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}LNode, * Tree;

Tree Init(int arr[], int len, int index); // 生成树
void PrintTree(Tree tree); // 打印树
int CheckSame(Tree one, Tree two); // 检查相似

int main()
{
              // 前序 1 2 4 8 9 5 10 3 6 7
    int arr1[MAX] = { 1,2,3,4,5,6,7,8,9,10 };
    int arr2[MAX] = { 2,3,4,5,6,7,8,9,10,1 };
    Tree one, two;
    one = Init(arr1, MAX, 0);
    printf("one: ");
    PrintTree(one);
    two = Init(arr2, MAX, 0);
    printf("\ntwo: ");
    PrintTree(two);
    printf("\n相似检查：%d", CheckSame(one, two));
}

/*
    ！注意  1、数组默认为0，所以需要传入长度控制，否则0会被错误的加入树中。
            2、在判断最下层节点是数组可能会超长。
*/
Tree Init(int arr[], int len, int index) {
    Tree top = (Tree)malloc(sizeof(LNode));
    if (index >= len) return NULL; // 一定要注意数组超长
    top->data = arr[index];
    top->left = Init(arr, len, 2 * index + 1);
    top->right = Init(arr, len, 2 * index + 2);
    return top;
}

void PrintTree(Tree tree) {
    if (tree != NULL) {
        printf("%d ", tree->data);
        PrintTree(tree->left);
        PrintTree(tree->right);
    }
}

/*
    基本思路：递归简单些
    两个数的同位置结点比较，三种情况
        1、 都有值  不是终点，继续向下判定.
        2、 都NULL  1
        3、 否则    0
*/
int CheckSame(Tree one, Tree two) {
    if (one != NULL && two != NULL) {
        return CheckSame(one->left, two->left) && CheckSame(one->right, two->right);
    }
    else if (one == NULL && two == NULL) return 1;
    else return 0;
}