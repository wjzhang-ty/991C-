/*
    求两个正整数m和n的最大公约数的过程可以表达为如下递归函数
            |~ gcd(n,m)        m<0
    gcd(m,n)|  m               n=0
            |_ gcd(n,m MOD n)  其他
    请写出分递归算法
*/

#include <stdio.h>
#include <stdlib.h>

int Gcd1(int n, int m); // 最大公约数（递归）
int Gcd2(int n, int m); // 最大公约数（非递归）

int main()
{
    printf("%d", Gcd2(2, 6));
}

/*
    递归本质也是借用堆栈实现的，将递归转为非递归最常规的一种做法是用堆栈模拟递归的过程
    抓住关键点整体思路会比较简单。
    1、因为递归每次都传入n,m。所以建立一个二维数组存放每一次计算后的n,m
    2、将公式中的n,m替换为list[][1],list[][0] 控制条件和计算过程仿照递归即可
    3、存入list之后记得top++
*/
int Gcd2(int m, int n) {
    int list[100][2] = { {m, n},0 }, top = 0;
    while (list[top][1] != 0) {
        if (list[top][0] > 0 && list[top][1] != 0) {
            list[top + 1][0] = list[top][1];
            list[top + 1][1] = list[top][0] % list[top][1];
        }
        else if (list[top][0] < 0)
        {
            list[top + 1][0] = list[top][1];
            list[top + 1][1] = list[top][0];
        }
        top++;
    }
    return list[top][0];
}

// 递归解法
int Gcd1(int m, int n) {
    if (m < 0) return Gcd1(n, m);
    if (n == 0) return m;
    return Gcd1(n, m % n);
}