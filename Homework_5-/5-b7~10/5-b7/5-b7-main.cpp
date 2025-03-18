/* 2353726 ��01 ���ϳ� */
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "5-b7.h"
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

void output(int step, int n, char src, char dst)
{
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

void column()
{  
    cct_gotoxy(9, 21);
    cout << "=========================" << endl;
    cct_gotoxy(11, 22);
    cout << "A         B         C" << endl;
    int pointer = 0;
    for (int i = 20; i > 10; i--)
    {
        cct_gotoxy(11, i);
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

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        movedisk(src, dst, n);
        cct_gotoxy(20, 26);
        cout << "��" << setw(4) << step << "��( 1) :" << setw(2) << src << "-->" << dst;
        if (display == 1)
        {
            output(step, n, src, dst);
        }
        column();
        pause();
        step = step++;
        hanoi(n - 1, tmp, src, dst);
    }
}

int main()
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
                break;
            }
        }
        break;
    }

    while (1) 
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

    while (1) 
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
    cct_gotoxy(20, 26);
    if (display == 1)
    {
        cout << "��ʼ:               ";
        output(step, n, x, z);
        column();
        pause();
    }
    hanoi(n, x, y, z);
    system("pause");
    return 0;
}