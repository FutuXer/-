//2353726 ��01 ���ϳ�
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    const double pi = 3.14159;
    int a, b, c; 
    cout << "�����������ε����߼���нǣ��Ƕȣ�" << endl;
    cin >> a >> b >> c;
    float x;
    x = c * pi / 180;
    cout << "�����ε����Ϊ : " << std::fixed << std::setprecision(3) << float(0.5 * a * b * sin(x)) << endl;
    cout << sin(c) << endl;



    return 0;
}