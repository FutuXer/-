/* 2353726 ��01 ���ϳ� */
#include <iostream>
using namespace std;

//87 86 56 76 87 92 76 96 98 23 55 56 34 23 -1
int main()
{
	int a[1000];
	int i = 0;
	cout << "������ɼ������1000������������������" << endl;
	for (i = 0; i < 1000; i++)
	{
		cin >> a[i];
		if (a[0] < 0)
		{
			cout << "����Ч����" << endl;
			break;
		}
		if (a[i] < 0)
		{
			break;
		}
	}
	if (a[0] >= 0)
	{
		cout << "���������Ϊ:" << endl;
		for (int j = 0; j < i; j++)
		{
			cout << a[j] << " ";
			if ((j + 1) % 10 == 0)
				cout << endl;
		}
		cout << endl;
		cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < i - j; k++)
			{
				if (a[k] < a[k + 1])
				{
					int t = a[k];
					a[k] = a[k + 1];
					a[k + 1] = t;
				}
			}
		}
		int rank = 1;
		int num = 1;
		int m = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] == a[j + 1])
			{
				cout << a[j] << " " << rank << endl;
				num = num + 1;
			}
			if (a[j] != a[j + 1])
			{
				cout << a[j] << " " << rank << endl;
				num = num + 1;
				rank = num;
			}
		}
	}



}