//
//  main.cpp
//  f-51Nod-1868-彩色树
//
//  Created by ZYJ on 2017/12/10.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

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

int tot = 0;
int hed[MAXN];
int nxt[MAXN << 1];
int val[MAXN << 1];

void addEdge(int x, int y)
{
    val[++tot] = y;
    nxt[tot] = hed[x];
    hed[x] = tot;
}

int cal(int x)
{
    return (ll)(x - 1) * x % MOD;
}

int n;
int col_num, ans;
int sz[MAXN];
int col[MAXN];
int sum[MAXN];
bool vis[MAXN];

void dfs(int rt, int pre)
{
    sz[rt] = 1;
    int now, tmp;
    for (int i = hed[rt]; i; i = nxt[i])
    {
        if (val[i] != pre)
        {
            now = sum[col[rt]];
            
            dfs(val[i], rt);
            
            tmp = sz[val[i]] - (sum[col[rt]] - now);
            ans += cal(tmp);
            ans %= MOD;
            sum[col[rt]] += tmp;
            sz[rt] += sz[val[i]];
        }
    }
    sum[col[rt]]++;
}

int main()
{
    scan_d(n);
    for (int i = 1; i <= n; i++)
    {
        scan_d(col[i]);
        if (!vis[col[i]])
        {
            col_num++;
            vis[col[i]] = 1;
        }
    }
    
    int x, y;
    for (int i = 1; i < n; i++)
    {
        scan_d(x);
        scan_d(y);
        addEdge(x, y);
        addEdge(y, x);
    }
    
    dfs(1, 0);
    
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            ans += cal(n - sum[i]);
            ans %= MOD;
        }
    }
    ans = ((ll)col_num * cal(n) % MOD - ans + MOD) % MOD;
    for (int i = 1; i < n; i++)
    {
        ans = (ll)ans * i % MOD;
    }
    
    printf("%d\n", ans);
    
    return 0;
}

