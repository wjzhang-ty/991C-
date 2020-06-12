/*
    已知非空二叉树采用二叉链表存储结构，根节点地址为T。
    请写出非递归算法，该算法打印数据信息为item的结点的所有祖先结点
    假设数据信息为item的结点不多于一个
*/

#include <stdlib.h>
#include <stdio.h>

// 树节点
typedef struct tnode {
    int data;
    struct tnode* left, * right;
}TNode, * TLinkList;

// 前序用的栈
typedef struct snode {
    TLinkList data;
    struct snode* next;
}SNode, * SLinkList;


TLinkList CreateTree(int arr[], int i, int len); // 创建二叉树
void DLR(TLinkList tree); // 非递归前序遍历
void PrintParent(TLinkList tree, int item); // 打印祖先结点

int main()
{
    int arr[20] = { 1,2,3,4,5,6,7,8,9,0,0,0,0,0,15,16,0,18 };
    TLinkList tree = CreateTree(arr, 0, 20);
    DLR(tree);
    printf("\n");
    PrintParent(tree, 18);
}

// 创建二叉树 0识别为空
TLinkList CreateTree(int arr[], int i, int len) {
    TLinkList temp;
    if (i >= len || arr[i] == 0) return NULL;
    temp = (TLinkList)malloc(sizeof(TNode));
    temp->data = arr[i];
    temp->left = CreateTree(arr, 2 * i + 1, len);
    temp->right = CreateTree(arr, 2 * i + 2, len);
    return temp;
}

/*
    注意事项
    1、记住是两层循环，有了这个大前提思路简单些
    2、栈是由后指向前，栈底是NULL用来判空（退出）
    3、注意结束条件，两个同时满足才可以，小心短路
*/
void DLR(TLinkList tree) {
    SLinkList top = NULL, temp;
    do
    {
        while (tree!=NULL)
        {
            printf("%d ", tree->data);
            temp = (SLinkList)malloc(sizeof(SNode));
            temp->data = tree;
            temp->next = top;
            top = temp;
            tree = tree->left;
        }
        tree = top->data->right;
        temp = top;
        top = top->next;
        free(temp);
    } while (!(tree==NULL&&top==NULL));
}

/*
    利用后序遍历来实现
    1. 顺序栈即可,需要对每个元素做标记. 0 仅访问左结点  1左右均访问了
    2. tree == NULL 并且根为0  切换到右子树上,继续向下迭代
    3. tree == NULL 并且根为1  出栈(while结束会回退 所以置为NULL继续循环即可)
*/
void PrintParent(TLinkList tree,int item) {
    TLinkList stack1[20], head = tree;
    int stack2[20], top = -1, flag;
    do
    {
        while (tree!=NULL)
        {
            stack1[++top] = tree;
            stack2[top] = 0;
            tree = tree->left;
        }
        tree = stack1[top];
        flag = stack2[top--];
        if (flag == 0) {
            stack1[++top] = tree;
            stack2[top] = 1;
            tree = tree->right;
        }
        else {
            if (tree->data == item) {
                while (top!=-1)
                {
                    printf("%d ", stack1[top--]->data);
                }
                break;
            }
            else {
                tree = NULL;
            }
        }
    } while (!(top==-1&&tree==NULL));
}