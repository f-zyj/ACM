//
//  main.cpp
//  f-河南第十届ACM省赛-I-Transmit information
//
//  Created by ZYJ on 2017/5/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 1005;

int k, m, s, t;
int ans[MAXN][MAXN];
int tmp[MAXN][MAXN];
int tmp_[MAXN][MAXN];
int used[MAXN], v[MAXN], cnt;

void floyd(int c[][MAXN], int a[][MAXN], int b[][MAXN])
{
    for (int k = 0; k < cnt; k++)
    {
        for (int i = 0; i < cnt; i++)
        {
            for (int j = 0; j < cnt; j++)
            {
                if (c[v[i]][v[j]] > a[v[i]][v[k]] + b[v[k]][v[j]])
                {
                    c[v[i]][v[j]] = a[v[i]][v[k]] + b[v[k]][v[j]];
                }
            }
        }
    }
}

void copy(int a[][MAXN], int b[][MAXN])
{
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < cnt; j++)
        {
            a[v[i]][v[j]] = b[v[i]][v[j]];
        }
    }
}

void slove(int k)
{
    while (k)
    {
        if (k & 1)
        {
            floyd(tmp_, ans, tmp);
            copy(ans, tmp_);
            memset(tmp_, 0x3f, sizeof(tmp_));
        }
        floyd(tmp_, tmp, tmp);
        copy(tmp, tmp_);
        memset(tmp_, 0x3f, sizeof(tmp_));
        k >>= 1;
    }
}

void init()
{
    cnt = 0;
    memset(tmp, 0x3f, sizeof(tmp));
    memset(tmp_, 0x3f, sizeof(tmp_));
    memset(ans, 0x3f, sizeof(ans));
    for (int i = 0; i < MAXN; i++)
    {
        ans[i][i] = 0;
    }
}

int main()
{
    init();

    scanf("%d%d%d%d", &k, &m, &s, &t);

    int x, y, w;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &w, &x, &y);
        if (!used[x])
        {
            used[x] = 1;
            v[cnt++] = x;
        }
        if (!used[y])
        {
            used[y] = 1;
            v[cnt++] = y;
        }
        if (tmp[x][y] > w)
        {
            tmp[x][y] = tmp[y][x] = w;
        }
    }
    
    slove(k);
    
    printf("%d\n", ans[s][t]);
    
    return 0;
}
