//
//  main.cpp
//  f-HDU-6006-Engineer Assignment
//
//  Created by ZYJ on 2017/11/14.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 20;
const int MAXM = 10;
const int MAXO = 111;

int N, M;
int vis[MAXO];
int a[MAXN][MAXM];
int b[MAXN][MAXM];
int dp[MAXN][(1 << MAXM) + 1];
vector<int> vi[MAXN];   //  第 i 个任务可以由这些状态的工程师集合来完成

void init()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++)
    {
        vi[i].clear();
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int ce = 1; ce <= T; ce++)
    {
        scanf("%d%d", &N, &M);
        
        init();
        
        //  N 个工程
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", a[i]);
            for (int j = 1; j <= a[i][0]; j++)
            {
                scanf("%d", a[i] + j);
            }
        }
        //  M 个工程师
        for (int i = 0; i < M; i++)
        {
            scanf("%d", b[i]);
            for (int j = 1; j <= b[i][0]; j++)
            {
                scanf("%d", b[i] + j);
            }
        }
        
        //  预处理，第 i 个任务可以由哪些人完成
        for (int i = 1; i <= N; i++)
        {
            int t = 1 << M;
            for (int j = 0; j < t; j++)
            {
                int cnt = 0;
                memset(vis, 0, sizeof vis);
                for (int k = 0; k < M; k++)
                {
                    if (j & (1 << k))
                    {
                        cnt++;
                        for (int l = 1; l <= b[k][0]; l++)
                        {
                            vis[b[k][l]] = 1;
                        }
                    }
                }
                
                //  任务需求不超过三个人
                if (cnt > 3)
                {
                    continue;
                }
                
                int flag = 1;
                for (int k = 1; k <= a[i][0]; k++)
                {
                    if (!vis[a[i][k]])
                    {
                        flag = 0;
                    }
                }
                if (flag)
                {
                    vi[i].push_back(j);
                }
            }
        }
        
        for (int i = 1; i <= N; i++)
        {
            int t = 1 << M;
            for (int j = 0; j < t; j++)
            {
                int sz = (int)vi[i].size();
                for (int k = 0; k < sz; k++)
                {
                    if ((j | vi[i][k]) == j)
                    {
                        dp[i][j] = max(dp[i - 1][j ^ vi[i][k]] + 1, dp[i][j]);
                    }
                }
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
        
        printf("Case #%d: %d\n", ce, dp[N][(1 << M) - 1]);
    }
    
    return 0;
}
