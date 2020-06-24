/*
    树采用链结构存储
    写一算法判断树是否为二叉排序树
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left, * right;
}TNode, * TLinkList;

TLinkList CreateTree(int arr[], int index, int len);
void LRD(TLinkList tree); // 后续非递归
int IsSort(TLinkList tree); // 是否为二叉排序树

int main()
{
    TLinkList tree;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,0,12,0,0,15 };
	//int arr[] = { 20,15,25,10,18,22,27,0,0,17,0,0,0,0,30 };
    tree = CreateTree(arr, 0, sizeof(arr) / sizeof(int));
	LRD(tree);
	printf("\n二插排叙述检测：%d", IsSort(tree));
}

TLinkList CreateTree(int arr[], int index, int len) {
	TLinkList tree;
	if (index >= len || arr[index] == 0) return NULL;
	tree = (TLinkList)malloc(sizeof(TNode));
	tree->data = arr[index];
	tree->left = CreateTree(arr, 2 * index + 1, len);
	tree->right = CreateTree(arr, 2 * index + 2, len);
	return tree;
}

void LRD(TLinkList tree) {
	TLinkList stack1[20];
	int stack2[20], f, top = -1;
	do
	{
		while (tree!=NULL) {
			stack1[++top] = tree;
			stack2[top] = 0;
			tree = tree->left;
		}
		tree = stack1[top];
		f = stack2[top--];
		if (f==0) {
			printf("%d ", tree->data);
			stack1[++top] = tree;
			stack2[top] = 1;
			tree = tree->right;
		}
		else {
			tree = NULL;
		}

	} while (!(top<0&&tree==NULL));
}

/*
	二叉排序树：左子树 < 根 < 右子树
	一开始基本概念错了，无所谓那个遍历方式都应该不难
*/
int IsSort(TLinkList tree) {
	TLinkList queue[20];
	int head = -1, rear = -1;
	queue[++head] = tree;
	rear = head;
	do
	{
		tree = queue[head];
		if (tree->left != NULL) {
			queue[++rear] = tree->left;
			if (tree->left->data > tree->data)return 0;
		} 
		if (tree->right != NULL) {
			queue[++rear] = tree->right;
			if (tree->right->data < tree->data)return 0;
		} 
		head++;
	} while (head<=rear);
	return 1;
}