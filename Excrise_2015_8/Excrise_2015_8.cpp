/*
	编写一程序，该程序功能是查找字符串中某字符首次出现的位置，并删除
	不考虑第一个出现的情况
*/

#include <stdio.h>

int find(char str[],char search) {
	int i = 1;
	while (*str++) {
		if (*str == search) {
			return i;
		}
		i++;
	 }
	return -1;
}

void del(char str[], int index) {
	int i = index, j = index + 1;
	while (str[i])
	{
		str[i++] = str[j++];
	}
}

int main()
{
	char str[10] = "abcdefg";
	int index = 0;
	printf("原字符串：%s\n", str);
	index = find(str,'c');
	printf("查找结果：%d\n", index+1);
	del(str, index);
	printf("删除结果：%s\n", str);
}
