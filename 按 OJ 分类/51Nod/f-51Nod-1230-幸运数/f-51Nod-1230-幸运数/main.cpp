//
//  main.cpp
//  f-51Nod-1230-幸运数
//
//  Created by ZYJ on 2017/6/14.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXD = 20;
const int MAXN = 1500;
const int MAXM = 163;

/*
 *  素数筛选，判断小于MAXN的数是不是素数
 *  notprime是一张表，false表示是素数，true表示不是
 */
int dig[MAXN];
bool notprime[MAXN];
ll dp[MAXD][MAXM][MAXN], L, R;  //  dp[i][j][k] i 位 j 和 k 平方和

void init()
{
    memset(notprime, false, sizeof(notprime));
    memset(dp, -1, sizeof(dp));
    
    notprime[0] = notprime[1] = true;
    for (int i = 2; i < MAXN; i++)
    {
        if (!notprime[i])
        {
            if (i > MAXN / i)   //  阻止后边i * i溢出（或者i,j用long long)
            {
                continue;
            }
            //  直接从i * i开始就可以，小于i倍的已经筛选过了
            for (int j = i * i; j < MAXN; j += i)
            {
                notprime[j] = true;
            }
        }
    }
}

ll dfs(int pos, int sum, int sqrt_sum, int flag)
{
    if (pos < 0)
    {
        return (!notprime[sum]) && (!notprime[sqrt_sum]);
    }
    if (!flag && dp[pos][sum][sqrt_sum] != -1)
    {
        return dp[pos][sum][sqrt_sum];
    }
    
    ll res = 0;
    int lim = flag ? dig[pos] : 9;
    for (int i = 0; i <= lim; i++)
    {
        res += dfs(pos - 1, sum + i, sqrt_sum + i * i, flag && (i == lim));
    }
    if (!flag)
    {
        dp[pos][sum][sqrt_sum] = res;
    }
    return res;
}

ll solve(ll n)
{
    int len = 0;
    while (n)
    {
        dig[len++] = n % 10;
        n /= 10;
    }
    return dfs(len - 1, 0, 0, 1);
}

int main(void)
{
    init();
    
    int T;
    cin >> T;
    while (T--)
    {
        scanf("%lld%lld", &L, &R);
        printf("%lld\n", solve(R) - solve(L - 1));
    }
    
    return 0;
}
