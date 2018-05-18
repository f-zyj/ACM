//
//  main.cpp
//  f-HOJ-1983-Beautiful numbers
//
//  Created by ZYJ on 2017/5/30.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

const int MAXI = 20;
const int MAXJ = 2525;
const int MAXK = 55;
const int MAXN = 2520;

ll dp[MAXI][MAXJ][MAXK];
int digit[MAXI];
int hash_[MAXJ];

int gcd(int a, int b)
{
    if (!b)
    {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

ll dfs(int pos, int num, int mod, bool flag)
{
    if (pos == 0)
    {
        return num % mod == 0;
    }
    if (flag && dp[pos][num][hash_[mod]] != -1)
    {
        return dp[pos][num][hash_[mod]];
    }
    int tag = flag ? 9 : digit[pos];
    ll ans = 0;
    for (int i = 0; i <= tag; i++)
    {
        ans += dfs(pos - 1, (num * 10 + i) % MAXN, i ? lcm(mod, i) : mod, flag || i < tag);
    }
    if (flag)
    {
        dp[pos][num][hash_[mod]] = ans;
    }
    return ans;
}

ll calc(ll x)
{
    if (x < 0)
    {
        return 0;
    }
    int len = 0;
    while (x)
    {
        digit[++len] = x % 10;
        x /= 10;
    }
    return dfs(len, 0, 1, 0);
}

//  计算 MAXN 所有的约数
void init()
{
    memset(dp, -1, sizeof(dp));
    int cnt = 0;
    for (int i = 1; i * i <= MAXN; i++)
    {
        if (MAXN % i == 0)
        {
            hash_[i] = cnt++;
            if (i * i != MAXN)
            {
                hash_[MAXN / i] = cnt++;
            }
        }
    }
}

int main()
{
    init();
    
    ll x, y;
    while (~scanf("%lld%lld", &x, &y))
    {
        printf("%lld\n", calc(y) - calc(x - 1));
    }
    
    return 0;
}
