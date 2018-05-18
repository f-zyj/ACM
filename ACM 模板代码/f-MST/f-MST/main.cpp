//
//  main.cpp
//  f-MST
//
//  Created by ZYJ on 16/7/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

/* 
 *  Minimal Steiner Tree
 *  G(V, E), A是V的一个子集, 求至少包含A中所有点的最小子树. 
 *  时间复杂度:O(N^3+N*2^A*(2^A+N))
 *  INIT: d[][]距离矩阵; id[]置为集合A中点的标号;
 *  CALL: steiner(int n, int a);
 *  给4个点对(a1,b1)...(a4,b4),
 *  求min(sigma(dist[ai][bi])),其中重复的路段只能算一次.
 *  这题要找出一个steiner森林, 最后要对森林中树的个数进行枚举
 */
#define typec int               //  type of cost
const typec inf = 0x3f3f3f3f;   //  max of cost
const typec V = 10010;
const typec A = 10;

int vis[V], id[A];              //  id[]:       A中点的标号
typec d[V][V], dp[1 << A][V];   //  dp[i][v]:   点v到点集i的最短距离

void steiner(int n, int a)
{
    int i, j, k, mx, mk = 0, top = (1 << a);
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    for (i = 0; i < a; i++)
    {
        //  vertex: 0 ~ n-1
        for (j = 0; j < n; j++)
        {
            dp[1 << i][j] = d[j][id[i]];
        }
    }
    for (i = 1; i < top; i++)
    {
        if (0 == (i & (i - 1)))
        {
            continue;
        }
        memset(vis, 0, sizeof(vis));
        for (k = 0; k < n; k++) //  init
        {
            for (dp[i][k] = inf, j = 1; j < i; j++)
            {
                if ((i | j) == i && dp[i][k] > dp[j][k] + dp[i - j][k])
                {
                    dp[i][k] = dp[j][k] + dp[i - j][k];
                }
            }
        }
        for (j = 0; mx = inf, j < n; j++)
        {
            //  update
            for (k = 0; k < n; k++)
            {
                if (dp[i][k] <= mx && 0 == vis[k])
                {
                    mx = dp[i][mk = k];
                }
            }
            for (k = 0, vis[mk] = 1; k < n; k++)
            {
                if (dp[i][mk] > dp[i][k] + d[k][mk])
                {
                    dp[i][mk] = dp[i][k] + d[k][mk];
                }
            }
        }
    }
    return ;
}

int main(int argc, const char * argv[])
{
    
    int n, a = 8;
    int b, z, i, j, k, x = 0, y;
    // TODO: read data;
    steiner(n, a);
    // enum to find the result
    for (i = 0, b = inf; z = 0, i < 256; b > z ? b = z : b, i++)
    {
        for (j = 0; y = 0, j < 4; z += !!y * dp[y][x], j++)
        {
            for (k = 0; k < 8; k += 2)
            {
                if ((i >> k & 3) == j)
                {
                    y += 3 << k, x = id[k];
                }
            }
        }
    }
    // TODO: cout << b << endl;
    return 0;
}
