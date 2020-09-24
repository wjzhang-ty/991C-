# C语言内置函数

>头文件: ctype.h

内置函数|返回值|说明
-|-|-
int isupper(int)|0假,非0真|判断是否为大写字母
int islower(int)|0假,非0真|判断是否为小写字母
int isalpha(int)|0假,非0真|判断是否为字母
int isdigit(int)|0假,非0真|判断是否为数字
int toupper(int)|大写字符|转为大写字母，不会改变原值
int tolower(int)|小写字符|转为小写字母

<br/>

>头文件: math.h

内置函数|返回值|说明
-|-|-
double ceil(double)|结果|向上取整
double floor(double)|结果|向下取整
double sqrt(double)|结果|开根
double pow(double x, double n)|结果|x的n次方
double exp(double x)|结果|e的x次幂
int abs(int)|结果|绝对值!!注意参数和返回值均为int

<br/>

>头文件: string.h

- 所有函数处理遇到只认\0之前的串，\0之后就当他没有。

内置函数|返回值|说明
-|-|-
char *strcat(char *s1,char *s2)|s1所指地址|把s2接到s1后面
char *strchr(char *s,int ch)|找到的字符的地址，找不到返回NULL | 在s所指字符串中，找出第一次出现字符ch的位置
int strcmp(char *s1,char *s2)|s1<s2,返回负数；s1= =s2,返回0；s1>s2,返回正数|对s1和s2所指字符串进行比较
char *strcpy(char *s1,char *s2)|s1 所指地址|将s1替换为s2
unsigned strlen(char *s)|返回串中字符（不计最后的'\0'）个数|求字符串s的长度
char *strstr(char *s1,char *s2)|返回找到的字符串的地址，找不到返回NULL|在s1所指字符串中，找出字符串s2第一次出现的位置
``` c
    char str1[] = "abcdef";
    char str2[] = "ab\0cd\0ef";
	printf("sizeof:str1 %ld  str2 %ld\n",sizeof(str1),sizeof(str2)); // 7 9
	printf("strlen:str1 %ld  str2 %ld\n",strlen(str1),strlen(str2)); // 6 2
```

>头文件：stdlib.h

内置函数|返回值|说明
-|-|-
void *calloc(unsigned n,unsigned size)|分配内存单元的起始地址；如不成功，返回0|分配n个数据项的内存空间，每个数据项的大小为size个字节，并初始化为0
void *free(void *p)|无|释放p所指的内存区
void *malloc(unsigned size)|分配内存空间的地址；如不成功，返回0|分配size个字节的存储空间，不初始化
void *realloc(void *p,unsigned size)|新分配内存空间的地址；如不成功，返回0|把p所指内存区的大小改为size个字节
int rand(void)|返回一个随机整数|产生0～32767的随机整数
void exit(int state)|无|程序终止执行，返回调用过程，state为0正常终止，非0非正常终止

>头文件：stdio.h

内置函数|返回值|说明
-|-|-
char gets(char* buf)|-|终端中接受字符串，\n结束，多余部分无视，末尾自动补0。（可以接受空格）。失败返回NULL
getchar()|-|终端中接受一个字符，\n结束（可自定义），多余部分无视。
char* fgets(char* buf, int size, FILE* fp)|-|文件中接受一行字符，\n结束，末尾自动补0
scanf()|-|终端中接受多个字符串，回车、空格、tab都认为结束（可以自定）！！当输入%c时，分隔符（空格 回车等）会被丢入缓存，并被随后的getchar scanf函数当作输入参数接受
puts(char* s)|-|输出字符串，\0结束追加换行
putchar(char s)|-|输出单个字符，只能输出单引号的值或者数字ASCII码
FILE fopen(char filename, *type)|FILE|打开文件
int fclose(FILE *stream)|-|关闭文件
size_t fwrite ( const void * ptr, size_t size, size_t nmemb, FILE * stream )|写入文件个数|写入（缓存，字节，多少个，fp）
size_t fread ( void * ptr, size_t size, size_t nmemb, FILE * stream )|读取文件个数|读取（缓存，字节，多少个，fp）
int fseek(FILE *stream, long int offset, int whence)|成功会回0|移动指针，看README
void rewind(FILE *stream)|-|移动指针至文件头部
int fprintf(FILE stream, char format[], argument,...)|转化的字节数，失败负数|格式化写入，格式同printf
int fscanf(FILE stream, char format[],argument...)|转化的字节数，失败负数|格式化读取，格式同scanf
int feof(FILE * stream)|返回非零值代表已到达文件尾|检查文件流是否读到了文件尾
int fgetc(FILE * stream)|ASCII码|获取下一个字符
int fputc(int c,FILE * stream)|返回成功写入的字符，失败返回EOF|会将参数c 转为unsigned char 后写入
char * fgets(char * s,int size,FILE * stream)|成功返回s指针，有错误返回NULL|读入字符并存到参数s所指的内存空间，直到出现换行字符、读到文件尾或是已读了size-1个字符为止，最后会加上NULL作为字符串结束。
int fputs(const char * s,FILE * stream)|成功返回写出的字符个数，有错误返回NULL|将参数s所指的字符串写入
FILE * freopen(const char * path,const char * mode,FILE * stream)|FILE失败NULL|会将原stream所打开的文件流关闭，然后打开参数path的文件
long ftell(FILE * stream)|成功返回目前的读写位置，有错返回-1|来取得文件流目前的读写位置。参数stream为已打开的文件指针


>常见ASCII码

ASCII|字符
-|-
0|\0
32|空格
48|0
65|A
97|a

<br/>

---
你来人间一趟， 你要看看太阳。  
和你的心上人， 一起走在街上。