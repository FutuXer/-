//2353726 ��01 ���ϳ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("������һ��[0-100��)�������:\n");
    double a;
    scanf("%lf", &a);
    double x = a + 1e-6;
    int b = (int)(x / 10);
    double c = x / 10 - b;
    int d = b / 1000000000;
    int e = b / 100000000 - 10 * d;
    int f = b / 10000000 - 10 * e - 100 * d;
    int g = b / 1000000 - 1000 * d - 100 * e - 10 * f;
    int h = b / 100000 - 10000 * d - 1000 * e - 100 * f - 10 * g;
    int i = b / 10000 - 100000 * d - 10000 * e - 1000 * f - 100 * g - 10 * h;
    int j = b / 1000 - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i;
    int k = b / 100 - 10000000 * d - 1000000 * e - 100000 * f - 10000 * g - 1000 * h - 100 * i - 10 * j;
    int l = b / 10 - 100000000 * d - 10000000 * e - 1000000 * f - 100000 * g - 10000 * h - 1000 * i - 100 * j - 10 * k;
    int m = b / 1 - 1000000000 * d - 100000000 * e - 10000000 * f - 1000000 * g - 100000 * h - 10000 * i - 1000 * j - 100 * k - 10 * l;
    int n = (int)(10 * c);
    int o = (int)(100 * c) - 10 * n;
    int p = (int)(1000 * c) - 100 * n - 10 * o;
    printf("ʮ��λ : %d\n", e);
    printf("��λ   : %d\n", f);
    printf("ǧ��λ : %d\n", g);
    printf("����λ : %d\n", h);
    printf("ʮ��λ : %d\n", i);
    printf("��λ   : %d\n", j);
    printf("ǧλ   : %d\n", k);
    printf("��λ   : %d\n", l);
    printf("ʮλ   : %d\n", m);
    printf("Բ     : %d\n", n);
    printf("��     : %d\n", o);
    printf("��     : %d\n", p);

	
	





	return 0;
}