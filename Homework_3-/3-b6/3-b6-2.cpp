//2353726 ��01 ���ϳ�
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout << "������[0-100��)֮�������:" << endl;
    double a;
    cin >> a;
    double x = a + 1e-6;
    int b = (int)(x / 10);
    double c = x / 10 - b;
    int d = b / 1000000000;
    int e = b / 100000000 - 10 * d;
    int f = b / 10000000 - 10 * e - 100 * d;
    int g = b / 1000000 - 1000 * d - 100 * e - 10 * f;
    int h = b / 100000 - 10000 * d - 1000 * e - 100 * f - 10 * g;
    int i = b / 10000 - 100000 * d - 10000 * e - 1000 * f - 100 * g - 10 * h;
    int j = b / 1000 - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i;
    int k = b / 100 - 10000000 * d - 1000000 * e - 100000 * f - 10000 * g - 1000 * h - 100 * i - 10 * j;
    int l = b / 10 - 100000000 * d - 10000000 * e - 1000000 * f - 100000 * g - 10000 * h - 1000 * i - 100 * j - 10 * k;
    int m = b / 1 - 1000000000 * d - 100000000 * e - 10000000 * f - 1000000 * g - 100000 * h - 10000 * i - 1000 * j - 100 * k - 10 * l;
    int n = int(10 * c);
    int o = int(100 * c) - 10 * n;
    int p = int(1000 * c) - 100 * n - 10 * o;

    cout << "��д�����:" << endl;
    //ʮ�ں���λ
    switch (e)
    {
        case 0:
            break;
        case 1:
            cout << "Ҽ";
            break;
        case 2:
            cout << "��";
            break;
        case 3:
            cout << "��";
            break;
        case 4:
            cout << "��";
            break;
        case 5:
            cout << "��";
            break;
        case 6:
            cout << "½";
            break;
        case 7:
            cout << "��";
            break;
        case 8:
            cout << "��";
            break;
        case 9:
            cout << "��";
            break;
    }
    if (e > 0)
        cout << "ʰ";
    switch (f)
    {
        case 0:
            break;
        case 1:
            cout << "Ҽ";
            break;
        case 2:
            cout << "��";
            break;
        case 3:
            cout << "��";
            break;
        case 4:
            cout << "��";
            break;
        case 5:
            cout << "��";
            break;
        case 6:
            cout << "½";
            break;
        case 7:
            cout << "��";
            break;
        case 8:
            cout << "��";
            break;
        case 9:
            cout << "��";
            break;
    }
    if (f > 0)
        cout << "��";
    else if (e>0&&f==0)
    {
        cout << "��";
    }
 //ǧ����λ
    switch (g)
    {
        case 0:
            if (f+h+i+j+k+l+m+n==0||f+h+i+j==0||h+i+j==0)
            {
            }
            else if (e+f==0)
            {
            }
            else
            {
                cout << "��";
            }
            break;
        case 1:
            cout << "Ҽ";
            break;
        case 2:
            cout << "��";
            break;
        case 3:
            cout << "��";
            break;
        case 4:
            cout << "��";
            break;
        case 5:
            cout << "��";
            break;
        case 6:
            cout << "½";
            break;
        case 7:
            cout << "��";
            break;
        case 8:
            cout << "��";
            break;
        case 9:
            cout << "��";
            break;
    }
    if (g > 0)
        cout << "Ǫ";
    switch (h)
    {
        case 0:
            if (g == 0)
            {
            }
            else if (i == 0 && j == 0)
            {
            }
            else
            {
                cout << "��";
            }
            break;
        case 1:
            cout << "Ҽ";
            break;
        case 2:
            cout << "��";
            break;
        case 3:
            cout << "��";
            break;
        case 4:
            cout << "��";
            break;
        case 5:
            cout << "��";
            break;
        case 6:
            cout << "½";
            break;
        case 7:
            cout << "��";
            break;
        case 8:
            cout << "��";
            break;
        case 9:
            cout << "��";
            break;          
    }
    if (h > 0)
        cout << "��";
    switch (i)
    {
        case 0:
            if (h == 0)
            {
            }
            else if (j == 0)
            {
            }
            else
            {
                cout << "��";
            }
            break;
        case 1:
            cout << "Ҽ";
            break;
        case 2:
            cout << "��";
            break;
        case 3:
            cout << "��";
            break;
        case 4:
            cout << "��";
            break;
        case 5:
            cout << "��";
            break;
        case 6:
            cout << "½";
            break;
        case 7:
            cout << "��";
            break;
        case 8:
            cout << "��";
            break;
        case 9:
            cout << "��";
            break;           
    }
    if (i > 0)
        cout << "ʰ";
    switch (j)
    {
        case 1:
            cout << "Ҽ";
            break;
        case 2:
            cout << "��";
            break;
        case 3:
            cout << "��";
            break;
        case 4:
            cout << "��";
            break;
        case 5:
            cout << "��";
            break;
        case 6:
            cout << "½";
            break;
        case 7:
            cout << "��";
            break;
        case 8:
            cout << "��";
            break;
        case 9:
            cout << "��";
            break;
    }
    if (g>0||h>0||i>0||j>0)
    {
        cout << "��";
    }
    //ǧ����
    switch (k)
    {
        case 0:
            if (a>9999.99&&l+m+n>0)
            {
                cout << "��";
            }
            else if (a>9999.99&&l+m+n==0)
            {
            }
            else
            {
            }
            break;
        case 1:
            cout << "Ҽ";
            break;
        case 2:
            cout << "��";
            break;
        case 3:
            cout << "��";
            break;
        case 4:
            cout << "��";
            break;
        case 5:
            cout << "��";
            break;
        case 6:
            cout << "½";
            break;
        case 7:
            cout << "��";
            break;
        case 8:
            cout << "��";
            break;
        case 9:
            cout << "��";
            break;          
    }
    if (k > 0)
        cout << "Ǫ";
    switch (l)
    {
        case 0:
            if (k == 0)
            {
            }
            else if (m == 0 && n == 0)
            {
            }
            else
            {
                cout << "��";
            }
            break;
        case 1:
            cout << "Ҽ";
            break;
        case 2:
            cout << "��";
            break;
        case 3:
            cout << "��";
            break;
        case 4:
            cout << "��";
            break;
        case 5:
            cout << "��";
            break;
        case 6:
            cout << "½";
            break;
        case 7:
            cout << "��";
            break;
        case 8:
            cout << "��";
            break;
        case 9:
            cout << "��";
            break;
    }
    if (l > 0)
        cout << "��";
    switch (m)
    {
        case 0:
            if (l == 0)
            {
            }
            else if (n == 0)
            {
            }
            else
            {
                cout << "��";
            }
            break;
        case 1:
            cout << "Ҽ";
            break;
        case 2:
            cout << "��";
            break;
        case 3:
            cout << "��";
            break;
        case 4:
            cout << "��";
            break;
        case 5:
            cout << "��";
            break;
        case 6:
            cout << "½";
            break;
        case 7:
            cout << "��";
            break;
        case 8:
            cout << "��";
            break;
        case 9:
            cout << "��";
            break;
    }
    if (m > 0)
        cout << "ʰ";
    switch (n)
    {
        case 0:
            if (e+f+g+h+i+j+k+l+m==0&&o+p==0)
            {
                cout << "��";
            }
            break;
        case 1:
            cout << "Ҽ";
            break;
        case 2:
            cout << "��";
            break;
        case 3:
            cout << "��";
            break;
        case 4:
            cout << "��";
            break;
        case 5:
            cout << "��";
            break;
        case 6:
            cout << "½";
            break;
        case 7:
            cout << "��";
            break;
        case 8:
            cout << "��";
            break;
        case 9:
            cout << "��";
            break;
    }
    if (e+f+g+h+i+j+k+l+m+n==0&&o+p>0)
    {
    }
    else
    {
        cout << "Բ";
    }
    if (o==0&&p==0)
    {
        cout << "��" << endl;
    }
    else if (o>0&&p==0)
    {
        switch (o)
        {
            case 1:
                cout << "Ҽ";
                break;
            case 2:
                cout << "��";
                break;
            case 3:
                cout << "��";
                break;
            case 4:
                cout << "��";
                break;
            case 5:
                cout << "��";
                break;
            case 6:
                cout << "½";
                break;
            case 7:
                cout << "��";
                break;
            case 8:
                cout << "��";
                break;
            case 9:
                cout << "��";
                break;
        }
        cout << "��" << "��" << endl;
    }
    else
    {
        switch (o)
        {
            case 0:
                if (e+f+g+h+i+j+k+l+m+n>0&&p>0)
                {
                    cout << "��";
                }
                else
                {
                }
                break;
            case 1:
                cout << "Ҽ";
                break;
            case 2:
                cout << "��";
                break;
            case 3:
                cout << "��";
                break;
            case 4:
                cout << "��";
                break;
            case 5:
                cout << "��";
                break;
            case 6:
                cout << "½";
                break;
            case 7:
                cout << "��";
                break;
            case 8:
                cout << "��";
                break;
            case 9:
                cout << "��";
                break;
        }
        if (o>0)
        {
            cout << "��";
        }
        switch (p)
        {
            case 0:
                break;
            case 1:
                cout << "Ҽ";
                break;
            case 2:
                cout << "��";
                break;
            case 3:
                cout << "��";
                break;
            case 4:
                cout << "��";
                break;
            case 5:
                cout << "��";
                break;
            case 6:
                cout << "½";
                break;
            case 7:
                cout << "��";
                break;
            case 8:
                cout << "��";
                break;
            case 9:
                cout << "��";
                break;
        }
        if (p > 0)
        {
            cout << "��" << endl;
        }
    }
    return 0;
}