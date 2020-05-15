/*
    通过键盘输入一系列数据元素，建立一个长度为n且不包含重复元素的线性表A
    这里，设线性表为顺序存储结构，且有足够空间。
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define LENGTH 50

void CREATELIST(int list[], int* len, int n); // 生成表
int CHECKDUP(int list[], int index); // 查重
void PRINTLIST(int list[], int len);

int main()
{
    int list[LENGTH];
    int length = 0;

    CREATELIST(list, &length, 3);
    PRINTLIST(list, length);
}

/*
    @param list 顺序表
    @param len 顺序表长度
    @param n 想要建立的长度
*/
void CREATELIST(int list[], int* len, int n) {
    printf("请输入%d个整数，回车分割\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
        if (CHECKDUP(list, i)) {
            i--;
        }
    }
    *len = n;
}

int CHECKDUP(int list[], int index) {
    int val = list[index];
    while (--index>=0)
    {
        if (list[index] == val) {
            return 1;
        }
    }
    return 0;
}

void PRINTLIST(int list[], int len) {
    int i = 0;
    while (i < len)
    {
        printf("%d ", list[i++]);
    }
    printf("\n");
}