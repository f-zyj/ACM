//
//  main.cpp
//  f-HDU-2017 多校训练赛1-1006-Function
//
//  Created by ZYJ on 2017/7/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

const int MAXM = 1e5 + 7;
const int MOD = 1e9 + 7;

struct Node
{
    int from;
    int to;
    int next;
} st[MAXM];

int n, m;
int sccno[MAXM];
int num[MAXM];
int pre[MAXM];
int low[MAXM];
int num_A[MAXM];
int num_B[MAXM];
int head[MAXM];
int dfs_clock, scc_cnt, cnt_A, cnt_B, tol;

stack<int> s;

void Tarjan(int u)
{
    pre[u] = low[u] = ++dfs_clock;
    s.push(u);
    for (int i = head[u]; i != -1; i = st[i].next)
    {
        int v = st[i].to;
        if (!pre[v])
        {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (!sccno[v])
        {
            low[u] = min(low[u], pre[v]);
        }
    }
    if (low[u] == pre[u])
    {
        scc_cnt++;
        for (; ; )
        {
            int x = s.top();
            s.pop();
            num[scc_cnt]++;
            sccno[x] = scc_cnt;
            if (x == u)
            {
                break;
            }
        }
    }
}

void init()
{
    scc_cnt = dfs_clock = tol = 0;
    memset(head, -1, sizeof(head));
    memset(sccno, 0, sizeof(sccno));
    memset(num, 0, sizeof(num));
    memset(pre, 0, sizeof(pre));
}

int solve()
{
    int ans = 1;
    for (int i = 0; i < cnt_A; i++)
    {
        int tmp = 0;
        for (int j = 0; j < cnt_B; j++)
        {
            if (num_A[i] >= num_B[j] && num_A[i] % num_B[j] == 0)
            {
                tmp += num_B[j];
                tmp %= MOD;
            }
        }
        
        ans = (ans * tmp) % MOD;
    }
    
    return ans;
}

void AddEdge(int u, int v)
{
    st[tol].from = u;
    st[tol].to = v;
    st[tol].next = head[u];
    head[u] = tol++;
}

int main()
{
    int ce = 0, x;
    while (~scanf("%d%d", &n, &m))
    {
        init();
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            AddEdge(i, x);
        }
        for (int i = 0; i < n; i++)
        {
            if (!pre[i])
            {
                Tarjan(i);
            }
        }
        cnt_A = scc_cnt;
        for (int i = 1; i <= scc_cnt; i++)
        {
            num_A[i - 1] = num[i];
        }
        
        init();
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &x);
            AddEdge(i, x);
        }
        for (int i = 0; i < m; i++)
        {
            if (!pre[i])
            {
                Tarjan(i);
            }
        }
        for (int i = 1; i <= scc_cnt; i++)
        {
            num_B[i - 1] = num[i];
        }
        cnt_B = scc_cnt;
        
        printf("Case #%d: ", ++ce);
        
        printf("%d\n", solve());
    }
    
    return 0;
}
