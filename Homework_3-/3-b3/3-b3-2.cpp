//2353726 ��01 ���ϳ�
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "������һ��[1-100��)֮�������:" << endl;
	double a;
    cin >> a;
    double x = a + 1e-6;
	int b = (int)(x / 10);
	double c = x/10 - b;
    int d = b / 1000000000;
    int e = b / 100000000 - 10 * d;
    int f = b / 10000000 - 10 * e - 100 * d;
    int g = b / 1000000 - 1000 * d - 100 * e - 10 * f;
    int h = b / 100000 - 10000 * d - 1000 * e - 100 * f - 10 * g;
    int i = b / 10000 - 100000 * d - 10000 * e - 1000 * f - 100 * g -10 * h;
    int j = b / 1000 - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h-10*i;
    int k = b / 100 - 10000000 * d - 1000000 * e - 100000 * f - 10000 * g - 1000 * h - 100 * i-10*j;
    int l = b / 10 - 100000000 * d - 10000000 * e - 1000000 * f - 100000 * g - 10000 * h - 1000 * i - 100 * j - 10 * k;
    int m = b / 1 - 1000000000 * d - 100000000 * e - 10000000 * f - 1000000 * g - 100000 * h - 10000 * i - 1000 * j - 100 * k - 10 * l;
    int n = int(10*c);
    int o = int(100 * c) - 10 * n;
    int p = int(1000 * c) - 100 * n - 10 * o;




    cout << "ʮ��λ : " << e << endl;
    cout << "��λ   : " << f << endl;
    cout << "ǧ��λ : " << g << endl;
    cout << "����λ : " << h << endl;
    cout << "ʮ��λ : " << i << endl;
    cout << "��λ   : " << j << endl;
    cout << "ǧλ   : " << k << endl;
    cout << "��λ   : " << l << endl;
    cout << "ʮλ   : " << m << endl;
    cout << "Բ     : " << n << endl;
    cout << "��     : " << o << endl;
    cout << "��     : " << p << endl;


    return 0;
}