/* 2353726 ���ϳ� ��01 */
#include <iostream>
using namespace std;

int fun1(char* str)
{
	int len = 0;
	char* p, * pe;
	pe = str;
	p = str;
	while (*pe != '\0')
	{
		pe++;
	}
	//������Ϊ��β0�ĳ���
	len = pe - str;
	pe = pe - 2;
	for (p = str; p <= str + len - 1; p++)
	{
		if (*p != *pe)
		{
			return 0;
			break;
		}
		if (pe == str)
		{
			break;
		}
		pe--;
	}
	return 1;
}

int main()
{
	char str[80] = { 0 };
	int x = 0;

	cout << "������һ������С��80���ַ��������Ĵ���" << endl;

	fgets(str, 80, stdin);
	x = fun1(str);
	
	if (x == 0)
	{
		cout << "no" << endl;
	}
	if (x == 1)
	{
		cout << "yes" << endl;
	}


	return 0;
}