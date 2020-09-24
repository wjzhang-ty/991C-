/*  北航2015-7
    请编写一程序，该程序的功能是首先将用户通过键盘输入的若干字符（用EOF结束输入）存入一维数组s中
    然后找出数组中具有最大ASCil码值得字符，并输出该字符以及该字符对应的ASCII码。 
    要求： 程序中有关输入、输出以及查找等操作必须通过指针完成
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char s[100] = {0};
    char max = 0, temp;
    int i = 0;
    while ((temp=getchar())!=EOF) // ctrl + z 回车
    {
        if (max < temp) max = temp;
        *(s + i++) = temp;
    }
    printf("max:%c %d", max, max);
}