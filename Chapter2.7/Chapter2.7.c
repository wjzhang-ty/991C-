/*
    已知长度为n得顺序表，表中元素有序排列
    写一算法删除所有大于x小于y得数据元素
*/

#include <stdio.h>


void PRINTLIST(int list[], int len); // 打印
void DELRANGE(int list[], int* len, int min, int max); // 范围删除

int main()
{
    int list[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int length = sizeof(list) / sizeof(int);

	PRINTLIST(list, length);
	DELRANGE(list, &length, 3, 6);
	PRINTLIST(list, length);

}

void DELRANGE(int list[], int* len,int min, int max) {
	int i = 0, j = 0;
	while (i < *len) {
		if (list[i] < min) {
			i++;
		}
		else if (list[i] <= max) {
			list[j++] = list[i++];
		}
		else {
			break;
		}
	}
	*len = j;
}

void PRINTLIST(int list[], int len) {
	int i = 0;
	while (i < len)
	{
		printf("%d ", list[i++]);
	}
	printf("\n");
}