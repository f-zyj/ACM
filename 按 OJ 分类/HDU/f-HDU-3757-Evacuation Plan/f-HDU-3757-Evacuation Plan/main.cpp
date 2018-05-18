//
//  main.cpp
//  f-HDU-3757-Evacuation Plan
//
//  Created by ZYJ on 2017/10/16.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 4e3 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3f;

short path[MAXN][MAXN];
long long dp[MAXN];

struct node
{
    long long dis;
    int pos, she;
};

int n, m;
node a[MAXN], b[MAXN];

bool cmp_dis(const node &a, const node &b)
{
    return a.dis < b.dis;
}

bool cmp_pos(const node &a, const node &b)
{
    return a.pos < b.pos;
}

void get_she(int i, int j)
{
    if (i != 1)
    {
        get_she(i - 1, path[i][j]);
    }
    a[i].she = b[j].pos;
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        memset(dp, 0x3f, sizeof(dp));
        
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i].dis);
            a[i].pos = i;
        }
        
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
        {
            scanf("%lld", &b[i].dis);
            b[i].pos = i;
        }
        
        sort(a + 1, a + 1 + n, cmp_dis);
        sort(b + 1, b + 1 + m, cmp_dis);
        
        dp[1] = abs(a[1].dis - b[1].dis);
        for (int i = 2; i <= n; i++)
        {
            int t = min(i, m);
            for (int j = t; j >= 1; j--)
            {
                if (dp[j] < dp[j - 1])
                {
                    dp[j] = dp[j] + abs(a[i].dis - b[j].dis);
                    path[i][j] = j;
                }
                else
                {
                    dp[j] = dp[j - 1] + abs(a[i].dis - b[j].dis);
                    path[i][j] = j - 1;
                }
            }
        }
        
        printf("%lld\n", dp[m]);
        
        get_she(n, m);
        
        sort(a + 1, a + 1 + n, cmp_pos);
        for (int i = 1; i < n; i++)
        {
            printf("%d ", a[i].she);
        }
        printf("%d\n", a[n].she);
    }
    
    return 0;
}

