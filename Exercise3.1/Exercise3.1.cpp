
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#define N 5

/* 输入 n 个整数，求最大值、最小值和平均值 */
void EX301() {
	int max, min, temp = 0;
	int i = 0;
	printf("请输入\n");
	while (i++ < 5)
	{
		scanf("%d", &temp);
		if (i == 1) min = max = temp;
		max = temp > max ? temp : max;
		min = temp < min ? temp : min;
	}
	printf("\nMAX:%d  MIN:%d", max, min);
}

/* 请编写函数 fun，其功能是：
将 s 所指字符串中除了下标为偶数、同时 ASCII 值也为偶数的字符外，
其余的全都删除，串中剩余字符所形成的一个新串放在 t 所指的一个数组中。
  */
void F303(char *arr, char t[]) { // char *arr 等同于 char arr[]
	int head = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (i % 2 == 0 && arr[i] % 2 == 0) {
			arr[head++] = arr[i];
		}
		arr[i] = '\0';
	}
}
void EX303() {
	char arr[] = "kv678v686534t35##@725%#";
	char t[20];
	F303(arr, t);
	printf("%s", arr);
}

/*编写函数,求出小于或等于 lim 的所有素数,并放在 aa 数组中,
该函数返回所求出的素数的个数
如 lim 为 15 时有 2、3、5、7、11、13 共 6 个*/
void EX304() {
	int arr[] = {2,3,5,7,11,13,14,15,16,17}; // 2-13都是
	int result[10];
	int total = 0,lim = 15,f=0;
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		if (arr[i]<=lim)
		{
			f = 1;
			for (int j = 2; j < arr[i]; j++)
			{
				if (arr[i] % j == 0) {
					f = 0;
					break;
				}
			}
			if (f) result[total++] = arr[i];
		}
	}
	printf("Len:%d\n", total);
	while (--total>=0)
	{
		printf("%d ", result[total]);
	}
}

int main()
{
//	EX301();
//	EX303();
	EX304();
}