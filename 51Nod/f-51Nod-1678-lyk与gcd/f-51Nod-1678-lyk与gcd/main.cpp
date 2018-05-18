//
//  main.cpp
//  f-51Nod-1678-lyk与gcd
//
//  Created by ZYJ on 2017/7/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1e6 + 10;
const int MAXM = 100;

int n, Q;
int num[MAXN];
int val[MAXN];
int factors[MAXM];
int fac_cnt;
long long sum = 0;

void init()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; j += i)
        {
            val[i] += num[j];
        }
    }
}

void update(int pos, int b)
{
    sum -= num[pos];
    
    int m = sqrt(pos);
    for (int i = 1; i <= m; ++i)
    {
        if (pos % i == 0)
        {
            if (i * i == pos)
            {
                val[i] = val[i] - num[pos] + b;
            }
            else
            {
                val[i] = val[i] - num[pos] + b;
                val[pos / i] = val[pos / i] - num[pos] + b;
            }
        }
    }
    
    num[pos] = b;
    sum += num[pos];
}

void getFactors(int x)
{
    int m = sqrt(x);
    fac_cnt = 0;
    for (int i = 2; i <= m; ++i)
    {
        if (x % i == 0)
        {
            while (x % i == 0)
            {
                x /= i;
            }
            factors[fac_cnt++] = i;
        }
    }
    if (x != 1)
    {
        factors[fac_cnt++] = x;
    }
}

long long solve(int x)
{
    getFactors(x);
    
    int cnt, mul, flag, tmp = 1 << fac_cnt;
    long long res = 0;
    for (int i = 1; i < tmp; ++i)
    {
        flag = i;
        mul = 1;
        cnt = 0;
        for (int j = 0; j < fac_cnt; ++j)
        {
            if (flag & (1 << j))
            {
                mul *= factors[j];
                cnt++;
            }
        }
        if (cnt & 1)
        {
            res += val[mul];
        }
        else
        {
            res -= val[mul];
        }
    }
    
    return res;
}

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

template <class T>
inline void out(T x)
{
    if (x > 9)
    {
        out(x / 10);
    }
    putchar(x % 10 + '0');
}

int main()
{
    scan_d(n), scan_d(Q);
    for (int i = 1; i <= n; ++i)
    {
        scan_d(num[i]);
        sum += num[i];
    }
    
    init();
    
    int a, b, pos;
    while (Q--)
    {
        scan_d(a);
        if (a == 1)
        {
            scan_d(pos), scan_d(b);
            update(pos, b);
        }
        else
        {
            scan_d(pos);
            cout << sum - solve(pos) << endl;
        }
    }
    
    return 0;
}
