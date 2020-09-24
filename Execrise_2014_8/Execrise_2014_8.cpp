/*
    写一程序，计算并输出子字符串在父字符串中出现的次数
    测次数函数为int STRCOUNT(char* str, char* substr) 未出现回0。 字符串操作用指针完成 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int STRCOUNT(char* str, char* substr) {
    //  总数     父队      子队         匹配长度              缓存（回退）
    int sum = 0, tail = 0, subtail = 0, len = strlen(substr), tempindex = 0;
    while (*(str+tail)) {   // 注意判断条件
        if (*(str + tail) == *(substr + subtail)) {
            subtail++;
            if (tempindex == 0) tempindex = tail+1; // 标记下一个位置为回退位置
        }
        else {
            subtail = 0;
            tempindex = 0;
        }
        tail++;
        if (subtail == len) {
            sum++;          // 统计
            subtail = 0;    // 重置
            tail = tempindex;// 回退
            tempindex = 0;
        }
    }
    return sum;
}

int main()
{
    char str[21], substr[21];
    printf("请输入20位以内完整字符串\n");
    scanf("%s", str);
    printf("请输入20位以内子字符串\n");
    scanf("%s", substr);
    int i;
    i = STRCOUNT(str, substr);
    printf("匹配结果：%d\n",i);
    return 0;
}