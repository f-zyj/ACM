//
//  main.cpp
//  f-51Nod-1515-明辨是非
//
//  Created by ZYJ on 2017/8/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <set>
#include <map>

using namespace std;

const int MAXN = 2e5 + 10;

int n, cnt = 1;
int pre[MAXN];
set<int> si[MAXN];
map<int, int> mii;

int find(int x)
{
    return pre[x] == x ? x : pre[x] = find(pre[x]);
}

int main()
{
    scanf("%d", &n);
    n <<= 1;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = i;
    }
    n >>= 1;
    
    int x, y, p;
    while (n--)
    {
        scanf("%d%d%d", &x, &y, &p);
        if (mii[x])
        {
            x = mii[x];
        }
        else
        {
            x = mii[x] = ++cnt;
        }
        if (mii[y])
        {
            y = mii[y];
        }
        else
        {
            y = mii[y] = ++cnt;
        }
        
        int u = find(x), v = find(y);
        if (p == 1)
        {
            if (si[u].count(v)) //  u 和 v 限制不相等
            {
                puts("NO");
            }
            else if (u != v)    //  未限制但并未相等
            {
                if (si[u].size() > si[v].size())
                {
                    swap(u, v);
                }
                pre[u] = v;
                for (auto it = si[u].begin(); it != si[u].end(); it++)
                {
                    si[*it].insert(v);
                    si[v].insert(*it);
                }
                puts("YES");
            }
            else
            {
                puts("YES");
            }
        }
        else
        {
            if (u == v)
            {
                puts("NO");
            }
            else
            {
                si[u].insert(v);
                si[v].insert(u);
                puts("YES");
            }
        }
    }
    
    return 0;
}
