/*
    n为大于等于0的整数，请写出计算以下公式非递归算法
    f(n)={n+1       n=0
         {n*f(n/2)   n!=0
    
    由于n/2趋于0，但不等于0，不会停止循环。此题仅在int的除法前提下展开
*/

#include <stdio.h>
#include <stdlib.h>

int MathFun(int k); // 公式实现

int main()
{
    int k = 10;
    printf("%d\n", MathFun(k));
    
}

/*
    堆栈，目前还不是很理解其神韵，针对自己当下的理解做如下概括。
        从[1...10]向数组插入数据
        再从[10...1]消费数据
        其中数组头节点（下标0）记录长度，不是数据不参与运算
*/
int MathFun(int k) {
    int arr[10] = { 0 }, sum = 0;
    int i = 1;
    
    // 依次入栈
    while (k)
    {
        arr[i++] = k;
        arr[0]++;
        k = k / 2;
    }
    // 此处省略arr[i]=1 (数学函数n=0时返回1) 因为1不影响结果 

    // 从后往前依次出栈
    for (i = arr[0]; i > 1; i--)
    {
        arr[i-1] = arr[i] * arr[i - 1]; 
        arr[0]--;
    }
    return arr[1];

}

