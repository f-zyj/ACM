//
//  main.cpp
//  f-51Nod-TalkingData数据科学精英夏令营挑战赛-A-初中的算术
//
//  Created by ZYJ on 2017/6/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 1000;

struct BigNum
{
    int num[MAXN];  //  数值存储
    int l;          //  整数位数
    int dot;        //  小数位数
    int len;        //  总的数位长度
};

int find_dot(char a, char str[])
{
    int len = (int)strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == a)
        {
            return i;
        }
    }
    return len;
}

void print(struct BigNum s)
{
    for (int i = s.l + s.dot - 1; i >= s.dot; i--)
    {
        printf("%d", s.num[i]);
    }
    if (s.dot > 0)
    {
        printf(".");
        for (int i = s.dot - 1; i >= 0; i--)
        {
            printf("%d",s.num[i]);
        }
    }
    printf("\n");
}

void trans(BigNum &a, char str[])
{
    memset(a.num, 0, sizeof(a.num));
    int len = (int)strlen(str);
    a.l = find_dot('.', str);
    a.dot = (len == a.l) ? 0 : (len - a.l - 1);
    
    int i = 0, k = 0, pa = a.l, l = len - 1;
    while (str[i++] == '0' && i <= pa)
    {
        a.l--;
    }
    while (str[l--] == '0' && l >= pa)
    {
        a.dot--;
    }
    for (i = pa+a.dot; i > pa; i--)
    {
        a.num[k++] = str[i] - '0';
    }
    for (i = pa - 1; i >= pa - a.l; i--)
    {
        a.num[k++] = str[i] - '0';
    }
    a.len = k;
}

BigNum  mul(BigNum a, BigNum b)
{
    BigNum m;
    memset(m.num, 0, sizeof(m.num));
    
    for (int i = 0; i < a.len; i++)
    {
        for (int j = 0; j < b.len; j++)
        {
            m.num[i + j] += a.num[i] * b.num[j];
        }
    }
    m.dot = a.dot + b.dot;
    m.len = a.len + b.len - 1;
    for (int i = 0; i < m.len; i++)
    {
        if (m.num[i] >= 10)
        {
            m.num[i + 1] += m.num[i] / 10;
            m.num[i] %= 10;
        }
    }
    if (m.num[m.len] > 0 && m.num[m.len] < 10)
    {
        m.len += 1;
    }
    else if (m.num[m.len] > 10)
    {
        m.num[m.len + 1] += m.num[m.len] / 10;
        m.num[m.len] %= 10;
        m.len += 2;
    }
    m.l = m.len - m.dot;
    return m;
}

int n;
char str[MAXN];
BigNum a, ans;

int main()
{
    scanf("%s%d", str, &n);
    
    trans(a, str);
    trans(ans, str);
    for (int i = 1; i < n; i++)
    {
        ans = mul(ans, a);
    }
    print(ans);

    return 0;
}
