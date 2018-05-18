//
//  main.cpp
//  f-51Nod-1635-第K个幸运排列
//
//  Created by ZYJ on 2017/11/8.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 15;
const int MAX_FAC = 14;
const int MAX_POW = 33;
const int MAGIC_4 = 4;
const int MAGIC_7 = 7;

ll n, k;
int num[MAXN];
ll pow[MAX_POW];
ll fac[MAX_FAC];

//  数位 DP，求 1~x 有多少幸运数字
ll dp(ll x)
{
    if (x == 0)
    {
        return 0;
    }
    
    int pos = 0;
    while (x)
    {
        num[++pos] = x % 10;
        x /= 10;
    }
    
    ll res = 0;
    for (int i = pos; i >= 1; i--)
    {
        if (num[i] > MAGIC_7)
        {
            res += pow[i];
            break;
        }
        else if (num[i] == MAGIC_7)
        {
            res += pow[i - 1];
            if (i == 1)
            {
                res++;
            }
        }
        else if (num[i] > MAGIC_4)
        {
            res += pow[i - 1];
            break;
        }
        else if (num[i] == MAGIC_4)
        {
            if (i == 1)
            {
                res++;
            }
        }
        else if (num[i] < MAGIC_4)
        {
            break;
        }
    }
    
    for (int i = 1; i < pos; i++)
    {
        res += pow[i];
    }
    
    return res;
}

bool vis[MAXN];
ll s[MAXN];

void reverse_cantor(ll n, ll k, ll base)
{
    --k;
    for (int i = 0, j; i < n; i++)
    {
        ll t = k / fac[n - i - 1];
        for (j = 1; j <= n; j++)
        {
            if (!vis[j])
            {
                if (t == 0)
                {
                    break;
                }
                --t;
            }
        }
        
        s[i] = j + base;
        vis[j] = true;
        k %= fac[n - i - 1];
    }
}

bool check(ll n)
{
    if (n == 0)
    {
        return false;
    }
    while (n > 0)
    {
        if (n % 10 != MAGIC_4 && n % 10 != MAGIC_7)
        {
            return false;
        }
        n /= 10;
    }
    
    return true;
}

void init()
{
    fac[0] = pow[0] = 1;
    for (int i = 1; i < MAX_FAC; i++)
    {
        fac[i] = fac[i - 1] * i;
    }
    for (int i = 1; i < MAX_POW; i++)
    {
        pow[i] = pow[i - 1] * 2;
    }
}

int main()
{
    init();
    
    scanf("%lld%lld", &n, &k);
    if (n < MAX_FAC && fac[n] < k)
    {
        puts("-1");
        return 0;
    }
    
    int cnt = 1;
    while (fac[cnt] < k)
    {
        cnt++;
    }
    
    ll pos = n - cnt, sta = pos + 1;
    ll ans = dp(pos);
    reverse_cantor(cnt, k, pos);
    for (ll i = sta; i <= n; i++)
    {
        if (check(i) && check(s[i - sta]))
        {
            ans++;
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
