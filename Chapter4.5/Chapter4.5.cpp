/*
    中缀表达式（正常的式子）E存放与字符数字中，以@作为结束标志。
    请写出判断一个中缀表达式E中左右圆括号是否配对的算法
*/

#include <stdlib.h>
#include <stdio.h>

int CheckStr(char str[]); // 检查中缀表达式，成功1 失败0

int main()
{
    char yes[20] = "2+(3*(9/2+7))@";
    char no[20] = "2+(3*(9/2+7)@";
    printf("检查yes：%d\n",CheckStr(yes));
    printf("检查no：%d\n", CheckStr(no));
}

int CheckStr(char str[]) {
    int i = 0,top=0;
    char stack[20];
    do
    {
        // 题目仅要求配对所以只需出入栈'()'不用考虑数字和+-*/
        if (str[i] == '(') {
            stack[top++] = str[i];
        }
        else if (str[i] == ')')
        {
            if (top == 0) return 0; // 栈中第一个就是）肯定不对
            str[--top] = 0; // 把）匹配的（出栈
        }
    } while (str[++i] != '@');
    return top > 0 ? 0 : 1; // 栈空说明（）匹配
}