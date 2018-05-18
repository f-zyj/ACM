//
//  main.cpp
//  f-二分图匹配
//
//  Created by ZYJ on 16/7/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//  //  匈牙利算法

//  邻接矩阵+DFS

///*
// *  初始化:g[][]两边顶点的划分情况 
// *  建立g[i][j]表示i->j的有向边就可以了,是左边向右边的匹配 
// *  g没有边相连则初始化为0
// *  uN是匹配左边的顶点数,vN是匹配右边的顶点数 
// *  调用:res=hungary();输出最大匹配数 
// *  优点:适用于稠密图,DFS找增广路,实现简洁易于理解
// *  时间复杂度:O(VE) 
// */
////顶点编号从0开始的
//const int MAXN = 510;
//int uN, vN;         //  u,v的数目,使用前面必须赋值
//int g[MAXN][MAXN];  //  邻接矩阵
//int linker[MAXN];
//bool used[MAXN];
//bool dfs(int u)
//{
//    for (int v = 0; v < vN; v++)
//    {
//        if (g[u][v] && !used[v])
//        {
//            used[v] = true;
//            if (linker[v] == -1 || dfs(linker[v]))
//            {
//                linker[v] = u;
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//int hungary()
//{
//    int res = 0;
//    memset(linker,-1,sizeof(linker));
//    for (int u = 0; u < uN; u++)
//    {
//        memset(used, false, sizeof(used));
//        if (dfs(u))
//        {
//            res++;
//        }
//    }
//    return res;
//}

//  邻接表+DFS

/*
 *  使用前用init()进行初始化,给uN赋值
 *  加边使用函数addedge(u,v)
 */
//const int MAXN = 5010;  //  点数的最大值
//const int MAXM = 50010; //  边数的最大值
//
//struct Edge
//{
//    int to, next;
//} edge[MAXM];
//
//int head[MAXN], tot;
//
//void init()
//{
//    tot = 0;
//    memset(head, -1, sizeof(head));
//    return ;
//}
//
//void addedge(int u, int v)
//{
//    edge[tot].to = v;
//    edge[tot].next = head[u];
//    head[u] = tot++;
//    return ;
//}
//
//int linker[MAXN];
//bool used[MAXN];
//int uN;
//
//bool dfs(int u)
//{
//    for (int i = head[u]; i != -1; i = edge[i].next)
//    {
//        int v = edge[i].to;
//        if (!used[v])
//        {
//            used[v] = true;
//            if (linker[v] == -1 || dfs(linker[v]))
//            {
//                linker[v] = u;
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//int hungary()
//{
//    int res = 0;
//    memset(linker, -1, sizeof(linker));
//    for (int u = 0; u < uN; u++)    //  点的编号0~uN-1
//    {
//        memset(used, false, sizeof(used));
//        if (dfs(u))
//        {
//            res++;
//        }
//    }
//    return res;
//}

//  邻接矩阵+BFS

///*
// *  INIT: g[][]邻接矩阵;
// *  CALL: res = MaxMatch();Nx, Ny初始化!!! 
// *  优点:适用于稀疏二分图,边较少,增广路较短。
// *  匈牙利算法的理论复杂度是O(VE)
// */
//const int MAXN = 1000;
//int g[MAXN][MAXN], Mx[MAXN], My[MAXN], Nx, Ny;
//int chk[MAXN], Q[MAXN], prev[MAXN];
//
//int MaxMatch()
//{
//    int res = 0;
//    int qs, qe;
//    memset(Mx, -1, sizeof(Mx));
//    memset(My, -1, sizeof(My));
//    memset(chk, -1, sizeof(chk));
//    for (int i = 0; i < Nx; i++)
//    {
//        if (Mx[i] == -1)
//        {
//            qs = qe = 0;
//            Q[qe++] = i;
//            prev[i] = -1;
//            bool flag = 0;
//            while (qs < qe && !flag)
//            {
//                int u = Q[qs];
//                for (int v = 0; v < Ny && !flag; v++)
//                {
//                    if (g[u][v] && chk[v] != i)
//                    {
//                        chk[v] = i; Q[qe++] = My[v];
//                        if (My[v] >= 0)
//                        {
//                            prev[My[v]] = u;
//                        }
//                        else
//                        {
//                            flag = 1;
//                            int d = u, e = v;
//                            while (d != -1)
//                            {
//                                int t = Mx[d];
//                                Mx[d] = e;
//                                My[e] = d;
//                                d = prev[d];
//                                e = t;
//                            }
//                        }
//                    }
//                }
//                qs++;
//            }
//            if (Mx[i] != -1)
//            {
//                res++;
//            }
//        }
//    }
//    return res;
//}

//  //  Kuhn Munkras算法

/*
 *  邻接距阵形式,复杂度O(m*m*n) 返回最佳匹配值,传入二分图大小m,n 
 *  邻接距阵mat,表示权,match1,match2返回一个最佳匹配,未匹配顶点
 *  match值为-1,一定注意m<=n,否则循环无法终止,最小权匹配可将权值 
 *  取相反数
 *  初始化:for (i = 0; i < MAXN; ++i)
 *          for (j = 0; j < MAXN ; ++j)
 *              mat[i][j] = -inf; 
 *  对于存在的边:mat[i][j] = val ;    //  注意,不能有负值
 */
//#define MAXN 310
//#define inf 1000000000
//#define _clr(x) memset(x, -1, sizeof(int) * MAXN)
//
//int kuhn_munkras(int m, int n, int mat[][MAXN], int *match_1, int *match_2)
//{
//    int s[MAXN], t[MAXN], l_1[MAXN], l_2[MAXN];
//    int p, q, ret = 0;
//    int i, j, k;
//    for (i = 0; i < m; i++)
//    {
//        for (l_1[i] = -inf, j = 0; j < n; j++)
//        {
//            l_1[i] = mat[i][j] > l_1[i] ? mat[i][j] : l_1[i];
//        }
//        if (l_1[i] == -inf)
//        {
//            return -1;  //  无结果
//        }
//    }
//    for (i = 0; i < n; l_2[i++] = 0);
//    for (_clr(match_1), _clr(match_2), i = 0; i < m; i++)
//    {
//        for (_clr(t), s[p = q = 0] = i; p <= q && match_1[i] < 0; p++)
//        {
//            for (k = s[p], j = 0; j < n && match_1[i] < 0; p++)
//            {
//                if (l_1[k] + l_2[j] == mat[k][j] && t[j] < 0)
//                {
//                    s[++q] = match_2[j], t[j] = k;
//                    if (s[q] < 0)
//                    {
//                        for (p = j; p >= 0; j = p)
//                        {
//                            match_2[j] = k = t[j];
//                            p = match_1[k];
//                            match_1[k] = j;
//                        }
//                    }
//                }
//            }
//        }
//        if (match_1[i] < 0)
//        {
//            for (i--, p = inf, k = 0; k <= q; k++)
//            {
//                for (j = 0; j < n; j++)
//                {
//                    if (t[j] < 0 && l_1[s[k]] + l_2[j] - mat[s[k]][j] < p)
//                    {
//                        p = l_1[s[k]] + l_2[j] - mat[s[k]][j];
//                    }
//                }
//            }
//            for (j = 0; j < n; l_2[j] += t[j] < 0 ? 0 : p, j++);
//            for (k = 0; k <= q; l_1[s[k++]] -= p);
//        }
//    }
//    for (i = 0; i < m; i++)
//    {   //  if处理无匹配的情况!!
//        if (match_1[i] < 0)             //  ???
//        {
//            return -1;
//        }
//        if (mat[i][match_1[i]] <= -inf) //  ???
//        {
//            return -1;
//        }
//        ret += mat[i][match_1[i]];
//    }
//    return ret;
//}
//
//int main(int argc, const char * argv[])
//{
//    
//    std::cout << "Hello, World!\n";
//    return 0;
//}


//  //  Hopcroft-Carp 算法

//  邻接表+DFS

/*
 *  复杂度O(sqrt(n)*E)
 *  邻接表存图,vector实现
 *  vector先初始化,然后假如边
 *  uN为左端的顶点数,使用前赋值(点编号0开始)
 */
//const int MAXN = 3000;
//const int INF = 0x3f3f3f3f;
//vector<int>G[MAXN];
//int uN;
//int Mx[MAXN], My[MAXN];
//int dx[MAXN], dy[MAXN];
//int dis;
//bool used[MAXN];
//
//bool SearchP()
//{
//    queue<int>Q;
//    dis = INF;
//    memset(dx, -1, sizeof(dx));
//    memset(dy, -1, sizeof(dy));
//    for (int i = 0 ; i < uN; i++)
//    {
//        if(Mx[i] == -1)
//        {
//            Q.push(i);
//            dx[i] = 0;
//        }
//    }
//    while (!Q.empty())
//    {
//        int u = Q.front();
//        Q.pop();
//        if (dx[u] > dis)
//        {
//            break;
//        }
//        int sz = (int)G[u].size();
//        for (int i = 0; i < sz; i++)
//        {
//            int v = G[u][i];
//            if (dy[v] == -1)
//            {
//                dy[v] = dx[u] + 1;
//                if (My[v] == -1)
//                {
//                    dis = dy[v];
//                }
//                else
//                {
//                    dx[My[v]] = dy[v] + 1;
//                    Q.push(My[v]);
//                }
//            }
//        }
//    }
//    return dis != INF;
//}
//
//bool DFS(int u)
//{
//    int sz = (int)G[u].size();
//    for (int i = 0; i < sz; i++)
//    {
//        int v = G[u][i];
//        if (!used[v] && dy[v] == dx[u] + 1)
//        {
//            used[v] = true;
//            if (My[v] != -1 && dy[v] == dis)
//            {
//                continue;
//            }
//            if (My[v] == -1 || DFS(My[v]))
//            {
//                My[v] = u;
//                Mx[u] = v;
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//int MaxMatch()
//{
//    int res = 0;
//    memset(Mx, -1, sizeof(Mx));
//    memset(My, -1, sizeof(My));
//    while (SearchP())
//    {
//        memset(used, false, sizeof(used));
//        for (int i = 0; i < uN; i++)
//        {
//            if(Mx[i] == -1 && DFS(i))
//            {
//                res++;
//            }
//        }
//    }
//    return res;
//}

//  邻接矩阵+DFS

/*
 *  INIT: g[][]邻接矩阵；
 *  CALL: res = MaxMatch(); Nx, Ny要初始化！！！
 *  时间复杂度: O(V^0.5 * E)
 */
const int MAXN = 3001;
const int INF = 1 << 28;
int g[MAXN][MAXN], Mx[MAXN], My[MAXN], Nx, Ny;
int dx[MAXN], dy[MAXN], dis;
bool vst[MAXN];

bool searchP()
{
    queue<int> Q;
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for (int i = 0; i < Nx; i++)
    {
        if (Mx[i] == -1)
        {
            Q.push(i); dx[i] = 0;
        }
    }
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if (dx[u] > dis)
        {
            break;
        }
        for (int v = 0; v < Ny; v++)
        {
            if (g[u][v] && dy[v] == -1)
            {
                dy[v] = dx[u]+1;
                if (My[v] == -1)
                {
                    dis = dy[v];
                }
                else
                {
                    dx[My[v]] = dy[v] + 1;
                    Q.push(My[v]);
                }
            }
        }
    }
    return dis != INF;
}

bool DFS(int u)
{
    for (int v = 0; v < Ny; v++)
    {
        if (!vst[v] && g[u][v] && dy[v] == dx[u] + 1)
        {
            vst[v] = 1;
            if (My[v] != -1 && dy[v] == dis)
            {
                continue;
            }
            if (My[v] == -1 || DFS(My[v]))
            {
                My[v] = u; Mx[u] = v;
                return 1;
            }
        }
    }
    return 0;
}

int MaxMatch()
{
    int res = 0;
    memset(Mx, -1, sizeof(Mx));
    memset(My, -1, sizeof(My));
    while (searchP())
    {
        memset(vst, 0, sizeof(vst));
        for (int i = 0; i < Nx; i++)
        {
            if (Mx[i] == -1 && DFS(i))
            {
                res++;
            }
        }
    }
    return res;
}