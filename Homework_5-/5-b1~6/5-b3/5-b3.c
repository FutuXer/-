//2353726 ��01 ���ϳ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int leapjudge(int year,int month,int day)
{
    int b[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int c[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 4 == 0) && (year % 400 == 0))//������
    {
        if (day > b[month] || day < 1)
        {
            printf("�������-�����µĹ�ϵ�Ƿ�\n");
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if (day > c[month] || day < 1)
        {
            printf("�������-�����µĹ�ϵ�Ƿ�\n");
            return 0;
        }
        else
        {
            return 2;
        }
    }
}

int daycal(int month, int day, int judge)
{
    if (judge == 1)
    {
        int sum = 0;
        int a[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
        for (int i = 0; i < month; i++)
        {
            sum = sum + a[i];
        }
        sum = sum + day;
        return sum;
    }
    else
    {
        int sum = 0;
        int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        for (int i = 0; i < month; i++)
        {
            sum = sum + a[i];
        }
        sum = sum + day;
        return sum;
    }
}

int main()
{
    int year, month, day, a;
    printf("�������꣬�£���\n");
    scanf("%d %d %d", &year, &month, &day);

    if (month > 12 || month < 1) 
    {
        printf("�������-�·ݲ���ȷ\n");
        return 0;
    }
    else 
    {
        int judge = leapjudge(year, month, day);
        a = daycal(month, day, judge);
    }
    printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, a);


    return 0;
}