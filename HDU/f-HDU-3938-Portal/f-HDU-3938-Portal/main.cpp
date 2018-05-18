//
//  main.cpp
//  f-HDU-3938-Portal
//
//  Created by ZYJ on 2016/11/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 50010;

struct edge
{
    int s, t, len;
};

struct order
{
    int id, q, res;
};

order Order[MAXN * 2];
edge Edge[MAXN];

int num[MAXN / 5];
int pre[MAXN / 5];
int out[MAXN];

bool cmp(edge a, edge b)
{
    return a.len < b.len;
}

int find(int x)
{
    int i = x, root;
    while (x != pre[x])
    {
        x = pre[x];
    }
    
    root = x;
    x = i;
    while (x != pre[x])
    {
        i = pre[x];
        pre[x] = root;
        x = i;
    }
    return root;
}

int join(int s, int t)
{
    int a = find(s);
    int b = find(t);
    
    int sum = 0;
    if (a != b)
    {
        //  不连通则进行连通并构成sum点对
        sum = num[a] * num[b];
        
        pre[b] = a;
        num[a] += num[b];
    }

    return sum;
}

bool cmp_(order a, order b)
{
    return a.q < b.q;
}

int main()
{
    int n, m, q;
    
    while (~scanf("%d%d%d", &n, &m, &q))
    {
        memset(Order, 0, sizeof(Order));
        
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &Edge[i].s, &Edge[i].t, &Edge[i].len);
        }
        sort(Edge, Edge + m, cmp);
        
        for (int i = 0; i < q; i++)
        {
            scanf("%d", &Order[i].q);
            Order[i].id = i;
        }
        sort(Order, Order + q, cmp_);
        
        for (int i = 0; i <= n; i++)
        {
            pre[i] = i;
            num[i] = 1;
        }
        
        int cnt = 0;
        for (int i = 0; i < q; i++)
        {
            int ans = Order[i - 1].res;
            while (cnt < m && Edge[cnt].len <= Order[i].q)
            {
                int a = Edge[cnt].s;
                int b = Edge[cnt].t;
                ans += join(a, b);
                cnt++;
            }
            out[Order[i].id] = Order[i].res = ans;
        }
        for (int i = 0; i < q; i++)
        {
            printf("%d\n", out[i]);
        }
    }
    
    return 0;
}
