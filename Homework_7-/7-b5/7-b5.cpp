/* 2353726 ���ϳ� ��01 */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�
class stu_list;
/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����
	int sit;
	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	friend stu_list;
public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������

	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */
	void integrate();
	void select();
	void rank();
	void judge();
};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */
void stu_list::integrate()
{
	int end1 = 0;
	for (end1 = 0; end1 < MAX_FILENAME_LEN; end1++)
	{
		if (list_round_1[end1].no <= 0)
		{
			break;
		}
	}
	//ȷ����һ��ѡ��ѧ�������λ�ã������±���ʽ��
	int end2 = 0;
	for (end2 = 0; end2 < MAX_FILENAME_LEN; end2++)
	{
		if (list_round_2[end2].no <= 0)
		{
			break;
		}
	}
	//ȷ���ڶ���ѡ��ѧ�������λ�ã������±���ʽ��
	for (int i = 0; i < MAX_FILENAME_LEN; i++)
	{
		if (list_round_1[i].no <= 0)
		{		
			break;
		}
		list_merge[i].stu_no = list_round_1[i].no;
		strcpy(list_merge[i].stu_name, list_round_1[i].name);
	}
	//��1����������
	int end3 = end1;
	for (int i = 0; i < end2; i++)
	{
		for (int j = 0; j < end1; j++)
		{
			if (list_round_2[i].no == list_round_1[j].no)
			{
				break;
			}
			if (list_round_1[end1 - 1].no != list_round_2[i].no && j == end1 - 1)
			{
				list_merge[end3].stu_no = list_round_2[i].no;
				strcpy(list_merge[end3].stu_name, list_round_2[i].name);
				end3++;
			}
		}
	}
}

void stu_list::select()
{
	for (int i = 0; i < MAX_FILENAME_LEN; i++)
	{
		if (list_merge[i].stu_no <= 0)
			break;
		for (int j = i + 1; j < MAX_FILENAME_LEN; j++)
		{
			if (list_merge[j].stu_no == list_merge[i].stu_no)
			{
				for (int k = j; k < MAX_FILENAME_LEN - 1; k++)
				{
					if (list_merge[k + 1].stu_no <= 0)
					{
						list_merge[k].stu_no = list_merge[k + 1].stu_no;
						break;
					}
					list_merge[k].stu_no = list_merge[k + 1].stu_no;
					strcpy(list_merge[k].stu_name, list_merge[k + 1].stu_name);					
				}
			}
		}
	}
}

void stu_list::rank()
{
	int end1 = 0;
	for (end1 = 0; end1 < MAX_FILENAME_LEN; end1++)
	{
		if (list_merge[end1].stu_no <= 0)
		{
			break;
		}
	}
	for (int i = 0; i < end1 - 1; i++)
	{
		for (int j = 0; j < end1 - i - 1; j++)
		{
			if (list_merge[j].stu_no > list_merge[j + 1].stu_no)
			{
				int tmp = list_merge[j].stu_no;
				char str[MAX_NAME_LEN] = { 0 };
				strcpy(str, list_merge[j].stu_name);
				list_merge[j].stu_no = list_merge[j + 1].stu_no;
				strcpy(list_merge[j].stu_name, list_merge[j + 1].stu_name);
				list_merge[j + 1].stu_no = tmp;
				strcpy(list_merge[j + 1].stu_name, str);
			}
		}
	}
}

void stu_list::judge()
{
	for (int i = 0; i < MAX_FILENAME_LEN; i++)
	{
		if (list_merge[i].stu_no <= 0)
		{
			break;	
		}
		int r1 = 0;
		int r2 = 0;
		for (int j = 0; j < MAX_FILENAME_LEN; j++)
		{
			if (list_merge[i].stu_no == list_round_1[j].no)
			{
				r1 = 1;
				break;
			}
		}
		for (int j = 0; j < MAX_FILENAME_LEN; j++)
		{
			if (list_merge[i].stu_no == list_round_2[j].no)
			{
				r2 = 1;
				break;
			}
		}
		if (r1 == 1 && r2 == 1)
			list_merge[i].sit = 1;
		if (r1 == 0 && r2 == 1)
			list_merge[i].sit = 2;
		if (r1 == 1 && r2 == 0)
			list_merge[i].sit = 3;
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸�
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* prompt)
{
	int num = 1;
	cout << "����ѡ������" << endl;
	cout << "============================================================" << endl;
	cout << "��� ѧ��     ����                            ��һ�� �ڶ���" << endl;
	cout << "============================================================" << endl;
	for (int i = 0; i < MAX_FILENAME_LEN; i++)
	{
		if (list_merge[i].stu_no <= 0)
		{
			break;
		}
		cout << setw(5) << std::left << num << setw(9) << std::left << list_merge[i].stu_no << setw(32) << std::left << list_merge[i].stu_name;
		if (list_merge[i].sit == 1)
		{
			cout << "Y      Y" << endl;
		}
		if (list_merge[i].sit == 2)
		{
			cout << "/      ��ѡ" << endl;
		}
		if (list_merge[i].sit == 3)
		{
			cout << "Y      �˿�" << endl;
		}
		num++;
	}
	cout << "============================================================" << endl;
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */
	list.integrate();
	list.select();
	list.rank();
	list.judge();

	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}