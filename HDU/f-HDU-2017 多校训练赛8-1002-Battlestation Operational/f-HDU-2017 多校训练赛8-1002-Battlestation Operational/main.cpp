//
//  main.cpp
//  f-HDU-2017 多校训练赛8-1002-Battlestation Operational
//
//  Created by ZYJ on 2017/8/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

int n;
bool check[MAXN];
int prime[MAXN];
ll d[MAXN];
ll miu[MAXN];
ll sum[MAXN];
ll cnt[MAXN];

void Mobius()
{
    memset(check, false, sizeof(check));
   
    d[1] = miu[1] = 1LL;
    int tot = 0;
    for (int i = 2; i < MAXN; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            d[i] = 2;
            cnt[i] = 1;
            miu[i] = -1;
        }
        for (int j = 0; j < tot; j++)
        {
            if ((ll)i * prime[j] > MAXN)
            {
                break;
            }
            
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                d[i * prime[j]] = d[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[i * prime[j]] = cnt[i] + 1;
                miu[i * prime[j]] = 0;
                break;
            }
            else
            {
                d[i * prime[j]] = d[i] << 1;
                cnt[i * prime[j]] = 1;
                miu[i * prime[j]] = -miu[i];
            }
        }
    }
    
    sum[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        sum[i] = (sum[i - 1] + d[i - 1] + 1) % MOD;
    }
    for (int i = 1; i < MAXN; i++)
    {
        sum[i] = (sum[i] + sum[i - 1]) % MOD;
        miu[i] = (miu[i] + miu[i - 1]) % MOD;
    }
}

int main()
{
    Mobius();

    ll ans;
    while (~scanf("%d", &n))
    {
        ans = 0;
        for (int i = 1, last; i <= n; i = last + 1)
        {
            last = n / (n / i);
            ans = (ans + (miu[last] - miu[i - 1]) % MOD * sum[n / i] % MOD) % MOD;
        }
        
        ans = (ans + MOD) % MOD;
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
