//
//  main.cpp
//  f-51Nod-1460-连接小岛
//
//  Created by ZYJ on 2016/9/23.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f

const int MAXN = 2e5 + 5;

struct node
{
    ll le, ri, id;
    
    bool operator < (const node &n)
    {
        if (ri == n.ri)
        {
            return le < n.le;
        }
        else
        {
            return ri < n.ri;
        }
    }
} island[MAXN], Node[MAXN];

int n, m, pos;
ll res[MAXN];
multiset<pair<ll, int> > bridge;
multiset<pair<ll, int> >::iterator it;

void input()
{
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &island[i].le, &island[i].ri);
    }
    pos = 0;
    for (int i = 2; i <= n; i++)
    {
        pos++;
        Node[pos].le = island[i].le - island[i - 1].ri;
        Node[pos].ri = island[i].ri - island[i - 1].le;
        Node[pos].id = pos;
    }
    sort(Node + 1, Node + pos + 1);
    
    ll t;
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld", &t);
        bridge.insert({t, i});
    }
    
    return ;
}

void solve()
{
    for (int i = 1; i <= pos; i++)
    {
        it = bridge.lower_bound({Node[i].le, 0});   //  求出大于等于node[i].le的第一个值
        if (it == bridge.end() || it->first > Node[i].ri)
        {
            puts("NO");
            return;
        }
        res[Node[i].id] = it->second;
        bridge.erase(it);
    }
    puts("YES");
    return ;
}

int main()
{
    input();
    solve();
    
    return 0;
}
