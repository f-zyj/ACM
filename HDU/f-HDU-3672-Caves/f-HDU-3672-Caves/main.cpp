//
//  main.cpp
//  f-HDU-3672-Caves
//
//  Created by ZYJ on 2017/10/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

#define clr(a, b) memset(a, b, sizeof(a))

using namespace std;

typedef long long ll;

const int MAXN = 510;

int n, q;
int root;
int hed[MAXN];
int nxt[MAXN];
int cost[MAXN];
bool vis[MAXN];
ll dp[MAXN][MAXN][2];

void dfs(int x)
{
    dp[x][1][0] = dp[x][1][1] = 0;
    for (int i = hed[x]; i; i = nxt[i])
    {
        dfs(i);
        for (int j = n; j >= 2; j--)
        {
            for (int k = 1; k < j; k++)
            {
                dp[x][j][0] = min(dp[x][j][0], dp[x][k][0] + dp[i][j - k][0] + cost[i] * 2);
                dp[x][j][1] = min(dp[x][j][1], min(dp[x][k][1] + dp[i][j - k][0] + cost[i] * 2,
                                                   dp[x][k][0] + dp[i][j - k][1] + cost[i]));
            }
        }
    }
}

int main()
{
    int ce = 1;
    while (cin >> n && n)
    {
        cout << "Case " << ce++ << ":" << endl;
        
        clr(dp, 0x3f);
        clr(hed, 0);
        clr(vis, 0);
        
        int a, b, c;
        for (int i = 1; i < n; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            a++;
            b++;
            vis[a] = true;
            nxt[a] = hed[b];
            hed[b] = a;
            cost[a] = c;    //  a 与 父亲 连边的花费
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                root = i;
                dfs(i);
                break;
            }
        }
        
        cin >> q;
        
        int x, k;
        for (int i = 0; i < q; i++)
        {
            scanf("%d", &x);
            k = n;
            while (dp[root][k][0] > x && dp[root][k][1] > x)
            {
                k--;
            }
            printf("%d\n", k);
        }
    }
    
    return 0;
}
