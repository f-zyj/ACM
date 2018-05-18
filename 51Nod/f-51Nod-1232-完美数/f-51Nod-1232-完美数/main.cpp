//
//  main.cpp
//  f-51Nod-1232-完美数
//
//  Created by ZYJ on 2017/9/20.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const ll MOD = 2520;
const int MAXN = 22;
const int MAXM = 55;

ll x, y;
int dig[MAXN];
int _hash[MOD + 10];

ll dp[MAXN][MAXM][MOD + 10];

ll gcd(ll x, ll y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        return gcd(y, x % y);
    }
}

void init()
{
    memset(dp, -1, sizeof(dp));
    
    int cnt = 0;
    for (int i = 1; i <= MOD; i++)
    {
        if (MOD % i == 0)
        {
            cnt++;
            _hash[i] = cnt;
        }
    }
}

ll dfs(ll n, ll tag = 1, ll lcm = 1, ll num = 0)
{
    if (n <= 0)
    {
        return num % lcm == 0;
    }
    
    if (!tag && dp[n][_hash[lcm]][num] != -1)
    {
        return dp[n][_hash[lcm]][num];
    }
    
    ll ans = 0;
    int end = (tag == 1) ? dig[n] : 9;
    for (int i = 0; i <= end; i++)
    {
        ll lcm_tmp;
        int m = (num * 10 + i) % MOD;
        if (i != 0)
        {
            lcm_tmp = lcm / gcd(lcm, i) * i;
        }
        else
        {
            lcm_tmp = lcm;
        }
        
        ans += dfs(n - 1, tag & (i == end), lcm_tmp, m);
    }
    
    if (!tag)
    {
        dp[n][_hash[lcm]][num] = ans;
    }
    
    return ans;
}

ll solve(ll x)
{
    int cnt = 0;
    memset(dig, 0, sizeof(dig));
    
    while (x)
    {
        cnt++;
        dig[cnt] = x % 10;
        x /= 10;
    }
    
    ll r = dfs(cnt);
    
    return r;
}

int main()
{
    init();
    
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%lld%lld", &x, &y);
        printf("%lld\n", solve(y) - solve(x - 1));
    }
    
    return 0;
}
