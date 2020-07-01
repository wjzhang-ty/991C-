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


    /* 结构体 */
    typedef struct node { 
        int data;   // -> typedef struct node zs 
    }zs, * pzs;     // -> typedef struct node *pzs
    zs stu_zs;      // 定义了一个结构体变量（已开辟内存）
    pzs stu_pzs;    // 定义了一个指向结构体的指针（没有开辟内存）

    stu_zs.data = 1;

    stu_pzs = (pzs)malloc(sizeof(zs));
    stu_pzs->data = 10;     
    (*stu_pzs).data = 11;   // 等价于上方写法（.优先级大于*）


    /* 字符串和字符数组 */
    char zcarr[10] = "123450x\089"; // \0占一位
    char* zstr = "97x";  // 自动在末尾补\0

    printf("*定义的字符串:%s", zstr);
    zstr;            // "97x"
    zstr++;          // "7x"
    zstr--;          // "97x"
    *zstr;           // '9'
    *zstr++;         // '7'
    zstr;
    zcarr;


    // 指针本身是一个变量
    int i = 2, i1 = 2, istr;
    int* p, * parr1, * parr2, * pstr;
    int arr[4] = { 15,16,17,18 };
    char str[] = "abced fced";
    char q[] = "ce", * position;


    p = &i; // 指针赋值


    pstr = str; // 字符串


    // 基础
    printf("打印指针%%p:\t\t %p\n", p);
    printf("指针递增%%p:\t\t %p\n", p + 1); // int占4位，p+1为p的地址+4
    printf("打印指针对应的数据:\t %d\n\n", *p);

    // 数组
    parr1 = arr; // 指向arr[0]
    parr2 = &arr[3];
    printf("将数组传给指针，指向数组第一位:\t\t %d\n", *parr1);
    printf("将数组&arr[n]传给指针，指向数组第n位:\t %d\n", *parr2);
    printf("数组指针递增运算*++parr1，指向下一个:\t %d\n", *++parr1);
    printf("指针仅在数组中才可以相减，返回间距:\t %d\n", *parr2 - *parr1);
    /* 数组和指针可以互换，例如下方三个骚操作，语义上等价
        *(arr + 1) = 2;     arr为数组名
        *(parr1 + 1) = 2;   parr1为指针，默认指向arr[0]
        p[1] = 2;
    */
    //二维指针（指向二维数组的指针）
    int d_arr[32][64] = { {1,2,3},{4,5,6} };
    int(*pda)[64]; // 需要等于二维数组的列，否则无法指向
    pda = d_arr; // 指向d_arr的第一行
    printf("二维指针pda=d_arr:\t %d\n", *pda[1]);  // *pda == pda[0] == d_arr[0]
    printf("二维指针pda=d_arr:\t %d\n", pda[0][1]); // d_arr[0][1]
    printf("二维指针pda=d_arr:\t %d\n", *(*pda + 1)); // 同上
    printf("二维指针自增:\t\t %d\n", *(*++pda + 1));
    // 指针数组
    int* p_arr[] = { arr, &i };
    printf("指针数组中的数组:\t %d\n", p_arr[0][0]);
    printf("指针数组中的数组:\t %d\n", *++p_arr[0]);
    printf("指针数组中的变量:\t %d\n\n", *p_arr[1]);



    // 字符串
    printf("将字符串传给指针，指向字符串第一位:\t %c\n\n", *pstr);

    // 作参数，绕过作用域
    sum(i, &i1);
    printf("指针用作参数:i=%d, i1=%d\n\n", i, i1);

    // 作返回值
    position = strstr(str, q);
    printf("strstr返回第一次匹配到末尾的子串: %s\n", position);
    // strrstr 返回最后一次出匹配到末尾的子串


    /* 指针的比较
        1、判断是否指向同一变量
        2、在数组中可以比较先后次序
        3、与0比较判断指针是否为有效指针
    */ 

    /* 强制转换和void*
        1、指针类型只是检测手段
        2、强制转换语法(int *) i
        3、void*是通用指针，可以存放任何类型变量指针
    */

    /* 除了加、减、比较、转换操作，其余操作均不合法 */

    /* 多重指针
        **pp 指向指针的指针
    */

    // 函数指针
    int (*psum)(int x, int* py);
    psum = sum;
    (*psum)(i, &i1);    // 调用函数

}

// 指针做参数可以解决作用域问题
// 执行后 函数外的第一个参数没有被修改，第二个参数被修改了
int sum(int x, int* py) {
    printf("sum被调用\n");
    x += *py;
    *py = x;
    return x;
}