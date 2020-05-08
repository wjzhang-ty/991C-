/*
	��һ���� C���Ի�������
*/
#include <stdio.h>

#define PI 3.1415926	// ��ӷ��
#define plus PI+2		// ���滻����ִ�����㣬���ȼ����滻��ı��ʽ����

int main() {	// ����ͷ 
	/*	
		int i = 1;
		���� ���� = ����;	
	*/
	const int i = 2147483647.9;	// const ���ɸ��ı���������ȡ��
	int  x, y;
	unsigned short s = 100;		// ������ȡֵ��Χ���ӵ�������Χ������Ϊ��
	long long ll = 9223372036854775807;		

	/*
		C��û���ַ������ͣ��ַ�����Char���鹹��
		Char�����ţ��ַ���˫����
	*/
	char c = 'abc';	// ���ܱ���c
	char str[] = "abc";

	float f = 0.32;
	double d = 101e-5;

	/* 
		ö�� 
		Ĭ����0->n
		����4��=10ʱ  ��5����11��ʼ����	
	*/
	enum testEnum {t1, t2, t3, t4=10, t5, t6};

	printf("Unsigned short  %%u:\t %u\n", s);
	printf("Long Long       %%lld:\t %lld\n",ll);
	printf("Long Long       %%d:\t %d\n", ll);
	printf("Int 8����       %%o:\t %o\n", i);
	printf("Int 10����      %%d:\t %d\n", i);
	printf("Int 16����      %%x:\t %x\n", i);
	printf("λ����          %%d:\t %d\n\n", 3<<3);	// ��תΪ2������ƽ�� 

	printf("Chart           %%c:\t %c\n", c);
	printf("Chart��ASCII��  %%d:\t %d\n", c);
	printf("ASCII�������   %%d:\t %d\n", c+'1');	// ASCII�����Ӽ�
	printf("Chartλ����     %%d:\t %c\n", c>>1);	// λ������Զ�ASCII
	printf("�ַ���          %%s:\t %s\n", str);
	printf("�ַ���[2]       %%c:\t %c\n\n", str[2]);

	printf("Float           %%f:\t %f\n", f);
	printf("Float��e        %%e:\t %e\n", f);
	printf("Double          %%lf:\t %lf\n\n", d);

	printf("���^ ͬ0��1:   %%d:\t %d\n\n", 1 ^ 1);

	printf("�꣺�滻�������:%lf:\n\n", plus * plus);

	printf("ö�٣�t1=%d t2=%d t3=%d t4=%d t5=%d t6=%d\n\n", t1, t2, t3, t4, t5, t6);

	/* ǿ������ת�� */
	printf("(double)(7/5)=  0%lf\n", (double)(7 / 5));
	printf("(double)7/5  =  %lf\n", (double)7 / 5);
	printf("(int)1.9     =  %d\n\n", (int)1.9);	// ����ȡ������ȡС������x-(int)x
	
	printf("������������\n");
	scanf_s("%d%x", &x, &y);
	printf("��������%d(10����)  %d(16����)\n\n", x, y);
	return 0;
}