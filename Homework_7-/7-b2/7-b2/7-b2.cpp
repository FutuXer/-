/* 2353726 ���ϳ� ��01 */
#include <iostream>
#include <conio.h>
#include "7-b2.h"
#include "cmd_console_tools.h"

using namespace std;
/* 1���������ͷ�ļ�
   2����������ȫ��������������̬ȫ�֣�������ʾconst��define
   3����������Ҫ�Ľṹ�塢�����ȣ������ޱ�Դ�����ļ�ʹ�� */

/* ������������Դ�����ļ���Ҫ�Ľṹ�壬��Ҫ�ŵ�.h��
       ��Ϊʾ��������Ҫ��ɾ�� */


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������Դ�����ļ���Ҫ�ĺ���������Ϊstatic����
***************************************************************************/
static int fun()
{
     //��Ϊʾ��������Ҫ��ɾ��
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��������������õĺ���������������ͷ�ļ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    int titlelen = strlen(original_para->title);
    int X = original_para->start_x;
    int Y = original_para->start_y;
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    int x = 0, y = 0;
    int flag = 0;
    int width = original_para->width;
    int high = original_para->high;
    int futuxer = 0; 
    while (menu[futuxer][0] != NULL)
    {
        futuxer++;
    }
    if (high > futuxer)
    {
        high = futuxer;
    }
    int chinstr = 0;
    if (width<=titlelen)
    {
        width = titlelen;
    }
    if (width%2==1)
        width++;
    int choose = 0;
    int upborder = 0;
    int downborder = high;
    cct_setcolor(original_para->bg_color, original_para->fg_color);
    cct_gotoxy(original_para->start_x, original_para->start_y);
    cout << "�X";
    if (titlelen % 2 == 0)
    {
        for (int i = 1; i <= (width - titlelen) / 4; i++)
            cout << "�T";
        cout << original_para->title;
        for (int i = 1; i <= (width - titlelen) / 4; i++)
            cout << "�T";
        if (((width - titlelen) / 2) % 2 != 0)
            cout << "�T";
    }
    if (titlelen % 2 == 1)
    {
        for (int i = 1; i <= (width - titlelen) / 4; i++)
            cout << "�T";
        cout << original_para->title << " ";
        for (int i = 1; i <= (width - titlelen) / 4; i++)
            cout << "�T";
        if (((width - titlelen) / 2) % 2 != 0)
            cout << "�T";
    }
    cout << "�[";
    int sj = 0;  
    cct_gotoxy(X, Y + high + 1);
    cout << "�^";
    for (int i = 1; i <= width / 2; i++)
    {
        cout << "�T";
    }
    cout << "�a";
    while (1)
    {
        sj = 0;
        for (int i = upborder; i < downborder; i++)
        {
            flag = 0;
            cct_gotoxy(X, Y + sj + 1);
            cout << "�U";
            chinstr = 0;
            for (int j = 0; j < width; j++)
            {
                if (menu[i][j] < 0 || menu[i][j]>127)
                    chinstr++;
            }
            if (chinstr % 2 == 1)
            {
                for (int k = 0; k < width - 1; k++)
                {
                    if (choose == i)
                    {
                        cct_setcolor(original_para->fg_color, original_para->bg_color);
                    }
                    else
                    {
                        cct_setcolor(original_para->bg_color, original_para->fg_color);
                    }
                    cct_getxy(x, y);
                    if (x == cols - 1 && x == buffer_cols - 1)
                    {
                        cout << " ";
                        flag = 1;
                    }
                    if (menu[i][k] == '\0')
                        cout << " ";
                    else
                        cout << menu[i][k];
                    cct_setcolor(original_para->bg_color, original_para->fg_color);
                }
                if (flag == 1)
                {
                    cout << '\b';
                }
                cout << " ";
            }
            else if (chinstr % 2 == 0)
            {
                for (int k = 0; k < width; k++)
                {
                    if (choose == i)
                    {
                        cct_setcolor(original_para->fg_color, original_para->bg_color);
                    }
                    else
                    {
                        cct_setcolor(original_para->bg_color, original_para->fg_color);
                    }
                    cct_getxy(x, y);
                    if (x == cols - 1 && x == buffer_cols - 1)
                    {
                        cout << " ";
                        flag = 1;
                    }
                    if (menu[i][k] == '\0')
                        cout << " ";
                    else
                        cout << menu[i][k];
                    cct_setcolor(original_para->bg_color, original_para->fg_color);
                }
                if (flag == 1)
                {
                    cout << '\b';
                }
            }
            cout << "�U";
            sj++;
        }
        while (1)
        {
            char ch = _getch();
            if (ch == 72 && choose != 0)
            {
                if (choose == upborder)
                {
                    upborder--;
                    downborder--;
                }
                choose--;
                break;
            }
            else if (ch == 80 && choose != 9)
            {
                if (choose == downborder - 1)
                {
                    upborder++;
                    downborder++;
                }
                choose++;
                break;
            }
            else if (ch == '\r')
            {
                return choose + 1;
            }
            else
            {
                continue;
            }
        }
    }
	return 0; //���践��
}
