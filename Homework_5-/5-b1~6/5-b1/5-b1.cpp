/* 2353726 ��01 ���ϳ� */
#include <iostream>
using namespace std;


int main()
{
	bool x = 1;
	cout << "��������������������������20������0������������" << endl;
	int a[21];
	for (int i = 0; i < 21 ;i++)
	{
		cin >> a[i];
		if (a[0] <= 0) 
		{
			x = 0;
			cout << "����Ч����" << endl;
		}
		if (a[i] <= 0)
		{
			break;
		}
	}
	cin.clear();
	cin.ignore(1024, '\n');
	if (x == 1)
	{
		cout << "ԭ����Ϊ: " << endl;
		for (int i = 0; i < 20; i++)
		{
			if (a[i] > 0)
			{
				cout << a[i] << " ";
			}
		}
		cout << endl;
		cout << "������Ҫ�����������" << endl;
		cin >> a[20];
		cout << "����������Ϊ��" << endl;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20 - i; j++)
			{
				if (a[j] > a[j + 1])
				{
					int t = a[j];
					a[j] = a[j + 1];
					a[j + 1] = t;
				}
			}
		}
		for (int i = 0; i < 21; i++)
		{
			if (a[i] > 0)
			{
				cout << a[i] << " ";
			}
		}
	}
	cout << endl;
	return 0;
}