// Base_File.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*
    r: 只读文件，找不到文件报错
    fopen(char[],char): 打开文件
    fclose(FILE):       关闭文件
    fgetc(FILE):        读取一个字符
    feof(FILE):         文件是否结束
*/
void Readfile(char path[]) {
    FILE* fp;
    fp = fopen(path, "r");
    if (fp != NULL) {
        // fgetc(fp)==EOF 也认为是结束
        while (!feof(fp))
            printf("%c", fgetc(fp));    // 一次读取一个字符
    }
    else printf("fail to open! \n");
    fclose(fp);
}

/* 
    fgets：一次读取多个字符，结果保存到字符数组中
*/
void Getsfile(char path[]) {
    char str[21]; // 多一个存'\0'
    FILE* fp;
    fp = fopen(path, "r");
    if (fp != NULL) {
        while (!feof(fp)) {
            fgets(str, 8, fp); // 一次读8个，结果保存到字符数组str中
            printf("%s", str);
        }
    }
    else printf("fail to open! \n");
    fclose(fp);
}

/*
    w: 写文件，清空原有文件再执行写，找不到就新建
    fputc(char,FILE):   一次写入一个字符
*/
int Writefile(char path[]) {
    char *str = "你拍一，\n我拍一，\n写好文件去蹦迪";
    FILE* fp;
    fp = fopen(path, "w");
    if (fp != NULL) {
        while (*str!='\0') {
            fputc(*str++, fp);          // 一次输入一个字符
        }
    }
    else printf("fail to open! \n");
    fclose(fp);
}

/*
    a: 追加文件，找不到文件报错
    fputs(char[],FILE): 一次写入一个字符串
*/
int Appendfile(char path[]) {
    FILE* fp;
    fp = fopen(path, "a");
    if (fp != NULL) {
        fputs("\n原地追加一个字符串", fp);
    }
    else printf("fail to open! \n");
    fclose(fp);
}

/*
    w+: 可读写，清空并新建文件
    fprintf(FILE,同printf):  格式化写入，格式同printf
    fscanf(FILE,同scanf):    格式化读取，格式同scanf
*/
void Printfile(char path[]) {
    FILE* fp;
    int num = 10;
    char name[10] = "Leeming";
    char gender = 'm';

    fp = fopen(path, "w+");
    if (fp != NULL) {
        fprintf(fp, "%d %s %c", num+1, name, gender);
        rewind(fp); // 指向开头
        fscanf(fp, "%d %s %c", &num, name, &gender);
        printf("%d\n%s\n%c\n", num, name, gender);
    }
    else printf("fail to open! \n");
    fclose(fp);
}

int main()
{
    //Writefile(".\\write1.txt");
    //Readfile(".\\write1.txt");
    //Appendfile(".\\write1.txt");
    //Getsfile(".\\write1.txt");
    Printfile(".\\write2.txt");
    //Readfile(".\\write2.txt");

    return 0;
}