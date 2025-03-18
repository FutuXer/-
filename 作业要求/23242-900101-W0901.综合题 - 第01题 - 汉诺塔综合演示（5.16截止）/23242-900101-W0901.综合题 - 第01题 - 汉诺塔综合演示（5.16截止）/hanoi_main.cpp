/* ��01 2353726 ���ϳ� */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
extern int step;
extern int a0;
extern int b0;
extern int c0;                                 //��¼Բ�̸���// 
extern int A[10];
extern int B[10];
extern int C[10];     //��������//
extern int t;                               //��ʱ
extern int display;                           //��ʾ��ֵ


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	while (true)
	{
		step = 1;
		b0 = 0;
		c0 = 0;                                   //��¼Բ�̸���// 
		for (int i = 0; i < 10; i++)
			A[i] = 0;
		for (int i = 0; i < 10; i++)
			B[i] = 0;
		for (int i = 0; i < 10; i++)
			C[i] = 0;
		t = 0;                                   //��ʱ
		display = 0;                             //��ʾ��ֵ
		/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
		cct_setconsoleborder(120, 40, 120, 9000);

		int menudig;
		menudig = menu();
		cout << endl;
		cout << endl;
		cout << endl;
		if (menudig == 48)
		{
			break;
		}
		if (menudig == 49)
			hanoi_s1(1);
		if (menudig == 50)
			hanoi_s2(2);
		if (menudig == 51)
			hanoi_s348(3);
		if (menudig == 52)
			hanoi_s348(4);
		if (menudig == 53)
			hanoi_s56789(5);
		if (menudig == 54)
			hanoi_s56789(6);
		if (menudig == 55)
			hanoi_s56789(7);
		if (menudig == 56)
			hanoi_s56789(8);
		if (menudig == 57)
			hanoi_s56789(9);
		cout << "��Ϸ���������س������ز˵�." << endl;
		char ch = _getch();

		while (ch != 13)
		{
			ch = _getch();
			continue;
		}
		cct_cls();
	}


	return 0;
}
