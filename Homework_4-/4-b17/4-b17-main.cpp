/* 2353726 ��01 ���ϳ� */
#include <iostream>
#include<limits.h>
#include<cmath>
using namespace std;

double a = 0;
double b = 0;
double c = 0;

void case1();
void case2();
void case3();
void case4();

int main()
{

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
			case2();
		if (delta == 0)
			case3();
		if (delta < 0)
			case4();
	}

	return 0;
}