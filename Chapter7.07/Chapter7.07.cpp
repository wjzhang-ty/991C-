/*
    已知某具有n个节点的二叉树前序序列为PREOD【0...n-1】 中序序列为INOD【0...m-1】
    各节点值无重复.写一算法生成二叉树的二叉链表结构
*/

#include <stdlib.h>
#include <stdio.h>

#define MAX 11

typedef struct node {
    int data;
    struct node* left, * right;
}TNode, * TLinkList;

TLinkList GenerateTree(int preod[], int inod[], int start, int end); // 核心
int FindIndex(int data, int inod[], int start, int end); // 查找当前值在中序序列中的位置
void LDR(TLinkList tree); // 递归中序遍历 检验正确否

int preIndex = 0;

int main()
{
    TLinkList tree;
    int PREOD[MAX] = { 1, 2, 4, 8, 17, 9, 5, 3, 6, 13, 7 };
    int INOD[MAX] = { 8, 17, 4, 9, 2, 5, 1, 6, 13, 3, 7 };
    tree = GenerateTree(PREOD, INOD, 0, MAX-1);
    LDR(tree);
}

/*
    思路要点：
    1、对中序序列分组递归，
    2、依照前序序列创建树，需要借助全局变量preIndex创建结点
    3、注意递归执行顺序，左边一直分到最底层才会去分右边，顺序正好是由左向右的
    4、不要纵向思考，横向思考
*/
TLinkList GenerateTree(int preod[], int inod[], int start, int end) {
    if (start > end) return NULL; // 分支结束，不继续向下递归，自然就轮到右边了
    int index;
    TLinkList temp = (TLinkList)malloc(sizeof(TNode));
    temp->data = preod[preIndex++];
    index = FindIndex(temp->data, inod, start, end); // 找到在中序序列中的位置
    temp->left = GenerateTree(preod, inod, start, index - 1); // 分组，递归拆分左边子树
    temp->right = GenerateTree(preod, inod, index + 1, end);
    return temp;
}

int FindIndex(int data, int inod[], int start, int end) {
    for (; start <= end; start++) {
        if (inod[start] == data) return start;
    }
}

void LDR(TLinkList tree) {
    if (tree != NULL) {
        LDR(tree->left);
        printf("%d ", tree->data);
        LDR(tree->right);
    }
}