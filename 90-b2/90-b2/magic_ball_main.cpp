/* 2353726 ���ϳ� ��01 */
#include <iostream>
#include "magic_ball.h"
using namespace std;

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	while (1)
	{
		cct_setfontsize("������", 16);
		cct_setconsoleborder(120, 30, 200, 200);
		int judge = 0;
		judge = menu();
		if (judge > '9' || judge < '0')
		{
			continue;
		}
		int sj = 0;
		sj = int(judge) - 48;
		if (judge == 48)
		{
			break;
		}
		else if (judge == 49 || judge == 50 || judge == 51 || judge == 52 || judge == 53 || judge == 54 || judge == 55 || judge == 56 || judge == 57)
		{
			int row, col;
			cct_cls();
			while (1)
			{
				cout << "����������(5-9)��" << endl;
				cin >> row;
				if (cin.good() == 0)
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				if (row < 5 || row>9)
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				break;
			}
			while (1)
			{
				cout << "����������(5-9)��" << endl;
				cin >> col;
				if (cin.good() == 0)
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				if (col < 5 || col>9)
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				break;
			}
			cout << endl;
			dig_ini(row, col, sj);
		}
		else
		{
			continue;
		}
	}
	return 0;
}

/*�������͵Ŀ�ܣ�ÿ��11��Ԫ�أ�ÿ��Ԫ�ؾ�Ϊһ�������ַ���2�ֽڣ�
		˫�߿�ܣ�"�X", "�^", "�[", "�a", "�T", "�U", "�j", "�m", "�d", "�g", "�p"
		���߿�ܣ�"��", "��", "��", "��", "��", "��", "��", "��",  "��", "��", "��"
		��˫����: "�V", "�\", "�Y", "�_", "�T", "��", "�h", "�k", "�b", "�e", "�n"
		�ᵥ��˫��"�W", "�]", "�Z", "�`", "��", "�U", "�i", "�l", "�c", "�f", "�o"
	

	˫�߿��ʹ���������������滻Ϊ�������ͣ�
	   �X�T�j�T�[
	   �U  �U  �U
	   �d�T�p�T�g
	   �U  �U  �U
	   �^�T�m�T�a
cout << "�X�T�j�T�[" << endl;
cout << "�U  �U  �U" << endl;
cout << "�d�T�p�T�g" << endl;
cout << "�U  �U  �U" << endl;
cout << "�^�T�m�T�a" << endl; 
*/