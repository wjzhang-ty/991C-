/*
             |~ n+1                 m=0
    ACK(m,n)=|  ACK(m-1,1)          m!=0,n=0
             |_ ACK(m-1,ACK(m,n-1)) m!=0,n!=0
    1、写出递归算法
    2、写出非递归算法
    3、根据非递归算法求出ACK（2，1）的值

    阿克曼函数，难度较大考试不考，pass
*/

#include <stdio.h>
#include <stdlib.h>

int Recursive(int m, int n); // 递归函数
int UnRecursive(int m, int n); // 非递归函数

int main()
{
    int m = 3, n = 2; // 阿克曼函数，结果29
    printf("%d", Recursive(m, n));
    
}

int Recursive(int m, int n) {
    if (m == 0) return n + 1;
    if (n == 0) return Recursive(m - 1, 1);
    return Recursive(m - 1, Recursive(m, n - 1));
    // Recursive(1, 2);
}

int UnRecursive(int m, int n) {
    return 1;
}