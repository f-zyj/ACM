//
//  main.c
//  f-ADV-3-金属采集
//
//  Created by ZYJ on 16/5/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define INF 0x3f3f3f3f
#define MAXSIZE 100001
#define MAX(a, b) a > b ? a : b
typedef long long ll;

int n, S, k;
int key = 1;
int flag[MAXSIZE] = {0};
int go[MAXSIZE] = {0};  //指向路径
int to[MAXSIZE * 2];    //指向节点
int next[MAXSIZE * 2];  //指向同一节点的其它路径
int cost[MAXSIZE * 2];  //能量
ll dp[MAXSIZE][11], sum = 0;   //dp[i][j]:i号节点j个机器人的花费

void addage(int x, int y, int w)
{
    ++key;
    to[key] = y;
    next[key] = go[x];
    go[x] = key;
    cost[key] = w;
    return ;
}

void dfs(int S)
{
    int i, a, b;
    for (i = go[S]; i; i = next[i]) //最后i = next[i] = 0结束
    {
        if (to[i] != flag[S])
        {
            flag[to[i]] = S;
            dfs(to[i]);
            
            for (a = k; a; a--)
            {
                for (b = 1; b <= a; b++)
                {
                    dp[S][a] = MAX(dp[S][a], dp[S][a - b] + dp[to[i]][b] + (ll)(-b + 2) * cost[i]);
                }
            }
        }
    }
    return ;
}

int main(int argc, const char * argv[])
{
    int i;
    int x, y, w;
    scanf("%d %d %d", &n, &S, &k);
    
    for (i = 1; i < n; i++)
    {
        scanf("%d %d %d", &x, &y, &w);
        sum += w;   //所有w和
        addage(x, y, w);
        addage(y, x, w);
    }
    
    sum += sum; //能量变为两倍，一来一回
    dfs(S);
    
    ll ans = INF;
    for (i = 0; i <= k; i++)
    {
        if (ans > sum - dp[S][i])   //每个路径至少经过一次，所以用sum减去dp[S][i]
        {
            ans = sum - dp[S][i];
        }
    }
    
    printf("%lld\n", ans);
    return 0;
}