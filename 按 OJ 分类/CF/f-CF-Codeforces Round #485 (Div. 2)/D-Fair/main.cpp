//
//  main.cpp
//  f-CF-Codeforces Round #485 (Div. 2)
//
//  Created by ZYJ on 2018/5/30.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1e5 + 10;
const int MAXM = 105;

int n, m, k, s;
int vis[MAXN];
int dis[MAXN][MAXM];
vector<int> a[MAXN];
vector<int> val[MAXM];

void solve()
{
    for (int i = 1; i <= k; i++)
    {
        queue<pii> qp;
        memset(vis, 0, sizeof(vis));
        
        for (auto it : val[i])
        {
            vis[it] = 1;
            qp.push({0, it});
        }
        while (!qp.empty())
        {
            auto it = qp.front();
            qp.pop();
            
            dis[it.second][i] = it.first;
            for (auto it_ : a[it.second])
            {
                if (!vis[it_])
                {
                    vis[it_] = 1;
                    qp.push({it.first + 1, it_});
                }
            }
        }
    }
}

int main(int argc, const char * argv[])
{
#if DEBUG
    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    freopen("/Users/zyj/Desktop/output.txt", "w", stdout);
#endif
    memset(dis, -1, sizeof(dis));
    
    cin >> n >> m >> k >> s;
    
    int x;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        val[x].push_back(i);
    }
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    solve();
    
    for (int i = 1; i <= n; i++)
    {
        vector<int> tmp;
        for (int j = 1; j <= k; j++)
        {
            if (dis[i][j] != -1)
            {
                tmp.push_back(dis[i][j]);
            }
        }
        sort(tmp.begin(), tmp.end());
        
        long long ans = 0;
        for (int j = 0; j < s; j++)
        {
            ans += tmp[j];
        }
        printf("%lld ", ans);
    }
    putchar(10);
    
    return 0;
}
