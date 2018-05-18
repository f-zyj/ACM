//
//  main.cpp
//  f-[kuangbin带你飞]专题二-搜索进阶-D-Escape
//
//  Created by ZYJ on 2017/4/15.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 105;
const int MAXT = 1e3 + 10;
const int dir[5][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {0, 0}};

int m, n, k, d, res;

bool vis[MAXT][MAXN][MAXN];

struct castle
{
    char c;
    int t, v;
} cte[MAXN][MAXN];

struct node
{
    int x, y;
    int step;
    node(int x_, int y_, int s_) : x(x_), y(y_), step(s_) {}
};


void init()
{
    res = -1;
    memset(vis, 0, sizeof(vis));
    memset(cte, 0, sizeof(cte));
}

bool check(int x,int y)
{
    if (x >= 0 && x <= m && y >= 0 && y <= n)
    {
        return 1;
    }
    return 0;
}

void bfs()
{
    queue<node> Q;
    Q.push(node(0, 0, 0));
    vis[0][0][0] = 1;
    
    while (!Q.empty())
    {
        node q = Q.front();
        Q.pop();
        
        if (q.step > d)
        {
            return ;
        }
        if (q.x == m && q.y == n)
        {
            res = q.step;
            return ;
        }
        
        for (int i = 0; i < 5; i++)
        {
            node nd = q;
            nd.x += dir[i][0];
            nd.y += dir[i][1];
            nd.step++;
            if (!check(nd.x, nd.y))
            {
                continue;
            }
            if (!vis[nd.step][nd.x][nd.y] && !cte[nd.x][nd.y].t)
            {
                int flag = 1;
                int dis;
                
                for (int k = nd.x - 1; k >= 0; k--)
                {
                    if (cte[k][nd.y].t)
                    {
                        if (cte[k][nd.y].c == 'S')
                        {
                            dis = nd.x - k;
                            if (dis % cte[k][nd.y].v)
                            {
                                break;
                            }
                            int temp = dis / cte[k][nd.y].v;
                            if (nd.step < temp)
                            {
                                break;
                            }
                            temp = nd.step - temp;
                            if (temp % cte[k][nd.y].t)
                            {
                                break;
                            }
                            flag = 0;
                            break;
                        }
                        break;
                    }
                }
                if (!flag)
                {
                    continue;
                }
                
                for (int k = nd.x + 1; k <= m; k++)
                {
                    if (cte[k][nd.y].t)
                    {
                        if (cte[k][nd.y].c == 'N')
                        {
                            dis = k - nd.x;
                            if (dis % cte[k][nd.y].v)
                            {
                                break;
                            }
                            int temp = dis / cte[k][nd.y].v;
                            if (nd.step < temp)
                            {
                                break;
                            }
                            temp = nd.step - temp;
                            if (temp % cte[k][nd.y].t)
                            {
                                break;
                            }
                            flag = 0;
                            break;
                        }
                        break;
                    }
                }
                if (!flag)
                {
                    continue;
                }
                
                for (int k = nd.y + 1; k <= n; k++)
                {
                    if (cte[nd.x][k].t)
                    {
                        if (cte[nd.x][k].c == 'W')
                        {
                            dis = k - nd.y;
                            if (dis % cte[nd.x][k].v)
                            {
                                break;
                            }
                            int temp = dis / cte[nd.x][k].v;
                            if (nd.step < temp)
                            {
                                break;
                            }
                            temp = nd.step - temp;
                            if (temp % cte[nd.x][k].t)
                            {
                                break;
                            }
                            flag = 0;
                            break;
                        }
                        break;
                    }
                }
                if (!flag)
                {
                    continue;
                }

                for (int k = nd.y - 1; k >= 0; k--)
                {
                    if (cte[nd.x][k].t)
                    {
                        if (cte[nd.x][k].c == 'E')
                        {
                            dis = nd.y - k;
                            if (dis % cte[nd.x][k].v)
                            {
                                break;
                            }
                            int temp = dis / cte[nd.x][k].v;
                            if (nd.step < temp)
                            {
                                break;
                            }
                            temp = nd.step - temp;
                            if (temp % cte[nd.x][k].t)
                            {
                                break;
                            }
                            flag = 0;
                            break;
                        }
                        break;
                    }
                }
                
                if (flag)
                {
                    vis[nd.step][nd.x][nd.y] = 1;
                    Q.push(nd);
                }
            }
        }
    }
}

int main()
{
    while (~scanf("%d%d%d%d", &m, &n, &k, &d))
    {
        init();
        
        char c[3];
        int t, v, x, y;
        for (int i = 0; i < k; i++)
        {
            scanf("%s%d%d%d%d", c, &t, &v, &x, &y);
            cte[x][y].c = c[0];
            cte[x][y].t = t;
            cte[x][y].v = v;
        }
        
        bfs();
        
        if (res != -1)
        {
            printf("%d\n", res);
        }
        else
        {
            printf("Bad luck!\n");
        }
    }
    
    return 0;
}
