/*
    用不多于3n/2的平均比较次数，在顺序表A[1..n]中分别找出最大元素和最小元素
*/
#include "stdio.h"
#include <stdlib.h>

typedef struct {
    int datas;
    int length;
    int capacity;
}SeqList;

void initSeq(SeqList* seq);

int main()
{
    SeqList list;
    initSeq(&list);
    printf("%d", list.datas[1]);
}

// 动态顺序表
void initSeq(SeqList* seq) {
    seq->length = 0;
    seq->capacity = 10;
    seq->datas = (SeqList*)malloc(seq->datas, seq->capacity * sizeof(SeqList));
    for (int i = 0; i < seq->capacity; i++) {
        seq->datas[i] = rand() % 20;
    }
}