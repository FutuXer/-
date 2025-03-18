/* 2353726 ��01 ���ϳ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int a = 1;
/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int a = 1;
    if (n == 0)
    {
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        printf("%5d:%3d#%2c-->%c\n", a, n, src, dst);
        a = a++;
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int n, ret;
    while (1)
    {
        printf("�����뺺ŵ���Ĳ���(1-16)\n");
        ret = scanf("%d", &n);
        if (ret == 0)
        {
            char ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        if (n < 1 || n>16)
        {
            char ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        else
        {
            char ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            break;
        }
    }
    while (1)
    {
        printf("��������ʼ��(A-C)\n");
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
        if (ret == 0)
        {
            char ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        if (k != 65 && k != 66 && k != 67 && k != 97 && k != 98 && k != 99)
        {
            char ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
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
            char ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
        while (1)
        {
            printf("������Ŀ����(A-C)\n");
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
            if (ret == 0)
            {
                char ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
                continue;
            }
            if (l != 65 && l != 66 && l != 67 && l != 97 && l != 98 && l != 99)
            {
                char ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
                continue;
            }
            
            if (l == k)
            {
                printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", l, k);
                char ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
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
                printf("�ƶ�����Ϊ:\n");
                int m;
                if (k != 65 && l != 65 && k != 97 && l != 97)
                    m = 65;
                if (k != 66 && l != 66 && k != 98 && l != 98)
                    m = 66;
                if (k != 67 && l != 67 && k != 99 && l != 99)
                    m = 67;
                hanoi(n, k, m, l);
                break;
            }
        }
        break;
    }


    return 0;
}