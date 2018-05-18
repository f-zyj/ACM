//
//  main.cpp
//  f-HDU-5877-Weak Pair
//
//  Created by ZYJ on 2017/5/16.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 10;

typedef long long ll;

vector<int> vi[MAXN];

ll ans, k;
ll num[MAXN * 2];
ll c[MAXN * 2];
ll data[MAXN * 2];
int vis[MAXN * 2];
int n, len;

void prepare()
{
    for (int i = 1; i <= 2 * n; i++)
    {
        data[i] = num[i];
    }
    sort(data + 1, data + 2 * n + 1);
    int m = (int)(unique(data + 1, data + 2 * n + 1) - data - 1);   //  去重
    
    for (int i = 1; i <= 2 * n; i++)
    {
        num[i] = lower_bound(data + 1, data + m + 1, num[i]) - data;
    }
}

ll lowbit(ll x)             //  计算lowbit
{
    return x & (-x);
}

void add(ll k, int val)     //  将第 k 个元素值加 val
{
    while (k <= 2 * n)
    {
        c[k] += val;
        k += lowbit(k);
    }
}

int sum(ll x)               //  求前x项和
{
    int s = 0;
    while (x > 0)
    {
        s += c[x];
        x -= lowbit(x);
    }
    return s;
}

void dfs(int s, int cnt = 0)
{
    int m = (int)vi[s].size();
    int cnt_ = sum(num[s] - 1);
    
    ans += cnt - cnt_;
    
    cnt++;
    add(num[s + n], 1);
    for (int i = 0; i < m; i++)
    {
        int u = vi[s][i];
        dfs(u, cnt);
    }
    add(num[s + n], -1);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        memset(c, 0, sizeof(c));
        for (int i = 0; i <= n; i++)
        {
            vi[i].clear();
        }
        
        scanf("%d%lld",&n, &k);
        
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", num + i);
            num[i + n] = k / num[i];
        }
        prepare();
        
        int a, b;
        for (int i = 0; i < n - 1; i++)
        {
            scanf("%d%d", &a, &b);
            vi[a].push_back(b);
            vis[b]++;           //  入度
        }
        
        int s = -1;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)    //  入度为0的为根
            {
                s = i;
                break;
            }
        }
        
        dfs(s);
        
        printf("%lld\n", ans);
    }
    
    return 0;  
}
