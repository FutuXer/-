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

int step = 1;                            //����ȫ�ֱ���//
int a0;
int b0;
int c0;                                 //��¼Բ�̸���// 
int A[10] = { 0,0,0,0,0,0,0,0,0,0 };
int B[10] = { 0,0,0,0,0,0,0,0,0,0 };
int C[10] = { 0,0,0,0,0,0,0,0,0,0 };     //��������//
int t = 0;                               //��ʱ
int display;                             //��ʾ��ֵ
/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
void move(char src, char dst, int n)
{
    int srccol = 0;
    int dstcol = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    if (src == 'A')
    {
        srccol = 13;
        for (i = 0; i < a0; i++)
        {
            if (A[i] == n)
                break;
        }
    }
    if (src == 'B')
    {
        srccol = 44;
        for (i = 0; i < a0; i++)
        {
            if (B[i] == n)
                break;
        }
    }
    if (src == 'C')
    {
        srccol = 75;
        for (i = 0; i < a0; i++)
        {
            if (C[i] == n)
                break;
        }
    }
    if (dst == 'A')
    {
        dstcol = 13;
        for (j = 0; j < a0; j++)
        {
            if (A[j] == n)
                break;
        }
        k = a0;
    }
    if (dst == 'B')
    {
        dstcol = 44;
        for (j = 0; j < a0; j++)
        {
            if (B[j] == n)
                break;
        }
        k = b0;
    }
    if (dst == 'C')
    {
        dstcol = 75;
        for (j = 0; j < a0; j++)
        {
            if (C[j] == n)
                break;
        }
        k = c0;
    }
    for (int l = 15 - i; l > 2; l--)
    {
        cct_showch(srccol - n, l, ' ', n, n, 2 * n + 1);
        Sleep(100);
        cct_showch(srccol - n, l, ' ', 0, 0, 2 * n + 1);
        if (l > 3)
            cct_showch(srccol, l, ' ', 14, 14, 1);
    }
    cct_setcolor(); //�ָ�ȱʡ��ɫ
    //��������
    if (dstcol > srccol)//����
    {
        for (int m = srccol - n; m <= dstcol - n; m++)
        {
            cct_showch(m, 3, ' ', n, n, 2 * n + 1);
            Sleep(100);
            if (m < dstcol - n)
            {
                cct_showch(m, 3, ' ', 0, 0, 2 * n + 1);
            }
        }
    }
    if (dstcol < srccol)//����
    {
        for (int m = srccol - n; m >= dstcol - n; m--)
        {
            cct_showch(m, 3, ' ', n, n, 2 * n + 1);
            Sleep(100);
            if (m > dstcol - n)
            {
                cct_showch(m, 3, ' ', 0, 0, 2 * n + 1);
            }
        }
    }
    cct_setcolor(); //�ָ�ȱʡ��ɫ
    for (int m = 3; m <= 16 - k; m++)//����
    {
        cct_showch(dstcol - n, m, ' ', n, n, 2 * n + 1);
        Sleep(100);
        if (m < 16 - k)
        {
            cct_showch(dstcol - n, m, ' ', 0, 0, 2 * n + 1);
        }
        if (m > 3)
            cct_showch(dstcol, m, ' ', 14, 14, 1);        
    }
    cct_showch(dstcol - n, 16 - k, ' ', n, n, 2 * n + 1);
    cct_setcolor(); //�ָ�ȱʡ��ɫ
}

void push(char src, int n)              //��ջ����//
{
    if (src == 'A')
    {
        A[a0++] = n;
    }
    else if (src == 'B')
    {
        B[b0++] = n;
    }
    else if (src == 'C')
    {
        C[c0++] = n;
    }
}

int pop(char src)                      //��ջ����//
{
    int ini = 0;
    if (src == 'A')
    {
        ini = A[--a0];
        return ini;
    }
    else if (src == 'B')
    {
        ini = B[--b0];
        return ini;
    }
    else
    {
        ini = C[--c0];
        return ini;
    }
}

void output(int step, int n, char src, char dst, int sj = 0)
{
    if (sj == 9)
    {
        cct_gotoxy(30, 36);
    }
    cout << " A:";
    for (int i = 0; i < a0; i++)
    {
        cout << std::right << setw(2) << A[i];
    }
    for (int space = 0; space < (21 - 2 * a0); space++)
    {
        cout << " ";
    }
    cout << " B:";
    for (int j = 0; j < b0; j++) {
        cout << std::right << setw(2) << B[j];
    }
    for (int space = 0; space < (21 - 2 * b0); space++)
    {
        cout << " ";
    }
    cout << " C:";
    for (int k = 0; k < c0; k++)
    {
        cout << std::right << setw(2) << C[k];
    }
    cout << endl;
}

void column(int sj = 0)
{
    int dis = 0;
    if (sj == 8 || sj == 9)
    {
        dis = 10;
    }
    cct_gotoxy(9, 21+dis);
    cout << "=========================" << endl;
    cct_gotoxy(11, 22+dis);
    cout << "A         B         C" << endl;
    int pointer = 0;
    for (int i = 20+dis; i > 10+dis; i--)
    {
        cct_gotoxy(10, i);
        if (pointer < a0)
        {
            cout << std::right << setw(2) << A[pointer];
        }
        else
        {
            cout << "   ";
        }
        cct_gotoxy(20, i);
        if (pointer < b0)
        {
            cout << std::right << setw(2) << B[pointer];
        }
        else
        {
            cout << "   ";
        }
        cct_gotoxy(30, i);
        if (pointer < c0)
        {
            cout << std::right << setw(2) << C[pointer];
        }
        else
        {
            cout << "   ";
        }
        pointer++;
    }
}

void pause()
{
    if (t == 0)
    {
        system("pause");
    }
    if (t == 1)
    {
        Sleep(1000);
    }
    if (t == 2)
    {
        Sleep(800);
    }
    if (t == 3)
    {
        Sleep(600);
    }
    if (t == 4)
    {
        Sleep(400);
    }
    if (t == 5)
    {
        Sleep(200);
    }
}

void movedisk(char src, char dst, int n)
{
    int disk = pop(src);
    push(dst, disk);
}

void printstep(char src, char dst, int n, int sj)
{
    int dis = 0;
    if (sj == 8 || sj == 9)
    {
        dis = 10;
    } 
    if (sj == 1 || sj == 2)
    {
        if (sj == 2)
            cout << "��" << setw(4) << step << "��( 1) :";
        cout << setw(2) << n << "# " << src << "-->" << dst << endl;
    }
    if (sj == 3)
    {
        cout << "��" << setw(4) << step << "��( 1) :";
        cout << setw(2) << n << "# " << src << "-->" << dst;
        output(step, n, src, dst);
    }
    if (sj == 4)
    {
        cct_gotoxy(20, 26);
        cout << "��" << setw(4) << step << "��( 1) :";
        cout << setw(2) << n << "# " << src << "-->" << dst;
        if (display == 1)
        {
            output(step, n, src, dst);
        }
    }
    if (sj ==8)
    {
        cct_gotoxy(20, 26 + dis);
        cout << "��" << setw(4) << step << "��( 1) :";
        cout << setw(2) << n << "# " << src << "-->" << dst;
        if (display == 1)
        {
            output(step, n, src, dst);
        }
    }
    if (sj == 9)
    {
        cct_gotoxy(0, 26 + dis);
        cout << "��" << setw(4) << step << "��( 1) :";
        cout << setw(2) << n << "# " << src << "-->" << dst;
    }
    
}

void tree(int sj, int n = 0, char src = 0, char dst = 0)
{
    if (sj == 4)
    {
        column();
        pause();
    }
    if (sj == 8)
    {
        column(8);
        pause();
        move(src, dst, n);
    }
}

void printcolumn(int sj, int n = 0, char src = 0, char tmp = 0, char dst = 0)
{
    int srccol = 0;
    int tmpcol = 0;
    int dstcol = 0;
    if (src == 'A')
        srccol = 13;
    if (src == 'B')
        srccol = 44;
    if (src == 'C')
        srccol = 75;
    if (tmp == 'A')
        tmpcol = 13;
    if (tmp == 'B')
        tmpcol = 44;
    if (tmp == 'C')
        tmpcol = 75;
    if (dst == 'A')
        dstcol = 13;
    if (dst == 'B')
        dstcol = 44;
    if (dst == 'C')
        dstcol = 75;
    cct_cls();
    if (sj == 6 || sj == 7)
    {
        cct_gotoxy(0, 0);
        cout << "��" << src << "�ƶ���" << dst << "����" << n << "��" << "����ʱ����Ϊ " << t << endl;
    }
    if (sj == 8 || sj == 9)
    {
        cct_gotoxy(0, 0);
        cout << "��" << src << "�ƶ���" << dst << "����" << n << "��";
        if (sj == 8)
        {
            cout << "����ʱ����Ϊ " << t << endl;
        }
    }
    if (1)
    {
        for (int i = 1; i < 26; i++)
        {
            cct_showch(i, 16, ' ', 14, 14, 1);
        }
        for (int j = 32; j < 57; j++)
        {
            cct_showch(j, 16, ' ', 14, 14, 1);
        }
        for (int j = 63; j < 88; j++)
        {
            cct_showch(j, 16, ' ', 14, 14, 1);
        }
        for (int i = 16; i > 3; i--)
        {
            cct_showch(13, i, ' ', 14, 14, 1);
            cct_showch(44, i, ' ', 14, 14, 1);
            cct_showch(75, i, ' ', 14, 14, 1);
            Sleep(100);
        }
        cct_setcolor(); //�ָ�ȱʡ��ɫ
    }
    //������
    if (n > 0 && sj == 6)
    {
        int j = 13;
        int colnum = n;
        for (int i = 15; i >= 16 - n; i--)//��������
        {
            for (int k = srccol - colnum; k <= srccol + colnum; k++)
            {
                cct_showch(k, i, ' ', j, j, 1);
            }
            j--;
            colnum--;
            Sleep(100);
        }
        cct_setcolor(); //�ָ�ȱʡ��ɫ
    }
    if (sj == 7)
    {
        int j = 13;
        int colnum = n;
        for (int i = 15; i >= 16 - n; i--)//��������
        {
            for (int k = srccol - colnum; k <= srccol + colnum; k++)
            {
                cct_showch(k, i, ' ', j, j, 1);
            }
            j--;
            colnum--;
            Sleep(100);
        }
        for (int i = 16 - n; i > 2; i--)
        {
            int k;
            for (k = srccol - colnum - 1; k <= srccol + colnum + 1; k++)
            {
                cct_showch(k, i, ' ', j + 1, j + 1, 1);
            }
            Sleep(100);
            for (k = srccol - colnum - 1; k <= srccol + colnum + 1; k++)
            {
                cct_showch(k, i, ' ', 0, 0, 1);
                if (i > 3)
                {
                    cct_showch(srccol, i, ' ', 14, 14, 1);
                }

            }
        }
        for (int i = srccol - colnum - 1; i <= dstcol - colnum - 1; i++)
        {
            cct_showch(i, 3, ' ', j + 1, j + 1, 3);
            Sleep(100);
            if (i < dstcol + colnum - 1)
            {
                cct_showch(i, 3, ' ', 0, 0, 1);
            }
        }
        for (int i = 3; i < 16; i++)
        {
            cct_showch(dstcol - 1, i, ' ', j + 1, j + 1, 3);
            Sleep(100);
            if (i < 15)
            {
                cct_showch(dstcol - 1, i, ' ', 0, 0, 3);
                if (i > 3)
                {
                    cct_showch(dstcol, i, ' ', 14, 14, 1);
                }
            }
        }
        cct_setcolor(); //�ָ�ȱʡ��ɫ
    }
    if (sj == 8 || sj == 9)
    {
        int colnum = n;
        int j = colnum;
        for (int i = 15; i >= 16 - n; i--)//��������
        {
            for (int k = srccol - colnum; k <= srccol + colnum; k++)
            {
                cct_showch(k, i, ' ', j, j, 1);
            }
            j--;
            colnum--;
            Sleep(100);
        }
        cct_setcolor(); //�ָ�ȱʡ��ɫ
        if (display == 1 && sj == 8)
        {
            
            cct_gotoxy(20, 36);
            cout << "��ʼ:               ";
            output(step, n, src, dst);
            column(8);
            pause();
        }
        if (sj == 9)
        {
            cct_gotoxy(9, 36);
            cout << "��ʼ:               ";
            output(step, n, src, dst);
            column(9);
        }
        cct_setcolor(); //�ָ�ȱʡ��ɫ
        if (sj == 9)
        {      
            int sum = n;
            char final = dst;
            char moving0 = 0;
            char moving1 = 0;
            int disk0 = 0;
            int disk1 = 0;
            while (1)
            {
                disk0 = 0;
                disk1 = 0;
                moving0 = 0;
                moving1 = 0;
                cct_gotoxy(0, 38);
                cout << "�������ƶ������ţ�������ʽ��AC=A���˵������ƶ���C��Q�˳�����";
                             
                moving0 = getchar();
                if (moving0 == 'q' || moving0 == 'Q')
                {
                    cout << "��Ϸ��ֹ������" << endl << endl << endl;
                    cout << "���س�������" << endl;
                    char back = getchar();
                    if (back == '\r')
                    {
                        break;
                    }
                }
                if (moving0 == 'A' || moving0 == 'a')
                {
                    moving0 = 'A';
                    if (a0 > 0)
                    {
                        disk0 = A[a0 - 1];
                    }
                }
                else if (moving0 == 'B' || moving0 == 'b')
                {
                    moving0 = 'B';
                    if (b0 > 0)
                    {
                        disk0 = B[b0 - 1];
                    }
                }
                else if (moving0 == 'C' || moving0 == 'c')
                {
                    moving0 = 'C';
                    if (c0 > 0)
                    {
                        disk0 = C[c0 - 1];
                    }
                }
                else
                {
                    cct_gotoxy(60, 38);
                    cout << "                                             ";
                    continue;
                }
                moving1 = getchar();
                if (moving1 != moving0 && moving1 != moving0 + 32)
                {
                    if (moving1 == 'A' || moving1 == 'a')
                    {
                        moving1 = 'A';
                    }
                    else if (moving1 == 'B' || moving1 == 'b')
                    {
                        moving1 = 'B';
                    }
                    else if (moving1 == 'C' || moving1 == 'c')
                    {
                        moving1 = 'C';
                    }
                    else
                    {
                        cct_gotoxy(60, 38);
                        cout << "                                             ";
                        continue;
                    }
                }
                else
                    continue;
                if ((moving0 == 'A' && a0 == 0) || (moving0 == 'B' && b0 == 0) || (moving0 == 'C' && c0 == 0))
                {
                    cout << "Դ��Ϊ�գ�����";
                    Sleep(1000);
                    cct_gotoxy(60, 38);
                    cout << "                                             ";
                    cct_gotoxy(0, 39);
                    cout << "                      ";
                    continue;
                }
                if (moving1 == 'A' && a0 > 0)
                {
                    disk1 = A[a0 - 1];
                }
                if (moving1 == 'B' && b0 > 0)
                {
                    disk1 = B[b0 - 1];
                }
                if (moving1 == 'C' && c0 > 0)
                {
                    disk1 = C[c0 - 1];
                }
                if (disk0 > disk1 && disk1 != 0)
                {
                    cout << "����ѹС�̣��Ƿ��ƶ�!";
                    Sleep(1000);
                    cct_gotoxy(60, 38);
                    cout << "                                             ";
                    cct_gotoxy(0, 39);
                    cout << "                      ";
                    continue;
                }
                else
                {                 
                    movedisk(moving0, moving1, disk0);
                    cct_gotoxy(0, 36);
                    cout << "                                                                                                            ";
                    printstep(moving0, moving1, disk0, sj);
                    output(step, disk0, moving0, moving1, sj);
                    column(9);
                    step++;
                    cct_setcolor(0, 7);
                    move(moving0, moving1, disk0);                   
                }
                if (final == 'A' && a0 == sum)
                {
                    cct_gotoxy(0, 39);
                    cout << "��Ϸ��������������" << endl;
                    cout << endl << endl << endl;
                    break;
                }
                if (final == 'B' && b0 == sum)
                {
                    cct_gotoxy(0, 39);
                    cout << "��Ϸ��������������" << endl;
                    cout << endl << endl << endl;
                    break;
                }
                if (final == 'C' && c0 == sum)
                {
                    cct_gotoxy(0, 39);
                    cout << "��Ϸ��������������" << endl;
                    cout << endl << endl << endl;
                    break;
                }
            }
        }
    }
}

void hanoi(int n, char src, char tmp, char dst, int sj)
{
    if (n == 0)
        return;
    else
    {
        hanoi(n - 1, src, dst, tmp, sj);
        movedisk(src, dst, n);
        printstep(src, dst, n, sj);
        tree(sj, n, src, dst);
        step = step++;
        hanoi(n - 1, tmp, src, dst, sj);
    }
}

void hanoi_s1(int sj)
{
    int n;
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (n < 1 || n>16)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
    }
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
        int k = getchar();
        if (k == 'a') {
            k = 'A';
        }
        if (k == 'b') {
            k = 'B';
        }
        if (k == 'c') {
            k = 'C';
        }
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (k != 65 && k != 66 && k != 67 && k != 97 && k != 98 && k != 99)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            if (k == 65 || k == 97)
                k = 65;

            if (k == 66 || k == 98)
                k = 66;

            if (k == 67 || k == 99)
                k = 67;
            cin.clear();
            cin.ignore(1024, '\n');
        }
        while (1)
        {
            cout << "������Ŀ����(A-C)" << endl;
            int l = getchar();
            if (l == 'a') {
                l = 'A';
            }
            if (l == 'b') {
                l = 'B';
            }
            if (l == 'c') {
                l = 'C';
            }
            if (cin.good() == 0)
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (l != 65 && l != 66 && l != 67 && l != 97 && l != 98 && l != 99)
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (l == k)
            {
                cout << "Ŀ����(" << char(l) << ")��������ʼ��(" << char(k) << ")��ͬ" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            else
            {
                if (l == 65 || l == 97)
                    l = 65;

                if (l == 66 || l == 98)
                    l = 66;

                if (l == 67 || l == 99)
                    l = 67;
                cout << "�ƶ�����Ϊ:" << endl;
                int m;
                if (k != 65 && l != 65 && k != 97 && l != 97)
                    m = 65;
                if (k != 66 && l != 66 && k != 98 && l != 98)
                    m = 66;
                if (k != 67 && l != 67 && k != 99 && l != 99)
                    m = 67;
                hanoi(n, k, m, l, sj);
                break;
            }
        }
        break;
    }
}

void hanoi_s2(int sj)
{
    int n;
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (n < 1 || n>16)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
    }
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
        int k = getchar();
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (k != 65 && k != 66 && k != 67 && k != 97 && k != 98 && k != 99)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            if (k == 65 || k == 97)
                k = 65;

            if (k == 66 || k == 98)
                k = 66;

            if (k == 67 || k == 99)
                k = 67;
            cin.clear();
            cin.ignore(1024, '\n');
        }
        while (1)
        {
            cout << "������Ŀ����(A-C)" << endl;
            int l = getchar();
            if (cin.good() == 0)
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (l != 65 && l != 66 && l != 67 && l != 97 && l != 98 && l != 99)
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (l == k)
            {
                cout << "Ŀ����(" << char(l) << ")��������ʼ��(" << char(k) << ")��ͬ" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            else
            {
                if (l == 65 || l == 97)
                    l = 65;

                if (l == 66 || l == 98)
                    l = 66;

                if (l == 67 || l == 99)
                    l = 67;
                cout << "�ƶ�����Ϊ:" << endl;
                int m;
                if (k != 65 && l != 65 && k != 97 && l != 97)
                    m = 65;
                if (k != 66 && l != 66 && k != 98 && l != 98)
                    m = 66;
                if (k != 67 && l != 67 && k != 99 && l != 99)
                    m = 67;
                hanoi(n, k, m, l, sj);
                break;
            }
        }
        break;
    }
}

void hanoi_s348(int sj)
{
    int n;
    char x, y, z;
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (n < 1 || n>16)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
    }
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
        int k = getchar();
        if (k == 'a') {
            k = 'A';
        }
        if (k == 'b') {
            k = 'B';
        }
        if (k == 'c') {
            k = 'C';
        }
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (k != 65 && k != 66 && k != 67 && k != 97 && k != 98 && k != 99)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            if (k == 65 || k == 97)
                k = 65;

            if (k == 66 || k == 98)
                k = 66;

            if (k == 67 || k == 99)
                k = 67;
            cin.clear();
            cin.ignore(1024, '\n');
        }
        while (1)
        {
            cout << "������Ŀ����(A-C)" << endl;
            int l = getchar();
            if (l == 'a') {
                l = 'A';
            }
            if (l == 'b') {
                l = 'B';
            }
            if (l == 'c') {
                l = 'C';
            }
            if (cin.good() == 0)
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (l != 65 && l != 66 && l != 67 && l != 97 && l != 98 && l != 99)
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (l == k)
            {
                cout << "Ŀ����(" << char(l) << ")��������ʼ��(" << char(k) << ")��ͬ" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            else
            {
                if (l == 65 || l == 97)
                    l = 65;

                if (l == 66 || l == 98)
                    l = 66;

                if (l == 67 || l == 99)
                    l = 67;
                int m;
                if (k != 65 && l != 65 && k != 97 && l != 97)
                    m = 65;
                if (k != 66 && l != 66 && k != 98 && l != 98)
                    m = 66;
                if (k != 67 && l != 67 && k != 99 && l != 99)
                    m = 67;
                if (k == 'A')
                {
                    for (int i = 0; i < n; i++)
                    {
                        A[i] = n - i;
                    }
                    a0 = n;
                }
                else if (k == 'B')
                {
                    for (int i = 0; i < n; i++)
                    {
                        B[i] = n - i;
                    }
                    b0 = n;
                }
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        C[i] = n - i;
                    }
                    c0 = n;
                }
                x = k;
                y = m;
                z = l;
                if (sj == 3)
                {
                    cout << "��ʼ:                  ";
                    cout << " A:";
                    for (int i = 0; i < A[0]; i++)
                    {
                        cout << std::right << setw(2) << A[i];
                    }
                    for (int space = 0; space < (21 - 2 * a0); space++)
                    {
                        cout << " ";
                    }
                    cout << " B:";
                    for (int j = 0; j < b0; j++) {
                        cout << std::right << setw(2) << B[j];
                    }
                    for (int space = 0; space < (21 - 2 * b0); space++)
                    {
                        cout << " ";
                    }
                    cout << " C:";
                    for (int k = 0; k < c0; k++)
                    {
                        cout << std::right << setw(2) << C[k];
                    }
                    cout << endl;
                    hanoi(n, k, m, l, sj);
                }
                break;
            }
        }
        break;
    }

    while (sj == 4)
    {
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
        cin >> t;
        if (t != 0 && t != 1 && t != 2 && t != 3 && t != 4 && t != 5) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            break;
        }
    }

    while (sj == 4)
    {
        cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
        cin >> display;
        if (display != 0 && display != 1)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (display == 0)
        {
            cct_cls();
            cout << "�� " << x << " �ƶ��� " << z << "���� " << n << " �㣬��ʱ����Ϊ " << t << "������ʾ�ڲ�����ֵ" << endl;
            break;
        }
        if (display == 1)
        {
            cct_cls();
            cout << "�� " << x << " �ƶ��� " << z << "���� " << n << " �㣬��ʱ����Ϊ " << t << "����ʾ�ڲ�����ֵ" << endl;
            break;
        }
    }
    if (sj == 4)
    {
        cct_gotoxy(20, 26);
        if (display == 1)
        {
            cout << "��ʼ:               ";
            output(step, n, x, z);
            column();
            pause();
        }
        hanoi(n, x, y, z, sj);
        system("pause");
    }
} 

void hanoi_s56789(int sj)
{
    int n = 0;
    char x = 0;
    char y = 0;
    char z = 0;
    while (sj == 6)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (n < 1 || n>16)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
    }
    while (sj == 6)
    {
        cout << "��������ʼ��(A-C)" << endl;
        int k = getchar();
        if (k == 'a') {
            k = 'A';
        }
        if (k == 'b') {
            k = 'B';
        }
        if (k == 'c') {
            k = 'C';
        }
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (k != 65 && k != 66 && k != 67 && k != 97 && k != 98 && k != 99)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            if (k == 65 || k == 97)
                k = 65;

            if (k == 66 || k == 98)
                k = 66;

            if (k == 67 || k == 99)
                k = 67;
            cin.clear();
            cin.ignore(1024, '\n');
        }
        while (1)
        {
            cout << "������Ŀ����(A-C)" << endl;
            int l = getchar();
            if (l == 'a') {
                l = 'A';
            }
            if (l == 'b') {
                l = 'B';
            }
            if (l == 'c') {
                l = 'C';
            }
            if (cin.good() == 0)
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (l != 65 && l != 66 && l != 67 && l != 97 && l != 98 && l != 99)
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (l == k)
            {
                cout << "Ŀ����(" << char(l) << ")��������ʼ��(" << char(k) << ")��ͬ" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            else
            {
                if (l == 65 || l == 97)
                    l = 65;

                if (l == 66 || l == 98)
                    l = 66;

                if (l == 67 || l == 99)
                    l = 67;
                cout << "�ƶ�����Ϊ:" << endl;
                int m;
                if (k != 65 && l != 65 && k != 97 && l != 97)
                    m = 65;
                if (k != 66 && l != 66 && k != 98 && l != 98)
                    m = 66;
                if (k != 67 && l != 67 && k != 99 && l != 99)
                    m = 67;
                printcolumn(sj, n, k, m, l);
                break;
            }
        }
        break;
    }
    if (sj == 5)
    {
        printcolumn(sj, 0, 0, 0, 0);
    }
    while (sj == 7)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (n < 1 || n>16)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
    }
    while (sj == 7)
    {
        cout << "��������ʼ��(A-C)" << endl;
        int k = getchar();
        if (k == 'a') {
            k = 'A';
        }
        if (k == 'b') {
            k = 'B';
        }
        if (k == 'c') {
            k = 'C';
        }
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (k != 65 && k != 66 && k != 67 && k != 97 && k != 98 && k != 99)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            if (k == 65 || k == 97)
                k = 65;

            if (k == 66 || k == 98)
                k = 66;

            if (k == 67 || k == 99)
                k = 67;
            cin.clear();
            cin.ignore(1024, '\n');
        }
        while (1)
        {
            cout << "������Ŀ����(A-C)" << endl;
            int l = getchar();
            if (l == 'a') {
                l = 'A';
            }
            if (l == 'b') {
                l = 'B';
            }
            if (l == 'c') {
                l = 'C';
            }
            if (cin.good() == 0)
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (l != 65 && l != 66 && l != 67 && l != 97 && l != 98 && l != 99)
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (l == k)
            {
                cout << "Ŀ����(" << char(l) << ")��������ʼ��(" << char(k) << ")��ͬ" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            else
            {
                if (l == 65 || l == 97)
                    l = 65;

                if (l == 66 || l == 98)
                    l = 66;

                if (l == 67 || l == 99)
                    l = 67;
                cout << "�ƶ�����Ϊ:" << endl;
                int m;
                if (k != 65 && l != 65 && k != 97 && l != 97)
                    m = 65;
                if (k != 66 && l != 66 && k != 98 && l != 98)
                    m = 66;
                if (k != 67 && l != 67 && k != 99 && l != 99)
                    m = 67;
                if (n % 2 == 0)
                {
                    printcolumn(sj, n, k, l, m);
                }
                else
                {
                    printcolumn(sj, n, k, m, l);
                }
                break;
            }
        }
        break;
    }
    while (sj == 8)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (n < 1 || n>16)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
    }
    while (sj == 8)
    {
        cout << "��������ʼ��(A-C)" << endl;
        int k = getchar();
        if (k == 'a') {
            k = 'A';
        }
        if (k == 'b') {
            k = 'B';
        }
        if (k == 'c') {
            k = 'C';
        }
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (k != 65 && k != 66 && k != 67 && k != 97 && k != 98 && k != 99)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            if (k == 65 || k == 97)
                k = 65;

            if (k == 66 || k == 98)
                k = 66;

            if (k == 67 || k == 99)
                k = 67;
            cin.clear();
            cin.ignore(1024, '\n');
        }
        while (1)
        {
            cout << "������Ŀ����(A-C)" << endl;
            int l = getchar();
            if (l == 'a') {
                l = 'A';
            }
            if (l == 'b') {
                l = 'B';
            }
            if (l == 'c') {
                l = 'C';
            }
            if (cin.good() == 0)
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (l != 65 && l != 66 && l != 67 && l != 97 && l != 98 && l != 99)
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (l == k)
            {
                cout << "Ŀ����(" << char(l) << ")��������ʼ��(" << char(k) << ")��ͬ" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            else
            {
                if (l == 65 || l == 97)
                    l = 65;

                if (l == 66 || l == 98)
                    l = 66;

                if (l == 67 || l == 99)
                    l = 67;
                int m;
                if (k != 65 && l != 65 && k != 97 && l != 97)
                    m = 65;
                if (k != 66 && l != 66 && k != 98 && l != 98)
                    m = 66;
                if (k != 67 && l != 67 && k != 99 && l != 99)
                    m = 67;
                if (k == 'A')
                {
                    for (int i = 0; i < n; i++)
                    {
                        A[i] = n - i;
                    }
                    a0 = n;
                }
                else if (k == 'B')
                {
                    for (int i = 0; i < n; i++)
                    {
                        B[i] = n - i;
                    }
                    b0 = n;
                }
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        C[i] = n - i;
                    }
                    c0 = n;
                }
                x = k;
                y = m;
                z = l;
                break;
            }
        }
        break;
    }
    while (sj == 8)
    {
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
        cin >> t;
        if (t != 0 && t != 1 && t != 2 && t != 3 && t != 4 && t != 5) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            break;
        }
    }
    while (sj == 8)
    {
        cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
        cin >> display;
        if (display != 0 && display != 1)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (display == 0)
        {
            cct_cls();
            cout << "�� " << x << " �ƶ��� " << z << "���� " << n << " �㣬��ʱ����Ϊ " << t << "������ʾ�ڲ�����ֵ" << endl;
            break;
        }
        if (display == 1)
        {
            cct_cls();
            cout << "�� " << x << " �ƶ��� " << z << "���� " << n << " �㣬��ʱ����Ϊ " << t << "����ʾ�ڲ�����ֵ" << endl;
            break;
        }
    }
    if (sj == 8)
    {        
        printcolumn(sj, n, x, y, z);
        hanoi(n, x, y, z, sj);
        system("pause");
    }
    while (sj == 9)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (n < 1 || n>16)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
    }
    while (sj == 9)
    {
        cout << "��������ʼ��(A-C)" << endl;
        int k = getchar();
        if (k == 'a') {
            k = 'A';
        }
        if (k == 'b') {
            k = 'B';
        }
        if (k == 'c') {
            k = 'C';
        }
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (k != 65 && k != 66 && k != 67 && k != 97 && k != 98 && k != 99)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            if (k == 65 || k == 97)
                k = 65;

            if (k == 66 || k == 98)
                k = 66;

            if (k == 67 || k == 99)
                k = 67;
            cin.clear();
            cin.ignore(1024, '\n');
        }
        while (1)
        {
            cout << "������Ŀ����(A-C)" << endl;
            int l = getchar();
            if (l == 'a') {
                l = 'A';
            }
            if (l == 'b') {
                l = 'B';
            }
            if (l == 'c') {
                l = 'C';
            }
            if (cin.good() == 0)
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (l != 65 && l != 66 && l != 67 && l != 97 && l != 98 && l != 99)
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (l == k)
            {
                cout << "Ŀ����(" << char(l) << ")��������ʼ��(" << char(k) << ")��ͬ" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            else
            {
                if (l == 65 || l == 97)
                    l = 65;

                if (l == 66 || l == 98)
                    l = 66;

                if (l == 67 || l == 99)
                    l = 67;
                int m;
                if (k != 65 && l != 65 && k != 97 && l != 97)
                    m = 65;
                if (k != 66 && l != 66 && k != 98 && l != 98)
                    m = 66;
                if (k != 67 && l != 67 && k != 99 && l != 99)
                    m = 67;
                if (k == 'A')
                {
                    for (int i = 0; i < n; i++)
                    {
                        A[i] = n - i;
                    }
                    a0 = n;
                }
                else if (k == 'B')
                {
                    for (int i = 0; i < n; i++)
                    {
                        B[i] = n - i;
                    }
                    b0 = n;
                }
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        C[i] = n - i;
                    }
                    c0 = n;
                }
                x = k;
                y = m;
                z = l;
                break;
            }
        }
        break;
    }
    if (sj == 9)
    {
        printcolumn(sj, n, x, y, z);
        
    }
}

