/* 2353726 ��01 ���ϳ� */
#include <iostream>
#include<limits.h>
#include<cmath>
using namespace std;

void case3(double a, double b, double c)
{
	double x;
	x = (-b) / (2 * a);
	if (x == -0)
	{
		x = 0;
	}
	cout << "���������ʵ����" << endl;
	cout << "x1=x2=" << x << endl;
}