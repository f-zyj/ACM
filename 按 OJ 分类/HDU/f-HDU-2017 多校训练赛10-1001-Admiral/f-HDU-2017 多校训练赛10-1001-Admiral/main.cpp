//
//  main.cpp
//  f-HDU-2017 多校训练赛10-1001-Admiral
//
//  Created by ZYJ on 2017/8/29.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const int MAXM = 6;
const int MAX_STEPS = 20;
const int MAX_LIMIT = 10;
const int DIR[4][2] = {{-1, -1}, {-1, 0},
                      {1, 0}, {1, 1}};

struct node
{
    int val[MAXM][MAXM];
    int r, c;
    bool tp;
    int step;
} s, t;

ll _hash(node &t)
{
    ll tmp = 0;
    for (int i = 0; i < MAXM; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            tmp = tmp * MAXM + t.val[i][j];
        }
    }
    
    return tmp;
}

map<ll, int> mark[2];
queue<node> q;

int bfs(node &s, node &t)
{
    while (!q.empty())
    {
        q.pop();
    }
    
    mark[0].clear();
    mark[1].clear();
    s.tp = 0;
    t.tp = 1;
    s.step = t.step = 0;
    mark[s.tp][_hash(s)] = 0;
    mark[t.tp][_hash(t)] = 0;
    q.push(s);
    q.push(t);
    
    while (!q.empty())
    {
        node e = q.front(), x;
        q.pop();
        
        ll tmp = _hash(e);
        if (mark[!e.tp].count(tmp))
        {
            if (mark[!e.tp][tmp] + e.step <= MAX_STEPS)
            {
                return mark[!e.tp][tmp] + e.step;
            }
            else
            {
                continue;
            }
        }
        
        if (e.step >= MAX_LIMIT)
        {
            continue;   //  因为是双向搜索，所以限制是20/2
        }
        
        for (int i = 0; i < 4; i++)
        {
            x = e;
            x.r += DIR[i][0];
            x.c += DIR[i][1];
            if (x.r >= MAXM || x.c > x.r || x.c < 0 || x.r < 0)
            {
                continue;
            }
            
            swap(x.val[x.r][x.c], x.val[e.r][e.c]);
            tmp = _hash(x);
            if (mark[x.tp].count(tmp))
            {
                continue;
            }
            
            mark[x.tp][tmp] = ++x.step;
            q.push(x);
        }
    }
    
    return -1;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        for (int i = 0; i < MAXM; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                scanf("%d", &s.val[i][j]);
                if (s.val[i][j] == 0)
                {
                    s.r = i;
                    s.c = j;
                }
                t.val[i][j] = i;
            }
        }
        t.r = 0, t.c = 0;
        
        int ans = bfs(s, t);
        
        if (ans == -1)
        {
            puts("too difficult");
        }
        else
        {
            printf("%d\n", ans);
        }
    }
    
    return 0;  
}
