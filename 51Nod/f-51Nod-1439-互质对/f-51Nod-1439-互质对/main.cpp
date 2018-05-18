//
//  main.cpp
//  f-51Nod-1439-互质对
//
//  Created by ZYJ on 2017/8/31.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 5e5 + 5;

int n, q, tag;
long long ans;
int cnt[MAXN];
int vis[MAXN];
int a[MAXN];
int flag[MAXN];
vector<int> prime[MAXN];

void dfs(int pos, int mul, int sym, int flag)
{
    if (pos == prime[tag].size())
    {
        if (flag == -1)
        {
            cnt[mul]--;
        }
        ans += sym * cnt[mul];
        
        if (flag == 1)
        {
            cnt[mul]++;
        }
        
        return ;
    }
    
    dfs(pos + 1, mul, sym, flag);
    dfs(pos + 1, mul * prime[tag][pos], -sym, flag);
}

void init()
{
    for (int i = 2; i < MAXN; i++)
    {
        if (vis[i])
        {
            continue;
        }
        for (int j = i; j < MAXN; j = j + i)
        {
            vis[j] = 1;
            prime[j].push_back(i);
        }
    }
}

int main()
{
    init();
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
    }
    
    ans = 0;
    int x;
    for (int i = 1; i <= q; i++)
    {
        scanf("%d", &x);
        if (flag[x] == 0)
        {
            flag[x] = 1;
            tag = a[x];
            dfs(0, 1, 1, 1);
        }
        else
        {
            flag[x] = 0;
            tag = a[x];
            dfs(0, 1, -1, -1);
        }
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
