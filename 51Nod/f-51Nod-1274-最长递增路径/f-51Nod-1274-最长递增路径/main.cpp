//
//  main.cpp
//  f-51Nod-1274-最长递增路径
//
//  Created by ZYJ on 2017/4/18.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5e4 + 10;

struct edge
{
    int x, y, w;
} Edge[MAXN];

int N, M;
int dp[MAXN];
int temp[MAXN];

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int main()
{
    scanf("%d%d", &N, &M);
    
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d", &Edge[i].x, &Edge[i].y, &Edge[i].w);
    }
    sort(Edge, Edge + M, cmp);
    
    int last = -1;
    for (int i = 0; i < M; i++)
    {
        if (i == M - 1 || Edge[i].w < Edge[i + 1].w)
        {
            for (int j = last + 1; j <= i; j++) //  防止重复加入，拷贝副本
            {
                temp[Edge[j].x] = dp[Edge[j].x];
                temp[Edge[j].y] = dp[Edge[j].y];
            }
            for (int j = last + 1; j <= i; j++)
            {
                dp[Edge[j].x] = max(dp[Edge[j].x], temp[Edge[j].y] + 1);
                dp[Edge[j].y] = max(dp[Edge[j].y], temp[Edge[j].x] + 1);
            }
            last = i;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, dp[i]);
    }
    printf("%d\n",ans);
    
    return 0;
}
