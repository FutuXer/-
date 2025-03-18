//2353726 ��01 ���ϳ�
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int year, month, day, a, leap;
    while (1)
    {
        cout << "���������(2000-2030)���·�(1-12) : " ;
        cin >> year >> month;
        if ((year % 4 == 0) && (year % 100 != 0) || (year % 4 == 0) && (year % 400 == 0))
            leap = 1;
        else
            leap = 0;
        if (cin.good() == 0)
        {
            cout << "����Ƿ�������������" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (year < 2000 || year>2030 || month < 1 || month>12)
        {
            cout << "����Ƿ�������������" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        while (1)
        {
            cout << "������" << year << "��" << month << "��" << "1�յ�����(0-6��ʾ������-������) : ";
            cin >> day;
            if (cin.good() == 0)
            {
                cout << "����Ƿ�������������" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (day < 0 || day>6)
            {
                cout << "����Ƿ�������������" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            break;
        }
        cout << endl;
        cout << year << "��" << month << "�µ�����Ϊ:" << endl;
        cout << "������  " << "����һ  " << "���ڶ�  " << "������  " << "������  " << "������  " << "������" << endl;
        if (month==1|| month == 3 || month == 5||month == 7|| month == 8|| month == 10|| month == 12)
        {
            a = 31;
        }
        else if ( month == 4 || month == 6 || month == 9 || month == 11 )
        {
            a = 30;
        }
        else 
        {
            a = 28 + leap;
        }
        for (int i = 1; i <= a; i++)
        {
            if (i==1)
            {
                for (int j = 0; j < day; j++)
                {
                    cout << "        ";
                }
            }
            cout << setw(4) << std::right << i << "    ";
            if ((i+day)%7==0)
            {
                cout << endl;
            }
        }
        break;
    }
    return 0;
}
