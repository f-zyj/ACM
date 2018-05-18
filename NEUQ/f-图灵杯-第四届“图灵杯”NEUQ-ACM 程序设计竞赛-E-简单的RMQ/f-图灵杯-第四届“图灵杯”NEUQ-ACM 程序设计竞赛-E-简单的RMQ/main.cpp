//
//  main.cpp
//  f-图灵杯-第四届“图灵杯”NEUQ-ACM 程序设计竞赛-E-简单的RMQ
//
//  Created by ZYJ on 2017/6/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int dp[MAXN][30];
int val[MAXN], tim[MAXN], pos[MAXN];
int lef[MAXN], rig[MAXN];

void solve(int n)
{
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = tim[pos[i]];
    }
    for (int j = 1; (1 << j) - 1 < n; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int main()
{
    int n, q;
    while (cin >> n, n)
    {
        memset(tim, 0, sizeof(tim));
        
        cin >> q;
        
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", val + i);
            if (i > 0 && val[i] != val[i - 1])
            {
                cnt++;
            }
            pos[i] = cnt;
            tim[cnt]++;
        }
        
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && val[i] != val[i - 1])
            {
                cnt = i;
            }
            lef[i] = cnt;
        }
        cnt = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (val[i] != val[i + 1] && 1 != n - 1)
            {
                cnt = i;
            }
            rig[i] = cnt;
        }
        
        solve(n);
        
        int l, r;
        for (int i = 1; i <= q; i++)
        {
            scanf("%d%d", &l, &r);
            if (pos[l - 1] == pos[r - 1])
            {
                printf("%d\n", r - l + 1);
            }
            else
            {
                int s = rig[l - 1] - l + 2;
                int t = r - lef[r - 1];
                int ans;
                l = l + s - 1;
                r = r - t - 1;
                
                if (l > r)
                {
                    ans = max(s, t);
                }
                else
                {
                    int k = 0;
                    while (1 << (k + 1) <= r - l + 1)
                    {
                        k++;
                    }
                    ans = max(max(dp[l][k], dp[r - (1 << k) + 1][k]), max(s, t));
                }
                
                printf("%d\n", ans);
            }
        }
    }
    
    return 0;
}
