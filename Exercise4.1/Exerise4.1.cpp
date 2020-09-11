// Exerise4.1.c :第四章编程题 
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/* 有 10 个学生，每个学生的数据包括学号、姓名、3 门课的成绩。
从键盘输入 10 个 学生数据，要求编程输出 3 门课平均成绩，总分
以及最高分的学生的数据（包括学号、姓名、 3 门课的成绩、平均分数 */
#define N 3
#define CLASS 3
typedef struct node {
	char name[20];
	int id;
	int score[CLASS];
}student;

void exe1() {
	student peoList[10];
	int total[CLASS] = { 0,0,0 }, best = 0;
	for (int i = 0; i < N; i++)
	{
		printf("请输入：学生姓名，学号，成绩1，成绩2，成绩3。用空格分隔\n");
		scanf("%s %d %d %d %d", peoList[i].name, &peoList[i].id, &peoList[i].score[0], &peoList[i].score[1], &peoList[i].score[2]);
		for (int j = 0; j < CLASS; j++)
		{
			total[j] +=  peoList[i].score[j];
		}
	}
	// 下方找最大下标比较好，这么写纯粹为了练习语法
	for (int i = 0; i < CLASS; i++)
	{
		printf("课程%d均分：%lf  ",i, total[i]/3.0);
		printf("课程%d总分：%d\n",i,total[i]);
		if (total[i] > best) best = i;
	}
	printf("最高分为：%s %d %d %d %d\n", peoList[best].name, peoList[best].id, peoList[best].score[0], peoList[best].score[1], peoList[best].score[2]);
}

/*学生的记录由学号和成绩组成，N 名学生的数据在主函数中输入结构体数组 s 中
请编写函数 fun：把分数最低的学生数据放在 h 所指的数组中。
注意:分数最低的 学生可能不止一个，函数返回分数最低的学生的人数。 */
typedef struct node2 {
	char name[20];
	int score;
}student2;

int fun(student2 peoList[], student2 h[]) {
	int min = NULL, total = 0;
	for (int i = 0; i < N; i++){
		if (min == NULL || min > peoList[i].score) min = peoList[i].score;
	}

	for (int i = 0; i < N; i++) {
		if (min == peoList[i].score) {
			h[total++] = peoList[i];
		}
	}
	return total;
}

void exe2Main() {
	student2 peoList[N],h[N],temp;
	int len = 0;
	for (int i = 0; i < N; i++)
	{
		printf("请输入姓名，成绩。逗号分隔\n");
		scanf("%s %d", (peoList+i)->name, &(peoList + i)->score);
	}
	// 第三题形同，多了个对名字排序，在此实现
	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			if (strcmp(peoList[i].name, peoList[j].name) > 0) {
				temp = peoList[i];
				peoList[i] = peoList[j];
				peoList[j] = temp;
			}
		}
	}
	peoList;	// 这里来断点
	len = fun(peoList, h);
	printf("共计：%d\n", len);
	for (int i = 0; i < len; i++)
	{
		printf("name:%s  %d\n", h[i].name, h[i].score);
	}
	
}

int main()
{
	//exe1();
	exe2Main();
}