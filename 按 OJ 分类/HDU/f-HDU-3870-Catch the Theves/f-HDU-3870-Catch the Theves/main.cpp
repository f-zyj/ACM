//
//  main.cpp
//  f-HDU-3870-Catch the Theves
//
//  Created by ZYJ on 2016/12/12.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 170000;
const int INF = 0x3f3f3f3f;

struct point
{
    int v, w;
} Point;

vector<point> Edge[MAXN];

int n,S,T,q[MAXN];
int dist[MAXN];
bool inq[MAXN];

int SPFA()
{
    int head = 0, tail = 0;
    memset(inq, false, sizeof(inq));
    
    for (int i = 0; i <= (n - 1) * (n - 1) + 1; i++)
    {
        dist[i] = INF;
    }
    
    q[tail++] = S;
    dist[S] = 0;
    inq[S] = true;
    
    while (head != tail)
    {
        int k = q[head];
        head = (head + 1) % MAXN;
        inq[k] = false;
        for (int i = 0; i < Edge[k].size(); i++)
        {
            Point = Edge[k][i];
            if (dist[Point.v] > dist[k] + Point.w)
            {
                dist[Point.v] = dist[k] + Point.w;
                if (!inq[Point.v])
                {
                    inq[Point.v] = true;
                    q[tail] = Point.v;
                    tail = (tail + 1) % MAXN;
                }
            }
        }
    }
    return dist[T];
}

int main()
{
    int t;
    scanf("%d", &t);
    
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < (n - 1) * (n - 1) + 2; i++)
        {
            Edge[i].clear();
        }
        S = (n - 1) * (n - 1);
        T = (n - 1) * (n - 1) + 1;
        
        int w;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &w);
                Point.w = w;
                if (i == 0 && j != n - 1)
                {
                    Point.v = j;
                    Edge[S].push_back(Point);
                }
                else if (j == n - 1 && i != n - 1)
                {
                    Point.v = i * (n - 1) + j - 1;
                    Edge[S].push_back(Point);
                }
                
                if (j == 0 && i != n - 1)
                {
                    Point.v = T;
                    Edge[i * (n - 1)].push_back(Point);
                }
                else if (i == n - 1 && j != n - 1)
                {
                    Point.v = T;
                    Edge[(n - 2) * (n - 1) + j].push_back(Point);
                }
                
                if (i != n - 1 && j != n - 1)
                {
                    if (i)
                    {
                        Point.v = (i - 1) * (n - 1) + j;
                        Edge[i * (n - 1) + j].push_back(Point);
                        Point.v = i * (n - 1) + j;
                        Edge[(i - 1) * (n - 1) + j].push_back(Point);
                    }
                    if (j)
                    {
                        Point.v = i * (n - 1) + j - 1;
                        Edge[i * (n - 1) + j].push_back(Point);
                        Point.v = i * (n - 1) + j;
                        Edge[i * (n - 1) + j - 1].push_back(Point);
                    }
                }
            }
        }
        
        printf("%d\n", SPFA());
    }
    
    return 0;
}
