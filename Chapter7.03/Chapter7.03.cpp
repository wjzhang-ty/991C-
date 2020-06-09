/*
    已知两棵二叉树都采用二叉链表存储结构，根结点的地址分别为T1和T2
    请写一递归算法，判断二叉树是否等价，并给出相应信息
*/

#include <stdlib.h>
#include <stdio.h>

#define MAX 10

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}LNode,*LinkList;

LinkList CreateTree(int arr[], int len, int index); // 创建二叉树
void MidPrint(LinkList tree); // 中序遍历
int CheckEqual(LinkList one, LinkList two); // 检查是否相等

int main()
{
    int arr1[MAX] = { 1,2,3,4,5,6,7,8,9,10 };
    int arr2[MAX] = { 1,2,3,4,5,6,7,8,9,10 };
    LinkList one, two;
    one = CreateTree(arr1, MAX, 0);
    printf("one: ");
    MidPrint(one);
    two = CreateTree(arr2, MAX, 0);
    printf("\ntwo: ");
    MidPrint(two);
    printf("\n检查等价：%d", CheckEqual(one, two));
}

LinkList CreateTree(int arr[],int len, int index) {
    LinkList tree = (LinkList)malloc(sizeof(LNode));
    if (index >= len) return NULL;
    tree->data = arr[index];
    tree->left = CreateTree(arr, len, 2 * index + 1); // 此处记得*2
    tree->right = CreateTree(arr, len, 2 * index + 2);
    return tree;
}
void MidPrint(LinkList tree) {
    if (tree != NULL) {
        MidPrint(tree->left);
        printf("%d ", tree->data);
        MidPrint(tree->right);
    }
}

// 只有末端都等于null才返回1  data相等只时满足向下递归的条件
int CheckEqual(LinkList one, LinkList two) {
    if (one != NULL && two != NULL) {
        if (one->data == two->data) {
            return CheckEqual(one->left, two->left) && CheckEqual(one->right, two->right);
        }
        else {
            return 0;
        }
    }
    if (one == NULL && two == NULL) return 1;
    else return 0;

}