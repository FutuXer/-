//2353726 ��01 ���ϳ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	printf("�����������ε����߼���нǣ��Ƕȣ�\n");
	const double pi = 3.14159;
	int a, b, c;
	scanf("%d %d %d/n", &a, &b, &c);
	float x = (float)sin(c * pi / 180);
	printf("�����ε����Ϊ : %.3f\n", (float)0.5 * a * b * x);


	return 0;
}