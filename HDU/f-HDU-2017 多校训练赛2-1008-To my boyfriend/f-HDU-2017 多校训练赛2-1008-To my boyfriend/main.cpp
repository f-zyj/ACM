//
//  main.cpp
//  f-HDU-2017 多校训练赛2-1008-To my boyfriend
//
//  Created by ZYJ on 2017/7/29.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 111;

struct node
{
    int x, n;
    node() {};
    node(int a, int b)
    {
        x = a;
        n = b;
    }
} stc[MAXN];

int n, m, tot;
ll ans;
int mat[MAXN][MAXN];
int pre[MAXN * MAXN][MAXN];
int tmp[MAXN * MAXN][MAXN];
int vis[MAXN * MAXN];

int get_cnt(int l, int r, int i, int j, int col)
{
    int sum = 0, t = 0, ret = 0;
    for (int k = l; k <= r; k++)
    {
        int d = (i == pre[col][k] && k >= j) ? i - tmp[col][k] : i - pre[col][k];
        if (!d)
        {
            t = sum = 0;
        }
        else
        {
            node u = node(d, 1);
            while (t && stc[t].x >= u.x)
            {
                sum -= stc[t].x * stc[t].n;
                u.n += stc[t].n;
                t--;
            }
            sum += u.x * u.n * 1ll;
            stc[++t] = u;
            ret += sum;
        }
    }
    
    return ret;
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
    int T;
    scan_d(T);
    while (T--)
    {
        memset(pre, 0, sizeof(pre));
        memset(vis, 0, sizeof(vis));
        
        tot = 0, ans = 0;
        scan_d(n), scan_d(m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scan_d(mat[i][j]);
                if (!vis[mat[i][j]])
                {
                    tot++;
                    vis[mat[i][j]] = 1;
                }
            }
        }
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                tmp[mat[i][j]][j] = pre[mat[i][j]][j];
                pre[mat[i][j]][j] = i;
            }
            for (int j = 1; j <= m; j++)
            {
                int col = mat[i][j];
                ans += (n - i + 1ll) *
                       (get_cnt(1, m, i, j, col)
                      - get_cnt(1, j - 1, i, j, col)
                      - get_cnt(j + 1, m, i, j, col));
            }
        }
        
        printf("%.9f\n", ans * 4.0 / (n * (n + 1) * m * (m + 1)));
    }
    
    return 0;
}
