/*
	一直长度为n的顺序表A，每个数据元素均为无符号整数
	写一算法，删除线性表中的所有奇数
*/

#include <stdio.h>
#include <stdlib.h>

void initSeq(int* seq, int* len); // 初始化
void printSeq(int seq[],int len); // 打印
void delOdd(int* seq, int* len);  // 找奇数，删除
void delSeq(int* seq, int* len, int index); // 删除

int main()
{
	int seq[20]; // 线性表
	int len; // 长度
	
	initSeq(&seq, &len);
	printSeq(seq, len);
	delOdd(&seq, &len);
	printSeq(seq, len);
}

void initSeq(int* seq, int* len) {
	int i = 0;
	*len = 0; // 注意！修改普通变量带个*
	while (i<10)
	{
		seq[i] = rand() % 20;
		(*len)++;
		i++;
	}
}

void printSeq(int seq[],int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", seq[i]);
	}
	printf("\n");
}

void delOdd(int* seq, int* len) {
	for (int i = 0; i < *len; i++) {
		if (seq[i] % 2 == 1) {
			// 注意i-- 调用delSeq后len会改变此处循环也需要回退一位
			delSeq(seq, len, i--);
		}
	}
}

void delSeq(int* seq, int* len, int index) {
	if (index<0 || index>*len) {
		printf("长度异常");
		exit(0); // 终止程序
	}
	for (int i = index; i < *len; i++) {
		seq[i] = seq[i + 1];
	}
	(*len)--;
}
