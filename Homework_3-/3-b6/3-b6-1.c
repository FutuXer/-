//2353726 ��01 ���ϳ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    printf( "������[0-100��)֮�������:\n");
    double a;
    scanf("%lf",&a);
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
    int n = (int)(10 * c);
    int o = (int)(100 * c) - 10 * n;
    int p = (int)(1000 * c) - 100 * n - 10 * o;

    printf( "��д�����:\n");
    //ʮ�ں���λ
    switch (e)
    {
        case 1:
            printf( "Ҽ");
            break;
        case 2:
            printf( "��");
            break;
        case 3:
            printf( "��");
            break;
        case 4:
            printf( "��");
            break;
        case 5:
            printf( "��");
            break;
        case 6:
            printf( "½");
            break;
        case 7:
            printf( "��");
            break;
        case 8:
            printf( "��");
            break;
        case 9:
            printf( "��");
            break;
    }
    if (e > 0)
        printf( "ʰ");
    switch (f)
    {
        case 0:
            if (e + g + h + i + j + k + l + m + n == 0 || (e > 0 && f == 0)||e+f==0)
            {
            }
            else
            {
                printf( "��");
            }
            break;
        case 1:
            printf( "Ҽ");
            break;
        case 2:
            printf( "��");
            break;
        case 3:
            printf( "��");
            break;
        case 4:
            printf( "��");
            break;
        case 5:
            printf( "��");
            break;
        case 6:
            printf( "½");
            break;
        case 7:
            printf( "��");
            break;
        case 8:
            printf( "��");
            break;
        case 9:
            printf( "��");
            break;
    }
    if (f > 0)
        printf( "��");
    else if (e > 0 && f == 0)
    {
        printf("��");
    }
    //ǧ����λ
    switch (g)
    {
        case 0:
            if (f + h + i + j + k + l + m + n == 0 || f + h + i + j + k + l == 0||h+i+j==0)
            {
            }
            else if (e + f == 0)
            {
            }
            else
            {
                printf( "��");
            }
            break;
        case 1:
            printf( "Ҽ");
            break;
        case 2:
            printf( "��");
            break;
        case 3:
            printf( "��");
            break;
        case 4:
            printf( "��");
            break;
        case 5:
            printf( "��");
            break;
        case 6:
            printf( "½");
            break;
        case 7:
            printf( "��");
            break;
        case 8:
            printf( "��");
            break;
        case 9:
            printf( "��");
            break;
    }
    if (g > 0)
        printf( "Ǫ");
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
                printf( "��");
            }
            break;
        case 1:
            printf( "Ҽ");
            break;
        case 2:
            printf( "��");
            break;
        case 3:
            printf( "��");
            break;
        case 4:
            printf( "��");
            break;
        case 5:
            printf( "��");
            break;
        case 6:
            printf( "½");
            break;
        case 7:
            printf( "��");
            break;
        case 8:
            printf( "��");
            break;
        case 9:
            printf( "��");
            break;
    }
    if (h > 0)
        printf( "��");
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
                printf( "��");
            }
            break;
        case 1:
            printf( "Ҽ");
            break;
        case 2:
            printf( "��");
            break;
        case 3:
            printf( "��");
            break;
        case 4:
            printf( "��");
            break;
        case 5:
            printf( "��");
            break;
        case 6:
            printf( "½");
            break;
        case 7:
            printf( "��");
            break;
        case 8:
            printf( "��");
            break;
        case 9:
            printf( "��");
            break;
    }
    if (i > 0)
        printf( "ʰ");
    switch (j)
    {
        case 1:
            printf( "Ҽ");
            break;
        case 2:
            printf( "��");
            break;
        case 3:
            printf( "��");
            break;
        case 4:
            printf( "��");
            break;
        case 5:
            printf( "��");
            break;
        case 6:
            printf( "½");
            break;
        case 7:
            printf( "��");
            break;
        case 8:
            printf( "��");
            break;
        case 9:
            printf( "��");
            break;
    }
    if (g > 0 || h > 0 || i > 0 || j > 0)
    {
        printf( "��");
    }
    //ǧ����
    switch (k)
    {
        case 0:
            if (a > 9999.99 && l + m + n > 0)
            {
                printf("��");
            }
            else if (a > 9999.99 && l + m + n == 0)
            {
            }
            else
            {
            }
            break;
        case 1:
            printf( "Ҽ");
            break;
        case 2:
            printf( "��");
            break;
        case 3:
            printf( "��");
            break;
        case 4:
            printf( "��");
            break;
        case 5:
            printf( "��");
            break;
        case 6:
            printf( "½");
            break;
        case 7:
            printf( "��");
            break;
        case 8:
            printf( "��");
            break;
        case 9:
            printf( "��");
            break;
    }
    if (k > 0)
        printf( "Ǫ");
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
                printf( "��");
            }
            break;
        case 1:
            printf( "Ҽ");
            break;
        case 2:
            printf( "��");
            break;
        case 3:
            printf( "��");
            break;
        case 4:
            printf( "��");
            break;
        case 5:
            printf( "��");
            break;
        case 6:
            printf( "½");
            break;
        case 7:
            printf( "��");
            break;
        case 8:
            printf( "��");
            break;
        case 9:
            printf( "��");
            break;
    }
    if (l > 0)
        printf( "��");
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
                printf( "��");
            }
            break;
        case 1:
            printf( "Ҽ");
            break;
        case 2:
            printf( "��");
            break;
        case 3:
            printf( "��");
            break;
        case 4:
            printf( "��");
            break;
        case 5:
            printf( "��");
            break;
        case 6:
            printf( "½");
            break;
        case 7:
            printf( "��");
            break;
        case 8:
            printf( "��");
            break;
        case 9:
            printf( "��");
            break;
    }
    if (m > 0)
        printf( "ʰ");
    switch (n)
    {
        case 1:
            printf( "Ҽ");
            break;
        case 2:
            printf( "��");
            break;
        case 3:
            printf( "��");
            break;
        case 4:
            printf( "��");
            break;
        case 5:
            printf( "��");
            break;
        case 6:
            printf( "½");
            break;
        case 7:
            printf( "��");
            break;
        case 8:
            printf( "��");
            break;
        case 9:
            printf( "��");
            break;
    }
    if (e + f + g + h + i + j + k + l + m + n == 0&&o+p>0)
    {
    }
    else
    {
        printf("Բ");
    }
    if (o == 0 && p == 0)
    {
        printf( "��\n");
    }
    else if (o > 0 && p == 0)
    {
        switch (o)
        {
            case 0:
                if (e + f + g + h + i + j + k + l + m == 0 && o + p == 0)
                {
                    printf("��");
                }
            case 1:
                printf( "Ҽ");
                break;
            case 2:
                printf( "��");
                break;
            case 3:
                printf( "��");
                break;
            case 4:
                printf( "��");
                break;
            case 5:
                printf( "��");
                break;
            case 6:
                printf( "½");
                break;
            case 7:
                printf( "��");
                break;
            case 8:
                printf( "��");
                break;
            case 9:
                printf( "��");
                break;
        }
        printf( "����\n");
    }
    else
    {
        switch (o)
        {
            case 0:
                if (p > 0)
                {
                    printf("��");
                }
                else
                {
                }
                break;
            case 1:
                printf( "Ҽ");
                break;
            case 2:
                printf( "��");
                break;
            case 3:
                printf( "��");
                break;
            case 4:
                printf( "��");
                break;
            case 5:
                printf( "��");
                break;
            case 6:
                printf( "½");
                break;
            case 7:
                printf( "��");
                break;
            case 8:
                printf( "��");
                break;
            case 9:
                printf( "��");
                break;
        }
        if (o > 0)
        {
            printf( "��");
        }
        switch (p)
        {
            case 0:
                break;
            case 1:
                printf( "Ҽ");
                break;
            case 2:
                printf( "��");
                break;
            case 3:
                printf( "��");
                break;
            case 4:
                printf( "��");
                break;
            case 5:
                printf( "��");
                break;
            case 6:
                printf( "½");
                break;
            case 7:
                printf( "��");
                break;
            case 8:
                printf( "��");
                break;
            case 9:
                printf( "��");
                break;
        }
        if (p > 0)
        {
            printf( "��\n");
        }
    }
    return 0;
}