/*
    已知非空二叉树采用顺序存储结构，结点的数据信息依次存放于数组BT[0...M]中
    假设结点的数据信息为整型数，若数组元素为0，则表示该元素对应的结点在二叉树中不存在
    请写出前序遍历的非递归算法
*/

#include <stdio.h>
#include <stdlib.h>

#define Max 20

void PreTraverse(int BT[]); // 前序遍历，非递归

int main()
{
    int BT[Max] = { 0 };
    for (int i = 0; i < 11; i++)
    {
        BT[i] = i + 1;
    }
    // tree = [1 | 2,3 | 4,5,6,0]
    PreTraverse(BT);
}

/* 
    借助栈，依次进栈，没有子节点就出栈
    1、存在左子树时，栈顶top跟着i前进
    2、左子树为0时，i指向右子树并对top出栈
        因为：i已经指向右子树，栈中存放的根左右子树均被访问过
        出栈后的top指向上一层，且上一层的右子树还未检查
    3、循环1，2
    没思路可以画个图用手比划一下
*/
void PreTraverse(int BT[]) {
    int top = 0, stack[Max] = { 0 }, i = 0;
    stack[top] = BT[i];
    do
    {
        // i基数过大时会超出数组上限所以需要判断i是否越界
        while (i< Max&&BT[i]!=0) 
        {
            printf("%d ", BT[i]);
            stack[++top] = i;
            i = i * 2 + 1; // 下标从0开始
        }
        i = stack[top--];
        i = i * 2 + 2;
        //if(BT[i]!=0)printf("%d ", BT[i]);
    } while (top>=0);
}
