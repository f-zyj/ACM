//
//  main.cpp
//  f-HDU-2017 多校训练赛2-1009-TrickGCD
//
//  Created by ZYJ on 2017/7/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const ll MOD = 1e9 + 7;

int mu[MAXN];

void mobius(int x)
{
    mu[1] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int j = i + i; j <= x; j += i)
        {
            mu[j] -= mu[i];
        }
    }
}

int n;
int cnt[MAXN << 1];

ll QPow(ll x, int y)
{
    ll ret = 1;
    while (y > 0)
    {
        if (y & 1)
        {
            ret = ret * x % MOD;
        }
        x = x * x % MOD;
        y >>= 1;
    }
    
    return ret;
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

int main()
{
    mobius(MAXN);
    
    int T, ce = 1, mn;

    scan_d(T);
    while (T--)
    {
        mn = MAXN;
        memset(cnt, 0, sizeof(cnt));
        
        scan_d(n);
        
        int x;
        while (n--)
        {
            scan_d(x);
            cnt[x]++;
            mn = min(mn, x);
        }
        
        ll ans = 0;
        int t = MAXN << 1;
        for (int i = 1; i <= t; i++)
        {
            cnt[i] += cnt[i - 1];
        }
        for (int i = 2; i <= mn; i++)
        {
            ll temp = 1;
            for (int j = 1; i * j <= MAXN; j++)
            {
                temp = (temp * QPow((ll)j, cnt[i * j + i - 1] - cnt[i * j - 1])) % MOD;
            }
            ans = (ans - temp * mu[i] + MOD) % MOD;
        }
        
        printf("Case #%d: %lld\n", ce++, ans);
    }
    
    return 0;
}
