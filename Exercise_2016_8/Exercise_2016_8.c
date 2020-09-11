/*  北航2016年八题
    读取/991c/source/score.dat中的成绩，一行一人。\t分隔。
    计算平均成绩并输出三个最高分
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    char name[20];
    float score;
    struct node* next;
}student, * STU;

STU insert(STU head, STU node) {
    STU list = head, lastnode;
    do
    {
        if (list->next != NULL && list->next->score < node->score) {
            node->next = list->next;
            list->next = node;
            return head;
        }
        lastnode = list;
        list = list->next;
    } while (list!=NULL);
    lastnode->next = node;
    return head;
}

int main()
{
    // 带头节点得链表
    STU head = (STU)malloc(sizeof(student)), temp ;
    head->next = NULL;
    head->score = -1;
    strcpy(head->name, "头节点");

    // 读文件
    FILE* fp;
    fp = fopen("D:\\991C-\\source\\score.dat", "r");
    if (fp != NULL) {
        while (!feof(fp))
        {
            temp = (STU)malloc(sizeof(student));
            fscanf(fp, "%s\t%f", &temp->name, &temp->score);
            temp->next = NULL;
            head = insert(head, temp); // 插入链表中，从高到低
        }
    }
    else printf("fail to open");

    // 求均分
    int num = 0;
    float average = 0;
    head = head->next;
    while (head!=NULL)
    {
        if (num < 3) {
            printf("%s:%f\n", head->name, head->score);
        }
        num++;
        average += head->score;
        head = head->next;
    }
    printf("均分:%f\n", average/num);
}
