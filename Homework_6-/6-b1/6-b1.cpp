/* 2353726 ���ϳ� ��01 */
#include <iostream>
#include <string.h>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	//hello -123w xyz k456.78 kjd 98
	cout << "�����������������������ֵ��ַ���" << endl;
	gets_s(str);
	p = str;
	pa = a;
	while (*p != '\0')
	{
		if (pa - a > 9)
		{
			break;
		}
		if (*p >= '0' && *p <= '9')
		{
			is_num = 1;
			*pa = int(*p - 48);
			p++;
			while (*p >= '0' && *p <= '9')
			{
				is_num = 1;
				*pa = *pa * 10 + int(*p - 48);
				p++;
			}
			pa++;
		}	
		else
		{
			p++;
		}
	}

	cout << "����" << pa - a << "������" << endl;

	for (pnum = a; pnum < pa; pnum++)
	{
		cout << *pnum << " ";
	}
	cout << endl;

	return 0;
}