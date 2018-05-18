////
////  main.cpp
////  f-51Nod-1366-贫富差距
////
////  Created by ZYJ on 16/9/12.
////  Copyright © 2016年 ZYJ. All rights reserved.
////
//
//#include <iostream>
//#include <cstring>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 55;
//const int INF = 0x3f3f3f3f;
//
//int N, d;
//char people[MAXN];
//
//typedef struct
//{
//    int N, E;
//    int relation[MAXN][MAXN];
//} MGraph;
//
//int pre[MAXN];
//bool root[MAXN];
//MGraph G;
//
//int Floyd(MGraph G)
//{
//    int A[MAXN][MAXN];
//    int path[MAXN][MAXN];
//    
//    for (int i = 1; i <= G.N; i++)
//    {
//        for (int j = 1; j <= G.N; j++)
//        {
//            A[i][j] = G.relation[i][j];
//            path[i][j] = -1;
//        }
//    }
//    for (int k = 1; k <= G.N; k++)
//    {
//        for (int i = 1; i <= G.N; i++)
//        {
//            for (int j = 1; j <= G.N; j++)
//            {
//                if (A[i][j] > A[i][k] + A[k][j])
//                {
//                    A[i][j] = A[i][k] + A[k][j];
//                    path[i][j] = k;
//                }
//            }
//        }
//    }
//    int res = -1;
//    for (int i = 1; i <= N; i++)
//    {
//        for (int j = 1; j <= N; j++)
//        {
//            if (A[i][j] != INF)
//            {
//                if (A[i][j] > res)
//                {
//                    res = A[i][j];
//                }
//            }
//        }
//    }
//    return res;
//}
//
//void init()
//{
//    for (int i = 1; i <= N; i++)
//    {
//        pre[i] = i;
//    }
//    
//    memset(G.relation, 0x3f, sizeof(G.relation));
//    G.N = N;
//    G.E = 0;
//    
//    memset(root, false, sizeof(root));
//    return ;
//}
//
//int find(int x)
//{
//    int r = x;
//    while (r != pre[r])
//    {
//        r = pre[r];
//    }
//    
//    int s = x, tmp;
//    while (pre[s] != r)
//    {
//        tmp = pre[s];
//        pre[s] = r;
//        s = tmp;
//    }
//    return r;
//}
//
//void join(int x, int y)
//{
//    int fx = find(x);
//    int fy = find(y);
//    if (fx != fy)
//    {
//        pre[fx] = fy;
//    }
//    return ;
//}
//
//int main(int argc, const char * argv[])
//{
//    int T;
//    cin >> T;
//    while (T--)
//    {
//        cin >> N >> d;
//        
//        init();
//        
//        for (int i = 0; i < N; i++)
//        {
//            scanf("%s", people);
//            for (int j = 0; j < N; j++)
//            {
//                if (people[j] == 'Y')
//                {
//                    G.relation[i + 1][j + 1] = 1; //  默认路径长度为1
//                    G.E++;
//                    join(i + 1, j + 1);
//                }
//                else if (i == j)
//                {
//                    G.relation[i + 1][j + 1] = 0;
//                }
//            }
//        }
//        
//        for (int i = 1; i <= N; i++)
//        {
//            root[find(i)] = true;
//        }
//        int res = 0;
//        for (int i = 1; i <= N; i++)
//        {
//            if (root[i])
//            {
//                res++;
//            }
//        }
//        
//        //  如果连通块超过一个则输出-1
//        if (res > 1)
//        {
//            cout << "-1\n";
//            continue;
//        }
//        
//        int ans = Floyd(G);
//        
//        cout << ans * d << '\n';
//    }
//    
//    return 0;
//}

#include <iostream>

/*
 *  Floyd算法，求从任意节点i到任意节点j的最短路径
 */
const int VertexNum = 100;

typedef struct
{
    char vertex[VertexNum];             //  顶点表
    int edges[VertexNum][VertexNum];    //  邻接矩阵,可看做边表
    int N, E;                           //  图中当前的顶点数和边数
} MGraph;

void Floyd(MGraph G)
{
    int A[VertexNum][VertexNum];
    int path[VertexNum][VertexNum];
    int i, j, k, n = G.N;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            A[i][j] = G.edges[i][j];
            path[i][j] = -1;
        }
        for (k = 0; k < n; k++)
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    if (A[i][j] > (A[i][k] + A[k][j]))
                    {
                        A[i][j] = A[i][k] + A[k][j];
                        path[i][j] = k;
                    }
                }
            }
        }
    }
    return ;
}