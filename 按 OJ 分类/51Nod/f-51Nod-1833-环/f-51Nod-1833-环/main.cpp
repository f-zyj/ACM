//
//  main.cpp
//  f-51Nod-1833-环
//
//  Created by ZYJ on 2017/11/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int MAXN = 22;
const int MAXM = (1 << 20) + 5;
const int MOD = 998244353;

int n, m;
int dp[MAXN][MAXM];
vector<int> vi[MAXN];

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int cal(int x)
{
    int ret = 0;
    while (x)
    {
        if (x & 1)
        {
            ret++;
        }
        x >>= 1;
    }
    
    return ret;
}

int main()
{
    scan_d(n);
    scan_d(m);
    
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        scan_d(u);
        scan_d(v);
        vi[u].push_back(v);
    }
    
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int t = 1 << n;
        for (int j = 0; j < t; j++)
        {
            if (cal(j) == i)
            {
                for (int k = 0; k < vi[i].size(); k++)
                {
                    v = vi[i][k];
                    if ((j >> (v - 1)) & 1)
                    {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j ^ (1 << (v - 1))]) % MOD;
                    }
                }
            }
        }
    }
    
    printf("%d\n", dp[n][(1 << n) - 1]);
    
    return 0;
}
