# C语言与数据结构学习笔记
* Basic C语言基础语法
* Chapter2.+ 第二章课后题（顺序表）
    * 2.1-2.9 顺序表  
    * 2.10-2.19 单链表
    * 2.20-2.24 循环链表
    * 2.26 双向链表
* Chapter4.+ 第四章课后题（堆栈）
    * 4.4 递归算法转非递归算法常规思路
    * 4.5 中缀表达式校验：堆栈的应用，字数组遍历
* Chapter7.+ 第七章课后题（二叉树）
    * 7.06 非递归前&后序遍历
    * 7.07 前序序列+中序序列转二叉树
    * 7.08 中序遍历非递归
    * 7.09 前序遍历非递归
    * 7.10 后序遍历非递归（不同于前中遍历，参考图中的算法思路）
    * 7.11 层次遍历
    * 7.15 中序线索二叉树：非递归创建，给递归遍历
    * 7.16 二叉排序树
* Chapter9.1 折半查找递归+非递归
* Exerise_2016_8 北航真题：文件读取+链表排序插入

---

## 基础速记
> 答题要点
* 初始化的变量未赋值时
    * 可以赋值运算
    * 不能做判断,不能在print中打印
    * 如果初值为NULL判断时NULL会被解析成0，考虑到个人思路的特点，不要碰这个。
* printf的计算方式是从右到左，输出值是全部计算完成后的值。下面例子
* scanf中使用%s只能用空格做分隔符
* 处理函数调用中的变元时从右到左←。执行运算时（定义、逗号表达式）从左到右→
* 逗号表达式：例（a=2,b=5,b++,a+b)得8。b++作用域仅限当前逗号内，出了逗号就加完了
``` c
int i
i=1;
printf("%d,%d",i++,++i); // 2,3
i=1;
printf("%d,%d",++i,i++); // 3,1
```

> 无聊的东西
* k=... 的返回值为k的值。例：if(k=0) A; else B; 执行语句B
* 复合语句：{}包起来一大坨语句
* 函数A中调用函数B。称为：嵌套调用
* 函数A中调用函数A。称为：直接递归调用
* 函数A中调用函数B，再利用函数B调用函数A。称为：间接递归调用

> 形参和实参

形参（定义函数时括号里的变量）|实参
-|-
被调用时才分配内存|定义后分配内存
出现在函数定义中，作用域函数内部|出现在主调函数中
形参没有确定的值|实参在传值时必须要有确的数值
*值传递时，形参实参各自独立*|*引用传递时实参形参一体*（就是传地址）
-|例：fun((a+b),(c+e))  实参个数为2

> 函数声明
完整格式：dataType  functionName( dataType1 param1, dataType2 param2 ... );
省略形参：dataType  functionName( dataType1, dataType2 ... );  

> 常量（int a = 1 中的1）
* 数值常量
    * 整形常量
    * 实（浮点）型常量
* 字符常量
    * 普通字符： 单引号
    * 转义字符： '\n'
* 字符串常量： “”包起来的
* 符号常量： #define NUM 100  其中NUM为符号常量，100为整型常量
* 实数常量e的用法
    * 前面为大于1小于10的数。    其余情况可以运行，但不符合规范
    * 后面必须跟整数，不能带小数
    * 1.2e-2  -->  0.012   e前面是原数，e表示10，e后面是次方，次方可以为负数（小数点往前移）

> 优先级
>> 此处引申出来的一个盲区：位运算（| & ^ ~）针对二进制的运算，先转为二进制再一位一位的运算
>>> ^： x^y  同0异1<br>
>>> ~： ~x 获得补码

级别|符号
-|-
1|[] &nbsp; () &nbsp; a++ &nbsp; a-- &nbsp; -> &nbsp; .
2|-a &nbsp; (int)a &nbsp; ++a &nbsp; --a &nbsp; *a &nbsp; &a &nbsp; ! &nbsp; ~ &nbsp; sizeof()
3|* / % 运算符
4|+ - 运算符
5|<< &nbsp; >> 
6|> &nbsp; >= &nbsp; < &nbsp; <=
7|== &nbsp; !=
8|&
9|^
10| \||
11|&&
12| \|\||



> scanf中的%3d %2f
* 浮点类型：
    * %8.2f：整数位保留8位（补0），小数位保留2位（5舍6入）
* 整形
    * %3d: 整数位至少保留3位。不足补空格，超出不处理。

> 结构、联合
* struct：一揽子成员全都在，sizeof等于成员之和
* union： 一揽子成员只能选一个，sizeof等于最大的成员
* typedef: 创建新的类型（别名）
``` c
struct student{}b;
struct student name; // b和name一个意思，都是定义的结构体变量

typedef int INTEGER;
INTEGER a; int b; // a、b一个意思

typedef struct student{ int a } Simple;
Simple name;  // 这里的Simple 是 struct student的别名
```

> 预处理（#开头的都是，#include也是）
* #define: 
    * 不预先计算
    * 宏可以携带参数,带参数的可以替换为参数本身的类型
    * define后是字符串，在编译时用这个字符串替换掉对应未知，运行时被替换的东西会被解析成新的类型计算
    * 别加封号
* #include: 
    * <>：直接从系统中查找标准头文件
    * ""：先从当前目录查找是否有指定名称头文件，再从系统中查找
* typedef: 先计算完再替换（！这个不属于预处理命令）
* enum：枚举（穷尽所有可能的别称）
    * 默认为0，逐个递增1
    * 可以用枚举赋值不可以用常量赋值。可以强制转换但无意义
``` c
#define int* INT_DEF
typedef int* INT_TYPE
INT_DEF d1, d2;  // -> int* d1, d2
INT_TYPE t1, t2; // -> int* t1, *t2


#define MAX(a,b) (a>b)?a:b
max = MAX(1,2);

enum season {spring, summer=3, autumn, winter}day1;
enum season day2 = spring;  // 赋值
day1 = ( enum season ) 0    // 强制转换赋值
```

> 字符串和字符数组
* 世上本没有字符串，给字符数组加个\0便成了串（必须以\0结尾才叫字符串）
* ***注意：***""串会在末尾加\0，长度+1
* 字符数组和数组一样，本来定义完了也就是个指向首地址的指针
* 数组的[]中可以使用变量，但是定义的时候**不可以**使用变量
``` c
char* str = "one stack string"; 
str++;  // 左侧第一个字符出队，变量是串："ne stack string"
*str++; // 左侧第一个字符出队，指针式字符：'e'  （++优先级高）
while(*str!='\0'){*str++;}   // 遍历字符串
```
> 转义符(\\)
* 输出控制符：\b退格，\t水平制表，\r回车等...
* 八进制转义符：'\数字' -> '\60' 八进制的60为十进制的48即为数字0
* 十六进制转义符：'\x数字' -> '\x30' 十六进制的30为十进制的48即为数字0

> 存储类型
* auto：自动添加该关键字，动态存储（调用变量所在函数时，系统才给变量分配空间）
* register：寄存器变量，动态存储
* extren：外部变量。初值0或空字符。一经定义，系统分配固定内存单元。在第一行想使用第十行定义的变量或其他文件变量用此关键字
* static：静态变量。不释放。初值为0或空字符。静态变量的作用域限定为当前文件。
* 全局变量：静态存储,全局变量作用域时整个源程序（多个文件）
* 静态全局变量：static 全局变量; 静态存储，作用域仅当前文件中有效

> 文件
* r： 只读，找不到报错
* w： 只写，删了再新建空文件
* a： 只写，末尾追加，找不到报错
* +： 可读写，其余字母继承上方特征（例w+：可读写，删了文件再新建空文件）
* b： 二进制文件，其余字母继承上方特征（例：rb：只读二进制文件）
* fseek：随机读写
    * fseek(fp,100L,0): 指向开头，向后移100.
    * fseek(fp,100L,1)：指向不变，向后移100.
    * fseek(fp,-100L,2):指向结尾，向前移100.
* ferror(fp);错误检测。每次没见操作都会有一次返回值，返回1时出错，并且错误标志长期保留不会重置
* clearerr(fp);重置错误，清除错误标志，方便下次检测

>常考问题要点
* 求素数（仅能被1和自身整除的数）：可以减少循环范围k=(int)sqrt((double)m)
* 斐波切纳数列：1 1 2 3 5 8 后一项为前两项之和
* 字符转数字：int num = '1'-'0'
* 在结构体中注意：普通形参用.  指针用->   谨防书写习惯

# C++
### IO (iostream.h)
* 输出：<<   ⬅计算。➡输出。 
* 输如：>>
``` c++
int a=10,b;
cout<<a<<","<<a++;   // 11, 10
cin>>a>>b;  //录入a,b
```

---

你来人间一趟， 你要看看太阳。  
和你的心上人， 一起走在街上。