/* 2353726 ���ϳ� ��01 */
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	char str[32] = { 0 }, * p, * pe;
	p = str;
	pe = str;
	int power = 0;
	int sum = 0;

	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	cin >> str;

	while (*pe != '\0')
	{
		pe++;
	}
	power = pe - str - 1;
	for (p = str; p <= pe - 1; p++)
	{
		if (*p == '1')
		{
			sum = sum + (unsigned int)pow(2, power);
		}
		power--;
	}

	cout << sum << endl;
}