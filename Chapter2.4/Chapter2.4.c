/*
    已知长度为n的线性表A采用顺序存储结构。请写出逆转该线性表的算法
    要求在逆转过程中用最少的附加空间（尽可能少的辅助变量）
*/
#include <stdio.h>

void myReplace(int* seq, int len); // 我的转置
void printSeq(int seq[], int len); // 打印数组

int main()
{
    int seq[10] = { 1,2,3,4,5,6,7,8,9,10 }; // 只要内存中连续都叫顺序表
    int len = sizeof(seq) / sizeof(seq[0]); // sizeof获取的是内存长度，总长/单个长=数量
    printSeq(seq, len);
    myReplace(&seq, len);
    printSeq(seq, len);
}

void myReplace(int* seq, int len) {
    int a;
    // 9/2=4(向下取整)
    for (int i = 0; i < len / 2; i++) {
        a = seq[i];
        seq[i] = seq[len - i - 1];
        seq[len - i - 1] = a;
    }
}

void printSeq(int seq[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", seq[i]);
    }
    printf("\n");
}