//2353726 ��01 ���ϳ�
/*2354269 ��Ц�� 2351121 ������ 1953079 ���Ǻ� 2351450 ֣���� 2350242 ��ʫ�� 2351887 ��쿳� 2352219 ��Ӧ��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 

int main()
{
	char a[12][28] = { 0 };
	char b[12][28] = { 0 };
	int num_mine = 0;
	char ch;
	int j = 1;
	for (int i = 1; i < 11; i++) 
	{
		while (j < 27) 
		{
			ch = getchar();
			if (ch == '\n')
			{
				continue;
			}
			if (ch == ' ') 
			{
				continue;
			}
			if (ch == '*')
			{
				a[i][j] = '*';
				b[i][j] = '*';
				num_mine++;
			}
			else
			{
				b[i][j] = ch;
			}	
			j++;
		}
		j = 1;
	}
	if (num_mine != 50)
	{
		printf("����1\n");
	}
	else
	{
		for (int i = 1; i < 11; i++)
		{
			for (int j = 1; j < 27; j++)
			{
				if (a[i][j] != '*')
				{
					for (int x = j - 1; x <= j + 1; x++)
					{
						if (a[i - 1][x] == '*')
						{
							a[i][j]++;
						}
						if (a[i + 1][x] == '*')
						{
							a[i][j]++;
						}
					}
					if (a[i][j - 1] == '*')
					{
						a[i][j]++;
					}
					if (a[i][j + 1] == '*')
					{
						a[i][j]++;
					}
				}
			}
		}
		for (int i = 1; i < 11; i++)
		{
			for (int j = 1; j < 27; j++)
			{			
				if (a[i][j] != '*' && ((int)(a[i][j]) != (b[i][j] - 48)))
				{
					printf("����2\n");
					return 0;
				}
			}
		}
		printf("��ȷ\n");
	}

	return 0;
}