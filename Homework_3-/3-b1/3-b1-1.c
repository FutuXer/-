//2353726 ��01 ���ϳ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("������뾶�͸߶�\n");
	const double pi = 3.14159;
	double a;
	double b;
	scanf("%lf %lf", &a, &b);
	printf("Բ�ܳ�     : %.2lf\n",2*pi*a);
	printf("Բ���     : %.2lf\n",pi*a*a);
	printf("Բ������ : %.2lf\n",4*pi*a*a);
	printf("Բ�����   : %.2lf\n",4*pi*a*a*a/3);
	printf("Բ�����   : %.2lf\n",pi*a*a*b);





	return 0;
}