//
//  main.cpp
//  f-次小生成树
//
//  Created by ZYJ on 16/6/8.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace::std;

//Prim拓展

/*
 * 求最小生成树时，用数组MAX[i][j]表示i到j的最大边权
 * 求完后，直接枚举所有不在MST中的边，替换掉最大边权的边，更新答案
 * 点的编号从0开始
 */
 
const int MAXN = 110;
const int INF = 0x3f3f3f3f;

bool vis[MAXN];
int lowc[MAXN];
int pre[MAXN];
int MAX[MAXN][MAXN];
bool used[MAXN][MAXN];

int Prim(int cost[][MAXN], int n)
{
    int ans = 0;
    memset(vis, false, sizeof(vis));
    memset(MAX, 0, sizeof(MAX));
    memset(used, false, sizeof(used));
    vis[0] = true;
    pre[0] = -1;
    lowc[0] = 0;
    
    for (int i = 1; i < n; i++)
    {
        lowc[i] = cost[0][i];
        pre[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        int minc = INF;
        int p = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && minc > lowc[j])
            {
                minc = lowc[j];
                p = j;
            }
        }
        if (minc == INF)
        {
            return -1;
        }
        ans += minc;
        vis[p] = true;
        used[p][pre[p]] = used[pre[p]][p] = true;
        for (int j = 0; j < n; j++)
        {
            if (vis[j])
            {
                MAX[j][p] = MAX[p][j] = max(MAX[j][pre[p]], lowc[p]);
            }
            if (!vis[j] && lowc[j] > cost[p][j])
            {
                lowc[j] = cost[p][j];
                pre[j] = p;
            }
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
