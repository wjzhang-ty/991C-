/* 北航2016—7题
    实现一个字符串比较函数strcpm_nc(s1,s2) 不区分大小写
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int strcpm_nc(char *s1, char *s2) {
    int result;
    while (*s1||*s2)
    {
        result = (int)(*s1 - *s2);
        if (result == 0 || ((*s1 >= 65 && *s1 <= 91) && result == -32) || ((*s1 >= 97 && *s1 <= 123) && result == 32)) {
            s1++;
            s2++;
        }
        else
        {
            return result;
        }
    }
    return 0;
}

int main()
{
    char str1[100], str2[100];
    int result;

    printf("请输入字符串1：");
    scanf("%s", str1);
    printf("\n请输入字符串2：");
    scanf("%s", str2);

    result = strcpm_nc(str1, str2);
    printf("\nstrcpm_nc：%d",result);
}