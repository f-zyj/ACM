//
//  main.cpp
//  f-计蒜客-2017 ACM-ICPC 亚洲区（乌鲁木齐赛区）网络赛-F-Islands
//
//  Created by ZYJ on 2017/9/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 1e4 + 7;

int n, m;
int low[MAXN];
int pre[MAXN];
int sccno[MAXN];
int in[MAXN];
int out[MAXN];
int dfs_clock, scc_cnt;
stack<int> s;
vector<int> G[MAXN];

void dfs(int u)
{
    low[u] = pre[u] = ++dfs_clock;
    s.push(u);
    
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (!pre[v])
        {
            dfs(v);
            low[u] = min(low[v], low[u]);
        }
        else if (!sccno[v])
        {
            low[u] = min(low[u], pre[v]);
        }
    }
    
    int x;
    if (low[u] == pre[u])
    {
        scc_cnt++;
        while (1)
        {
            x = s.top();
            s.pop();
            sccno[x] = scc_cnt;
            if (x == u)
            {
                break;
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d%d", &n, &m);
        
        for (int i = 1; i <= n; i++)
        {
            G[i].clear();
        }
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        memset(sccno, 0, sizeof(sccno));
        memset(pre, 0, sizeof(pre));
        dfs_clock = 0, scc_cnt = 0;
        
        int u, v;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!pre[i])
            {
                dfs(i);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < G[i].size(); j++)
            {
                if (sccno[i] != sccno[G[i][j]])
                {
                    out[sccno[i]]++;
                    in[sccno[G[i][j]]]++;
                }
            }
        }
        
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= scc_cnt; i++)
        {
            if (in[i] == 0)
            {
                cnt1++;
            }
            if (out[i] == 0)
            {
                cnt2++;
            }
        }
        if (scc_cnt == 1)
        {
            puts("0");
        }
        else
        {
            printf("%d\n", max(cnt1, cnt2));
        }
    }
    
    return 0;
}
