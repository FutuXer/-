/* 2353726 ���ϳ� ��01 */
#include <iostream>
#include <conio.h>
#include <iomanip>	
#include <ctime>
#include <cstring>
#include <cmath>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;

void graph_check_clear(int row, int col, char dig[12][12], char color[12][12], int piccolor[12][12])
{
	char str[5] = { "��" };
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
	//����Ƿ��������

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (color[i][j] == 1)
			{
				cct_showstr(4 * j - 2, 2 * i, str, piccolor[i][j], 0, 1, 2);
			}
		}
	}
}

void draw_struc(int row, int col, char dig[12][12], char color[12][12], int piccolor[12][12], int sj = 0)
{
	char str1[5] = { "�X" };
	char str2[5] = { "�[" };
	char str3[5] = { "�^" };
	char str4[5] = { "�a" };
	char str5[5] = { "�T" };
	char str6[5] = { "�U" };
	char str7[5] = { "��" };
	char str8[5] = { "��" };
	char str9[5] = { "�j" };
	char str10[5] = { "�d" };
	char str11[5] = { "�p" };
	char str12[5] = { "�g" };
	char str13[5] = { "�m" };
	char str14[5] = { "  " };
	char str15[5] = { "��" };
	char str16[5] = { "��" };
	if (sj == 4)
	{
		cct_setconsoleborder(40, row + 6, 100, 100);
		cout << "��Ļ��" << row + 6 << "��40��" << endl;
		cct_showstr(1, 1, str1, 7, 0, 1, 2);
		cct_showstr(2 * col + 3, 1, str2, 7, 0, 1, 2);
		cct_showstr(1, row + 2, str3, 7, 0, 1, 2);
		cct_showstr(2 * col + 3, row + 2, str4, 7, 0, 1, 2);
		for (int i = 1; i <= col; i++)
		{
			cct_showstr(2 * i + 1, 1, str5, 7, 0, 1, 2);
			Sleep(30);
		}
		for (int i = 1; i <= col; i++)
		{
			cct_showstr(2 * i + 1, row + 2, str5, 7, 0, 1, 2);
			Sleep(30);
		}
		for (int i = 3; i <= row + 2; i++)
		{
			cct_showstr(1, i - 1, str6, 7, 0, 1, 2);
			Sleep(30);
		}
		for (int i = 3; i <= row + 2; i++)
		{
			cct_showstr(2 * col + 3, i - 1, str6, 7, 0, 1, 2);
			Sleep(30);
		}
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{

				cct_showstr(2 * j + 1, i + 1, str7, piccolor[i][j], 0, 1, 2);
				Sleep(30);
			}
		}
		cct_setcolor();
	}
	if (sj == 5)
	{
		cct_setconsoleborder(40, 2 * row + 5, 100, 100);
		cout << "��Ļ��" << 2 * row + 5 << "��40��" << endl;
		for (int i = 1; i <= 2 * row + 1; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (i == 1 && j == 1)
				{
					cct_showstr(0, 1, str1, 7, 0, 1, 2);
					Sleep(10);
					cct_showstr(2, 1, str5, 7, 0, 1, 2);
					Sleep(10);
				}
				if (j != 1 && i == 1)
				{
					cct_showstr(4 * j - 4, 1, str9, 7, 0, 1, 2);
					Sleep(10);
					cct_showstr(4 * j - 2, 1, str5, 7, 0, 1, 2);
					Sleep(10);
				}
				if (i == 1 && j == col)
				{
					cct_showstr(4 * j, 1, str2, 7, 0, 1, 2);
					Sleep(10);
				}
				//��һ��
				if (i % 2 == 0)
				{
					cct_showstr(4 * j - 4, i, str6, 7, 0, 1, 2);
					Sleep(10);
					cct_showstr(4 * j - 2, i, str14, 7, 7, 1, 2);
					Sleep(10);
					if (j == col)
					{
						cct_showstr(4 * j, i, str6, 7, 0, 1, 2);
					}
					Sleep(10);
				}
				//ż����

				if (i % 2 == 1 && i != 1 && i != 2 * row + 1)
				{
					if (j == 1)
					{
						cct_showstr(0, i, str10, 7, 0, 1, 2);
						Sleep(10);
						cct_showstr(2, i, str5, 7, 0, 1, 2);
						Sleep(10);
					}
					if (j != 1)
					{
						cct_showstr(4 * j - 4, i, str11, 7, 0, 1, 2);
						Sleep(10);
						cct_showstr(4 * j - 2, i, str5, 7, 0, 1, 2);
						Sleep(10);
					}
					if (j == col)
					{
						cct_showstr(4 * j, i, str12, 7, 0, 1, 2);
						Sleep(10);

					}					
				}
				//������

				if (i == 2 * row + 1)
				{
					if (j == 1)
					{
						cct_showstr(0, i, str3, 7, 0, 1, 2);
						Sleep(10);
						cct_showstr(2, i, str5, 7, 0, 1, 2);
						Sleep(10);
					}
					if (j != 1)
					{
						cct_showstr(4 * j - 4, i, str13, 7, 0, 1, 2);
						Sleep(10);
						cct_showstr(4 * j - 2, i, str5, 7, 0, 1, 2);
						Sleep(10);
					}
					if (j == col)
					{
						cct_showstr(4 * j, i, str4, 7, 0, 1, 2);
						Sleep(10);
					}
				}
				//���һ��
			}
		}
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
				Sleep(30);
			}
		}
		cct_setcolor();
	}
	if (sj == 6)
	{
		cct_setconsoleborder(40, row + 6, 100, 100);
		cout << "��Ļ��" << row + 6 << "��40��" << endl;
		cct_showstr(1, 1, str1, 7, 0, 1, 2);
		cct_showstr(2 * col + 3, 1, str2, 7, 0, 1, 2);
		cct_showstr(1, row + 2, str3, 7, 0, 1, 2);
		cct_showstr(2 * col + 3, row + 2, str4, 7, 0, 1, 2);
		for (int i = 1; i <= col; i++)
		{
			cct_showstr(2 * i + 1, 1, str5, 7, 0, 1, 2);
		}
		for (int i = 1; i <= col; i++)
		{
			cct_showstr(2 * i + 1, row + 2, str5, 7, 0, 1, 2);
		}
		for (int i = 3; i <= row + 2; i++)
		{
			cct_showstr(1, i - 1, str6, 7, 0, 1, 2);
		}
		for (int i = 3; i <= row + 2; i++)
		{
			cct_showstr(2 * col + 3, i - 1, str6, 7, 0, 1, 2);
		}
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
		cct_setcolor();
		if (xiao == 0)
		{
			cct_gotoxy(15, 0);
			cout << "(δ�ҵ���ʼ�������";
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= col; j++)
				{
					if (color[i][j] == 0)
					{
						cct_showstr(2 * j + 1, i + 1, str7, piccolor[i][j], 0, 1, 2);
					}
				}
			}
			cct_setcolor();
		}
		if (xiao == 1)
		{
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= col; j++)
				{				
					if (color[i][j] == 0)
					{
						cct_showstr(2 * j + 1, i + 1, str7, piccolor[i][j], 0, 1, 2);
					}
					if (color[i][j] == 1)
					{
						cct_showstr(2 * j + 1, i + 1, str8, piccolor[i][j], 0, 1, 2);
					}
				}
			}
			cct_setcolor();
		}
	}
	if (sj == 7)
	{
		cct_setconsoleborder(40, 2 * row + 5, 100, 100);
		cout << "��Ļ��" << 2 * row + 5 << "��40��" << endl;
		for (int i = 1; i <= 2 * row + 1; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (i == 1 && j == 1)
				{
					cct_showstr(0, 1, str1, 7, 0, 1, 2);
					Sleep(10);
					cct_showstr(2, 1, str5, 7, 0, 1, 2);
				}
				if (j != 1 && i == 1)
				{
					cct_showstr(4 * j - 4, 1, str9, 7, 0, 1, 2);
					cct_showstr(4 * j - 2, 1, str5, 7, 0, 1, 2);
				}
				if (i == 1 && j == col)
				{
					cct_showstr(4 * j, 1, str2, 7, 0, 1, 2);
				}
				//��һ��
				if (i % 2 == 0)
				{
					cct_showstr(4 * j - 4, i, str6, 7, 0, 1, 2);
					cct_showstr(4 * j - 2, i, str14, 7, 7, 1, 2);
					if (j == col)
					{
						cct_showstr(4 * j, i, str6, 7, 0, 1, 2);
					}
				}
				//ż����

				if (i % 2 == 1 && i != 1 && i != 2 * row + 1)
				{
					if (j == 1)
					{
						cct_showstr(0, i, str10, 7, 0, 1, 2);
						cct_showstr(2, i, str5, 7, 0, 1, 2);
					}
					if (j != 1)
					{
						cct_showstr(4 * j - 4, i, str11, 7, 0, 1, 2);
						cct_showstr(4 * j - 2, i, str5, 7, 0, 1, 2);
					}
					if (j == col)
					{
						cct_showstr(4 * j, i, str12, 7, 0, 1, 2);
					}
				}
				//������

				if (i == 2 * row + 1)
				{
					if (j == 1)
					{
						cct_showstr(0, i, str3, 7, 0, 1, 2);
						cct_showstr(2, i, str5, 7, 0, 1, 2);
					}
					if (j != 1)
					{
						cct_showstr(4 * j - 4, i, str13, 7, 0, 1, 2);
						cct_showstr(4 * j - 2, i, str5, 7, 0, 1, 2);
					}
					if (j == col)
					{
						cct_showstr(4 * j, i, str4, 7, 0, 1, 2);
					}
				}
				//���һ��
			}
		}
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
		cct_setcolor();
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (color[i][j] == 0)
				{
					cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
				}
				if (color[i][j] == 1)
				{
					cct_showstr(4 * j - 2, 2 * i, str8, piccolor[i][j], 0, 1, 2);
				}

			}
		}
		cct_setcolor();
		while (xiao == 1)
		{
			cct_gotoxy(0, 2 * row + 2);
			cout << "���س������������������0����...";
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
						cct_showstr(4 * j - 2, 2 * i, str15, piccolor[i][j], 0, 1, 2);
						Sleep(20);
						cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
						Sleep(20);
						cct_showstr(4 * j - 2, 2 * i, str15, piccolor[i][j], 0, 1, 2);
						Sleep(200);
						cct_showstr(4 * j - 2, 2 * i, str14, 7, 7, 1, 2);
						Sleep(200);
						dig[i][j] = 0;
					}
				}
			}
			//����

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
							piccolor[k + 1][j] = piccolor[k][j];
							cct_showstr(4 * j - 2, 2 * k + 1, str7, piccolor[k][j], 0, 1, 2);
							cct_showstr(4 * j - 2, 2 * k, str14, 7, 7, 1, 2);
							Sleep(70);
							//����1
							cct_showstr(4 * j - 2, 2 * k + 2, str7, piccolor[k][j], 0, 1, 2);
							cct_showstr(4 * j - 2, 2 * k + 1, str5, 7, 0, 1, 2);
							Sleep(70);
							//����2
						}
						times++;
						dig[times][j] = 0;
						color[times][j] = 1;
					}
				}
			}
			cct_setcolor();
			//���ֳ�0

			cct_gotoxy(0, 2 * row + 2);
			cout << "���س���������ֵ���...           ";
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
				for (int i = 1; i <= row; i++)
				{
					if (dig[i][j] == 0)
					{
						dig[i][j] = 1 + rand() % (9);
						if (dig[i][j] >= 1 && dig[i][j] <= 6)
							piccolor[i][j] = int(dig[i][j]);
						else
							piccolor[i][j] = int(dig[i][j]) + 1;
						color[i][j] = 0;
						cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
						Sleep(200);
					}
				}
			}
			cct_setcolor();
			//��ֵ���
			xiao = 0;
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
		}
		cct_setcolor();
		if (xiao == 0)
		{
			cct_gotoxy(14, 0);
			cout << "(δ�ҵ���ʼ��������)";
			cct_gotoxy(0, 2 * row + 2);
			cout << "���س�����ʾ������ʾ...        ";
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
			graph_check_clear(row, col, dig, color, piccolor);
			cct_setcolor();
		}
	}
	if (sj == 8)
	{
		cct_setconsoleborder(40, 2 * row + 5, 100, 100);
		cout << "��Ļ��" << 2 * row + 5 << "��40��(��ǰ������0 �Ҽ��˳�)" << endl;
		for (int i = 1; i <= 2 * row + 1; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (i == 1 && j == 1)
				{
					cct_showstr(0, 1, str1, 7, 0, 1, 2);
					cct_showstr(2, 1, str5, 7, 0, 1, 2);
				}
				if (j != 1 && i == 1)
				{
					cct_showstr(4 * j - 4, 1, str9, 7, 0, 1, 2);
					cct_showstr(4 * j - 2, 1, str5, 7, 0, 1, 2);
				}
				if (i == 1 && j == col)
				{
					cct_showstr(4 * j, 1, str2, 7, 0, 1, 2);
				}
				//��һ��
				if (i % 2 == 0)
				{
					cct_showstr(4 * j - 4, i, str6, 7, 0, 1, 2);
					cct_showstr(4 * j - 2, i, str14, 7, 7, 1, 2);
					if (j == col)
					{
						cct_showstr(4 * j, i, str6, 7, 0, 1, 2);
					}
				}
				//ż����

				if (i % 2 == 1 && i != 1 && i != 2 * row + 1)
				{
					if (j == 1)
					{
						cct_showstr(0, i, str10, 7, 0, 1, 2);
						cct_showstr(2, i, str5, 7, 0, 1, 2);
					}
					if (j != 1)
					{
						cct_showstr(4 * j - 4, i, str11, 7, 0, 1, 2);
						cct_showstr(4 * j - 2, i, str5, 7, 0, 1, 2);
					}
					if (j == col)
					{
						cct_showstr(4 * j, i, str12, 7, 0, 1, 2);
					}
				}
				//������

				if (i == 2 * row + 1)
				{
					if (j == 1)
					{
						cct_showstr(0, i, str3, 7, 0, 1, 2);
						cct_showstr(2, i, str5, 7, 0, 1, 2);
					}
					if (j != 1)
					{
						cct_showstr(4 * j - 4, i, str13, 7, 0, 1, 2);
						cct_showstr(4 * j - 2, i, str5, 7, 0, 1, 2);
					}
					if (j == col)
					{
						cct_showstr(4 * j, i, str4, 7, 0, 1, 2);
					}
				}
				//���һ��
			}
		}
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
		cct_setcolor();
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (color[i][j] == 0)
				{
					cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
				}
				if (color[i][j] == 1)
				{
					cct_showstr(4 * j - 2, 2 * i, str8, piccolor[i][j], 0, 1, 2);
				}

			}
		}
		cct_setcolor();
		while (xiao == 1)
		{
			
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= col; j++)
				{
					if (color[i][j] == 1)
					{
						cct_showstr(4 * j - 2, 2 * i, str15, piccolor[i][j], 0, 1, 2);
						Sleep(20);
						cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
						Sleep(20);
						cct_showstr(4 * j - 2, 2 * i, str15, piccolor[i][j], 0, 1, 2);
						Sleep(200);
						cct_showstr(4 * j - 2, 2 * i, str14, 7, 7, 1, 2);
						Sleep(200);
						dig[i][j] = 0;
					}
				}
			}
			//����

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
							piccolor[k + 1][j] = piccolor[k][j];						
						}
						//��������ɫ����һ��
						for (int k = i - 1; k > times; k--)
						{
							cct_showstr(4 * j - 2, 2 * k + 1, str7, piccolor[k + 1][j], 0, 1, 2);
							cct_showstr(4 * j - 2, 2 * k, str14, 7, 7, 1, 2);
						}
						Sleep(50);
						for (int k = i - 1; k > times; k--)
						{
							cct_showstr(4 * j - 2, 2 * k + 2, str7, piccolor[k + 1][j], 0, 1, 2);
							cct_showstr(4 * j - 2, 2 * k + 1, str5, 7, 0, 1, 2);
						}
						Sleep(50);
						times++;
						dig[times][j] = 0;
						color[times][j] = 1;
					}
				}
			}
			cct_setcolor();
			//��0
			
			for (int j = 1; j <= col; j++)
			{
				for (int i = 1; i <= row; i++)
				{
					if (dig[i][j] == 0)
					{
						dig[i][j] = 1 + rand() % (9);
						if (dig[i][j] >= 1 && dig[i][j] <= 6)
							piccolor[i][j] = int(dig[i][j]);
						else
							piccolor[i][j] = int(dig[i][j]) + 1;
						color[i][j] = 0;
						cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
						Sleep(200);
					}
				}
			}
			cct_setcolor();
			//��ֵ���

			xiao = 0;
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
		}
		cct_setcolor();
		if (xiao == 0)
		{
			char str[5] = { "��" };
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
			//����Ƿ��������

			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= col; j++)
				{
					if (color[i][j] == 1)
					{
						cct_showstr(4 * j - 2, 2 * i, str, piccolor[i][j], 0, 1, 2);
					}
				}
			}
			cct_setcolor();

			int X = 0, Y = 0;
			int ret, maction;
			int keycode1, keycode2;
			int loop = 1;
			char output = 'A';

			cct_setcursor(CURSOR_INVISIBLE);
			cct_enable_mouse();

			while (loop)
			{
				ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
				if (ret == CCT_MOUSE_EVENT)
				{
					if (maction == MOUSE_RIGHT_BUTTON_CLICK)
					{
						break;
					}

					output = 'A';
					cct_gotoxy(0, 2 * row + 2);
					cout << "[��ǰ���] ";				
					if (((X + 1) % 4 == 0 || (X + 2) % 4 == 0) && X <= 4 * col - 1 && Y % 2 == 0 && Y <= 18)
					{
						output = 'A' + Y / 2 - 1;
						cout << output << "��" << int((X + 2) / 4) << "��      ";
						
						if (maction == MOUSE_LEFT_BUTTON_CLICK && color[int(Y / 2)][int((X + 2) / 4)] == 1)
						{
							cct_gotoxy(0, 2 * row + 2);
							cout << "��ǰѡ��" << output << "��" << int((X + 2) / 4) << "��     ";
							Sleep(1000);
							cct_setcursor(CURSOR_VISIBLE_NORMAL);
							break;
						}
						else if (maction == MOUSE_LEFT_BUTTON_CLICK)
						{
							cct_gotoxy(0, 2 * row + 2);
							cout << "����ѡ��" << output << "��" << int((X + 2) / 4) << "��     ";
							Sleep(100);
						}
					}
					else
					{
						cct_gotoxy(11, 2 * row + 2);
						cout << "λ�÷Ƿ�";
					}

				}
			}

			cct_disable_mouse();	//�������
		}
	}
   	if (sj == 9)
	{
		int score = 0;
		cct_setconsoleborder(40, 2 * row + 5, 100, 100);
		cout << "��Ļ��" << 2 * row + 5 << "��40��(��ǰ������0 �Ҽ��˳�)" << endl;
		for (int i = 1; i <= 2 * row + 1; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (i == 1 && j == 1)
				{
					cct_showstr(0, 1, str1, 7, 0, 1, 2);
					cct_showstr(2, 1, str5, 7, 0, 1, 2);
				}
				if (j != 1 && i == 1)
				{
					cct_showstr(4 * j - 4, 1, str9, 7, 0, 1, 2);
					cct_showstr(4 * j - 2, 1, str5, 7, 0, 1, 2);
				}
				if (i == 1 && j == col)
				{
					cct_showstr(4 * j, 1, str2, 7, 0, 1, 2);
				}
				//��һ��
				if (i % 2 == 0)
				{
					cct_showstr(4 * j - 4, i, str6, 7, 0, 1, 2);
					cct_showstr(4 * j - 2, i, str14, 7, 7, 1, 2);
					if (j == col)
					{
						cct_showstr(4 * j, i, str6, 7, 0, 1, 2);
					}
				}
				//ż����

				if (i % 2 == 1 && i != 1 && i != 2 * row + 1)
				{
					if (j == 1)
					{
						cct_showstr(0, i, str10, 7, 0, 1, 2);
						cct_showstr(2, i, str5, 7, 0, 1, 2);
					}
					if (j != 1)
					{
						cct_showstr(4 * j - 4, i, str11, 7, 0, 1, 2);
						cct_showstr(4 * j - 2, i, str5, 7, 0, 1, 2);
					}
					if (j == col)
					{
						cct_showstr(4 * j, i, str12, 7, 0, 1, 2);
					}
				}
				//������

				if (i == 2 * row + 1)
				{
					if (j == 1)
					{
						cct_showstr(0, i, str3, 7, 0, 1, 2);
						cct_showstr(2, i, str5, 7, 0, 1, 2);
					}
					if (j != 1)
					{
						cct_showstr(4 * j - 4, i, str13, 7, 0, 1, 2);
						cct_showstr(4 * j - 2, i, str5, 7, 0, 1, 2);
					}
					if (j == col)
					{
						cct_showstr(4 * j, i, str4, 7, 0, 1, 2);
					}
				}
				//���һ��
			}
		}
		//�����
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
		cct_setcolor();
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (color[i][j] == 0)
				{
					cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
				}
				if (color[i][j] == 1)
				{
					cct_showstr(4 * j - 2, 2 * i, str8, piccolor[i][j], 0, 1, 2);
				}

			}
		}
		//�ڰ�����ɫ
		cct_setcolor();
		while (xiao == 1)
		{
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= col; j++)
				{
					if (color[i][j] == 1)
					{
						cct_showstr(4 * j - 2, 2 * i, str15, piccolor[i][j], 0, 1, 2);
						Sleep(20);
						cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
						Sleep(20);
						cct_showstr(4 * j - 2, 2 * i, str15, piccolor[i][j], 0, 1, 2);
						Sleep(200);
						cct_showstr(4 * j - 2, 2 * i, str14, 7, 7, 1, 2);
						Sleep(200);
						dig[i][j] = 0;
						score++;
					}
				}
			}
			cct_setcolor();
			//����
			cct_gotoxy(25, 0);
			cout << score;

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
							piccolor[k + 1][j] = piccolor[k][j];						
						}
						for (int k = i - 1; k > times; k--)
						{
							cct_showstr(4 * j - 2, 2 * k + 1, str7, piccolor[k + 1][j], 0, 1, 2);
							cct_showstr(4 * j - 2, 2 * k, str14, 7, 7, 1, 2);
						}
						Sleep(50);
						for (int k = i - 1; k > times; k--)
						{
							cct_showstr(4 * j - 2, 2 * k + 2, str7, piccolor[k + 1][j], 0, 1, 2);
							cct_showstr(4 * j - 2, 2 * k + 1, str5, 7, 0, 1, 2);
						}
						Sleep(50);
						times++;
						dig[times][j] = 0;
						color[times][j] = 1;
					}
				}
			}
			cct_setcolor();
			//��0

			for (int j = 1; j <= col; j++)
			{
				for (int i = 1; i <= row; i++)
				{
					if (dig[i][j] == 0)
					{
						dig[i][j] = 1 + rand() % (9);
						if (dig[i][j] >= 1 && dig[i][j] <= 6)
							piccolor[i][j] = int(dig[i][j]);
						else
							piccolor[i][j] = int(dig[i][j]) + 1;
						color[i][j] = 0;
						cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
						Sleep(200);
					}
				}
			}
			cct_setcolor();
			//��ֵ���

			xiao = 0;
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
		}
		//��������
		cct_setcolor();
		if (xiao == 0)
		{
			int loop = 0;
			char str[5] = { "��" };
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
						loop = 1;
					}

					//dig[i+1][j]��ǵ����
					if (dig[i][j - 1] == dig[i][j + 1] && dig[i + 1][j] == dig[i][j - 1] && dig[i + 1][j] != dig[i - 1][j] && dig[i][j] != dig[i][j - 1])
					{
						color[i][j] = 1;
						color[i + 1][j] = 1;
						loop = 1;
					}

					//dig[i][j+1]��ǵ����
					if (dig[i - 1][j] == dig[i + 1][j] && dig[i][j - 1] == dig[i - 1][j] && dig[i][j - 1] != dig[i][j + 1] && dig[i][j] != dig[i - 1][j])
					{
						color[i][j] = 1;
						color[i][j - 1] = 1;
						loop = 1;
					}

					//dig[i][j-1]��ǵ����
					if (dig[i - 1][j] == dig[i + 1][j] && dig[i][j + 1] == dig[i - 1][j] && dig[i][j - 1] != dig[i][j + 1] && dig[i][j] != dig[i - 1][j])
					{
						color[i][j] = 1;
						color[i][j + 1] = 1;
						loop = 1;
					}

					//��������ȫ���
					if (dig[i - 1][j] == dig[i + 1][j] && dig[i][j - 1] == dig[i][j + 1] && dig[i - 1][j] == dig[i][j - 1] && dig[i - 1][j] != dig[i][j])
					{
						color[i][j] = 1;
						color[i + 1][j] = 1;
						color[i - 1][j] = 1;
						color[i][j + 1] = 1;
						color[i][j - 1] = 1;
						loop = 1;
					}

					//00X�����
					if (j > 2 && dig[i][j - 2] == dig[i][j - 1] && dig[i][j - 1] == dig[i][j + 1] && dig[i][j] != dig[i][j - 1])
					{
						color[i][j] = 1;
						color[i][j + 1] = 1;
						loop = 1;
					}
					if (j > 2 && dig[i][j - 2] == dig[i][j - 1] && dig[i][j - 1] == dig[i + 1][j] && dig[i][j] != dig[i][j - 1])
					{
						color[i][j] = 1;
						color[i + 1][j] = 1;
						loop = 1;
					}
					if (j > 2 && dig[i][j - 2] == dig[i][j - 1] && dig[i][j - 1] == dig[i - 1][j] && dig[i][j] != dig[i][j - 1])
					{
						color[i][j] = 1;
						color[i - 1][j] = 1;
						loop = 1;
					}

					//X00�����
					if (j <= col - 2 && dig[i][j + 2] == dig[i][j + 1] && dig[i][j - 1] == dig[i][j + 1] && dig[i][j] != dig[i][j + 1])
					{
						color[i][j] = 1;
						color[i][j - 1] = 1;
						loop = 1;
					}
					if (j <= col - 2 && dig[i][j + 2] == dig[i][j + 1] && dig[i + 1][j] == dig[i][j + 1] && dig[i][j] != dig[i][j + 1])
					{
						color[i][j] = 1;
						color[i + 1][j] = 1;
						loop = 1;
					}
					if (j <= col - 2 && dig[i][j + 2] == dig[i][j + 1] && dig[i - 1][j] == dig[i][j + 1] && dig[i][j] != dig[i][j + 1])
					{
						color[i][j] = 1;
						color[i - 1][j] = 1;
						loop = 1;
					}

					//X��00�����
					if (i > 2 && dig[i - 2][j] == dig[i - 1][j] && dig[i - 1][j] == dig[i][j - 1] && dig[i - 1][j] != dig[i][j])
					{
						color[i][j] = 1;
						color[i][j - 1] = 1;
						loop = 1;
					}
					if (i > 2 && dig[i - 2][j] == dig[i - 1][j] && dig[i - 1][j] == dig[i][j + 1] && dig[i - 1][j] != dig[i][j])
					{
						color[i][j] = 1;
						color[i][j + 1] = 1;
						loop = 1;
					}
					if (i > 2 && dig[i - 2][j] == dig[i - 1][j] && dig[i - 1][j] == dig[i + 1][j] && dig[i - 1][j] != dig[i][j])
					{
						color[i][j] = 1;
						color[i + 1][j] = 1;
						loop = 1;
					}

					//X��00�����
					if (i <= row - 2 && dig[i + 2][j] == dig[i + 1][j] && dig[i + 1][j] == dig[i][j - 1] && dig[i + 1][j] != dig[i][j])
					{
						color[i][j] = 1;
						color[i][j - 1] = 1;
						loop = 1;
					}
					if (i <= row - 2 && dig[i + 2][j] == dig[i + 1][j] && dig[i + 1][j] == dig[i][j + 1] && dig[i + 1][j] != dig[i][j])
					{
						color[i][j] = 1;
						color[i][j + 1] = 1;
						loop = 1;
					}
					if (i <= row - 2 && dig[i + 2][j] == dig[i + 1][j] && dig[i + 1][j] == dig[i - 1][j] && dig[i + 1][j] != dig[i][j])
					{
						color[i][j] = 1;
						color[i - 1][j] = 1;
						loop = 1;
					}

				}
			}
			//����Ƿ��������
			
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= col; j++)
				{
					if (color[i][j] == 1)
					{
						cct_showstr(4 * j - 2, 2 * i, str, piccolor[i][j], 0, 1, 2);
					}
				}
			}
			cct_setcolor();

			int X = 0, Y = 0;
			int ret, maction;
			int keycode1, keycode2;

			char output = 'A';
			int X1 = 0, Y1 = 0;
			int X2 = 0, Y2 = 0;
			int gameover = 0;

			cct_setcursor(CURSOR_INVISIBLE);
			cct_enable_mouse();

			while (loop)
			{
				ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

				if (ret == CCT_MOUSE_EVENT)
				{
					if (maction == MOUSE_RIGHT_BUTTON_CLICK)
					{
						break;
					}
					//�Ҽ��˳�

					output = 'A';
					cct_gotoxy(0, 2 * row + 2);
					cout << "[��ǰ���] ";
					if (((X + 1) % 4 == 0 || (X + 2) % 4 == 0) && X <= 4 * col - 1 && Y % 2 == 0 && Y <= 18 && X >= 0)//�Ϸ�����
					{
						output = 'A' + Y / 2 - 1;
						cout << output << "��" << int((X + 2) / 4) << "��                                ";

						if (maction == MOUSE_LEFT_BUTTON_CLICK && color[int(Y / 2)][int((X + 2) / 4)] == 1 && X1 == 0 && Y1 == 0)
						{
							cct_gotoxy(0, 2 * row + 2);
							output = 'A' + Y / 2 - 1;
							cout << "��ǰѡ��" << output << "��" << int((X + 2) / 4) << "��                           ";
							Sleep(500);
							X1 = int((X + 2) / 4);
							Y1 = int(Y / 2);
							cct_showstr(4 * X1 - 2, 2 * Y1, str, piccolor[Y1][X1], 7, 1, 2);
							cct_setcolor();
						}
						//ѡ�е�һ������
						else if (maction == MOUSE_LEFT_BUTTON_CLICK && color[int(Y / 2)][int((X + 2) / 4)] == 1 && X1 != 0 && Y1 != 0)
						{						
							X2 = int((X + 2) / 4);
							Y2 = int(Y / 2);
							output = 'A' + Y2 - 1;
							if (X1 == X2 && Y1 == Y2)
							{
								output = 'A' + Y2 - 1;
								cct_showstr(4 * X1 - 2, 2 * Y1, str, piccolor[Y1][X1], 0, 1, 2);
								cct_setcolor();
								cct_gotoxy(0, 2 * row + 2);
								cout << "��ǰѡ��" << output << "��" << int((X + 2) / 4) << "��                      ";
								cct_setcolor();
								Sleep(200);
								X1 = 0;
								X2 = 0;
								Y1 = 0;
								Y2 = 0;
								continue;
							}
							//ѡ��������ͬ��

							else if ((abs(X1 - X2) == 1 && abs(Y1 - Y2) == 0) || (abs(X1 - X2) == 0 && abs(Y1 - Y2) == 1) && color[Y2][X2] == 1)
							{
								
								int m = dig[Y2][X2], n = piccolor[Y2][X2];
								dig[Y2][X2] = dig[Y1][X1];
								dig[Y1][X1] = m;
								piccolor[Y2][X2] = piccolor[Y1][X1];
								piccolor[Y1][X1] = n;
								//������������

								xiao = 0;
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

								if (xiao == 0)
								{
									dig[Y1][X1] = dig[Y2][X2];
									dig[Y2][X2] = m;
									piccolor[Y1][X1] = piccolor[Y2][X2];
									piccolor[Y2][X2] = n;
									//����ȥ
									cct_gotoxy(0, 2 * row + 2);
									output = 'A' + Y2 - 1;
									cout << "���ܽ���" << char('A' + Y1 - 1) << "��" << X1 << "�� <=> " << output << "��" << X2 << "��";
									Sleep(100);

									X1 = 0;
									Y1 = 0;
									X2 = 0;
									Y2 = 0;
									m = 0;
									n = 0;
									//����X2,Y2����

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
									//����Ƿ��������
									for (int i = 1; i <= row; i++)
									{
										for (int j = 1; j <= col; j++)
										{
											if (color[i][j] == 1)
											{
												cct_showstr(4 * j - 2, 2 * i, str, piccolor[i][j], 0, 1, 2);
											}
										}
									}
									//��ʾ������
									cct_setcolor();
									continue;
								}
								//��������
								if (xiao == 1)
								{
									cct_showstr(4 * X1 - 2, 2 * Y1, str7, piccolor[Y1][X1], 0, 1, 2);
									cct_showstr(4 * X2 - 2, 2 * Y2, str7, piccolor[Y2][X2], 0, 1, 2);
									//����λ��
								}
								while (xiao == 1)
								{
									for (int i = 1; i <= row; i++)
									{
										for (int j = 1; j <= col; j++)
										{
											if (color[i][j] == 0)
											{
												cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
											}
											if (color[i][j] == 1)
											{
												cct_showstr(4 * j - 2, 2 * i, str8, piccolor[i][j], 0, 1, 2);
											}

										}
									}
									Sleep(500);
									//��ɫ�ڰ�

									for (int i = 1; i <= row; i++)
									{
										for (int j = 1; j <= col; j++)
										{
											if (color[i][j] == 1)
											{
												cct_showstr(4 * j - 2, 2 * i, str15, piccolor[i][j], 0, 1, 2);
												Sleep(20);
												cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
												Sleep(20);
												cct_showstr(4 * j - 2, 2 * i, str15, piccolor[i][j], 0, 1, 2);
												Sleep(200);
												cct_showstr(4 * j - 2, 2 * i, str14, 7, 7, 1, 2);
												Sleep(200);
												dig[i][j] = 0;
												score++;
											}
										}
									}
									//����

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
													piccolor[k + 1][j] = piccolor[k][j];												
												}
												for (int k = i - 1; k > times; k--)
												{
													cct_showstr(4 * j - 2, 2 * k + 1, str7, piccolor[k + 1][j], 0, 1, 2);
													cct_showstr(4 * j - 2, 2 * k, str14, 7, 7, 1, 2);
												}
												Sleep(50);
												for (int k = i - 1; k > times; k--)
												{
													cct_showstr(4 * j - 2, 2 * k + 2, str7, piccolor[k + 1][j], 0, 1, 2);
													cct_showstr(4 * j - 2, 2 * k + 1, str5, 7, 0, 1, 2);
												}
												Sleep(50);
												times++;
												dig[times][j] = 0;
												color[times][j] = 1;
											}
										}
									}
									cct_setcolor();
									//��0

									for (int j = 1; j <= col; j++)
									{
										for (int i = 1; i <= row; i++)
										{
											if (dig[i][j] == 0)
											{
												dig[i][j] = 1 + rand() % (9);
												if (dig[i][j] >= 1 && dig[i][j] <= 6)
													piccolor[i][j] = int(dig[i][j]);
												else
													piccolor[i][j] = int(dig[i][j]) + 1;
												color[i][j] = 0;
												cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
												Sleep(200);
											}
										}
									}
									cct_setcolor();
									//��ֵ���

									xiao = 0;
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
									cct_setcolor();
								}

								gameover = 0;
								cct_gotoxy(25, 0);
								cout << score << " �Ҽ��˳�)";
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
								//����Ƿ��������
								for (int i = 1; i <= row; i++)
								{
									for (int j = 1; j <= col; j++)
									{
										if (color[i][j] == 1)
										{
											cct_showstr(4 * j - 2, 2 * i, str, piccolor[i][j], 0, 1, 2);
											gameover = 1;
										}
									}
								}
								//��ʾ������
								cct_setcolor();
								//��ѭ������֮����ʾ������
								X1 = 0;
								X2 = 0;
								Y1 = 0;
								Y2 = 0;
								if (gameover == 0)
								{
									break;
								}
							}
						}
						else if (maction == MOUSE_LEFT_BUTTON_CLICK && color[int(Y / 2)][int((X + 2) / 4)] == 0)
						{
							cct_gotoxy(0, 2 * row + 2);
							cout << "����ѡ��" << output << "��" << int((X + 2) / 4) << "��                        ";
							Sleep(100);
						}
					}
					else
					{
						cct_gotoxy(11, 2 * row + 2);
						cout << "λ�÷Ƿ�                           ";
					}

				}
			}

			cct_disable_mouse();	//�������
		}
	}
}
//������ʼ�ṹ


void ini_struct(int row, int col, char dig[12][12], char color[12][12], int sj)
{
	cct_setfontsize("������", 28);
	int piccolor[12][12] = { 0 };
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (dig[i][j] >= 1 && dig[i][j] <= 6)
			{
				piccolor[i][j] = int(dig[i][j]);
			}
			else
			{
				piccolor[i][j] = int(dig[i][j]) + 1;
			}
		}
	}
	//�����϶�Ӧ��ɫ

	draw_struc(row, col, dig, color, piccolor, sj);
	if (sj == 4)
	{
		cct_gotoxy(1, row + 3);
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
	if (sj == 5)
	{
		cct_gotoxy(0, 2 * row + 2);
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
	if (sj == 6)
	{
		cct_gotoxy(1, row + 3);
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
	if (sj == 7)
	{
		cct_gotoxy(0, 2 * row + 2);
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
	if (sj == 8)
	{
		cct_gotoxy(0, 2 * row + 2);
		jieshu();
	}
	if (sj == 9)
	{
		cct_gotoxy(0, 2 * row + 2);
		jieshu();
	}
}


