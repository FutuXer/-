//2353726 ��01 ���ϳ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret, x;

	while (1)
	{
		printf("������x��ֵ[0-100] : ");
		ret = scanf("%d", &x); //����x�ķ�ʽ������scanf�Ҹ�ʽ��Ϊ%d����׼�÷�scanf
		if (ret == 1 && (x >= 0 && x <= 100))
			break;
		if (ret==0)
		{
			char ch;
			while ((ch = getchar()) != '\n' && ch != EOF);
			continue;
		}
		else
		{
			continue;
		}
	}

	printf("cin.good()=%d x=%d\n", ret, x);

	return 0;
}