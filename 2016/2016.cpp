/* 
    2016.cpp : 2016年911C语言程序设计题目
    本地有个student.txt自己打开看看
    写一程序，计算平均成绩，并输出成绩最高的三人（名，分），不足三人则输出全部
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX 3

// 学生对象
typedef struct node {
    char name[10];
    float sorce;
    struct node* next;
}StuNode,*LinkList;

// 求均分利用静态变量
int Splitequal(float score, int f) {
    static float sumScore = 0;  // 不会被销毁分数可以累加
    static float peo = 0;       // 同上
    if (!f) return sumScore / peo; // f=0时输出均分
    sumScore += score;  // 累加
    peo++;
}

/*
    前三名排序，利用链表
    确保传入参数结尾均为NULL
    带头结点，插入第一项不用分类讨论
*/
LinkList Top3(LinkList list, LinkList node) {
    LinkList top = list;
    int len = 0, canChange = 1; // 长度控制和可插入控制
    while (list->next != NULL && len++ < 3)
    {
        if (canChange&&list->next->sorce < node->sorce) {
            node->next = list->next;
            list->next = node;
            // 插入一次后置为0不可重复插入，利用while找到第三项
            canChange = 0;
        }
        list = list->next;
    }
    if (list->next!=NULL) free(list->next); // 回收第四项内存
    list->next = len < MAX ? node : NULL;   // 设置结尾，需要保证node->next=NULL
    return top;
}

// 打印链表
void printStack(LinkList list) {
    list = list->next;
    printf("\n");
    while (list!=NULL)
    {
        printf("姓名%s 成绩%f\n", list->name, list->sorce);
        list = list->next;
    }
}


int main()
{
    LinkList list = (LinkList)malloc(sizeof(StuNode));
    list->next = NULL;
    LinkList temp;


    FILE* fp;
    fp = fopen(".\\student.txt", "r");
    if (fp == NULL) return printf("fail to open! \n");
    while (!feof(fp))
    {
        temp = (LinkList)malloc(sizeof(StuNode));
        temp->next = NULL;
        fscanf(fp, "%s\r%f", &temp->name, &temp->sorce);
        Splitequal(temp->sorce, 1);
        list = Top3(list, temp);
    }
    fclose(fp);


    printf("均分%d", Splitequal(0, 0));
    printStack(list);
}