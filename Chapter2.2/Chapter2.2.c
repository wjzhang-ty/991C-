/*
    用不多于3n/2的平均比较次数，在顺序表A[1..n]中分别找出最大元素和最小元素
*/
#include "stdio.h"
#include <stdlib.h>

typedef struct {
    int* datas;
    int length;
    int capacity;
}SeqList;

void initSeq(SeqList* seq);
void findLimit(SeqList seq);    // 不需要处理链表所以不用*

int main()
{
    SeqList list;
    initSeq(&list);
    findLimit(list);
}

// 动态顺序表
void initSeq(SeqList* seq) {
    seq->length = 0;
    seq->capacity = 10;
    seq->datas = (int*)malloc(seq->capacity * sizeof(int)); // 动态申请内存
    for (int i = 0; i < seq->capacity; i++) {
        seq->datas[i] = rand() % 20;
        seq->length++;
    }
}

void findLimit(SeqList seq) {
    int minIndex = 0, maxIndex = 0;
    for (int i = 0; i < seq.length; i++) {
        if (seq.datas[i] > seq.datas[maxIndex]) {
            maxIndex = i;
        }
        if (seq.datas[i] < seq.datas[minIndex]) {
            minIndex = i;
        }
    }
    printf("最大值：seq.datas[%d]=%d\n", maxIndex, seq.datas[maxIndex]);
    printf("最小值：seq.datas[%d]=%d\n", minIndex, seq.datas[minIndex]);
}