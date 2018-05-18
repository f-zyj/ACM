//
//  main.cpp
//  f-HDU-2017 多校训练赛4-1007-Matching In Multiplication
//
//  Created by ZYJ on 2017/8/5.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>

const int MAXN = 3e5 * 2 + 10;
const int MOD = 998244353;

int n, cnt;
int q[MAXN];
int hed[MAXN];
int deg[MAXN];
int v[MAXN << 1];
int val[MAXN << 1];
int nxt[MAXN << 1];
bool vis[MAXN];

inline void add(int x, int y, int z)
{
    deg[x]++;
    deg[y]++;
    
    v[++cnt] = y;
    val[cnt] = z;
    nxt[cnt] = hed[x];
    hed[x] = cnt;
    v[++cnt] = x;
    val[cnt] = z;
    nxt[cnt] = hed[y];
    hed[y] = cnt;
}

inline int go(int x)
{
    for (int i = hed[x]; i; i = nxt[i])
    {
        if (!vis[v[i]])
        {
            return v[i];
        }
    }
    
    return 0;
}

inline int get(int x, int y)
{
    for (int i = hed[x]; i; i = nxt[i])
    {
        if (v[i] == y)
        {
            return val[i];
        }
    }
    
    return 0;
}

void init()
{
    cnt = 0;
    int x = n << 1;
    for (int i = 1; i <= x; i++)
    {
        hed[i] = deg[i] = vis[i] = 0;
    }
}

int main()
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        
        init();
        
        int y, w;
        for (int i = 1; i <= n; i++)    //  1 ~ n U n+1 ~ 2n V
        {
            scanf("%d%d", &y, &w);
            add(i, y + n, w);
            scanf("%d%d", &y, &w);
            add(i, y + n, w);
        }
        
        n <<= 1;
        int t = 0;
        for (int i = (n >> 1) + 1; i <= n; i++)
        {
            if (deg[i] == 1)
            {
                q[++t] = i;
            }
        }
        
        int ans = 1, h = 1;
        while (h <= t)
        {
            int u = q[h++], w = 0;
            for (int i = hed[u]; i; i = nxt[i])
            {
                if (!vis[v[i]])
                {
                    w = v[i];
                    ans = 1LL * ans * val[i] % MOD;
                    break;
                }
            }
            vis[u] = vis[w] = 1;
            
            for (int i = hed[w]; i; i = nxt[i])
            {
                u = v[i];
                if (!vis[u])
                {
                    deg[u]--;
                    if (deg[u] == 1)
                    {
                        q[++t] = u;
                    }
                }
            }
        }
        
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                vis[q[t = 1] = i] = 1;
                for (int j = go(i); j; j = go(j))
                {
                    vis[q[++t] = j] = 1;
                }
                q[t + 1] = q[1];
                y = w = 1;
                for (int j = 1; j <= t; j += 2)
                {
                    y = 1LL * y * get(q[j], q[j + 1]) % MOD;
                }
                for (int j = 2; j <= t; j += 2)
                {
                    w = 1LL * w * get(q[j], q[j + 1]) % MOD;
                }
                ans = 1LL * ans * (y + w) % MOD;
            }
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
