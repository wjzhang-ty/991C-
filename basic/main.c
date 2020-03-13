/*
	第一二章 C语言基础部分
*/
#include <stdio.h>

#define PI 3.1415926	// 别加封号
#define plus PI+2		// 先替换后再执行运算，优先级有替换后的表达式决定

int main() {	// 函数头 
	/*	
		int i = 1;
		类型 变量 = 常量;	
	*/
	const int i = 2147483647.9;	// const 不可更改变量，向下取整
	int  x, y;
	unsigned short s = 100;		// 负数的取值范围叠加到正数范围，不能为负
	long long ll = 9223372036854775807;		

	/*
		C中没有字符串类型，字符串由Char数组构成
		Char单引号，字符串双引号
	*/
	char c = 'abc';	// 仅能保存c
	char str[] = "abc";

	float f = 0.32;
	double d = 101e-5;

	/* 
		枚举 
		默认由0->n
		当第4项=10时  第5项由11开始递增	
	*/
	enum testEnum {t1, t2, t3, t4=10, t5, t6};

	printf("Unsigned short  %%u:\t %u\n", s);
	printf("Long Long       %%lld:\t %lld\n",ll);
	printf("Long Long       %%d:\t %d\n", ll);
	printf("Int 8进制       %%o:\t %o\n", i);
	printf("Int 10进制      %%d:\t %d\n", i);
	printf("Int 16进制      %%x:\t %x\n", i);
	printf("位运算          %%d:\t %d\n\n", 3<<3);	// 先转为2进制再平移 

	printf("Chart           %%c:\t %c\n", c);
	printf("Chart的ASCII码  %%d:\t %d\n", c);
	printf("ASCII码的运算   %%d:\t %d\n", c+'1');	// ASCII码做加减
	printf("Chart位运算     %%d:\t %c\n", c>>1);	// 位运算针对对ASCII
	printf("字符串          %%s:\t %s\n", str);
	printf("字符串[2]       %%c:\t %c\n\n", str[2]);

	printf("Float           %%f:\t %f\n", f);
	printf("Float带e        %%e:\t %e\n", f);
	printf("Double          %%lf:\t %lf\n\n", d);

	printf("异或^ 同0异1:   %%d:\t %d\n\n", 1 ^ 1);

	printf("宏：替换后才运算:%lf:\n\n", plus * plus);

	printf("枚举：t1=%d t2=%d t3=%d t4=%d t5=%d t6=%d\n\n", t1, t2, t3, t4, t5, t6);

	/* 强制类型转换 */
	printf("(double)(7/5)=  0%lf\n", (double)(7 / 5));
	printf("(double)7/5  =  %lf\n", (double)7 / 5);
	printf("(int)1.9     =  %d\n\n", (int)1.9);	// 向下取整，获取小数部分x-(int)x
	
	printf("请输入两个数\n");
	scanf_s("%d%x", &x, &y);
	printf("您输入了%d(10进制)  %d(16进制)\n\n", x, y);
	return 0;
}