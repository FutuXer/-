//2353726 ��01 ���ϳ�
#include <iostream>
using namespace std;

int main()
{
	char a[3][128] = { 0 };
	int daxie = 0;
	int xiaoxie = 0;
	int shuzi = 0;
	int kongge = 0;
	int qita = 0;
	cout << "�������1��" << endl;
	cin.getline(a[0], 128, '\n');
	cout << "�������2��" << endl;
	cin.getline(a[1], 128, '\n');
	cout << "�������3��" << endl;
	cin.getline(a[2], 128, '\n');
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 127; j++)
		{
			if (a[i][j] == 0)
				break;
			if (a[i][j] >= 'A' && a[i][j] <= 'Z')
				daxie++;
			else if (a[i][j] >= 'a' && a[i][j] <= 'z')
				xiaoxie++;
			else if (a[i][j] >= '0' && a[i][j] <= '9')
				shuzi++;
			else if (a[i][j] == ' ')
				kongge++;
			else if (a[i][j] != '\0')
				qita++;
		}
	}
	cout << "��д : " << daxie << endl;
	cout << "Сд : " << xiaoxie << endl;
	cout << "���� : " << shuzi << endl;
	cout << "�ո� : " << kongge << endl;
	cout << "���� : " << qita << endl;

	return 0;
}