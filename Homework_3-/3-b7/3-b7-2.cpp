//2353726 ��01 ���ϳ�
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "����������ֵ��" << endl;
	double cash;
	cin >> cash;
	int x = int(cash);
	double y = cash - x;
	int a = x / 10, b = x - 10 * a, c = int(10 * y), d = int(100 * y - 10 * c);
	int e, f, g, h, wushi, ershi, shi, yi, wu, wujiao, yijiao, wufen, erfen, yifen;
	switch (a)
	{
		case 0:
			wushi = 0, ershi = 0, shi = 0, e = 0;
			break;
		case 1:
			wushi = 0, ershi = 0, shi = 1, e = 1;
			break;
		case 2:
			wushi = 0, ershi = 1, shi = 0, e = 1;
			break;
		case 3:
			wushi = 0, ershi = 1, shi = 1, e = 2;
			break;
		case 4:
			wushi = 0, ershi = 2, shi = 0, e = 2;
			break;
		case 5:
			wushi = 1, ershi = 0, shi = 0, e = 1;
			break;
		case 6:
			wushi = 1, ershi = 0, shi = 1, e = 2;
			break;
		case 7:
			wushi = 1, ershi = 1, shi = 0, e = 2;
			break;
		case 8:
			wushi = 1, ershi = 1, shi = 1, e = 3;
			break;
		case 9:
			wushi = 1, ershi = 2, shi = 0, e = 3;
			break;
		default:
			wushi = 0, ershi = 0, shi = 0, e = 0;
			break;
	}
	switch (b)
	{
		case 0:
			wu = 0, yi = 0, f = 0;
			break;
		case 1:
			wu = 0, yi = 1, f = 1;
			break;
		case 2:
			wu = 0, yi = 2, f = 2;
			break;
		case 3:
			wu = 0, yi = 3, f = 3;
			break;
		case 4:
			wu = 0, yi = 4, f = 4;
			break;
		case 5:
			wu = 0, yi = 1, f = 1;
			break;
		case 6:
			wu = 1, yi = 1, f = 2;
			break;
		case 7:
			wu = 1, yi = 2, f = 3;
			break;
		case 8:
			wu = 1, yi = 3, f = 4;
			break;
		case 9:
			wu = 1, yi = 4, f = 5;
			break;
		default:
			wu = 0, yi = 0, f = 0;
			break;
	}
	switch (c)
	{
		case 0:
			wujiao = 0, yijiao = 0, g = 0;
			break;
		case 1:
			wujiao = 0, yijiao = 1, g = 1;
			break;
		case 2:
			wujiao = 0, yijiao = 2, g = 2;
			break;
		case 3:
			wujiao = 0, yijiao = 3, g = 3;
			break;
		case 4:
			wujiao = 0, yijiao = 4, g = 4;
			break;
		case 5:
			wujiao = 1, yijiao = 0, g = 1;
			break;
		case 6:
			wujiao = 1, yijiao = 1, g = 2;
			break;
		case 7:
			wujiao = 1, yijiao = 2, g = 3;
			break;
		case 8:
			wujiao = 1, yijiao = 3, g = 4;
			break;
		case 9:
			wujiao = 1, yijiao = 4, g = 5;
			break;
		default:
			wujiao = 0, yijiao = 0, g = 0;
			break;
	}
	switch (d)
	{
		case 0:
			wufen = 0, erfen = 0, yifen = 0, h = 0;
			break;
		case 1:
			wufen = 0, erfen = 0, yifen = 1, h = 1;
			break;
		case 2:
			wufen = 0, erfen = 1, yifen = 0, h = 1;
			break;
		case 3:
			wufen = 0, erfen = 1, yifen = 1, h = 2;
			break;
		case 4:
			wufen = 0, erfen = 2, yifen = 0, h = 2;
			break;
		case 5:
			wufen = 1, erfen = 0, yifen = 0, h = 1;
			break;
		case 6:
			wufen = 1, erfen = 0, yifen = 1, h = 2;
			break;
		case 7:
			wufen = 1, erfen = 1, yifen = 0, h = 2;
			break;
		case 8:
			wufen = 1, erfen = 1, yifen = 1, h = 3;
			break;
		case 9:
			wufen = 1, erfen = 2, yifen = 0, h = 3;
			break;
		default:
			wufen = 0, erfen = 0, yifen = 0, h = 0;
			break;
	}
	cout << "��" << e + f + g + h << "�����㣬�������£�" << endl;
	if (wushi>0)
	{
		cout << "50Ԫ : " << wushi << "��" << endl;
	}
	if (ershi>0)
	{
		cout << "20Ԫ : " << ershi << "��" << endl;
	}
	if (shi>0)
	{
		cout << "10Ԫ : " << shi << "��" << endl;
	}
	if (wu > 0)
	{
		cout << "5Ԫ  : " << wu << "��" << endl;
	}
	if (yi > 0)
	{
		cout << "1Ԫ  : " << yi << "��" << endl;
	}
	if (wujiao > 0)
	{
		cout << "5��  : " << wujiao << "��" << endl;
	}
	if (yijiao > 0)
	{
		cout << "1��  : " << yijiao << "��" << endl;
	}
	if (wufen > 0)
	{
		cout << "5��  : " << wufen << "��" << endl;
	}
	if (yifen > 0)
	{
		cout << "1��  : " << yifen << "��" << endl;
	}
	return 0;
}