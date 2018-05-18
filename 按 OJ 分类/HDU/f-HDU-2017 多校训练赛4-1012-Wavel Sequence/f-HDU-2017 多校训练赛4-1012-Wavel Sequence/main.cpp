//
//  main.cpp
//  f-HDU-2017 多校训练赛4-1012-Wavel Sequence
//
//  Created by ZYJ on 2017/8/5.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>

const int MAXN = 2010;
const int MOD = 998244353;

int n, m;
int a[MAXN], b[MAXN];
int g[MAXN][MAXN][2];
int h[MAXN][MAXN][2];

inline void get_mod(int &x, int y)
{
    x += y;
    if (x >= MOD)
    {
        x -= MOD;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &b[i]);
        }
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                g[i][j][0] = h[i][j][0] = 0;
                g[i][j][1] = h[i][j][1] = 0;
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    if (a[i] == b[j])
                    {
                        int t = h[i][j][k ^ 1];
                        if (!k)
                        {
                            get_mod(t, 1);
                        }
                        if (t)
                        {
                            get_mod(ans, t);
                            get_mod(g[i + 1][j][k], t);
                        }
                    }
                    if (g[i][j][k])
                    {
                        get_mod(g[i + 1][j][k], g[i][j][k]);
                        if (!k)
                        {
                            if (a[i] > b[j])
                            {
                                get_mod(h[i][j + 1][k], g[i][j][k]);
                            }
                        }
                        else if (a[i] < b[j])
                        {
                            get_mod(h[i][j + 1][k], g[i][j][k]);
                        }
                    }
                    if (h[i][j][k])
                    {
                        get_mod(h[i][j + 1][k], h[i][j][k]);
                    }
                }
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
