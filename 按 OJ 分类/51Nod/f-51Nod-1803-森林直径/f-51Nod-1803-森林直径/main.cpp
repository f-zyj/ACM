//
//  main.cpp
//  f-51Nod-1803-森林直径
//
//  Created by ZYJ on 2017/11/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 5;
const int MAXM = 66;
const int MAXT = 5555;

int n, q, cnt;
int tmp, ans;
int fat[MAXT];
int pre[MAXT];
int hed[MAXN];
int Hed[MAXN];
int nxt[MAXN];
int Nxt[MAXT];
int dep[MAXN];
int Dep[MAXN];
int dp[MAXN][MAXM];

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

void dfs(int x)
{
    Hed[x] = 0;
    for (int i = hed[x]; i; i = nxt[i])
    {
        dfs(i);
        
        if (i == hed[x])
        {
            Hed[x] = pre[cnt--];
            Nxt[Hed[x]] = Hed[i];
            Dep[Hed[x]] = dep[i];
            fat[Hed[x]] = i;
            for (int j = Hed[x]; j; j = Nxt[j])
            {
                dp[i][Dep[j] - dep[x]] = min(dp[i][Dep[j] - dep[x]], fat[j]);
            }
        }
        else
        {
            int t = pre[cnt--];
            Nxt[t] = Hed[i];
            Dep[t] = dep[i];
            fat[t] = i;
            Hed[i] = t;
            for (int j = Hed[i]; j; j = Nxt[j])
            {
                dp[i][Dep[j] - dep[x]] = min(dp[i][Dep[j] - dep[x]], fat[j]);
            }
            for (int j = Hed[x]; j; j = Nxt[j])
            {
                for (int k = Hed[i]; k; k = Nxt[k])
                {
                    dp[i][Dep[j] + Dep[k] - 2 * dep[x]] =
                        min(dp[i][Dep[j]+ Dep[k] - 2 * dep[x]], max(fat[j], fat[k]));
                }
            }
            for (int j = Hed[x], k = Hed[i]; k; k = Nxt[k], j = Nxt[j])
            {
                fat[j] = min(fat[j], fat[k]);
                if (!Nxt[j] && Nxt[k])
                {
                    Nxt[j] = Nxt[k];
                    break;
                }
            }
            for (int j = Hed[x], k = Hed[i]; k && j != k; j = Nxt[j], k = Nxt[k])
            {
                pre[++cnt] = k;
            }
        }
    }
}

void init()
{
    cnt = MAXT - 1;
    memset(dp, 0x3f, sizeof(dp));
    
    for (int i = 1; i < MAXT; i++)
    {
        pre[i] = i;
    }
    
}

int main()
{
    init();
    
    scan_d(n);
    
    int x, y;
    for (int i = 2; i <= n; i++)
    {
        scan_d(x);
        scan_d(y);
        nxt[i] = hed[x];
        hed[x] = i;
        dep[i] = dep[x] + 1;
    }
    
    dfs(1);
    
    for (int i = n - 1; i > 1; i--)
    {
        for (int j = 1; j < MAXM; j++)
        {
            dp[i][j] = min(dp[i][j], dp[i + 1][j]);
        }
    }
    
    scan_d(q);
    
    int l, r;
    while (q--)
    {
        scan_d(l);
        scan_d(r);
        l++;
        r++;
        tmp = 0;
        for (int i = 1; i < MAXM; i++)
        {
            if (dp[l][i] <= r)
            {
                tmp = i;
            }
            else
            {
                break;
            }
        }
        
        ans += tmp;
    }
    
    printf("%d\n", ans);
    
    return 0;
}
