/*
	已知长度为n的顺序表A。
	请写一时间复杂度为O(n)的算法，删除线性表中原来序号为奇数的元素
*/

#include <stdio.h>

void DELODD(int list[], int* len); // 删除奇数序号元素
void PRINTLIST(int list[], int len); // 打印

int main()
{
	int list[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int length = sizeof(list) / sizeof(int);

	PRINTLIST(list, length);
	DELODD(list, &length);
	PRINTLIST(list, length);
}

void DELODD(int list[],int* len){
	int i = 1, j = 0;
	while (i < *len) {
		list[j++] = list[i];
		i += 2;
		// (*len)--; // 写在循环外更好
	}
	*len = j;
}

void PRINTLIST(int list[], int len) {
	int i = 0;
	while (i<len)
	{
		printf("%d ", list[i++]);
	}
	printf("\n");
}