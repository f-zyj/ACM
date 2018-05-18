//
//  main.cpp
//  f-51Nod-1679-连通率
//
//  Created by ZYJ on 2017/7/28.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

int n;
int idx;
int head[MAXN];
long long ans[MAXN];
long long sum[MAXN];
long long siz[MAXN];
long long pow_2[MAXN];

struct Edge
{
    int to, next;
} edges[MAXN << 1];

void addEdge(int u, int v)
{
    ++idx;
    edges[idx].to = v;
    edges[idx].next = head[u];
    head[u] = idx;
}

void dfs(int rt, int pre)
{
    sum[rt] = siz[rt] = 1LL;
    ans[rt] = 0LL;
    for (int i = head[rt]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v != pre)
        {
            dfs(v, rt);
            ans[rt] = ((ans[rt] * pow_2[siz[v]]) % MOD
                     + (ans[v] * pow_2[siz[rt]]) % MOD
                      + sum[rt] * sum[v] % MOD) % MOD;
            sum[rt] = (sum[rt] * pow_2[siz[v]] % MOD
                     + sum[v] * pow_2[siz[rt] - 1] % MOD) % MOD;
            siz[rt] = (siz[rt] + siz[v]) % MOD;
        }
    }
}

void init()
{
    pow_2[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        pow_2[i] = (pow_2[i - 1] << 1) % MOD;
    }
}

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

int main()
{
    init();
    
    scanf("%d", &n);
    
    int x, y;
    for (int i = 1; i < n; i++)
    {
        scan_d(x), scan_d(y);
        addEdge(x, y);
        addEdge(y, x);
    }
    dfs(1, 0);
    
    printf("%lld\n", ans[1]);
    
    return 0;
}
