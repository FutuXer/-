//2353726 ��01 ���ϳ�
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	while (1)
	{
		cout << "������x��ֵ[-10~ +65]" << endl;
		double x;
		int result = 1;
		double n = 0, a = 0, b = 1;
		cin >> x;
		if (x < -10 || x>65)
		{
			cout << "����Ƿ�,����������" << endl;
			continue;
		}
		while (fabs(b) >= 1e-6)
		{
			a = a + b;
			n = n + 1;
			b = b * x / n;
		}
		std::cout << "e^" << x << "=" << std::setprecision(10) << a << std::endl;
		break;
	}
	return 0;
}