//2353726 ��01 ���ϳ�
#include <iostream>
#include <ctime>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	int code = 0, daxie = 0, xiaoxie = 0, shuzi = 0, qita = 0;
    int dn = 0, xn = 0, sn = 0, qn = 0;
    int sum = dn + xn + sn + qn;
	cin >> code >> daxie >> xiaoxie >> shuzi >> qita;
    if (cin.good() == 0)
    {
        cin.clear();
        cin.ignore(1024, '\n');
        return 0;
    }
    if (code < 12 || code>16)
    {
        cout << "���볤��[" << code << "]����ȷ";
        return 0;
    }
    if (daxie < 2 || daxie>code)
    {
        cout << "��д��ĸ����[" << daxie << "]����ȷ";
        return 0;
    }
    if (xiaoxie < 2 || xiaoxie>code)
    {
        cout << "Сд��ĸ����[" << xiaoxie << "]����ȷ";
        return 0;
    }
    if (shuzi < 2 || shuzi>code)
    {
        cout << "���ָ���[" << shuzi << "]����ȷ";
        return 0;
    }
    if (qita < 2 || qita>code)
    {
        cout << "�������Ÿ���[" << qita << "]����ȷ";
        return 0;
    }
    if (daxie + xiaoxie + shuzi + qita > code)
    {
        cout << "�����ַ�����֮��[" << daxie << "+" << xiaoxie << "+" << shuzi << "+" << qita << "]���������볤��[" << code << "]" << endl;
    }
    cout << code << " " << daxie << " " << xiaoxie << " " << shuzi << " " << qita << endl;

    char password[17] = { 0 };
    int i = 0;
    char ch = 0;
    for (int l = 0; l < 10;)
    {
        i = 0;
        ch = 0;
        dn = 0;
        xn = 0;
        sn = 0;
        qn = 0;
        while (i < code)
        {          
            int k1 = rand() % (4);
            if (k1 == 0)
            {
                ch = rand() % (26) + 'A';
                password[i] = ch;
                dn++;
            }
            if (k1 == 1)
            {
                ch = rand() % (26) + 'a';
                password[i] = ch;
                xn++;
            }
            if (k1 == 2)
            {
                ch = rand() % (10) + '0';
                password[i] = ch;
                sn++;
            }
            if (k1 == 3)
            {
                ch = other[rand() % (15)];
                password[i] = ch;
                qn++;
            }
            i++;               
        }
        if (dn < daxie || xn < xiaoxie || sn < shuzi || qn < qita)
        {
            continue;
        }
        for (int j = 0; j < code; j++)
        {
            cout << password[j];
        }
        cout << endl;
        l++;
    }

    return 0;
}