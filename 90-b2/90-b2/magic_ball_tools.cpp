/* 2353726 ���ϳ� ��01 */
#include <iostream>
#include <conio.h>
#include <iomanip>	
#include <ctime>
#include <cstring>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;

void jieshu()
{
	cout << "��С�������������End����...";
	int x = 0, y = 0;
	cct_getxy(x, y);
	cin.clear();
	cin.ignore(1024, '\n');
	while (1)
	{
		char jieshu[2048] = { 0 };
		for (int i = 0; ; i++)
		{
			jieshu[i] = getchar();
			if (jieshu[i] == '\n')
			{
				break;
			}
		}
		if (strlow(jieshu) == 0)
		{
			cct_cls();
			break;
		}
		else
		{
			cct_gotoxy(x, y);
			for (int i = 0; i < 3; i++)
			{
				jieshu[i] = 0;
			}
			cct_gotoxy(x, y);
			cout << "   " << endl;
			cout << "�����������������";
			cct_gotoxy(x, y);
			continue;
		}
	}
}
