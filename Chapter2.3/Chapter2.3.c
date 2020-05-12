/*
    已知长度为n的线性表A采用顺序存储结构，表中均为int数据。
    请写出该顺序表中查找值为item的数据元素的递归算法。
    查找成功返回位置，失败返回-1。
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int datas[10];
    int length;
}SeqList;

void initSeq(SeqList* seq); // 初始化
int searchSeq(SeqList seq,int val,int index); // 查

int main()
{
    SeqList seq;
    int val;
    int index;

    printf("请输入您要查找的元素值（1-11）");
    scanf("%d", &val);

    initSeq(&seq);
    index = searchSeq(seq,val,0);

    printf("所查找的值为%d，位于第%d个元素", val, index);
}

void initSeq(SeqList* seq) {
    seq->length = 0;
    for (int i = 0; i < 10; i++) {
        seq->datas[i] = i+1;
        seq->length++;
    }
}

/*
    @param seq 顺序表
    @param val 查找值
    @param index 所查找的下标
*/
int searchSeq(SeqList seq,int val,int index) {
    if (index > seq.length) {
        return -1;
    }
    else if (seq.datas[index] == val) {
        return index;
    }
    else {
        return searchSeq(seq, val, ++index);
    }
}