/*
	已知非空二叉树采用二叉链表结构
	请写出生成该二叉树的中序线索二叉树非递归算法
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data, lbit, rbit;
	struct node* left, * right;
}TNode, * TLinkList;

TLinkList CreateTree(int arr[], int index, int len); // 创建二叉树
TLinkList CreateClueTree(TLinkList tree); // 线索化
void PrintClue(TLinkList tree, int f);

int main()
{
	TLinkList tree;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,0,12,0,0,15 };
	tree = CreateTree(arr, 0, sizeof(arr) / sizeof(int));
	tree = CreateClueTree(tree);
	PrintClue(tree,1);
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

/*
	线索化（有头节点，并且最后一个节点指向头节点）
	lbit==0 left：从哪儿来
	rbit==0 right：到哪儿去
	tree是当前结点，修改lbit。 prior是上一个结点，修改rbit。
*/
TLinkList CreateClueTree(TLinkList tree) {
	TLinkList head, prior, stack[20];
	int top = -1;
	head = (TLinkList)malloc(sizeof(TNode));
	head->left = tree;
	head->right = head; // 右结点没卵用，异常情况可以退出
	head->lbit = 1;
	head->rbit = 1;
	prior = head; // 上一结点
	do
	{
		while (tree != NULL) {
			stack[++top] = tree;
			tree = tree->left;
		}
		tree = stack[top--]; // 回退一下，
		if (tree->left == NULL) {
			tree->left = prior;
			tree->lbit = 0;
		}
		else {
			tree->lbit = 1;
		}
		if (prior->right == NULL) { // 如果上一结点时叶子结点
			prior->right = tree;
			prior->rbit = 0;
		}
		else
		{
			prior->rbit = 1;
		}
		prior = tree; // 记录上一个结点
		tree = tree->right;
	} while (!(tree==NULL&&top<0));
	prior->right = head;
	prior->rbit = 0;
	return head;
}


/*
	lbit == 0 表示线索， lbit == 1 表示子树
	1、线索二叉树有个头节点，判断下一个结点是否为头节点来终止循环
	2、一直向左下探，lbit==0到底，切换到右侧
	3、为了防止循环左下探，探测时将lbit置为0.
		当通过有线索找到该结点时不再执行左下探操作了
		未被置为0的结点依旧左下探
*/
void PrintClue(TLinkList tree, int f) {
	TLinkList p = tree->left;
	while (p!=tree)
	{
		while (p->lbit == 1) { 
			p->lbit = 0;
			p = p->left; 
		}
		printf("%d ", p->data);
		p = p->right;
	}
}