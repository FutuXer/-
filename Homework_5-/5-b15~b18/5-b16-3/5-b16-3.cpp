//2353726 ��01 ���ϳ�
#include <iostream>
#include <string>
using namespace std;

void input(string num[], string name[], int grade[], int i)
{
	cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
	cin >> num[i] >> name[i] >> grade[i];
}

void rank0(string num[], string name[], int grade[])
{
	string number = "";
	string name0 = "";
	int marks = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (num[j] > num[j + 1])
			{
				number = num[j];
				name0 = name[j];
				marks = grade[j];
				num[j] = num[j + 1];
				name[j] = name[j + 1];
				grade[j] = grade[j + 1];
				num[j + 1] = number;
				name[j + 1] = name0;
				grade[j + 1] = marks;
			}
		}
	}
}

void output(string num[], string name[], int grade[])
{
	cout << endl;
	cout << "ȫ��ѧ��(ѧ������):" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << name[i] << " " << num[i] << " " << grade[i] << endl;
	}
}

int main()
{
	string num[10] = { "" };
	string name[10] = { "" };
	int grade[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		input(num, name, grade, i);
	}
	rank0(num, name, grade);
	output(num, name, grade);

	return 0;
}
