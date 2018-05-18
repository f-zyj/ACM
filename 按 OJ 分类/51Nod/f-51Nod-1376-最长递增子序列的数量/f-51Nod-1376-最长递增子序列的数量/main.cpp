//
//  main.cpp
//  f-51Nod-1376-最长递增子序列的数量
//
//  Created by ZYJ on 2016/10/19.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 50010;
const int MOD = 1e9 + 7;

inline int read()
{
    int x = 0, c = getchar();
    for (; c > '9' || c < '0'; c = getchar());
    for (; c >= '0' && c <= '9'; c = getchar())
    {
        x = (x << 1) + (x << 3) + c - '0';
    }
    return x;
}

vector<int> h[MAXN];
vector<int> g[MAXN];
int f[MAXN];        //  递增序列
int maxLen, times;

inline int get(int c, int x)
{
    int l = -1, r = (int)(h[c].size() - 1);
    while (l < r - 1)
    {
        if (h[c][(l + r) >> 1] >= x)
        {
            l = (l + r) >> 1;
        }
        else
        {
            r = (l + r) >> 1;
        }
    }
    l = (l >= 0) ? g[c][l] : 0;
    return (g[c][g[c].size() - 1] + MOD - l) % MOD;
}

int main()
{
    memset(f, 100, sizeof(f));
    f[0] = -1;
    h[0].push_back(-1);
    g[0].push_back(1);
    
    int n = read();
    for (int k, x, s, i = 1; i <= n; i++)
    {
        k = read();
        x = (int)(lower_bound(f, f + n + 1, k) - f);
        f[x] = k;
        h[x].push_back(k);
        s = get(x - 1, k);
        if (x > maxLen)
        {
            maxLen = x, times = 0;
        }
        if (x == maxLen)
        {
            times = (times + s) % MOD;
        }
        if (g[x].size())
        {
            s = (s + g[x][g[x].size() - 1]) % MOD;
        }
        g[x].push_back(s);
    }
    printf("%d\n", times);
    
    return 0;
}
