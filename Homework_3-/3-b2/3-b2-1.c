//2353726 ��01 ���ϳ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("������һ��[1..30000]�������:\n"); 
	int a;
	scanf("%d", &a);
    int b = a / 10000;
	int c = a / 1000-10*b;
	int d = a / 100-10*c-100*b;
	int e = a / 10-1000*b-100*c-10*d;
	int f = a - 10000 * b-1000*c-100*d-10*e;
	printf("��λ : %d\n", b);
	printf("ǧλ : %d\n", c);
	printf("��λ : %d\n", d);
	printf("ʮλ : %d\n", e);
	printf("��λ : %d\n", f);
	




	return 0;
}