/* 2353726 ���ϳ� ��01 */
#include <iostream>
#include <conio.h>
#include <iomanip>	
#include <ctime>
#include <cstring>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;

int strlow(char str[])
{
	for (int i = 0; i < 3; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}

	}
	if (strcmp(str, "end\n") == 0)
		return 0;
	else
	{
		return 1;
	}
}

void checkclear(int row, int col, char dig[12][12], char color[12][12])
{
	cout << endl;
	cout << "��ѡ���������ʾ����ͬɫ��ʶ����" << endl;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			color[i][j] = 0;
		}
	}
	//��ʼ����ɫ

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			//dig[i-1][j]��ǵ����
			if (dig[i][j - 1] == dig[i][j + 1] && dig[i - 1][j] == dig[i][j - 1] && dig[i + 1][j] != dig[i - 1][j] && dig[i][j] != dig[i][j - 1])
			{
				color[i][j] = 1;
				color[i - 1][j] = 1;
			}

			//dig[i+1][j]��ǵ����
			if (dig[i][j - 1] == dig[i][j + 1] && dig[i + 1][j] == dig[i][j - 1] && dig[i + 1][j] != dig[i - 1][j] && dig[i][j] != dig[i][j - 1])
			{
				color[i][j] = 1;
				color[i + 1][j] = 1;
			}

			//dig[i][j+1]��ǵ����
			if (dig[i - 1][j] == dig[i + 1][j] && dig[i][j - 1] == dig[i - 1][j] && dig[i][j - 1] != dig[i][j + 1] && dig[i][j] != dig[i - 1][j])
			{
				color[i][j] = 1;
				color[i][j - 1] = 1;
			}

			//dig[i][j-1]��ǵ����
			if (dig[i - 1][j] == dig[i + 1][j] && dig[i][j + 1] == dig[i - 1][j] && dig[i][j - 1] != dig[i][j + 1] && dig[i][j] != dig[i - 1][j])
			{
				color[i][j] = 1;
				color[i][j + 1] = 1;
			}

			//��������ȫ���
			if (dig[i - 1][j] == dig[i + 1][j] && dig[i][j - 1] == dig[i][j + 1] && dig[i - 1][j] == dig[i][j - 1] && dig[i - 1][j] != dig[i][j])
			{
				color[i][j] = 1;
				color[i + 1][j] = 1;
				color[i - 1][j] = 1;
				color[i][j + 1] = 1;
				color[i][j - 1] = 1;
			}
				
			//00X�����
			if (j > 2 && dig[i][j - 2] == dig[i][j - 1] && dig[i][j - 1] == dig[i][j + 1] && dig[i][j] != dig[i][j - 1])
			{
				color[i][j] = 1;
				color[i][j + 1] = 1;
			}
			if (j > 2 && dig[i][j - 2] == dig[i][j - 1] && dig[i][j - 1] == dig[i + 1][j] && dig[i][j] != dig[i][j - 1])
			{
				color[i][j] = 1;
				color[i + 1][j] = 1;
			}
			if (j > 2 && dig[i][j - 2] == dig[i][j - 1] && dig[i][j - 1] == dig[i - 1][j] && dig[i][j] != dig[i][j - 1])
			{
				color[i][j] = 1;
				color[i - 1][j] = 1;
			}

			//X00�����
			if (j <= col - 2 && dig[i][j + 2] == dig[i][j + 1] && dig[i][j - 1] == dig[i][j + 1] && dig[i][j] != dig[i][j + 1])
			{
				color[i][j] = 1;
				color[i][j - 1] = 1;
			}
			if (j <= col - 2 && dig[i][j + 2] == dig[i][j + 1] && dig[i + 1][j] == dig[i][j + 1] && dig[i][j] != dig[i][j + 1])
			{
				color[i][j] = 1;
				color[i + 1][j] = 1;
			}
			if (j <= col - 2 && dig[i][j + 2] == dig[i][j + 1] && dig[i - 1][j] == dig[i][j + 1] && dig[i][j] != dig[i][j + 1])
			{
				color[i][j] = 1;
				color[i - 1][j] = 1;
			}

			//X��00�����
			if (i > 2 && dig[i - 2][j] == dig[i - 1][j] && dig[i - 1][j] == dig[i][j - 1] && dig[i - 1][j] != dig[i][j])
			{
				color[i][j] = 1;
				color[i][j - 1] = 1;
			}
			if (i > 2 && dig[i - 2][j] == dig[i - 1][j] && dig[i - 1][j] == dig[i][j + 1] && dig[i - 1][j] != dig[i][j])
			{
				color[i][j] = 1;
				color[i][j + 1] = 1;
			}
			if (i > 2 && dig[i - 2][j] == dig[i - 1][j] && dig[i - 1][j] == dig[i + 1][j] && dig[i - 1][j] != dig[i][j])
			{
				color[i][j] = 1;
				color[i + 1][j] = 1;
			}

			//X��00�����
			if (i <= row - 2 && dig[i + 2][j] == dig[i + 1][j] && dig[i + 1][j] == dig[i][j - 1] && dig[i + 1][j] != dig[i][j])
			{
				color[i][j] = 1;
				color[i][j - 1] = 1;
			}
			if (i <= row - 2 && dig[i + 2][j] == dig[i + 1][j] && dig[i + 1][j] == dig[i][j + 1] && dig[i + 1][j] != dig[i][j])
			{
				color[i][j] = 1;
				color[i][j + 1] = 1;
			}
			if (i <= row - 2 && dig[i + 2][j] == dig[i + 1][j] && dig[i + 1][j] == dig[i - 1][j] && dig[i + 1][j] != dig[i][j])
			{
				color[i][j] = 1;
				color[i - 1][j] = 1;
			}
		
		}
	}

	int row0;
	char letter;
	row0 = 0;
	for (int i = 0; i <= col; i++, row0++)
	{
		if (i == 0)
			cout << "  |";
		else
			cout << std::right << setw(3) << row0;
	}
	cout << endl;
	for (int i = 0; i <= col; i++)
	{
		if (i == 0)
			cout << "--+";
		else
			cout << "---";
	}
	cout << "-" << endl;
	letter = 'A';
	for (int i = 1; i <= row; i++)
	{
		cout << letter << " |";
		for (int j = 1; j <= col; j++)
		{
			if (color[i][j] == 1)
			{
				cout << "  ";
				cct_setcolor(14, 2);
				cout << int(dig[i][j]);
				cct_setcolor();
			}
			else
			{
				cout << std::right << setw(3) << int(dig[i][j]);
			}
		}
		cout << endl;
		letter++;
	}
	cout << endl;
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
//����Ƿ��������

int checkdig(int row, int col, char dig[12][12], char color[12][12])
{
	int xiao = 0;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col - 2; j++)
		{
			int k = 1;
			while (1)
			{
				if (dig[i][k + j] != dig[i][j])
					break;
				else
					k++;
			}
			if (k >= 3)
			{
				for (int m = 0; m < k; m++)
				{
					color[i][m + j] = 1;
				}
				xiao = 1;
			}
		}
	}
	//ȷ��������Ҫ��ɫ������
	for (int i = 1; i <= col; i++)
	{
		for (int j = 1; j <= row - 2; j++)
		{
			int k = 1;
			while (1)
			{
				if (dig[j + k][i] != dig[j][i])
					break;
				else
					k++;
			}
			if (k >= 3)
			{
				for (int m = 0; m < k; m++)
				{
					color[j + m][i] = 1;
				}
				xiao = 1;
			}
		}
	}
	//ȷ����������Ҫ��ɫ������
	return xiao;
}
//�����ɫ����

void supplydig(int row, int col, char dig[12][12], char color[12][12], int sj)
{
	int xiao = 0;
	int row0 = 0;
	char letter = 0;
	cout << endl;
	cout << "���س���������ֵ���..." << endl;
	cout << "��ֵ��������飨��ͬɫ��ʶ����" << endl;
	char back;
	while (1)
	{
		back = _getch();
		if (back == '\r')
		{
			break;
		}
		else
		{
			continue;
		}
	}
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (color[i][j] == 1)
			{
				dig[i][j] = 1 + rand() % (9);
			}
		}
	}
	row0 = 0;
	for (int i = 0; i <= col; i++, row0++)
	{
		if (i == 0)
			cout << "  |";
		else
			cout << std::right << setw(3) << row0;
	}
	cout << endl;
	for (int i = 0; i <= col; i++)
	{
		if (i == 0)
			cout << "--+";
		else
			cout << "---";
	}
	cout << "-" << endl;
	letter = 'A';
	for (int i = 1; i <= row; i++)
	{
		cout << letter << " |";
		for (int j = 1; j <= col; j++)
		{
			if (color[i][j] == 1)
			{
				cout << "  ";
				cct_setcolor(14, 3);
				cout << int(dig[i][j]);
				cct_setcolor();
			}
			else
			{
				cout << std::right << setw(3) << int(dig[i][j]);
			}
		}
		cout << endl;
		letter++;
	}
	cout << endl;
	char jieshu[4] = { 0 };
	xiao = checkdig(row, col, dig, color);
	if (xiao == 0)
	{
		cout << "��ʼ���޿�������" << endl;
		if (sj == 2)
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
		if (sj == 3)
		{
			checkclear(row, col, dig, color);
		}
	}
	if (xiao == 1)
	{
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				color[i][j] = 0;
			}
		}
		//��ʼ����ɫ
		cout << endl;
		cout << "��ʼ���������ͬɫ��ʶ����" << endl;
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col - 2; j++)
			{
				int k = 1;
				while (1)
				{
					if (dig[i][k + j] != dig[i][j])
						break;
					else
						k++;
				}
				if (k >= 3)
				{
					for (int m = 0; m < k; m++)
					{
						color[i][m + j] = 1;
					}
					xiao = 1;
				}
			}
		}
		//ȷ��������Ҫ��ɫ������
		for (int i = 1; i <= col; i++)
		{
			for (int j = 1; j <= row - 2; j++)
			{
				int k = 1;
				while (1)
				{
					if (dig[j + k][i] != dig[j][i])
						break;
					else
						k++;
				}
				if (k >= 3)
				{
					for (int m = 0; m < k; m++)
					{
						color[j + m][i] = 1;
					}
					xiao = 1;
				}
			}
		}
		//ȷ����������Ҫ��ɫ������
		row0 = 0;
		for (int i = 0; i <= col; i++, row0++)
		{
			if (i == 0)
				cout << "  |";
			else
				cout << std::right << setw(3) << row0;
		}
		cout << endl;
		for (int i = 0; i <= col; i++)
		{
			if (i == 0)
				cout << "--+";
			else
				cout << "---";
		}
		cout << "-" << endl;
		letter = 'A';
		for (int i = 1; i <= row; i++)
		{
			cout << letter << " |";
			for (int j = 1; j <= col; j++)
			{
				if (color[i][j] == 1)
				{
					cout << "  ";
					cct_setcolor(14, 3);
					cout << int(dig[i][j]);
					cct_setcolor();
				}
				else
				{
					cout << std::right << setw(3) << int(dig[i][j]);
				}
			}
			cout << endl;
			letter++;
		}
		dropdig(row, col, dig, color, xiao, sj);
	}
}
//��ֵ��亯��

void dropdig(int row, int col, char dig[12][12], char color[12][12], int x, int sj)
{
	cout << endl;
	int row0 = 0;
	char letter = 0;
	if (x == 1)
	{
		cout << "���س����������������0����..." << endl;
		char back;
		while (1)
		{
			back = _getch();
			if (back == '\r')
			{
				break;
			}
			else
			{
				continue;
			}
		}
		for (int j = 1; j <= col; j++)
		{
			int times = 0;
			for (int i = 1; i <= row; i++)
			{

				if (color[i][j] == 1)
				{				
					color[i][j] = 0;
					for (int k = i - 1; k > times; k--)
					{
						dig[k + 1][j] = dig[k][j];
						color[k + 1][j] = color[k][j];
					}
					times++;
					dig[times][j] = 0;
					color[times][j] = 1;				
				}
			}
		}
		row0 = 0;
		for (int i = 0; i <= col; i++, row0++)
		{
			if (i == 0)
				cout << "  |";
			else
				cout << std::right << setw(3) << row0;
		}
		cout << endl;
		for (int i = 0; i <= col; i++)
		{
			if (i == 0)
				cout << "--+";
			else
				cout << "---";
		}
		cout << "-" << endl;
		letter = 'A';
		for (int i = 1; i <= row; i++)
		{
			cout << letter << " |";
			for (int j = 1; j <= col; j++)
			{
				if (color[i][j] == 1)
				{
					cout << "  ";
					cct_setcolor(14, 4);
					cout << int(dig[i][j]);
					cct_setcolor();
				}
				else
				{
					cout << std::right << setw(3) << int(dig[i][j]);
				}
			}
			cout << endl;
			letter++;
		}
		supplydig(row, col, dig, color, sj);
	}
	if (x == 0)
	{
		cout << "��ʼ�޿��������С���޷����ԣ����ٴ�����" << endl;
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
}
//�����0����

void dig_ini(int row, int col, int sj)
{
	srand(static_cast<unsigned int>(time(nullptr)));


	char dig[12][12] = { 0 };
	char color[12][12] = { 0 };

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			dig[i][j] = 1 + rand() % (9);
		}
	}
	
	if (sj == 6 || sj == 7 || sj == 8 || sj == 9)
	{
		ini_struct(row,col,dig,color,sj);
	}
	int row0 = 0;
	if (sj != 6 && sj != 7 && sj != 8 && sj != 9)
	{
		cout << "��ʼ����:" << endl;
	
		for (int i = 0; i <= col; i++, row0++)
		{
			if (i == 0)
				cout << "  |";
			else
				cout << std::right << setw(3) << row0;
		}
		cout << endl;
		for (int i = 0; i <= col; i++)
		{
			if (i == 0)
				cout << "--+";
			else
				cout << "---";
		}
		cout << "-" << endl;
		char letter = 'A';
		for (int i = 1; i <= row; i++)
		{
			cout << letter << " |";
			for (int j = 1; j <= col; j++)
			{
				cout << std::right << setw(3) << int(dig[i][j]);
			}
			cout << endl;
			letter++;
		}
		cout << endl;
	}
	if (sj == 4 || sj == 5)
	{
		cout << "���س�����ʾͼ��...";

		char back;
		while (1)
		{
			back = _getch();
			if (back == '\r')
			{
				break;
			}
			else
			{
				continue;
			}
		}
		cout << endl;
		ini_struct(row, col, dig, color, sj);
	}	
	if (sj != 4 && sj != 5 && sj != 6 && sj != 7 && sj != 8 && sj != 9)
	{
		bool xiao = 0;
		char letter = 0;
		cout << "���س�������Ѱ�ҳ�ʼ��������Ĳ���...";
		char back;
		while (1)
		{
			back = _getch();
			if (back == '\r')
			{
				break;
			}
			else
			{
				continue;
			}
		}
		cout << endl;
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col - 2; j++)
			{
				int k = 1;
				while (1)
				{
					if (dig[i][k + j] != dig[i][j])
						break;
					else
						k++;
				}
				if (k >= 3)
				{
					for (int m = 0; m < k; m++)
					{
						color[i][m + j] = 1;
					}
					xiao = 1;
				}
			}
		}
		//ȷ��������Ҫ��ɫ������
		for (int i = 1; i <= col; i++)
		{
			for (int j = 1; j <= row - 2; j++)
			{
				int k = 1;
				while (1)
				{
					if (dig[j + k][i] != dig[j][i])
						break;
					else
						k++;
				}
				if (k >= 3)
				{
					for (int m = 0; m < k; m++)
					{
						color[j + m][i] = 1;
					}
					xiao = 1;
				}
			}
		}
		//ȷ����������Ҫ��ɫ������
		if (xiao == 1)
		{
			cout << "��ʼ���������ͬɫ��ʶ����" << endl;
			row0 = 0;
			for (int i = 0; i <= col; i++, row0++)
			{
				if (i == 0)
					cout << "  |";
				else
					cout << std::right << setw(3) << row0;
			}
			cout << endl;
			for (int i = 0; i <= col; i++)
			{
				if (i == 0)
					cout << "--+";
				else
					cout << "---";
			}
			cout << "-" << endl;
			letter = 'A';
			for (int i = 1; i <= row; i++)
			{
				cout << letter << " |";
				for (int j = 1; j <= col; j++)
				{
					if (color[i][j] == 1)
					{
						cout << "  ";
						cct_setcolor(14, 3);
						cout << int(dig[i][j]);
						cct_setcolor();
					}
					else
					{
						cout << std::right << setw(3) << int(dig[i][j]);
					}
				}
				cout << endl;
				letter++;
			}
			if (sj == 1)
			{
				cout << endl;
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
		}
		else if (sj == 1 && xiao == 0)
		{
			cout << "��ʼ���޿�������" << endl;
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
		if (sj == 2)
		{
			dropdig(row, col, dig, color, xiao, sj);
		}
		if (sj == 3 && xiao == 1)
		{
			dropdig(row, col, dig, color, xiao, sj);
		}
		if (sj == 3 && xiao == 0)
		{
			cout << "��ʼ���޿�������" << endl;
			checkclear(row, col, dig, color);
		}
	}

}
//��ʼ����

