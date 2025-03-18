/* 2353726 ���ϳ� ��01 */

#include <cstdio>   //NULL
//������������κ�ϵͳͷ�ļ�

/* ----- ���������κ���ʽ��ȫ�ֱ���/ȫ������/ֻ��ȫ�ֱ���/�궨��!!!!! ----- */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��returnֻ��һ��ʾ�����ɸı� */
int tj_strlen(const char* str)
{
    int i = 0;
    if (str == NULL)
    {
        return 0;
    }
    else
    {
        while (*str != '\0')
        {
            str++;
            i++;
        }
        return i;
    }
}

char *tj_strcat(char *s1, const char *s2)
{
    if (s2 == NULL || s1 == NULL)
    {
        return s1;
    }
    char* original_s1 = s1;
    while (*s1 != '\0')
    {
        s1++;
    }
    while (*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return original_s1;
}

char *tj_strncat(char *s1, const char *s2, const int len)
{
    char* p = s1;
    int lens2 = tj_strlen(s2);
    int l = 0;
    int copy_len = (lens2 < len) ? lens2 : len;
    if (s1 == NULL || s2 == NULL)
    {
        return s1;
    }
    char* original_s1 = s1;
    while (*p != '\0')
    {
        p++;
    }
    while (*s2 != '\0' && l < copy_len) 
    {
        *p = *s2;
        p++;
        s2++;
        l++;
    }
    *p = '\0'; // ����ַ���������

    return original_s1;
}

char *tj_strcpy(char *s1, const char *s2)
{
    if (s1 == NULL)
    {
        return s1;
    }
    if (s2 == NULL)
    {
        *s1 = '\0';
        return s1;
    }
    char* original_s1 = s1;
    // ��s2�����ݸ��Ƶ�s1
    while (*s2 != '\0') 
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0'; // ����ַ���������
    return original_s1;
}

char *tj_strncpy(char *s1, const char *s2, const int len)
{
    char* p = s1;
    int lens2 = tj_strlen(s2);
    int l = 0;
    int copy_len = (lens2 < len) ? lens2 : len;

    if (s1 == NULL || s2 == NULL) 
    {
        return s1;
    }
    char* original_s1 = s1;
    while (copy_len >= 1)
    {
        *s1++ = *s2++;
        copy_len--;
    }

    return original_s1;
}

int tj_strcmp(const char *s1, const char *s2)
{
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;
    while (1)
    {
        if (*s1 == '\0' && *s2 == '\0')
        {
            break;
        }
        if (*s1 != *s2)
        {
            return (int)*s1 - (int)*s2;
        }
        s1++;
        s2++;
    }

    return 0;
}

int tj_strcasecmp(const char *s1, const char *s2)
{
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;
    while (1)
    {
        if (*s1 == '\0' && *s2 == '\0')
        {
            break;
        }
        if (*s1 != *s2)
        {
            char x = *s1, y = *s2;
            if (*s1 >= 'A' && *s1 <= 'Z')
                x = *s1 + 32;
            if (*s2 >= 'A' && *s2 <= 'Z')
                y = *s2 + 32;
            if (x != y)
            {
                return int(x - y);
            }
        }
        s1++;
        s2++;
    }

    return 0;
}

int tj_strncmp(const char *s1, const char *s2, const int len)
{
    int lens1 = tj_strlen(s1);
    int lens2 = tj_strlen(s2);
    int a = 1;
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
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;
    while (a <= l)
    {
        if (*s1 == '\0' && *s2 == '\0')
        {
            break;
        }
        if (*s1 != *s2)
        {
            return (int)*s1 - (int)*s2;
        }
        s1++;
        s2++;
        a++;
    }
    return 0;
}

int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    int lens1 = tj_strlen(s1);
    int lens2 = tj_strlen(s2);
    int a = 1;
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
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;

    while (a <= l)
    {
        if (*s1 == '\0' && *s2 == '\0')
        {
            break;
        }
        if (*s1 != *s2)
        {
            char x = *s1, y = *s2;
            if (*s1 >= 'A' && *s1 <= 'Z')
                x = *s1 + 32;
            if (*s2 >= 'A' && *s2 <= 'Z')
                y = *s2 + 32;
            if (x != y)
            {
                return int(x - y);
            }
        }
        s1++;
        s2++;
        a++;
    }
    return 0;
}

char *tj_strupr(char *str)
{
    char* p = str;
    if (str == NULL) 
    {
        return str;
    }
    while (*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
        {
            *str = *str - 32;
        }
        str++;
    }

    return p;
}

char *tj_strlwr(char *str)
{
    char* p = str;
    if (str == NULL)
    {
        return str;
    }
    while (*str != '\0')
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            *str = *str + 32;
        }
        str++;
    }

    return p;
}

int tj_strchr(const char *str, const char ch)
{
    if (str == NULL)
    {
        return 0;
    }
    int loc = 1;
    while (*str != '\0')
    {
        if (*str == ch)
        {
            return loc;
        }
        str++;
        loc++;
    }

    return 0;
}

int tj_strstr(const char *str, const char *substr)
{
    if (str == NULL || substr == NULL)
        return 0;
    int lensub = tj_strlen(substr);
    int loc = 1;
    while (*str != '\0')
    {
        const char* p_str = str;
        const char* p_substr = substr;
        // ����Ƿ�ƥ�����ַ���
        while (*p_substr != '\0' && *p_str == *p_substr)
        {
            p_str++;
            p_substr++;
        }
        // ������ַ���������ĩβ��˵��ƥ��ɹ�
        if (*p_substr == '\0')
        {
            // ����ƥ�����ʼλ��
            return loc;
        }
        str++;
        loc++;
    }

    return 0;
}

int tj_strrchr(const char *str, const char ch)
{
    if (str == NULL)
    {
        return 0;
    }
    int len = tj_strlen(str);
    while (*str != '\0')
    {
        str++;
    }
    str--;
    while (len >= 0)
    {
        if (*str == ch)
        {
            return len;
        }
        len--;
        str--;
    }
    return 0;
}

int tj_strrstr(const char *str, const char *substr)
{
    if (str == NULL || substr == NULL)
        return 0;
    int len = tj_strlen(str);
    int lensub = tj_strlen(substr);
    while (*str != '\0')
    {
        str++;
    }
    str--;
    while (*substr != '\0')
    {
        substr++;
    }
    substr--;
    while (len > 0)
    {
        if (*str == *substr)
        {
            int i = 0;
            while (*str == *substr)
            {
                i++;
                str--;
                substr--;
                lensub--;
                len--;
            }

            if (lensub == 0)
            {
                return len + 1;
            }
            else
            {
                str = str + i - 1;
                substr = substr + i;
                len = len + i - 1;
                lensub = lensub + i;
            }
        }
        else
        {
            str--;
            len--;
        }
    }

    return 0;
}

char *tj_strrev(char *str)
{
    if (str == NULL)
        return str;

    char* p = str;
    char* p_str = str;

    while (*p_str != '\0') // �ҵ��ַ�����ĩβ
    {
        p_str++;
    }
    p_str--; // ��ָ���Ƶ��ַ���ĩβ��ǰһ��λ��

    while (p < p_str) // �����ַ���ֱ������ָ������
    {
        char temp = *p;
        *p = *p_str;
        *p_str = temp;

        p++;
        p_str--;
    }

    return str;
}
