//2353726 ��01 ���ϳ�
#include <iostream>
using namespace std;

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��return 0ֻ��һ��ʾ�����ɸı� */

/* ���������κ���ʽ���ⲿȫ�֡���̬ȫ�֡��궨�塢ֻ������ */

int tj_strlen(const char str[])
{
    int i = 1;
    if (str[0] == '\0')
        return 0;
    else
    {
        while (str[i] != '\0')
        {
            i++;
        }
        return i;
    }
}

int tj_strcat(char s1[], const char s2[])
{
    int a = tj_strlen(s1);
    int b = tj_strlen(s2);
    int i = 0;
    for (i = 0; i < b; i++)
    {
        s1[a + i] = s2[i];
    }
    s1[a + i] = '\0';
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strncat(char s1[], const char s2[], const int len)
{
    int lens1 = tj_strlen(s1);
    int lens2 = tj_strlen(s2);
    if (len < lens2)
    {
        int i = 0;
        for (i = 0; i < len; i++)
        {
            s1[lens1 + i] = s2[i];
        }
        s1[lens1 + i] = '\0';
    }
    if (len >= lens2)
    {
        int i = 0;
        for (i = 0; i < lens2; i++)
        {
            s1[lens1 + i] = s2[i];
        }
        s1[lens1 + i] = '\0';
    }
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strcpy(char s1[], const char s2[])
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int lens2 = tj_strlen(s2);
    int i = 0;
    for (i = 0; i < lens2; i++)
    {
        s1[i] = s2[i];
    }
    s1[i] = '\0';
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strncpy(char s1[], const char s2[], const int len)
{
    int lens1 = tj_strlen(s1);
    int lens2 = tj_strlen(s2);
    if (len < lens2)
    {
        int i = 0;
        for (i = 0; i < len; i++)
        {
            s1[i] = s2[i];
        }
    }
    if (len >= lens2)
    {
        int i = 0;
        for (i = 0; i < lens2; i++)
        {
            s1[i] = s2[i];
        }
    }
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}


int tj_strcmp(const char s1[], const char s2[])
{
    int lens1 = tj_strlen(s1);
    int lens2 = tj_strlen(s2);
    int a = 0;
    if (lens1 >= lens2) 
    {
        lens1 = lens2;
    }
    for (int i = 0; i <= lens1; i++)
    {
        if (s1[i] == s2[i])
        {   
        }
        else
        {
            a = int(s1[i] - s2[i]);
            break;
        }
    }
    return a; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasecmp(const char s1[], const char s2[])
{
    int lens1 = tj_strlen(s1);
    int lens2 = tj_strlen(s2);
    int a = 0;
    if (lens1 >= lens2)
        lens1 = lens2;
    for (int i = 0; i <= lens2; i++)
    {
        if (s1[i]!=s2[i])
        {
            char x = s1[i], y = s2[i];
            if (s1[i] >= 'A' && s1[i] <= 'Z')
                x = s1[i] + 32;
            if (s2[i] >= 'A' && s2[i] <= 'Z')
                y = s2[i] + 32;
            if (x != y)
            {
                return int(x - y);
            }
        }
    }
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    int lens1 = tj_strlen(s1);
    int lens2 = tj_strlen(s2);
    int a = 0;
    int l = len;
    if (lens1 >= lens2)
    {
        lens1 = lens2;
        if (l > lens2)
        {
            l = lens2 + 1;
        }
    }
    if (len > lens1)
    {
        l = lens1 + 1;
    } 
    for (int i = 0; i < l; i++)
    {
        if (s1[i] == s2[i])
        {
        }
        else
        {
            a = int(s1[i] - s2[i]);
            break;
        }
    }
    return a; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    int lens1 = tj_strlen(s1);
    int lens2 = tj_strlen(s2);
    int a = 0;
    int l = len;
    if (lens1 >= lens2)
    {
        lens1 = lens2;
        if (l > lens2)
        {
            l = lens2 + 1;
        }
    }
    if (len > lens1)
    {
        l = lens1 + 1;
    }
    for (int i = 0; i < l; i++)
    {
        if (s1[i] != s2[i])
        {
            char x = s1[i], y = s2[i];
            if (s1[i] >= 'A' && s1[i] <= 'Z')
                x = s1[i] + 32;
            if (s2[i] >= 'A' && s2[i] <= 'Z')
                y = s2[i] + 32;
            if (x != y)
            {
                return int(x - y);
            }
        }
    }
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strupr(char str[])
{
    int len = tj_strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }

    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strlwr(char str[])
{
    int len = tj_strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }

    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strchr(const char str[], char ch)
{
    int len = tj_strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ch)
        {
            return i + 1;
        }
    }

    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strstr(const char str[], const char substr[])
{
    int len1 = tj_strlen(str);
    int len2 = tj_strlen(substr);
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (str[i + j] != substr[j])
            {
                break;
            }
            if (str[i + len2 - 1] == substr[len2 - 1])
            {
                return i + 1;
            }
        }
    }
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strrchr(const char str[], const char ch)
{
    int len = tj_strlen(str);
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == ch)
        {
            return i + 1;
        }
    }

    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strrstr(const char str[], const char substr[])
{
    int len1 = tj_strlen(str);
    int len2 = tj_strlen(substr);
    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = 0; j < len2; j++)
        {
            if (str[i + j] != substr[j])
            {
                break;
            }
            if (str[i + len2 - 1] == substr[len2 - 1])
            {
                return i + 1;
            }
        }
    }
    return 0; //returnֵ�ɸ�����Ҫ�޸�

    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strrev(char str[])
{
    int len = tj_strlen(str);
    int j = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        str[j] = str[i];
        j++;
    }

    return 0; //returnֵ�ɸ�����Ҫ�޸�
}