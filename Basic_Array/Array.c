/* 数组及字符串 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // 数组名：arrint  数组名是一个常量
    int arrint[50] = {1,2,3,4}; // 未初始化的均为0
    int copyarr[50];
    int arr2[][4] = { {1,2,3},{5,6,7,8} }; // 可以不声明行，但必须有列

    char str[] = "Hello \0word"; // 默认已\0结尾，但数组长度为12
    char tests1[5] = { 'a','c','v','s','q' };
    char* tests2;
    tests2 = "assdgdafgd";
    scanf("%s", (char *)&tests2);
    printf("\ntests2:%s\n", tests2);
    char tests3[5] = { "asdgg" };
    char copystr[100] = ""; // 粘贴容器空间必须足够
    char format[32];

    printf("arrint[49]: %d\n", arrint[49]);
    printf("数组名表示数组首个元素的地址: %p\n", arrint);
    printf("arrint中元素数量: %d\n", sizeof(arrint) / sizeof(arrint[0]));
    memcpy(copyarr, arrint, sizeof(arrint));    // 数组复制
    printf("copyar[2]r: %d\n", copyarr[2]);
    printf("数组作为参数: %d\n", dot_vec(arrint,arr2,50));
    printf("二维数组arr2[1][2]: %d\n", arr2[1][2]);



    printf("字符串以/0结尾: ");
    puts(str);
    printf("请输入一个数: ");

    sprintf(format, "hello %%.%df\n", 2); // 动态字符串，存到format中
    printf(format, 2.102);

    strcpy(copystr, str);
    //strncpy(copystr, str,2); // 仅复制前两个字符
    printf("字符串复制: %s\n", copystr);

    strcat(str, "word");
    strncat(str, "word",1); // 仅追加前一个字符
    printf("字符串追加: %s\n",str);

    printf("字符串比较strcmp: %d\n", strcmp(str, copystr));  // 1不同
    printf("字符串比较strncmp: %d\n", strncmp(str, copystr,3)); // 0相同

    printf("字符串长度检查：%d\n", strlen(str)); // 不包含\0

    // 取字符串的数据
    // char time[100] = "06/Aug/2020:14:59:30 +0800";
    // sscanf(time, "%d/%3c/%d:%d:%d:%d%d",&a,&b,&c,&d,&e,&f,%g);
    // a:06   b:'Aug'  c:2020   d:14   e:59   f:30   g:800
}

// 数组可以作为参数，传的是地址
// 对数组参数的大小声明无效，以数组实际大小为准
// * 数组内部无法判断数组的大小 *
// 二维数组必须说明列数，否组报错
int dot_vec(int va[], int ca[][4], int array_length) {
    return ca[1][1] /va[2];
}
