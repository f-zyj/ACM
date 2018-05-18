//
//  main.cpp
//  f-51Nod-1607-卷积和
//
//  Created by ZYJ on 2016/9/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int a[25];
ll all[25];
ll sum[25];
ll cnt[25];
ll fact[25];

ll dfs(int len, int pos)
{
    if (len == 0)
    {
        ll tmp = 0;
        for (int i = pos; i > 0; i--)
        {
            tmp += a[i] * a[pos - i + 1];
        }
        return tmp % MOD;
    }
    
    ll tmp = 0;
    int cnt = (pos == len) ? 1 : 0;
    for (int i = cnt; i < a[len]; i++)
    {
        int num = len - 1;
        for (int j = pos; j > 0; j--)
        {
            int k = pos - j + 1;
            if (j > len)
            {
                if (k > len)
                {
                    tmp = (tmp + a[j] * a[k] * fact[num]) % MOD;
                }
                else if (k == len)
                {
                    tmp = (tmp + a[j] * i * fact[num]) % MOD;
                }
                else
                {
                    tmp = (tmp + a[j] * 45 * fact[num - 1]) % MOD;
                }
            }
            else if (j == len)
            {
                if (k > len)
                {
                    tmp = (tmp + i * a[k] * fact[num]) % MOD;
                }
                else if (k == len)
                {
                    tmp = (tmp + i * i * fact[num]) % MOD;
                }
                else
                {
                    tmp = (tmp + i * 45 * fact[num - 1]) % MOD;
                }
            }
            else
            {
                if (k > len)
                {
                    tmp = (tmp + a[k] * 45 * fact[num - 1]) % MOD;
                }
                else if (k == len)
                {
                    tmp = (tmp + i * 45 * fact[num - 1]) % MOD;
                }
                else
                {
                    if (k == j)
                    {
                        tmp = (tmp + 285 * fact[num - 1]) % MOD;
                    }
                    else
                    {
                        tmp = (tmp + 45 * 45 * fact[num - 2]) % MOD;
                    }
                }
            }
        }
    }
    return (tmp + dfs(len - 1, pos)) % MOD;
}

ll solve(ll x)
{
    if (x == 0)
    {
        return 0;
    }
    int len = 0;
    while (x)
    {
        a[++len] = x % 10;
        x /= 10;
    }
    return (dfs(len, len) + sum[len - 1]) % MOD;
}

void init()
{
    all[0] = 0;
    cnt[0] = 0;
    all[1] = 285;
    cnt[1] = 285;
    fact[0] = 1, fact[1] = 10;
    for (int i = 2; i < 20; i++)
    {
        all[i] = (cnt[i - 2] * 90 % MOD + 90 * 45 * fact[i - 2] % MOD) % MOD;
        cnt[i] = (cnt[i - 2] * 100 % MOD + 90 * 45 * fact[i - 2] % MOD) % MOD;
        fact[i] = fact[i - 1] * 10 % MOD;
    }
    sum[0] = 0;
    for (int i = 1; i < 20; i++)
    {
        sum[i] = (sum[i - 1] + all[i]) % MOD;
    }
}

ll ans[100005];

int main()
{
    init();
    
    ll L, R;
    cin >> L >> R;
    
    cout << ((solve(R) - solve(L - 1)) % MOD + MOD) % MOD << endl;
    return 0;
}
