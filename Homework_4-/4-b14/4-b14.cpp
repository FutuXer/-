/* 2353726 ��01 ���ϳ� */
#include <iostream>
#include<limits.h>
#include<cmath>
using namespace std;

void case1()
{
	cout << "����һԪ���η���" << endl;
}

void case2(double a, double b, double c)
{
	double x1, x2;
	x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	cout << "����������ʵ����" << endl;
	if (x1 > x2) {
		cout << "x1=" << x1 << endl;
		cout << "x2=" << x2 << endl;
	}
	else {
		cout << "x1=" << x2 << endl;
		cout << "x2=" << x1 << endl;
	}
}

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

void case4(double a, double b, double c)
{
	cout << "�����������" << endl;
	double shibu = -b / (2 * a);
	double xubu = fabs(sqrt(-b * b + 4 * a * c) / (2 * a));
	if (fabs(xubu - 1) < 1e-6)//�鲿Ϊ����һ�����
	{
		if (fabs(shibu) > 1e-6)
		{
			cout << "x1=" << shibu << "+" << "i" << endl;
			cout << "x2=" << shibu << "-" << "i" << endl;
		}
		else//ʵ��Ϊ0�����
		{
			cout << "x1=" << "i" << endl;
			cout << "x2=" << "-i" << endl;
		}
	}
	else if (fabs(shibu) < 1e-6)
	{
		cout << "x1=" << xubu << "i" << endl;
		cout << "x2=-" << xubu << "i" << endl;
	}
	else
	{
		cout << "x1=" << shibu << "+" << xubu << "i" << endl;
		cout << "x2=" << shibu << "-" << xubu << "i" << endl;
	}
	
}

int main()
{
	double a = 0;
	double b = 0;
	double c = 0;

	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
	cin >> a >> b >> c;

	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;

	double delta = b * b - 4 * a * c;
	if (fabs(delta) < 1e-6)
		delta = 0;
	if (a == 0)
		case1();
	else
	{
		if (delta > 0)
			case2(a, b, c);
		if (delta == 0)
			case3(a, b, c);
		if (delta < 0)
			case4(a, b, c);
	}

	return 0;
}