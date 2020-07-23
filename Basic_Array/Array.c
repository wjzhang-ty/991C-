/* 数组及字符串 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char strInt[10] = { '1',65,66,'C','a','n','I','n','t' };
    printf("数字将会当成ASCII码：%s\n", strInt);
    char str1[20] = "123\0956";
    printf("%s\n", str1);
    printf("strlen:%d\n", strlen(str1));
    printf("strstr:%s _ %s\n", strstr(str1,"56"), strstr(str1, "23"));
    printf("strcmp:%d\n", strcmp(str1, "1238")); // '1239'>'1238'
    printf("strcat:%s\n", strcat(str1,"38"));
    printf("%s\n", str1);
    return 0;
}
