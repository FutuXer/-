//2353726 ��01 ���ϳ�
#include <iostream>
#include <string>
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�";
string result;

void daxie(int num, int flag_of_zero)
{
	if (num == 0)
	{
		if (flag_of_zero)
			result = result + chnstr[0] + chnstr[1];
	}
	else if (num > 0 && num < 10)
	{
		result = result + chnstr[2 * num] + chnstr[2 * num + 1];
	}
	else
	{
		result = result + "error\n";
	}
}

int main()
{
	cout << "������[0-100��)֮������֣�" << endl;
	double a;
	cin >> a;
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
	int g0, h0, i0, k0, l0, m0, n0, o0;
	if (f + h + i + j + k + l + m + n == 0 || f + h + i + j == 0 || h + i + j == 0)
	{
		g0 = 0;
	}
	else if (e + f == 0)
	{
		g0 = 0;
	}
	else
	{
		g0 = 1;
	}
	if (g == 0)
	{
		h0 = 0;
	}
	else if (i == 0 && j == 0)
	{
		h0 = 0;
	}
	else
	{
		h0 = 1;
	}
	if (h == 0)
	{
		i0 = 0;
	}
	else if (j == 0)
	{
		i0 = 0;
	}
	else
	{
		i0 = 1;
	}
	if (a > 9999.99 && l + m + n > 0)
	{
		k0 = 1;
	}
	else if (a > 9999.99 && l + m + n == 0)
	{
		k0 = 0;
	}
	else
	{
		k0 = 0;
	}
	if (k == 0)
	{
		l0 = 0;
	}
	else if (m == 0 && n == 0)
	{
		l0 = 0;
	}
	else
	{
		l0 = 1;
	}
	if (l == 0)
	{
		m0 = 0;
	}
	else if (n == 0)
	{
		m0 = 0;
	}
	else
	{
		m0 = 1;
	}
	if (e + f + g + h + i + j + k + l + m == 0 && o + p == 0)
	{
		n0 = 1;
	}
	else
	{
		n0 = 0;
	}
	if (e + f + g + h + i + j + k + l + m + n > 0 && p > 0)
	{
		o0 = 1;
	}
	else
	{
		o0 = 0;
	}
	daxie(e, 0);
	if (e > 0)
		result = result + "ʰ";
	daxie(f, 0);
	if (f + e > 0)
		result = result + "��";
	daxie(g, g0);
	if (g > 0)
		result = result + "Ǫ";
	daxie(h, h0);
	if (h > 0)
		result = result + "��";
	daxie(i, i0);
	if (i > 0)
		result = result + "ʰ";
	daxie(j, 0);
	if (g > 0 || h > 0 || i > 0 || j > 0)
		result = result + "��";
	daxie(k, k0);
	if (k > 0)
		result = result + "Ǫ";
	daxie(l, l0);
	if (l > 0)
		result = result + "��";
	daxie(m, m0);
	if (m > 0)
		result = result + "ʰ";
	daxie(n, n0);
	if (e + f + g + h + i + j + k + l + m + n == 0 && o + p > 0)
	{
	}
	else
	{
		result = result + "Բ";
	}
	if (o == 0 && p == 0)
	{
		result = result + "��";
	}
	else
	{
		daxie(o, o0);

	}
	if (o > 0)
	{
		result = result + "��";
	}
	daxie(p, 0);
	if (p > 0)
	{
		result = result + "��";
	}
	else if (p == 0 && o > 0)
	{
		result = result + "��";
	}
	cout << "��д����ǣ�" << endl;
	cout << result << endl;

	return 0;
}