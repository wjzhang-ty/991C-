/*
	A、B两个顺序表长度分别为n,m.
	请写一算法，在A的i个位置插入线性表B（不考虑存储空间溢出）
*/

#include <stdio.h>
#include <stdlib.h>

void INITLIST(int list[], int* len); // 初始化顺序表
void INSERTLIST(int listA[], int* listALength, int listB[], int listBLength, int index); // 插入
void PRINTLIST(int list[], int len);


int main()
{
	int listA[20];
	int listALength = 10;
	int listB[4];
	int listBLength = sizeof(listB) / sizeof(int);

	INITLIST(listA, &listALength);
	INITLIST(listB, &listBLength);

	printf("顺序表A：");
	PRINTLIST(listA, listALength);
	printf("顺序表B：");
	PRINTLIST(listB, listBLength);
	INSERTLIST(listA, &listALength, listB, listBLength, 3);
	printf("\n插入后顺序表A：");
	PRINTLIST(listA, listALength);

}

void INITLIST(int list[], int* len) {
	for (int i = 0; i < *len; i++) {
		list[i] = rand() % 20;
	}
}

// @param index 次序（非下标）
void INSERTLIST(int listA[], int* listALength, int listB[], int listBLength,int index) {
	// i指向合并后的下标，向前遍历。顺序表A划分为三段A1 B A2
	for (int i = *listALength + listBLength - 1,j=listBLength; i >= 0; i--) {
		if (i > listBLength + index -1) { // 完成A2段，i指向B段末尾
			listA[i] = listA[i - listBLength];
		}
		else if (i>index-1) { // 完成B段
			listA[i] = listB[--j];
		}
		else {
			break;
		}
	}
	*listALength += listBLength;
}

void PRINTLIST(int list[], int len) {
	int i = 0;
	while (i < len)
	{
		printf("%d ", list[i++]);
	}
	printf("\n");
}