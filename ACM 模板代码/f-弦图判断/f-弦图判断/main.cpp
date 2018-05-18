//
//  main.cpp
//  f-弦图判断
//
//  Created by ZYJ on 16/7/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

/*
 *  弦图判断
 *  INIT: g[][]置为邻接矩阵;
 *  CALL: mcs(n); peo(n);
 *  第一步: 给节点编号 mcs(n)
 *  设已编号的节点集合为A, 未编号的节点集合为B
 *  开始时A为空, B包含所有节点.
 *  for num=n-1 downto 0 do {
 *      在B中找节点x, 使与x相邻的在A集合中的节点数最多,
 *      将x编号为num，并从B移入A。
 *  }
 *  第二部：检查peo(n)
 *  for num=0 to n-1 do {
 *      对编号为num的点x，设所有编号>num且与x相邻的点集为C
 *      在C中找出编号最小的节点y，
 *      若C中存在x != y，使得y与x之间无边，则此图不是弦图。
 *  }
 *  检查完毕, 则此图是弦图.
 */
const int V = 10010;
int g[V][V], order[V], inv[V], tag[V];

void mcs(int n)
{
    int i, j, k;
    memset(tag, 0, sizeof(tag));
    memset(order, -1, sizeof(order));
    for (i = n - 1; i >= 0; i--)
    {   //  vertex:0~n-1
        for (j = 0; order[j] >= 0; j++);
        for (k = j + 1; k < n; k++)
        {
            if (order[k] < 0 && tag[k] > tag[j])
            {
                j = k;
            }
        }
        order[j] = i, inv[i] = j;
        for (k = 0; k < n; k++)
        {
            if (g[j][k])
            {
                tag[k]++;
            }
        }
    }
    return ;
}

int peo(int n)
{
    int i, j, k, w, min;
    for (i = n - 2; i >= 0; i--)
    {
        j = inv[i], w = -1, min = n;
        for (k = 0; k < n; k++)
        {
            if (g[j][k] && order[k] > order[j] && order[k] < min)
            {
                min = order[k], w=k;
            }
        }
        if (w < 0)
        {
            continue;
        }
        for (k = 0; k < n; k++)
        {
            if (g[j][k] && order[k] > order[w] && !g[k][w])
            {
                return 0;   //  no
            }
        }
    }
    return 1;               //  yes
}