//
//  main.cpp
//  f-2017"百度之星"程序设计大赛-资格赛-1003-度度熊与邪恶大魔王
//
//  Created by ZYJ on 2017/8/5.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

#define clr(a, b) memset(a, b, sizeof(a))

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MAXM = 1e3 + 5;
const int MAXB = 11;

int n, m;
ll a[MAXN], b[MAXN];
ll k[MAXM], p[MAXM];
ll dp[MAXM][MAXB];

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        ll ma_a = 0, mx_b = 0, mx_p = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld%lld", a + i, b + i);
            ma_a = max(ma_a, a[i]);
            mx_b = max(mx_b, b[i]);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%lld%lld", k + i, p + i);
            mx_p = max(mx_p, p[i]);
        }
        
        if (mx_b >= mx_p)
        {
            printf("-1\n");
            continue;
        }
        
        clr(dp, 0x3f);
        for (int i = 0; i < MAXB; i++)      //  防御
        {
            for (int j = 1; j <= ma_a; j++) //  伤害
            {
                for (int x = 0; x < m; x++) //  技能
                {
                    if (p[x] <= i)
                    {
                        continue;
                    }
                    
                    ll tmp = p[x] - i;
                    if (tmp >= j)
                    {
                        dp[j][i] = min(dp[j][i], k[x]);
                    }
                    else
                    {
                        dp[j][i] = min(dp[j][i], dp[j - tmp][i] + k[x]);
                    }
                }
            }
        }
        
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += dp[a[i]][b[i]];
        }
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
