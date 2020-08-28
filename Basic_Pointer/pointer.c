#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

/* 指针相关 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 命令行参数，类似于shell脚本获取参数
    argc是后者的个数
    argv是一个指针数组
        其中元素分别指向命令行参数的各个字段
        argv[0]指向程序的全局路径
*/
int main(int argc, char* argv[])
{
    int a[3][4] = { 1,3,5,7,9,11,13,15,17,19,21,23 };
    printf("%d,%d\n", a, *a);
    printf("%d,%d\n", a[0], *(a+0));
    printf("%d,%d\n", &a[0], &a[0][0]);
    printf("%d,%d\n", a[1], a+1);
    printf("%d,%d\n", &a[1][0], *(a+1)+0);
    printf("%d,%d\n", a[2], *(a+2));
    printf("%d,%d\n", &a[2], a+2);
    /* 普通变量 */
    int z = 1;
    z;           // 1
    &z;          // 地址
 // *z;          // 错误*必须配指针变量

    int* pz = &z;
 // int* pz = z; // 错误,指针变量接地址
    pz;          // z 的地址
    &pz;         // pz的地址
    *pz;         // 1 （z的值）


    /* 数组 */
    int zarr[4] = { 1,9,5,7 };
    zarr;        // zarr[0]的地址，（元素的地址）
    zarr + 1;    // zarr[1]的地址，平移了一个元素
    &zarr;       // zarr的首地址，（数组的地址）
    &zarr + 1;   // 无意义 的地址，平移了整个数组
    &zarr[0] + 1;// zarr[1]的地址，平移了一个元素
    &zarr[2];    // zarr[2]的地址
    *zarr;       // 1 (zarr[0]的值)
    *zarr + 1;   // 2 (zarr[0]的值+1)
 // zarr++; &zarr++; *zarr++      // 错误

    int* pzarr = zarr;
    pzarr;       // zarr[0]的地址，（元素的地址）
    pzarr + 1;   // zarr[1]的地址，平移了一个元素
    &pzarr;      // pzarr的地址
    &pzarr + 1;  // 无意义地址，平移了整个数组
    *pzarr;      // 1 (zarr[0]的值)
    *pzarr + 1;  // 2 (zarr[0]的值+1) 
    *pzarr++;    // 9 (zarr[1]的值)       优先级 ++ > * > +

}