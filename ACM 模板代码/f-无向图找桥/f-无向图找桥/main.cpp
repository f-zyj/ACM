//
//  main.cpp
//  f-无向图找桥
//
//  Created by ZYJ on 16/6/13.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

//无向图找桥

/*
 * 无向图找桥
 * INIT: edge[][]邻接矩阵；vis[],pre[],ans[],bridge置0；
 * CALL: dfs(0, -1, 1, n);
 */

//const int V = 1010;
//
//int bridge; //桥
//int edge[V][V];
//int ans[V];
//int pre[V];
//int vis[V];
//
//void dfs(int cur, int father, int dep, int n)
//{
//    //vertex: 0 ~ n - 1
//    if (bridge)
//    {
//        return ;
//    }
//    vis[cur] = 1;
//    pre[cur] = ans[cur] = dep;
//    
//    for (int i = 0; i < n; i++)
//    {
//        if (edge[cur][i])
//        {
//            if (i != father && 1 == vis[i])
//            {
//                if (pre[i] < ans[cur])
//                {
//                    ans[cur] = pre[i];  //back edge
//                }
//            }
//            if (0 == vis[i])    //tree edge
//            {
//                dfs(i, cur, dep + 1, n);
//                if (bridge)
//                {
//                    return ;
//                }
//                if (ans[i] < ans[cur])
//                {
//                    ans[cur] = ans[i];
//                }
//                if (ans[i] > pre[cur])
//                {
//                    bridge = 1;
//                    return ;
//                }
//            }
//        }
//    }
//    vis[cur] = 2;
//    return ;
//}

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
