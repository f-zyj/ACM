//
//  main.cpp
//  f-HDU-2962-Trucking
//
//  Created by ZYJ on 2016/12/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define MEM(a, v) memset (a, v, sizeof(a))

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1010;

struct edge
{
    int to;
    int hei, dis;
};

bool used[MAXN];
int	c, r;
int	dist[MAXN];

vector<edge> map[MAXN];

int spfa(int beg, int end, int lim)
{
    queue<int> q;
    edge e;
    
    MEM(dist, 0x3f);
    MEM(used, 0);
    
    q.push(beg);
    used[beg] = 1;
    dist[beg] = 0;
    
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        
        for (int i = 0; i < map[t].size(); ++i)
        {
            e = map[t][i];
            if (e.hei >= lim && dist[t] + e.dis < dist[e.to])
            {
                dist[e.to] = dist[t] + e.dis;
                if (!used[e.to])
                {
                    used[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
        used[t] = 0;
    }
    
    return dist[end];
}

void init ()
{
    for (int i = 1; i <= c; ++i)
    {
        map[i].clear();
    }
}

int main ()
{
    int key = 0;
    while (scanf("%d%d", &c, &r), c | r)
    {
        edge e;
        
        init();
        
        int x, y, h = 0, d;
        for (int i = 1; i <= r; ++i)
        {
            scanf("%d%d%d%d", &x, &y, &h, &d);
            h = (h == -1 ? INF : h);
            e.to = y;
            e.hei = h;
            e.dis = d;
            
            map[x].push_back(e);
            e.to = x;
            map[y].push_back(e);
        }
        
        int low = 1, mid, high;
        scanf("%d%d%d", &x, &y, &high);
        
        //  二分查找，暴力枚举所有高度
        int res = INF, ans = INF;
        while (low <= high)
        {
            mid = (low + high) / 2;
            res = spfa(x, y, mid);
            if (INF == res)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
                ans = res;
                h = mid;
            }
        }
        
        if (key)
        {
            putchar('\n');
        }
        printf("Case %d:\n", ++key);
        if (ans != INF)
        {
            printf("maximum height = %d\nlength of shortest route = %d\n", h, ans);
        }
        else
        {
            printf ("cannot reach destination\n");
        }
    }
    
    return 0 ;
}
