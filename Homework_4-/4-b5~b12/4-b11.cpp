/* 2353726 ��01 ���ϳ� */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
   ----------------------------------------------------------------------------------- */

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡ��ĸ��
	 ���������
	 �� �� ֵ��
	 ˵    �����βΰ�������
			   ��ʾ����һ������order��ָ������/����
   ***************************************************************************/
void print_letter(char start, char A)
{
	if (start == A)
	{
		cout << "A";
	}
	else
	{
		cout << start;
		print_letter(start - 1, 65);
		cout << start;
	}
}

void print_tower(int a, int ord, int length)
{
	int space = (length - (2 * (a - 65) + 1)) / 2;
	if (a == 64)
	{
		return;
	}
	if (a == 65) 
	{
		if (space != 0) 
		{
			cout << setw(space) << ' ';
		}
		cout << "A" << endl;
	}
	else
	{
		if (ord == 1)
		{
			print_tower(a - 1, ord, length);
		}
		if (space != 0)
		{
			cout << setw(space) << ' ';
		}
		print_letter(a,65);
		cout << endl;
		if (ord == 2)
		{
			print_tower(a - 1, ord, length);
		}
	}
}

char border(int a)
{
	if (a == 0)
	{
		return 32;
	}
	else
	{
		cout << "=";
		return border(a - 1);
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout << border(2 * (int(end_ch) - 64) - 1) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << border(2 * (int(end_ch) - 64) - 1) << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(int(end_ch), 1, 2 * (int(end_ch) - 64) - 1); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(�м�ΪA) */
	cout << border(2 * (int(end_ch) - 64) - 1) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << border(2 * (int(end_ch) - 64) - 1) << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(int(end_ch), 2, 2 * (int(end_ch) - 64) - 1); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ��м�ΪA�� */
	cout << border(2 * (int(end_ch) - 64) - 1) << endl;/* ����ĸ����������= */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << border(2 * (int(end_ch) - 64) - 1) << endl;/* ����ĸ����������= */
	print_tower(int(end_ch), 1, 2 * (int(end_ch) - 64) - 1);   //��ӡ A~�����ַ��������� 
	print_tower(int(end_ch - 1), 2, 2 * (int(end_ch) - 64) - 1);  //��ӡ A~�����ַ�-1�ĵ����� 
	cout << endl;

	return 0;
}
