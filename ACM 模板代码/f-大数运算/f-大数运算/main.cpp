//
//  main.cpp
//  f-大数运算
//
//  Created by ZYJ on 16/7/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

//  高效大数运算

/*
 *  < , <= , + , - , * , / , %(修改/的最后一行可得)
 */
//const int base = 10000; //  (base^2) fit into int
//const int width = 4;    //  width = log base
//const int N = 1000;     //  n * width: 可表示的最大位数
//
//struct bint
//{
//    int ln, v[N];
//    bint (int r = 0)
//    {
//        //  r应该是字符串!
//        for (ln = 0; r > 0; r /= base)
//        {
//            v[ln++] = r % base;
//        }
//    }
//    bint &operator = (const bint &r)
//    {
//        memcpy(this, &r, (r.ln + 1) * sizeof(int));
//        return *this;
//    }
//};
//
//bool operator < (const bint &a, const bint &b)
//{
//    int i;
//    if (a.ln != b.ln)
//    {
//        return a.ln < b.ln;
//    }
//    for (i = a.ln - 1; i >= 0 && a.v[i] == b.v[i]; i--);
//    return i < 0 ? 0 : a.v[i] < b.v[i];
//}
//
//bool operator <= (const bint &a, const bint &b)
//{
//    return !(b < a);
//}
//
//bint operator + (const bint &a, const bint &b)
//{
//    bint res;
//    int i, cy = 0;
//    for (i = 0; i < a.ln || i < b.ln || cy > 0; i++)
//    {
//        if (i < a.ln)
//        {
//            cy += a.v[i];
//        }
//        if (i < b.ln)
//        {
//            cy += b.v[i];
//        }
//        res.v[i] = cy % base;
//        cy /= base;
//    }
//    res.ln = i;
//    return res;
//}
//
//bint operator - (const bint &a, const bint &b)
//{
//    bint res;
//    int i, cy = 0;
//    for (res.ln = a.ln, i = 0; i < res.ln; i++)
//    {
//        res.v[i] = a.v[i] - cy;
//        if (i < b.ln)
//        {
//            res.v[i] -= b.v[i];
//        }
//        if (res.v[i] < 0)
//        {
//            cy = 1, res.v[i] += base;
//        }
//        else
//        {
//            cy = 0;
//        }
//    }
//    while (res.ln > 0 && res.v[res.ln - 1] == 0)
//    {
//        res.ln--;
//    }
//    return res;
//}
//
//bint operator * (const bint &a, const bint &b)
//{
//    bint res;
//    res.ln = 0;
//    if (0 == b.ln)
//    {
//        res.v[0] = 0;
//        return res;
//    }
//    int i, j, cy;
//    for (i = 0; i < a.ln; i++)
//    {
//        for (j = cy = 0; j < b.ln || cy > 0; j++, cy /= base)
//        {
//            if (j < b.ln)
//            {
//                cy += a.v[i] * b.v[j];
//            }
//            if (i + j < res.ln)
//            {
//                cy += res.v[i + j];
//            }
//            if (i + j >= res.ln)
//            {
//                res.v[res.ln++] = cy % base;
//            }
//            else
//            {
//                res.v[i + j] = cy % base;
//            }
//        }
//    }
//    return res;
//}
//
//bint operator / (const bint &a, const bint &b)
//{   //  !b != 0
//    bint tmp, mod, res;
//    int i, lf, rg, mid;
//    mod.v[0] = mod.ln = 0;
//    for (i = a.ln - 1; i >= 0; i--)
//    {
//        mod = mod * base + a.v[i];
//        for (lf = 0, rg = base -1; lf < rg;)
//        {
//            mid = (lf + rg + 1) / 2;
//            if (b * mid <= mod)
//            {
//                lf = mid;
//            }
//            else
//            {
//                rg = mid - 1;
//            }
//        }
//        res.v[i] = lf;
//        mod = mod - b * lf;
//    }
//    res.ln = a.ln;
//    while (res.ln > 0 && res.v[res.ln - 1] == 0)
//    {
//        res.ln--;
//    }
//    return res;     //  return mod 就是%运算
//}
//
//int digits(bint& a) //  返回位数
//{
//    if (a.ln == 0)
//    {
//        return 0;
//    }
//    int l = (a.ln - 1) * 4;
//    for (int t = a.v[a.ln - 1]; t; ++l, t /= 10);
//    return l;
//}
//
//bool read(bint &b, char buf[])  //  读取失败返回0
//{
//    if (1 != scanf("%s", buf))
//    {
//        return 0;
//    }
//    int w, u, ln = (int)strlen(buf);
//    memset(&b, 0, sizeof(bint));
//    if ('0' == buf[0] && 0 == buf[1])
//    {
//        return 1;
//    }
//    for (w = 1, u = 0; ln;)
//    {
//        u += (buf[--ln] - '0') * w;
//        if (w * 10 == base)
//        {
//            //  ...
//        }
//        else
//        {
//            w *= 10;
//        }
//    }
//    if (w != 1)
//    {
//        b.v[b.ln++] = u;
//    }
//    return 1;
//}
//
//void write(const bint &v)
//{
//    int i;
//    printf("%d", v.ln == 0 ? 0 : v.v[v.ln - 1]);
//    for (i = v.ln - 2; i >= 0; i--)
//    {
//        printf("%04d", v.v[i]); //  !4 == width
//    }
//    printf("\n");
//    return ;
//}

//  普通大数运算

const int MAXSIZE = 200;

void Add(char *str1, char *str2, char *str3);
void Minus(char *str1, char *str2, char *str3);
void Mul(char *str1, char *str2, char *str3);
void Div(char *str1, char *str2, char *str3);

int main()
{
    char str1[MAXSIZE], str2[MAXSIZE], str3[MAXSIZE];
    while (scanf("%s %s", str1, str2) == 2)
    {
        if (strcmp(str1, "0"))
        {
            memset(str3, '0', sizeof(str3));
            Add(str1, str2, str3);
            printf("%s\n", str3);
            memset(str3, '0', sizeof(str3));
            Minus(str1, str2, str3);
            printf("%s\n", str3);
            memset(str3, '0', sizeof(str3));
            Mul(str1, str2, str3);
            printf("%s\n", str3);
            memset(str3, '0', sizeof(str3));
            Div(str1, str2, str3);
            printf("%s\n", str3);
        }
        else
        {
            if (strcmp(str2, "0"))
            {
                printf("%s\n-%s\n0\n0\n", str2, str2);
            }
            else
            {
                printf("0\n0\n0\n0\n");
            }
        }
    }
    return 0;
}

void Add(char *str1, char *str2, char *str3)
{   //  str3 = str1 + str2;
    int i, j, i1, i2, tmp, carry;
    int len1 = (int)strlen(str1), len2 = (int)strlen(str2);
    char ch;
    i1 = len1 - 1;
    i2 = len2 - 1;
    j = carry = 0;
    for (; i1 >= 0 && i2 >= 0; ++j, --i1, --i2)
    {
        tmp = str1[i1] - '0' + str2[i2] - '0' + carry;
        carry = tmp / 10;
        str3[j] = tmp % 10 + '0';
    }
    while (i1 >= 0)
    {
        tmp = str1[i1--] - '0' + carry;
        carry = tmp / 10;
        str3[j++] = tmp % 10 + '0';
    }
    while (i2 >= 0)
    {
        tmp = str2[i2--] - '0' + carry;
        carry = tmp / 10;
        str3[j++] = tmp % 10 + '0';
    }
    if (carry)
    {
        str3[j++] = carry + '0';
    }
    str3[j] = '\0';
    for (i = 0, --j; i < j; ++i, --j)
    {
        ch = str3[i];
        str3[i] = str3[j];
        str3[j] = ch;
    }
    return ;
}

void Minus(char *str1, char *str2, char *str3)
{   //  str3 = str1-str2 (str1 > str2)
    int i, j, i1, i2, tmp, carry;
    int len1 = (int)strlen(str1), len2 = (int)strlen(str2);
    char ch;
    i1 = len1 - 1;
    i2 = len2 - 1;
    j = carry = 0;
    while (i2 >= 0)
    {
        tmp = str1[i1] - str2[i2] - carry;
        if (tmp < 0)
        {
            str3[j] = tmp + 10 + '0';
            carry = 1;
        }
        else
        {
            str3[j] = tmp + '0';
            carry = 0;
        }
        i1--;
        i2--;
        j++;
    }
    while (i1 >= 0)
    {
        tmp = str1[i1] - '0' - carry;
        if (tmp < 0)
        {
            str3[j] = tmp + 10 + '0';
            carry = 1;
        }
        else
        {
            str3[j] = tmp + '0';
            carry = 0;
        }
        --i1;
        ++j;
    }
    --j;
    while (str3[j] == '0' && j > 0)
    {
        --j;
    }
    str3[++j] = '\0';
    for (i = 0, --j; i < j; ++i, --j)
    {
        ch = str3[i];
        str3[i] = str3[j];
        str3[j] = ch;
    }
    return ;
}

void Mul(char *str1, char *str2, char *str3)
{
    int i, j = 0, i1, i2, tmp, carry, jj;
    int len1 = (int)strlen(str1), len2 = (int)strlen(str2);
    char ch;
    jj = carry = 0;
    for (i1 = len1 - 1; i1 >= 0; --i1)
    {
        j = jj;
        for (i2 = len2 - 1; i2 >= 0; --i2, ++j)
        {
            tmp = (str3[j] - '0') + (str1[i1] - '0') * (str2[i2] - '0') + carry;
            if (tmp > 9)
            {
                carry = tmp / 10;
                str3[j] = tmp % 10 + '0';
            }
            else
            {
                str3[j] = tmp + '0';
                carry = 0;
            }
        }
        if (carry)
        {
            str3[j] = carry + '0';
            carry = 0;
            j++;
        }
        jj++;
    }
    j--;
    while (str3[j] == '0' && j > 0)
    {
        j--;
    }
    str3[++j] = '\0';
    for (i = 0, --j; i < j; ++i, --j)
    {
        ch = str3[i];
        str3[i] = str3[j];
        str3[j] = ch;
    }
    return ;
}
    
void Div(char *str1, char *str2, char *str3)
{
    int i1, i2, i, j, jj = 0, tag, carry, cf, c[MAXSIZE];
    int len1 = (int)strlen(str1), len2 = (int)strlen(str2), lend;
    char d[MAXSIZE];
    memset(c, 0, sizeof(c));
    memcpy(d, str1, len2);
    lend = len2;
    j = 0;
    for (i1 = len2 - 1; i1 < len1; ++i1)
    {
        if (lend < len2)
        {
            d[lend] = str1[i1+1];
            c[j] = 0;
            ++j;
            ++lend;
        }
        else if (lend == len2)
        {
            jj = 1;
            for (i = 0; i < lend; ++i)
            {
                if (d[i] > str2[i])
                {
                    break;
                }
                else if (d[i] < str2[i])
                {
                    jj = 0;
                    break;
                }
            }
            if (jj == 0)
            {
                d[lend] = str1[i1+1];
                c[j] = 0;
                ++j;
                ++lend;
                continue;
            }
        }
        if (jj == 1 || lend > len2)
        {
            cf = jj = 0;
            while (d[jj] <= '0' && jj < lend)
            {
                ++jj;
            }
            if (lend - jj > len2)
            {
                cf = 1;
            }
            else if (lend - jj < len2)
            {
                cf = 0;
            }
            else
            {
                i2 = 0;
                cf = 1;
                for (i = jj; i < lend; ++i)
                {
                    if (d[i] < str2[i2])
                    {
                        cf = 0;
                        break;
                    }
                    else if (d[i] > str2[i2])
                    {
                        break;
                    }
                    ++i2;
                }
            }
            while (cf)
            {
                i2 = len2 - 1;
                cf = 0;
                for (i = lend - 1; i >= lend - len2; --i)
                {
                    d[i] = d[i] - str2[i2] + '0';
                    if (d[i] < '0')
                    {
                        d[i] = d[i] + 10;
                        carry = 1;
                        --d[i - 1];
                    }
                    else
                    {
                        carry = 0;
                    }
                    --i2;
                }
                ++c[j];
                jj = 0;
                while (d[jj] <= '0' && jj < lend)
                {
                    ++jj;
                }
                if (lend - jj > len2)
                {
                    cf = 1;
                }
                else if (lend - jj < len2)
                {
                    cf = 0;
                }
                else
                {
                    i2 = 0;
                    cf = 1;
                    for (i = jj; i < lend; ++i)
                    {
                        if (d[i] < str2[i2])
                        {
                            cf = 0;
                            break;
                        }
                        else if (d[i] > str2[i2])
                        {
                            break;
                        }
                        ++i2;
                    }
                }
            }
            jj = 0;
            while (d[jj] <= '0' && jj < lend)
            {
                ++jj;
            }
            for (i = 0; i < lend - jj; ++i)
            {
                d[i] = d[i + jj];
            }
            d[i] = str1[i1 + 1];
            lend = i + 1;
            j++;
        }
    }
    i = tag = 0;
    while (c[i] == 0)
    {
        ++i;
    }
    for (; i < j; ++i, ++tag)
    {
        str3[tag] = c[i]+'0';
    }
    str3[tag] = '\0';
    return ;
}
