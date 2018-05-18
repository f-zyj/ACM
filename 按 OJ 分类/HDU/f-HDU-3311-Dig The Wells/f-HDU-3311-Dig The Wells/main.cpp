//
//  main.cpp
//  f-HDU-3311-Dig The Wells
//
//  Created by ZYJ on 2016/11/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define INF 0x3f3f3f3f

const int MAXQ = 74000;
const int MAXD = 1010;
const int MAXM = 10010;
const int MAXS = 74;

int N, M, P, first[MAXD], e, next[MAXM], v[MAXM], w[MAXM];
int bit[MAXD], q[MAXQ + 10], front, rear, inq[MAXD][MAXS];
int f[MAXD][MAXS], dp[MAXS];

void add(int x, int y, int z)
{
    v[e] = y, w[e] = z;
    next[e] = first[x], first[x] = e++;
}

void init()
{
    int i, x, y, z;
    memset(f, 0x3f, sizeof(f));
    memset(bit, 0, sizeof(bit));
    for (i = 1; i <= N + M; i++)
    {
        if (i <= N)
        {
            bit[i] = 1 << (i - 1);
        }
        scanf("%d", &z);
        if (i <= N)
        {
            f[i][bit[i]] = 0, f[i][bit[i] | 1 << N] = z;
        }
        else f[i][1 << N] = z;
    }
    memset(first, -1, sizeof(first));
    e = 0;
    for (i = 0; i < P; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z), add(y, x, z);
    }
}

int Min(int x, int y)
{
    return x < y ? x : y;
}

void spfa()
{
    int i, x, st, y, nst;
    while (front != rear)
    {
        x = q[front] & 1023, st = q[front] >> 10;
        inq[x][st] = 0;
        ++front > MAXQ ? front = 0 : 0;
        for (i = first[x]; i != -1; i = next[i])
        {
            y = v[i], nst = st | bit[y];
            if (f[x][st] + w[i] < f[y][nst])
            {
                f[y][nst] = f[x][st] + w[i];
                if (st == nst && !inq[y][nst])
                {
                    q[rear ++] = nst << 10 | y, inq[y][nst] = 1;
                    rear > MAXQ ? rear = 0 : 0;
                }
            }
        }
    }
}

void solve()
{
    int i, j, k, nn = 1 << (N + 1);
    front = rear = 0;
    memset(inq, 0, sizeof(inq));
    for (i = 0; i < nn; i++)
    {
        for (j = 1; j <= N + M; j++)
        {
            for (k = i - 1 & i; k; k = k - 1 & i)
            {
                f[j][i] = Min(f[j][i], f[j][k | bit[j]] + f[j][i - k | bit[j]]);
            }
            if (f[j][i] < INF)
            {
                q[rear ++] = i << 10 | j, inq[j][i] = 1;
                rear > MAXQ ? rear = 0 : 0;
            }
        }
        spfa();
    }
    
    memset(dp, 0x3f, sizeof(dp));
    for (i = 0; i < nn; i++)
    {
        for (j = 1; j <= N + M; j++)
        {
            dp[i] = Min(dp[i], f[j][i]);
        }
    }
    for (i = 0; i < nn; i ++)
    {
        if (i & 1 << N)
        {
            for (j = i - 1 & i; j; j = j - 1 & i)
            {
                if (j & 1 << N)
                {
                    dp[i] = Min(dp[i], dp[j] + dp[i - j | 1 << N]);
                }
            }
        }
    }
    printf("%d\n", dp[(1 << (N + 1)) - 1]);
}

int main()
{
    while (scanf("%d%d%d", &N, &M, &P) == 3)
    {
        init();
        solve();
    }
    return 0;
}
