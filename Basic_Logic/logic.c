/* 基础的条件和循环语法 */

#include <stdio.h>

int main()
{
    int a = 1;
    int b = 2;
    int c = 0;

    // else优先匹配最近的上一个if
    if (a < b)
        if (b < 1)
            c = 3;
        else
            c = 4;
    printf("c等于4吗？(1真0假): %d\n\n",c==4?1:0); // 三目

    // 记一下格式
    switch (a)
    {
    case 1:
        printf("switch a=1\n");
    case 2:
        printf("switch a=2\n\n");
        break;
    case 3:
        printf("switch a=3\n");
    default:
        break;
    }

    do
    {
        printf("do while %d\n", b++);
        goto Print; // goto跳转后中断循环
    } while (b>34); // while中必须有表达式，while()报错

Print:
    printf("goto 中断了循环\n");
    return 0;
}
