//
//  main.cpp
//  f-51Nod-1188-最大公约数之和 V2
//
//  Created by ZYJ on 2017/8/6.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 5e6 + 50;

int N;
ll ans[MAXN];
int prime[MAXN];
int phi[MAXN];
bool flag[MAXN];

void get_phi()
{
    int cnt = 0;
    memset(flag, true, sizeof(flag));
    
    phi[1] = 1;
    for(int i = 2; i < MAXN; i++)
    {
        if (flag[i])
        {
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < cnt; j++)
        {
            if (1ll * i * prime[j] > MAXN)
            {
                break;
            }
            flag[i * prime[j]] = false;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = prime[j] * phi[i];
                break;
            }
            else
            {
                phi[i * prime[j]] = (prime[j] - 1) * phi[i];
            }
        }
    }
}

void init()
{
    get_phi();
    memset(ans, 0, sizeof(ans));
    
    for (int i = 1; i < MAXN; i++)
    {
        for (int j = 2; j < MAXN; j++)
        {
            if (1ll * i * j < MAXN)
            {
                ans[1ll * i * j] += phi[j] * i;
            }
            else
            {
                break;
            }
        }
    }
    
    for (int i = 1; i < MAXN; i++)
    {
        ans[i] += ans[i - 1];
    }
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
inline void print_d(T x)
{
    if (x > 9)
    {
        print_d(x / 10);
    }
    putchar(x % 10 + '0');
}

int main()
{
    init();
    
    int T;
    scan_d(T);
    while (T--)
    {
        scan_d(N);
        print_d(ans[N]);
        putchar(10);
    }
    
    return 0;
}
