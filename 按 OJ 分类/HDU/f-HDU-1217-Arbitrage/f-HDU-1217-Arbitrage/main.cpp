//
//  main.cpp
//  f-HDU-1217-Arbitrage
//
//  Created by ZYJ on 2016/11/12.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//  WA
//#include <cstdio>
//#include <iostream>
//#include <string>
//#include <map>
//
//using namespace std;
//
//typedef double typec;
//
//map<string, int> money;
//
///*
// *  Floyd算法，求从任意节点i到任意节点j的最短路径
// *  edges[][]:初始化为0（edges[i][i]：初始化为1）
// */
//const int VertexNum = 30;
//
//typedef struct
//{
//    int N;                              //  图中当前的顶点数
//    typec edges[VertexNum][VertexNum];  //  邻接矩阵,可看做边表
//} MGraph;
//
//void Floyd(MGraph G)
//{
//    int i, j, k, n = G.N;
//
//    for (k = 1; k <= n; k++)
//    {
//        for (i = 1; i <= n; i++)
//        {
//            for (j = 1; j <= n; j++)
//            {
//                if (G.edges[i][j] < (G.edges[i][k] * G.edges[k][j]))
//                {
//                    G.edges[i][j] = G.edges[i][k] * G.edges[k][j];
//                }
//            }
//        }
//    }
//    
//    return ;
//}
//
//MGraph G;
//
//int main()
//{
//    int n, m;
//    string str, str_;
//    double r;
//    
//    int iCase = 0;
//    while (scanf("%d", &n), n)
//    {
//        iCase++;
//        G.N = n;
//        for (int i = 1; i <= n; i++)
//        {
//            cin >> str;
//            money[str] = i;
//        }
//        for (int i = 1; i <= n; i++)
//        {
//            for (int j = 1; j <= n; j++)
//            {
//                if (i == j)
//                {
//                    G.edges[i][j] = 1;
//                }
//                else
//                {
//                    G.edges[i][j] = 0;
//                }
//            }
//        }
//       
//        scanf("%d", &m);
//        while (m--)
//        {
//            cin >> str >> r >> str_;
//            G.edges[money[str]][money[str_]] = r;
//        }
//        
//        Floyd(G);
//        
//        bool flag = false;
//        for (int i = 1; i <= n; i++)
//        {
//            if (G.edges[i][i] > 1)
//            {
//                flag = true;
//                break;
//            }
//        }
//        if (flag)
//        {
//            printf("Case %d: Yes\n", iCase);
//        }
//        else
//        {
//            printf("Case %d: No\n", iCase);
//        }
//    }
//    
//    return 0;
//}

#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef double typec;

map<string, int> money;

/*
 *  Floyd算法，求从任意节点i到任意节点j的最短路径
 *  edges[][]:初始化为INF（edges[i][i]：初始化为0）
 */
const int MAXN = 33;

void Floyd(typec edges[][MAXN], int n)
{
    int i, j, k;
    
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (edges[i][j] < (edges[i][k] * edges[k][j]))
                {
                    edges[i][j] = edges[i][k] * edges[k][j];
                }
            }
        }
    }
    
    return ;
}

double edges[MAXN][MAXN];

int main()
{
    int n, m;
    string str, str_;
    double r;
    
    int iCase = 0;
    while (scanf("%d", &n), n)
    {
        iCase++;
        
        for (int i = 1; i <= n; i++)
        {
            cin >> str;
            money[str] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    edges[i][j] = 1;
                }
                else
                {
                    edges[i][j] = 0;
                }
            }
        }
        
        scanf("%d", &m);
        while (m--)
        {
            cin >> str >> r >> str_;
            edges[money[str]][money[str_]] = r;
        }
        
        Floyd(edges, n);
        
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            if (edges[i][i] > 1)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            printf("Case %d: Yes\n", iCase);
        }
        else
        {
            printf("Case %d: No\n", iCase);
        }
    }
    
    return 0;
}
