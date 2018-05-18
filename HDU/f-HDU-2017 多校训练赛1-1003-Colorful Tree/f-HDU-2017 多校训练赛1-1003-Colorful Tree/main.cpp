//
//  main.cpp
//  f-HDU-2017 多校训练赛1-1003-Colorful Tree
//
//  Created by ZYJ on 2017/7/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long ll;

const int MAXN = 2e5 + 10;

int n;
ll ans;
int c[MAXN];
int lnk[MAXN];
int pos[MAXN];
int ctr[MAXN];  //  某种颜色的虚树结点个数
int rem[MAXN];  //  某种颜色的所有虚树的结点个数

struct Edge
{
    int nxt, v;
} e[MAXN << 1];

inline ll get_cnt(int x)
{
    return (x * (x - 1LL)) >> 1;
}

int dfs(int rt, int pre)
{
    int su = 1, o = pos[c[rt]];
    pos[c[rt]] = rt;
    for (int it = lnk[rt]; it; it = e[it].nxt)
    {
        if (e[it].v != pre)
        {
            ctr[rt] = 0;
            int sv = dfs(e[it].v, rt);
            ans -= get_cnt(sv - ctr[rt]);
            su += sv;
        }
    }
    (o ? ctr[o] : rem[c[rt]]) += su;
    pos[c[rt]] = o;
    
    return su;  //  返回子树的结点个数
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
    int ce = 1;
    while (~scanf("%d", &n))
    {
        memset(lnk, 0, sizeof(lnk));
        memset(rem, 0, sizeof(rem));
        
        for (int i = 1; i <= n; ++i)
        {
            scan_d(c[i]);
        }
        
        int u, v;
        for (int i = 1; i < n; ++i)
        {
            scan_d(u), scan_d(v);
            e[i << 1] = (Edge){lnk[u], v};
            lnk[u] = i << 1;
            e[i << 1 | 1] = (Edge){lnk[v], u};
            lnk[v] = i << 1 | 1;
        }
        
        ans = get_cnt(n) * n;
        
        dfs(1, -1);
        
        for (int i = 1; i <= n; ++i)
        {
            ans -= get_cnt(n - rem[i]);
        }
        
        printf("Case #%d: %lld\n", ce++, ans);
    }
    
    return 0;
}

