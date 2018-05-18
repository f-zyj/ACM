//
//  main.cpp
//  f-有向图最小树形图
//
//  Created by ZYJ on 16/7/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 *  有向图最小树形图
 *  INIT: eg置为边表；res置为0；cp[i]置为i；
 *  CALL: dirTree(root, nv, ne); res是结果
 */

#define typec int               // type of res
const typec V = 1010;
const typec E = 10010;
const typec inf = 0x3f3f3f3f;   // max of res

typec res, dis[V];
int to[V], cp[V], tag[V];

struct Edge
{
    int u, v;
    typec c;
} eg[E];

int iroot(int i)
{
    if (cp[i] == i)
    {
        return i;
    }
    return cp[i] = iroot(cp[i]);
}

int dirTree(int root, int nv, int ne)   //  root:树根
{
    //  vertex:0~n-1
    int i, j, k, circle = 0;
    memset(tag, -1, sizeof(tag));
    memset(to, -1, sizeof(to));
    for (i = 0; i < nv; i++)
    {
        dis[i] = inf;
    }
    for (j = 0; j < ne; j++)
    {
        i = iroot(eg[j].u);
        k = iroot(eg[j].v);
        if (k != i && dis[k] > eg[j].c)
        {
            dis[k] = eg[j].c;
            to[k] = i;
        }
    }
    to[root] = -1;
    dis[root] = 0;
    tag[root] = root;
    for (i = 0; i < nv; i++)
    {
        if (cp[i] == i && -1 == tag[i])
        {
            j = i;
            for (; j != -1 && tag[j] == -1; j = to[j])
            {
                tag[j] = i;
                if (j == -1)
                {
                    return 0;
                }
                if (tag[j] == i)
                {
                    circle = 1;
                    tag[j] = -2;
                    for (k = to[j]; k != j; k = to[k])
                    {
                        tag[k] = -2;
                    }
                }
            }
        }
    }
    if (circle)
    {
        for (j = 0; j < ne; j++)
        {
            i = iroot(eg[j].u);
            k = iroot(eg[j].v);
            if (k != i && tag[k] == -2)
            {
                eg[j].c -= dis[k];
            }
        }
        for (i = 0; i < nv; i++)
        {
            if (tag[i] == -2)
            {
                res += dis[i];
                tag[i] = 0;
                for (j = to[i]; j != i; j = to[j])
                {
                    res += dis[j];
                    cp[j] = i;
                    tag[j] = 0;
                }
            }
        }
        if (0 == dirTree(root, nv, ne))
        {
            return 0;
        }
    }
    else
    {
        for (i = 0; i < nv; i++)
        {
            if (cp[i] == i)
            {
                res += dis[i];
            }
        }
    }
    return 1;   //  若返回0代表原图不连通
}

