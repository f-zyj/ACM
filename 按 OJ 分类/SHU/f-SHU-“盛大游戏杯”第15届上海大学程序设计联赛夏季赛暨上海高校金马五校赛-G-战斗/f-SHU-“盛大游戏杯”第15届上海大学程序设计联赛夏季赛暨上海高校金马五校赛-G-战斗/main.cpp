//
//  main.cpp
//  f-SHU-“盛大游戏杯”第15届上海大学程序设计联赛夏季赛暨上海高校金马五校赛-G-战斗
//
//  Created by ZYJ on 2017/7/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 11;

struct node
{
    int v, a;
} my[MAXN], sy[MAXN];

int n;
int rk[MAXN], vis[MAXN];

bool judge()
{
    int i = 0, j = 0;
    node a = sy[i], b = my[rk[j]];
    while (i < n && j < n)
    {
        int t1 = a.v / b.a;
        int t2 = b.v / a.a;
        int x = min(t1, t2);
        a.v -= b.a * x;
        b.v -= a.a * x;
        while (a.v > 0 && b.v > 0)
        {
            a.v -= b.a;
            b.v -= a.a;
        }
        if (a.v <= 0)
        {
            a = sy[++i];
        }
        if (b.v <= 0)
        {
            b = my[rk[++j]];
        }
    }
    return j == n ? false : true;
}

bool dfs(int pos)
{
    if (pos == n)
    {
        if (judge())
        {
            return true;
        }
        return false;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            rk[pos] = i;
            vis[i] = 1;
            if (dfs(pos + 1))
            {
                return true;
            }
            vis[i] = 0;
        }
    }
    
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &sy[i].v, &sy[i].a);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &my[i].v, &my[i].a);
        }
        
        if (dfs(0))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    
    return 0;
}
