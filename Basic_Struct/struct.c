/* 结构和联合 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NumberOf(x) (sizeof(x)/sizeof(x[0]))

// 类型定义
typedef char* String;	// 把char* 称为 String 

// 定义结构体
struct student_t
{
	String name; // char* name
	char* class;
	int id;
	int list[8];
} stu1 = { "test" }, stu2;	// 定义变量方法一

// 定义结构体。匿名结构体只能在此处定义变量
struct
{
	char* name;
	struct student_t* stu; // 嵌套结构体,可以用来构建链表
} class1 = { "mysql",&stu1 }; // 嵌套结构体赋值

typedef struct student_t Stu; // 类型定义结构体

// 联合类型的定义
union data {
	short sum;
	char* name;
	double salary;
}union1 = { 1 }; // 联合体仅能存放成员变量中的一个

int main()
{
	Stu stu3 = { "wjzhang","math",1,{1} };	 // 定义变量方法二
	Stu stu4 = { "zzh" }; // 未赋值的成员，int类型为0，数组中8个0，char类型为NULL
	printf("struct类型的数据长度等于其成员变量的长度总和：%d\n", sizeof(stu3));
	struct student_t stuArr[10] = { // 结构体数组初始值同上
		{ "zzh" }
	}; 

	for (int i = 0; i < NumberOf(stuArr); i++) {
		printf("name:%s  id:%d\n", stuArr[i].name, stuArr[i].id);
	}

	struct student_t* pstu1 = &stu4; // 指针
	(*pstu1).class = "bio";	// 因为 . 的优先级高于 *  所以记得加括号
	printf("%s\n", pstu1->class);


	printf("\nunion类型的数据长度等于其中最长的成员变量的长度：%d\n", sizeof(union data));
	union1.name = "zwj";
	printf("union仅能存放一个成员，name：%s  sum：%d\n", union1.name,union1.sum);
	union1.sum = 1;
	printf("union仅能存放一个成员，name：%s  sum：%d\n", union1.name, union1.sum);

	

}