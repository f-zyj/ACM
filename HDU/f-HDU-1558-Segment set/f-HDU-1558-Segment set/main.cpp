//
//  main.cpp
//  f-HDU-1558-Segment set
//
//  Created by ZYJ on 2016/11/4.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

const double eps = 1e-10;
const int MAXN = 1010;

struct point
{
    double x, y;
};

struct edge
{
    point a;
    point b;
};

int pre[MAXN];
int res[MAXN];
struct edge Edge[MAXN];

double min(double a, double b)
{
    return a < b ? a : b;
}

double max(double a, double b)
{
    return a > b ? a : b;
}

bool inter(point a, point b, point c, point d)
{
    if (min(a.x, b.x) > max(c.x, d.x) || min(a.y, b.y) > max(c.y, d.y) || min(c.x, d.x) > max(a.x, b.x) || min(c.y, d.y) > max(a.y, b.y))
    {
        return 0;
    }
    double h, i, j, k;
    h = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    i = (b.x - a.x) * (d.y - a.y) - (b.y - a.y) * (d.x - a.x);
    j = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);
    k = (d.x - c.x) * (b.y - c.y) - (d.y - c.y) * (b.x - c.x);
    return h * i <= eps && j * k <= eps;
}

int find(int x)
{
    int r = x;
    while (pre[r] != r)
    {
        r = pre[r];
    }
    
    int i = x, j;
    while (i != r)
    {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}

void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    
    if (fx != fy)
    {
        pre[fx] = fy;
        res[fy] += res[fx];
    }

}

int main(int argc, const char * argv[])
{
    int T;
    scanf("%d", &T);
    
    char order[2];
    int key;
    int n;
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i <= n; i++)
        {
            pre[i] = i;
            res[i] = 1;
        }
        
        int lines = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", order);
            if (order[0] == 'P')
            {
                lines++;
                scanf("%lf%lf%lf%lf", &Edge[lines].a.x, &Edge[lines].a.y,
                      &Edge[lines].b.x, &Edge[lines].b.y);
                for (int j = 1; j < lines; j++)
                {
                    if (inter(Edge[lines].a, Edge[lines].b, Edge[j].a, Edge[j].b))
                    {
                        join(lines, j);
                    }
                }
            }
            else
            {
                scanf("%d", &key);
                printf("%d\n", res[find(key)]);
            }
        }
        if (T)  //  除了最后一组结尾都要输出空行
        {
            puts("");
        }
    }
    
    return 0;
}
