//2353726 ��01 ���ϳ�
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "������һ��[1..30000]�������:" << endl;
    int a;
    cin >> a;
    int b = a / 10000;
    int c = a / 1000 - 10 * b;
    int d = a / 100 - 10 * c - 100 * b;
    int e = a / 10 - 1000 * b - 100 * c - 10 * d;
    int f = a - 10000 * b - 1000 * c - 100 * d - 10 * e;
    cout << "��λ : " << b << endl;
    cout << "ǧλ : " << c << endl;
    cout << "��λ : " << d << endl;
    cout << "ʮλ : " << e << endl;
    cout << "��λ : " << f << endl;

    return 0;
}