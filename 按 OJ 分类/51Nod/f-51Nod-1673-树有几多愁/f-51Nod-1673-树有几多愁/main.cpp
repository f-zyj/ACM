//
//  main.cpp
//  f-51Nod-1673-树有几多愁
//
//  Created by ZYJ on 2017/7/20.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

typedef vector<int>::iterator vit;

const int MAXN = 1e5 + 10;
const int MAX_LEAF = 20;
const int MOD = 1e9 + 7;

int n;
int tot = 0, ans = 1;
int f[MAXN];
int g[1 << MAX_LEAF];
int p[1 << MAX_LEAF];
double h[1 << MAX_LEAF];

vector<int> e[MAXN];

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

void dfs(int u, int pre)
{
    for (vit it = e[u].begin(); it != e[u].end(); ++it)
    {
        int v = *it;
        if (v == pre)
        {
            continue;
        }
        
        dfs(v, u);
        
        f[u] |= f[v];
    }
    
    if (!f[u])
    {
        f[u] = 1 << tot++;
    }
    g[f[u]]++;
}

int main()
{
    scan_d(n);
    
    int u, v;
    for(int i = 1; i < n; ++i)
    {
        scan_d(u), scan_d(v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    dfs(1, -1);
    
    int tmp;
    reverse(g, g + (1 << tot));
    for (int i = 0; i < tot; ++i)
    {
        tmp = 1 << i;
        for (int j = 1; j < 1 << tot; ++j)
        {
            if (j & tmp)
            {
                g[j] += g[j ^ tmp];
            }
        }
    }
    
    reverse(g, g + (1 << tot));
    for (int i = 0; i < tot; ++i)
    {
        tmp = 1 << i;
        for (int j = 1; j < 1 << tot; ++j)
        {
            if (j & tmp)
            {
                g[j] = g[j ^ tmp] - g[j];
            }
        }
    }
    
    memset(p, -1, sizeof(p));
    for (int i = 1; i < 1 << tot; ++i)
    {
        for (int j = 0; j < tot; ++j)
        {
            tmp = 1 << j;
            if ((i & tmp) && (p[i] == -1 || h[i] < h[i ^ tmp]))
            {
                h[i] = h[i ^ tmp];
                p[i] = j;
            }
        }
        h[i] += log(g[i] + 1);
    }
    
    for (int i = (1 << tot) - 1; i; i ^= 1 << p[i])
    {
        ans = ans * (g[i] + 1LL) % MOD;
    }
    
    printf("%d\n", ans);
    
    return 0;
}


