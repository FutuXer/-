/* 2353726 ��01 ���ϳ� */
#include <iostream>
using namespace std;

int countnum(int num, int n, int num_sum)
{
	if (n <= 0)
	{
		return num_sum;
	}
	else
	{
		int lastdig = n % 10;
		if (lastdig == num)
			num_sum = num_sum + 1;		
		return countnum(num, n / 10, num_sum);
	}
}



int main()
{
	int digit[10000] = { 0 };
	cout << "���������ݵĸ���[1..10000]" << endl;
	int n;
	cin >> n;
	cout << "������" << n << "��������" << endl;
	for (int i = 0; i < n; i++)
	{
		int dig;
		cin >> dig;
		digit[i] = dig;
	}
	cout << "����������[0..9]" << endl;
	int num;
	cin >> num;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += countnum(num, digit[i], 0);
	}
	cout << n << "�����к���" << num << "�ĸ��� : " << sum << endl;	

	return 0;
}