//2353726 ��01 ���ϳ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    printf("�������꣬�£���\n");
    int year, month, day, a, leap;
	scanf("%d %d %d", &year, &month, &day);
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 4 == 0) && (year % 400 == 0))
		leap = 1;
	else
		leap = 0;
	if (month < 1 || month>12)
	{
		printf("�������-�·ݲ���ȷ\n");
	}
	else
        switch (month)
        {
            case 1:
                a = day;
                if (day < 1 || day>31)
                {
                    printf("�������-�����µĹ�ϵ�Ƿ�\n");
                }
                else
                    printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, a);
                break;
            case 2:
                a = 31 + day;
                if (day < 1 || day>28 + leap)
                {
                    printf("�������-�����µĹ�ϵ�Ƿ�\n");
                }
                else
                    printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, a);
                break;
            case 3:
                a = 59 + day + leap;
                if (day < 1 || day>31)
                {
                    printf("�������-�����µĹ�ϵ�Ƿ�\n");
                }
                else
                    printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, a);
                break;
            case 4:
                a = 91 + day + leap;
                if (day < 1 || day>30)
                {
                    printf("�������-�����µĹ�ϵ�Ƿ�\n");
                }
                else
                    printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, a);
                break;
            case 5:
                a = 121 + day + leap;
                if (day < 1 || day>31)
                {
                    printf("�������-�����µĹ�ϵ�Ƿ�\n");
                }
                else
                    printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, a);
                break;
            case 6:
                a = 152 + day + leap;
                if (day < 1 || day>30)
                {
                    printf("�������-�����µĹ�ϵ�Ƿ�\n");
                }
                else
                    printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, a);
                break;
            case 7:
                a = 182 + day + leap;
                if (day < 1 || day>31)
                {
                    printf("�������-�����µĹ�ϵ�Ƿ�\n");
                }
                else
                    printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, a);
                break;
            case 8:
                a = 213 + day + leap;
                if (day < 1 || day>31)
                {
                    printf("�������-�����µĹ�ϵ�Ƿ�\n");
                }
                else
                    printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, a);
                break;
            case 9:
                a = 244 + day + leap;
                if (day < 1 || day>30)
                {
                    printf("�������-�����µĹ�ϵ�Ƿ�\n");
                }
                else
                    printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, a);
                break;
            case 10:
                a = 274 + day + leap;
                if (day < 1 || day>31)
                {
                    printf("�������-�����µĹ�ϵ�Ƿ�\n");
                }
                else
                    printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, a);
                break;
            case 11:
                a = 305 + day + leap;
                if (day < 1 || day>30)
                {
                    printf("�������-�����µĹ�ϵ�Ƿ�\n");
                }
                else
                    printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, a);
                break;
            case 12:
                a = 335 + day + leap;
                if (day < 1 || day>31)
                {
                    printf("�������-�����µĹ�ϵ�Ƿ�\n");
                }
                else
                    printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, a);
        }
	return 0;
}