//
//  main.cpp
//  f-51Nod-1486-大大走格子
//
//  Created by ZYJ on 2016/10/23.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 3e3 + 1e2;
const int MAXM = 3e5 + 1e4;

struct node
{
    int x, y;
} p[MAXN];

int h, w, n;
ll fac[MAXM], inv[MAXM];
ll sum[MAXN];

int cmp(node a, node b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

ll pow(ll x, ll k)
{
    ll ans = 1 ;
    while (k)
    {
        if (k & 1)
        {
            ans = ans * x % MOD ;
        }
        k = k >> 1;
        x = (x * x) % MOD ;
    }
    return ans;
}

void init()
{
    ll i, c;
    fac[0] = inv[0] = 1;
    for (i = 1; i <= h + w; i++)
    {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    c = max(h, w);
    inv[c] = pow(fac[c], MOD - 2);
    for (i = c - 1; i > 0 ; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

int main()
{
    ll i, j;
    while (scanf("%d%d%d", &h, &w, &n) != EOF)
    {
        init();
        for (i = 0; i < n; i++)
        {
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        p[n].x = h;
        p[n++].y = w;
        sort(p, p + n, cmp);
        int x1, y1, x2, y2;
        for (i = 0; i < n; i++)
        {
            x1 = p[i].x - 1;
            y1 = p[i].y - 1 ;
            sum[i] = fac[x1 + y1] * inv[x1] % MOD * inv[y1] % MOD;
            for (j = 0; j < i; j++)
            {
                if (p[j].x <= p[i].x && p[j].y <= p[i].y)
                {
                    x2 = x1 - p[j].x + 1;
                    y2 = y1 - p[j].y + 1;
                    sum[i] = (sum[i] - fac[x2 + y2] * inv[x2] % MOD * inv[y2] % MOD * sum[j] % MOD) % MOD;
                    if (sum[i] <= 0)
                    {
                        sum[i] = (sum[i] + MOD) % MOD;
                    }
                }
            }
        }
        printf("%lld\n", sum[n - 1]);
    }
    
    return 0 ;
}
