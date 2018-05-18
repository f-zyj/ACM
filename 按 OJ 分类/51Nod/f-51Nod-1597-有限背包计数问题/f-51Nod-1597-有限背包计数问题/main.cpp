//
//  main.cpp
//  f-51Nod-1597-有限背包计数问题
//
//  Created by ZYJ on 2017/8/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const int MAXM = 320;
const int MOD = 23333333;

int n, m;
int tmp[MAXN];
int f[2][MAXN];
int g[MAXM][MAXN];
ll f1[MAXN], g1[MAXN];

int main()
{
    scanf("%d", &n);
    
    f[0][0] = g[0][0] = 1;
    m = (int)ceil(sqrt((double)n));
    
    int now = 0, pre = 1;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            tmp[j] = 0;
        }
        int cnt = -1;
        swap(now, pre);
        for (int j = 0; j <= n; ++j)
        {
            ++cnt;
            if (cnt >= i)
            {
                cnt = 0;
            }
            tmp[cnt] += f[pre][j];
            tmp[cnt] %= MOD;
            f[now][j] = tmp[cnt];
            if (j >= i * i)
            {
                tmp[cnt] = (tmp[cnt] - f[pre][j - i * i] + MOD) % MOD;
            }
        }
    }
    
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i && i + j <= n)
            {
                g[i][i + j] += g[i][j];
                g[i][i + j] %= MOD;
            }
            if (j + m + 1 <= n)
            {
                g[i + 1][j + m + 1] += g[i][j];
                g[i + 1][j + m + 1] %= MOD;
            }
        }
    }
    ++g1[0];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            g1[i] += g[j][i];
            g1[i] %= MOD;
        }
    }
    for (int i = 0; i <= n; ++i)
    {
        f1[i] = f[now][i];
    }
    
    ll ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        ans += (f1[i] * g1[n - i] % MOD);
        ans %= MOD;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
