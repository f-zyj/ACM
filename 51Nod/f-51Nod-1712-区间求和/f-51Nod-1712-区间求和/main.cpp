//
//  main.cpp
//  f-51Nod-1712-区间求和
//
//  Created by ZYJ on 2016/12/14.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 3e6 + 10;

typedef unsigned int uint;

int n, lrk[MAXN], rrk[MAXN], pre[MAXN], nxt[MAXN], pos[MAXN];
uint a[MAXN], decA[MAXN], decB[MAXN], f[MAXN], g[MAXN], ans = 0;

void in(uint &w)
{
    w = 0;
    char c = getchar();
    while (c > '9' || c < '0')
    {
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        w = w * 10 + c - '0';
        c = getchar();
    }
}

uint mult(uint a, uint b)
{
    uint s = 0;
    while (b)
    {
        if (b & 1)
        {
            s += a;
        }
        a += a;
        b >>= 1;
    }
    return s;
}

int main()
{
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
    {
        in(a[i]);
    }
    memset(pos, 0, sizeof(pos));
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pos[a[i]];
        pos[a[i]] = i;
        lrk[i] = lrk[pre[i]] + 1;
        decA[i] = decA[pre[i]] + pre[i];
    }
    memset(pos, 0, sizeof(pos));
    for (int i = n; i >= 1; i--)
    {
        nxt[i] = pos[a[i]];
        pos[a[i]] = i;
        rrk[i] = rrk[nxt[i]] + 1;
        decB[i] = decB[nxt[i]] + nxt[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (rrk[i] == 1)
        {
            nxt[i] = i + n;
            pre[i + n] = i;
            lrk[nxt[i]] = lrk[i] + 1;
            decA[i + n] = decA[i] + i;
        }
        if (lrk[i] == 1)
        {
            pre[i] = i + n * 2;
            nxt[i + n * 2] = i;
            rrk[pre[i]] = rrk[i] + 1;
            decB[i + n * 2] = decB[i] + i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] + i * rrk[i] - decA[nxt[i - 1]];
    }
    for (int i = n; i >= 1; i--)
    {
        g[i] = g[i + 1] + i * lrk[i] - decB[pre[i + 1]];
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i] + g[i] - i * 2;
    }
    memset(g, 0, sizeof(g));
    memset(decA, 0, sizeof(decA));
    for (int i = 1; i <= n; i++)
    {
        decA[i] = decA[pre[i]] + (pre[i] >= 1 && pre[i] <= n);
        if (rrk[i] == 1)
        {
            decA[i + n] = decA[i] + 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        g[i] = g[i - 1] + rrk[i] - decA[nxt[i - 1]];
        f[i] = mult(g[i] - 1, i) * 2 - f[i];
        ans += mult(f[i], a[i]); 
    }
    cout << ans << endl;
    
    return 0; 
}
