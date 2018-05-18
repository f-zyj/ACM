//
//  main.cpp
//  f-POJ-3866-Exclusive Access 2
//
//  Created by ZYJ on 2017/10/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 20;
const int MAXM = 111;

map<char, int> mci;
map<int, char> mic;

int n, m;
bool ok[1 << MAXN];
bool g[MAXN][MAXN];
char s1[MAXN];
char s2[MAXN];
int q1[MAXM];
int q2[MAXM];
int num[MAXN];
int pre[1 << MAXN];
int dp[1 << MAXN];

int main()
{
    scanf("%d", &m);
    
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        scanf("%s%s", s1, s2);
        
        if (!mci.count(s1[0]))
        {
            mic[n] = s1[0];
            mci[s1[0]] = n++;
        }
        if (!mci.count(s2[0]))
        {
            mic[n] = s2[0];
            mci[s2[0]] = n++;
        }
        u = mci[s1[0]];
        v = mci[s2[0]];
        q1[i] = u;
        q2[i] = v;
        g[u][v] = g[v][u] = 1;
    }
    
    ok[0] = 1;
    for (int i = 1; i < (1 << n); i++)
    {
        ok[i] = 1;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                if (!ok[i ^ (1 << j)])
                {
                    ok[i] = 0;
                    break;
                }
                
                for (int k = 0; k < n; k++)
                {
                    if (j != k && (i & (1 << k)) && g[j][k])
                    {
                        ok[i] = 0;
                        break;
                    }
                }
                
                break;
            }
        }
    }
    
    memset(dp, 0x3f, sizeof(dp));
    
    dp[0] = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        for (int j = i; j; j = i & (j - 1))
        {
            if (ok[j] && dp[i ^ j] + 1 < dp[i])
            {
                dp[i] = dp[i ^ j] + 1;
                pre[i] = j;
            }
        }
    }
    
    printf("%d\n", dp[(1 << n) - 1] - 2);
    
    for (int i = (1 << n) - 1, clo = 1; i; i ^= pre[i], clo++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((1 << j) & pre[i])
            {
                num[j] = clo;
            }
        }
    }
    
    for (int i = 1; i <= m; i++)
    {
        if (num[q1[i]] < num[q2[i]])
        {
            printf("%c %c\n", mic[q1[i]], mic[q2[i]]);
        }
        else
        {
            printf("%c %c\n", mic[q2[i]], mic[q1[i]]);
        }
    }
    
    return 0;
}
