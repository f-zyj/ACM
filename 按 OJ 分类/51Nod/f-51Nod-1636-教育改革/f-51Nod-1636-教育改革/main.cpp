//
//  main.cpp
//  f-51Nod-1636-教育改革
//
//  Created by ZYJ on 2017/10/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 55;
const int MAXM = 105;

int N, M, K;

struct lesson
{
    ll a, b, c;
    
    bool operator < (const lesson &t) const
    {
        return c < t.c;
    }
} les[MAXN];

ll ans = -1;
ll dp[MAXN][MAXN][MAXM];

void _max(ll &a, ll b)
{
    a = max(a, b);
}

int main()
{
    cin >> N >> M >> K;
    
    for (int i = 1; i <= M; ++i)
    {
        scanf("%lld%lld%lld", &les[i].a, &les[i].b, &les[i].c);
    }
    
    memset(dp, -1, sizeof dp);
    
    sort(les + 1, les + M + 1);
    
    for (int i = 1; i <= M; ++i)
    {
        for (ll j = les[i].a; j <= les[i].b; ++j)
        {
            _max(dp[i][1][j - les[i].a], j);
            for (int k = M; les[i].c < les[k].c; --k)
            {
                if (les[k].a <= j + K && j + K <= les[k].b)
                {
                    for (int l = min(i, N - 1); l; --l)
                    {
                        if (dp[i][l][j - les[i].a] > 0)
                        {
                            _max(dp[k][l + 1][j + K - les[k].a], dp[i][l][j - les[i].a] + j + K);
                        }
                    }
                }
                if (les[k].a <= j * K && j * K <= les[k].b)
                {
                    for (int l = min(i, N - 1); l; --l)
                    {
                        if (dp[i][l][j - les[i].a] > 0)
                        {
                            _max(dp[k][l + 1][j * K - les[k].a], dp[i][l][j - les[i].a] + j * K);
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= M; ++i)
    {
        for (ll j = les[i].b - les[i].a; ~j; --j)
        {
            _max(ans, dp[i][N][j]);
        }
    }
    
    if (ans == -1)
    {
        puts("NO");
    }
    else
    {
        printf("YES\n%lld\n", ans);
    }
    
    return 0;
}
