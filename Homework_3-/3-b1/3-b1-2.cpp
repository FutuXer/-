//2353726 ��01 ���ϳ�
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double pi = 3.14159;
    double a;
    double b;
    cout << "������뾶�͸߶�" << endl;
    cin >> a >> b ;
    cout << std::fixed << std::setprecision(2) << "Բ�ܳ�        : " << 2 * a * pi << endl;
    cout << std::fixed << std::setprecision(2) << "Բ���        : " << pi * a * a << endl;
    cout << std::fixed << std::setprecision(2) << "Բ������    : " << 4 * pi * a * a << endl;
    cout << std::fixed << std::setprecision(2) << "Բ�����      : " << (static_cast<double>(4) / 3) * pi * a * a * a << endl;
    cout << std::fixed << std::setprecision(2) << "Բ�����      : " << pi * a * a * b << endl;


    return 0;
}
















