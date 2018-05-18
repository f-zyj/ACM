//
//  main.cpp
//  f-HDU-3549-Flow Problem
//
//  Created by ZYJ on 2017/3/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

/*
 *  Dinic 最大流 O(V^2 * E)
 *  INIT: ne=2; head[]置为0; addedge()加入所有弧;
 *  CALL: flow(n, s, t);
 */
#define typec int               //  type of cost

using namespace std;

const typec inf = 0x3f3f3f3f;   // max of cost
const typec MAXE = 2010;
const typec MAXN = 1010;

struct edge
{
    int x, y, nxt;
    typec c;
} bf[MAXE];

int ne, head[MAXN], cur[MAXN], ps[MAXN], dep[MAXN];

void addedge(int x, int y, typec c)
{   //  add an arc(x->y, c);    vertex:0~n-1;
    bf[ne].x = x;
    bf[ne].y = y;
    bf[ne].c = c;
    bf[ne].nxt = head[x];
    head[x] = ne++;
    bf[ne].x = y;
    bf[ne].y = x;
    bf[ne].c = 0;
    bf[ne].nxt = head[y];
    head[y] = ne++;
    return ;
}

typec flow(int n, int s, int t)
{
    typec tr, res = 0;
    int i, j, k, f, r, top;
    while (1)
    {
        memset(dep, -1, n * sizeof(int));
        for (f = dep[ps[0] = s] = 0, r = 1; f != r;)
        {
            for (i = ps[f++], j = head[i]; j; j = bf[j].nxt)
            {
                if (bf[j].c && -1 == dep[k = bf[j].y])
                {
                    dep[k] = dep[i] + 1;
                    ps[r++] = k;
                    if (k == t)
                    {
                        f = r;
                        break;
                    }
                }
            }
        }
        if (-1 == dep[t])
        {
            break;
        }
        memcpy(cur, head, n * sizeof(int));
        for (i = s, top = 0; ;)
        {
            if (i == t)
            {
                for (k = 0, tr = inf; k < top; ++k)
                {
                    if (bf[ps[k]].c < tr)
                    {
                        tr = bf[ps[f = k]].c;
                    }
                }
                for (k = 0; k < top; ++k)
                {
                    bf[ps[k]].c -= tr, bf[ps[k]^1].c += tr;
                }
                res += tr;
                i = bf[ps[top = f]].x;
            }
            for (j = cur[i]; cur[i]; j = cur[i] = bf[cur[i]].nxt)
            {
                if (bf[j].c && dep[i] + 1 == dep[bf[j].y])
                {
                    break;
                }
            }
            if (cur[i])
            {
                ps[top++] = cur[i];
                i = bf[cur[i]].y;
            }
            else
            {
                if (0 == top)
                {
                    break;
                }
                dep[i] = -1;
                i = bf[ps[--top]].x;
            }
        }
    }
    return res;
}

int E, N;

int main()
{
    int T;
    cin >> T;
    
    for (int i = 1; i <= T; i++)
    {
        cin >> N >> E;
        
        ne = 2;
        memset(head, 0, sizeof(head));
        
        int s, t;
        typec w;
        while (E--)
        {
            scanf("%d%d%d", &s, &t, &w);
            addedge(s - 1, t - 1, w);
        }
        
        typec ans = flow(N, 0, N - 1);
        
        printf("Case %d: %d\n", i, ans);
    }
    
    return 0;
}
