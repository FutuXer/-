/* 2353726 ���ϳ� ��01 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�
const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
void move_by_ijkl(int a)
{
	int x = 34, y = 8;
	while (a == 49)
	{
		int key1 = _getch();
		if (key1 == 81 || key1 == 113)
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "��Ϸ���������س������ز˵�.";
			while (1)
			{
				int back = _getch();
				if (back == 13)
					break;
				else
					continue;
			}
			break;
		}
		if (key1 == 32)
		{
			cout << " ";
			gotoxy(hout, x, y);
			continue;
		}
		// ���ݰ��µļ�ֵ�ƶ����
		if ((key1 == 73 || key1 == 105) && y > 1)  // �ϼ�ͷ
			y--;
		else if ((key1 == 75 || key1 == 107) && y < 17)  // �¼�ͷ
			y++;
		else if ((key1 == 74 || key1 == 106) && x > 1)  // ���ͷ
			x--;
		else if ((key1 == 76 || key1 == 108) && x < 69)  // �Ҽ�ͷ
			x++;
		// �ƶ���굽��λ��
		gotoxy(hout, x, y);
	}
	while (a == 50)
	{
		int key1 = _getch();
		if (key1 == 81 || key1 == 113)
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "��Ϸ���������س������ز˵�.";
			while (1)
			{
				int back = _getch();
				if (back == 13)
					break;
				else
					continue;
			}
			break;
		}
		if (key1 == 32)
		{
			cout << " ";
			gotoxy(hout, x, y);
			continue;
		}
		// ���ݰ��µļ�ֵ�ƶ����
		if ((key1 == 73 || key1 == 105) && y > 1)  // �ϼ�ͷ
			y--;
		else if ((key1 == 73 || key1 == 105) && y == 1)
			y = 16;

		if ((key1 == 75 || key1 == 107) && y < 17)  // �¼�ͷ
			y++;
		else if ((key1 == 75 || key1 == 107) && y == 17)
			y = 2;

		if ((key1 == 74 || key1 == 106) && x > 1)  // ���ͷ
			x--;
		else if ((key1 == 74 || key1 == 106) && x == 1)
			x = 68;

		if ((key1 == 76 || key1 == 108) && x < 69)  // �Ҽ�ͷ
			x++;
		else if ((key1 == 76 || key1 == 108) && x == 69)
			x = 2;
		// �ƶ���굽��λ��
		gotoxy(hout, x, y);
	}
	while (a == 53)
	{
		int key1 = _getch();
		if (key1 == 81 || key1 == 113)
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "��Ϸ���������س������ز˵�.";
			while (1)
			{
				int back = _getch();
				if (back == 13)
					break;
				else
					continue;
			}
			break;
		}
		if (key1 == 32)
		{
			cout << " ";
			gotoxy(hout, x, y);
			continue;
		}
		if (key1 == 0 || key1 == 224)
		{
			int key2 = _getch();
			continue;
		}
		if ((key1 == 73 || key1 == 105) && y > 1)  // �ϼ�ͷ
			y--;
		else if ((key1 == 75 || key1 == 107) && y < 17)  // �¼�ͷ
			y++;
		else if ((key1 == 74 || key1 == 106) && x > 1)  // ���ͷ
			x--;
		else if ((key1 == 76 || key1 == 108) && x < 69)  // �Ҽ�ͷ
			x++;
		// �ƶ���굽��λ��
		gotoxy(hout, x, y);
	}
	while (a == 54)
	{
		int key1 = _getch();
		if (key1 == 81 || key1 == 113)
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "��Ϸ���������س������ز˵�.";
			while (1)
			{
				int back = _getch();
				if (back == 13)
					break;
				else
					continue;
			}
			break;
		}
		if (key1 == 32)
		{
			cout << " ";
			gotoxy(hout, x, y);
			continue;
		}
		if (key1 == 0 || key1 == 224)
		{
			int key2 = _getch();
			continue;
		}
		if ((key1 == 73 || key1 == 105) && y > 1)  // �ϼ�ͷ
			y--;
		else if ((key1 == 73 || key1 == 105) && y == 1)
			y = 16;

		if ((key1 == 75 || key1 == 107) && y < 17)  // �¼�ͷ
			y++;
		else if ((key1 == 75 || key1 == 107) && y == 17)
			y = 2;

		if ((key1 == 74 || key1 == 106) && x > 1)  // ���ͷ
			x--;
		else if ((key1 == 74 || key1 == 106) && x == 1)
			x = 68;

		if ((key1 == 76 || key1 == 108) && x < 69)  // �Ҽ�ͷ
			x++;
		else if ((key1 == 76 || key1 == 108) && x == 69)
			x = 2;		
		// �ƶ���굽��λ��
		gotoxy(hout, x, y);
	}
}

void move_by_arrow(int a)
{
	int x = 34, y = 8;
	while (a == 51)
	{	
		int key1 = _getch();
		if (key1 == 81 || key1 == 113)
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "��Ϸ���������س������ز˵�.";
			while (1)
			{
				int back = _getch();
				if (back == 13)
					break;
				else
					continue;
			}
			break;
		}
		if (key1 == 32)
		{
			cout << " ";
			gotoxy(hout, x, y);
			continue;
		}
		if (key1 != 0 && key1 != 224)
		{
			continue;
		}
		int key2 = _getch();
		// ���ݰ��µļ�ֵ�ƶ����
		if (key2 == 72 && y > 1)  // �ϼ�ͷ
			y--;
		else if (key2 == 80 && y < 17)  // �¼�ͷ
			y++;
		else if (key2 == 75 && x > 1)  // ���ͷ
			x--;
		else if (key2 == 77 && x < 69)  // �Ҽ�ͷ
			x++;
		// �ƶ���굽��λ��
		gotoxy(hout, x, y);
	}
	while (a == 52)
	{	
		int key1 = _getch();
		if (key1 == 81 || key1 == 113)
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "��Ϸ���������س������ز˵�.";
			while (1)
			{
				int back = _getch();
				if (back == 13)
					break;
				else
					continue;
			}
			break;
		}
		if (key1 == 32)
		{
			cout << " ";
			gotoxy(hout, x, y);
			continue;
		}
		if (key1 != 0 && key1 != 224)
		{
			continue;
		}
		int key2 = _getch();
		// ���ݰ��µļ�ֵ�ƶ����
		if (key2 == 72 && y > 1)  // �ϼ�ͷ
			y--;
		else if (key2 == 72 && y == 1)
			y = 16;

		if (key2 == 80 && y < 17)  // �¼�ͷ
			y++;
		else if (key2 == 80 && y == 17)
			y = 2;

		if (key2 == 75 && x > 1)  // ���ͷ
			x--;
		else if (key2 == 75 && x == 1)
			x = 68;

		if (key2 == 77 && x < 69)  // �Ҽ�ͷ
			x++;
		else if (key2 == 77 && x == 69)
			x = 2;
		// �ƶ���굽��λ��
		gotoxy(hout, x, y);
	}
}
//�˵�����
void menu(int me)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));
	/* �˾�������ǵ���ϵͳ��cls�������� */
	cls(hout);
	/* ��ʾ��ʼ�ı߿����е�����ַ� */
	init_border(hout);
	//��ͣ
	int x = 34;
	int y = 8;
	gotoxy(hout, x, y);
	int a = me;
	if (a == 49 || a == 50 || a == 53 || a == 54)
	{
		move_by_ijkl(a);
	}
	if (a == 51 || a == 52)
	{
		move_by_arrow(a);
	}
	
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	while (1)
	{
		cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl;
		cout << "2.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl;
		cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
		cout << "4.�ü�ͷ�������������ң��߽����" << endl;
		cout << "5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ,���ͷ���ã�" << endl;
		cout << "6.��I��J��K��L��������������(��Сд���ɣ��߽����,���ͷ���ã�" << endl;
		cout << "0.�˳�" << endl;
		cout << "[��ѡ��0-6] ";
		int me = _getch();
		if (me == 48)
		{
			break;
		}
		else
		{
			menu(me);
			cls(hout);
		}
	}


	return 0;
}