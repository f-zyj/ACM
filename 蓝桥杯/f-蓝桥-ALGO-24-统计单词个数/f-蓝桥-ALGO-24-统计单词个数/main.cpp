//
//  main.cpp
//  f-蓝桥-ALGO-24-统计单词个数
//
//  Created by ZYJ on 2017/6/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 222;
const int MAXM = 9;

int P, K, n;
int val[MAXN][MAXN];
int dp[MAXN][MAXN];
int vis[MAXN];
char s[MAXN];
char w[MAXM][MAXN];

int main()
{
    scanf("%d%d\n", &P, &K);
    
    int cnt = 0;
    for (int i = 1; i <= P; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            scanf("%c", &s[++cnt]);
        }
        getchar();
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", w[i]);
    }
    
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = i; j <= cnt; j++)
        {
            memset(vis, 0, sizeof(vis));
            for (int k = 1; k <= n; k++)
            {
                int len = (int)strlen(w[k]);
                for (int o = i; o <= j - len + 1; o++)
                {
                    if (vis[o])
                    {
                        continue;
                    }
                    bool flag = 1;
                    for (int p = 0; p < len; p++)
                    {
                        if (s[o + p] != w[k][p])
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag)
                    {
                        val[i][j]++;
                        vis[o] = 1;
                    }
                }
            }
        }
    }
    
    for (int k = 1; k <= K; k++)
    {
        for (int i = 1; i <= cnt; i++)
        {
            for (int j = k - 1; j <= i - 1; j++)
            {
                dp[i][k] = max(dp[i][k], dp[j][k - 1] + val[j + 1][i]);
            }
        }
    }
    
//    cout << s + 1 << '\n';
    printf("%d\n", dp[cnt][K]);
    
    return 0;
}
