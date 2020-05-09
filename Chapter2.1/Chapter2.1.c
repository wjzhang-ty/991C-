/*
    已知长度为n的线性表A采用顺序存储结构。
    请写一算法，找出该线性表中值最小的数据元素，给出该元素在表中的位置
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

// 顺序表结构体
typedef struct {
    int datas[MaxSize];
    int length;
}SeqList;

void initSeq(SeqList seq[],int len); // 初始化顺序表
int findMin(SeqList seq[]); // 初始化顺序表

int main()
{
    SeqList seq;
    initSeq(&seq,MaxSize);
    int min = findMin(&seq);
    printf("顺序表中最小值是：%d, 下标为：%d\n", seq.datas[min], min);
}

void initSeq(SeqList seq[], int len) {
    seq->length = 0; // 记得给的初始值
    for (int i = 0; i < len; i++)
    {
        seq->datas[i] = rand()%95;
        seq->length++;
    }
}

int findMin(SeqList seq[]) {
    int min = 0;
    for (int i = 0; i < seq->length; i++)
    {
        if (seq->datas[i] < seq->datas[min]) {
            min = i;
        }
    }
    return min;
}