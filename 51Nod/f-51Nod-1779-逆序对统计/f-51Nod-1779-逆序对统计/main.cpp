//
//  main.cpp
//  f-51Nod-1779-逆序对统计
//
//  Created by ZYJ on 2017/7/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = (1 << 20) + 1;
const int MAXM = 111;

int n, m;
int a[MAXM];
int b[MAXN];
int dp[2][MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", a + i);
        a[i]--;
    }
    
    int tmp = 1 << n;
    for (int i = 0; i <= n; i++)
    {
        b[1 << i] = 1;
    }
    for (int i = 1; i < tmp; i++)
    {
        b[i] = b[i & -i] + b[i ^ (i & -i)];
    }
    
    int cur = 0, ns;
    memset(dp, -1, sizeof(dp));
    dp[cur][0] = 0;
    for (int i = 0; i < m; i++, cur ^= 1)
    {
        int *last = dp[cur], *now = dp[cur ^ 1];
        for (int s = 0; s < tmp; s++)
        {
            if (last[s] != -1)
            {
                now[s] = max(now[s], last[s]);
                if (~s & (1 << a[i + 1]))
                {
                    ns = s | (1 << a[i + 1]);
                    now[ns] = max(now[ns], last[s] + b[ns >> (a[i + 1] + 1)]);
                }
                last[s] = -1;
            }
        }
    }
    
    printf("%d\n", dp[cur][tmp - 1]);
    
    return 0;
}
