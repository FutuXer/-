//2353726 ��01 ���ϳ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//87 86 56 76 87 92 76 96 98 23 55 56 34 23 -1
int main()
{
	printf("������ɼ������1000������������������\n");
	int a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		scanf("%d", &a[i]);
		if (a[0] < 0)
		{
			printf("����Ч����\n");
			break;
		}
		if (a[i] < 0 && a != 0)
		{
			break;
		}
	}
	if (a[0] >= 0)
	{
		printf("���������Ϊ:\n");
		int j;
		for (j = 0; j < i; j++)
		{
			printf("%d ", a[j]);
			if ((j + 1) % 10 == 0)
				printf("\n");
		}
		if ((j + 1) % 10 != 0)
		{
			printf("\n");
		}
		printf("�����������Ķ�Ӧ��ϵΪ:\n");
		for (int m = 0; m < i; m++)
		{
			for (int k = 0; k < i - m; k++)
			{
				if (a[k] < a[k + 1])
				{
					int t = a[k];
					a[k] = a[k + 1];
					a[k + 1] = t;
				}
			}
		}
		int num = 1;
		int m = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] == a[j + 1])
			{
				num = num + 1;
			}
			if (a[j] != a[j + 1])
			{
				printf("%d %d\n", a[j], num);
				num = 1;
			}
		}
	}
		

	return 0;
}



