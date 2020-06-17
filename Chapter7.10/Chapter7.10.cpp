/*
    已知二叉树采用二叉链表存储
    写一算法求以item为根节点的子树深度
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
void LRD(TLinkList tree); // 后续遍历
int ChildDeep(TLinkList tree, TLinkList item); // 求子树深度

int main()
{
    TLinkList tree, p;
    int arr[] = { 1,2,3,4,5,6,7,8,9,10,0,12,0,0,15 };
    tree = CreateTree(arr, 0, sizeof(arr)/sizeof(int));
    LRD(tree);

    p = tree->right->left->left;

    printf("子树深度:%d", ChildDeep(tree, p));
   

}

TLinkList CreateTree(int arr[], int index, int len) {
    TLinkList temp;
    if (index >= len||arr[index]==0) return NULL;
    temp = (TLinkList)malloc(sizeof(TNode));
    temp->data = arr[index];
    temp->left = CreateTree(arr, 2 * index + 1, len);
    temp->right = CreateTree(arr, 2 * index + 2, len);
    return temp;
}

/*
    后续非递归
    1、不用链栈（用线性栈）
    2、用图的思考方式，两个同步数组。一个放结点，一个放是否被访问
*/
void LRD(TLinkList tree) {
    TLinkList stack1[20], temp;
    int stack2[20], top = -1, f;
    do
    {
        while (tree!=NULL)
        {
            stack1[++top] = tree;
            stack2[top] = 0; // 标记0未被访问
            tree = tree->left;
        }
        tree = stack1[top]; // 回退
        f = stack2[top--];  // 暂存当前标记，top回退
        if (f == 0) {
            printf("%d ", tree->data);  // 访问
            stack1[++top] = tree;       
            stack2[top] = 1;            // 标记置为1
            tree = tree->right;
        }
        else {
            tree = NULL; // 如果已被问，置为NULL，while循环继续回退
        }
    } while (!(tree==NULL&&top<0));
}

/*
    利用前序遍历实现
    1、匹配到开始统计深度，deep存最终深度，tempdeep存当前子树深度
    2、防止遍历item的兄弟子树。在出栈的时候再次匹配到item结束循环
                                top存在NULL的情况 记得加条件
    3、如果是叶子结点不会触发二次匹配，需要在第一次匹配时判断退出。
*/
int ChildDeep(TLinkList tree, TLinkList item) {
    if (tree == NULL) return 0;
    SLinkList top = NULL, temp;
    int deep = 0,tempdeep=0;
    do
    {
        while (tree != NULL)
        {
            if (item == tree) { // 如果匹配深度+1
                deep = 1;
                if (tree->left == NULL && tree->right == NULL) return 1; // 如果是根节点
            } 
            if (deep) tempdeep++;
            temp = (SLinkList)malloc(sizeof(SNode));
            temp->data = tree;
            temp->next = top;
            top = temp;
            tree = tree->left;
        }
        // while即为一条子树结束,deep 存最大值
        deep = deep > tempdeep ? deep : tempdeep;
        tree = top->data->right;
        temp = top;
        top = top->next;
        free(temp);
        if (top!=NULL && top->data == item)return deep;
    } while (!(top == NULL && tree == NULL));
    return deep;
}