//
//  main.cpp
//  f-NYOJ-1276-机器设备
//
//  Created by ZYJ on 2017/5/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 1111;
const double ESP = 1e-6;
const double INITE = 10000;    //  驱动轮能量

int N;
double Xt, Yt;
int root = -1, last = -1;

struct gear
{
    int pos;
    double x, y, r;
    double e, sum;
    int flag;
} gr[MAXN];

vector<int> vi[MAXN];

int charge(int i, int j)
{
    double a = (gr[i].x - gr[j].x) * (gr[i].x - gr[j].x);
    double b = (gr[i].y - gr[j].y) * (gr[i].y - gr[j].y);
    double c = (gr[i].r + gr[j].r) * (gr[i].r + gr[j].r);
    if (fabs(a + b - c) < ESP)
    {
        return 1;
    }
    return 0;
}

void bfs()
{
    queue<gear> qg;
    qg.push(gr[root]);
    while (!qg.empty())
    {
        gear g = qg.front();
        qg.pop();
        for (int i = 0; i < vi[g.pos].size(); i++)
        {
            int pos = gr[vi[g.pos][i]].pos;
            if (!gr[pos].flag)
            {
                gr[pos].flag = 1;
                gr[pos].e = -gr[g.pos].e * gr[g.pos].r / gr[pos].r;
                gr[pos].sum = gr[g.pos].sum + fabs(gr[pos].e);
                if (pos == last)
                {
                    printf("%d\n", (int)gr[pos].sum);
                    return ;
                }
                qg.push(gr[pos]);
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        for (int i = 0; i < MAXN; i++)
        {
            vi[i].clear();
        }
        
        cin >> N >> Xt >> Yt;
        for (int i = 0; i < N; i++)
        {
            scanf("%lf%lf%lf", &gr[i].x, &gr[i].y, &gr[i].r);
            gr[i].pos = i;
            gr[i].flag = 0;
            if (gr[i].x == 0 && gr[i].y == 0)
            {
                root = i;
                gr[i].e = INITE;
                gr[i].sum = INITE;
                gr[i].flag = 1;
            }
            if (gr[i].x == Xt && gr[i].y == Yt)
            {
                last = i;
            }
        }
        
        if (root == last)
        {
            cout << INITE << '\n';
            continue;
        }
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0;	j < N; j++)
            {
                if (i != j && charge(i, j))
                {
                    vi[i].push_back(j);
                    vi[j].push_back(i);
                }
            }
        }
        
        bfs();
    }
    
    return 0;
}
