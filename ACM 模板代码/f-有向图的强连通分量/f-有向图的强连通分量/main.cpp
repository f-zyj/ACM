//
//  main.cpp
//  f-有向图的强连通分量
//
//  Created by ZYJ on 16/7/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

//  Tarjan

///*
// *  Tarjan算法
// *  复杂度O(N+M)
// */
//const int MAXN = 20010; //  点数
//const int MAXM = 50010; //  边数
//
//struct Edge
//{
//    int to, next;
//}edge[MAXM];
//
//int head[MAXN], tot;
//int Low[MAXN], DFN[MAXN], Stack[MAXN], Belong[MAXN];    //  Belong数组的值是1~scc
//int Index, top;
//int scc;                                                //  强连通分量的个数
//bool Instack[MAXN];
//int num[MAXN];                                          //  各个强连通分量包含点的个数,数组编号1~scc
//                                                        //  num数组不一定需要,结合实际情况
//void addedge(int u, int v)
//{
//    edge[tot].to = v;
//    edge[tot].next = head[u];
//    head[u] = tot++;
//    return ;
//}
//
//void Tarjan(int u)
//{
//    int v;
//    Low[u] = DFN[u] = ++Index;
//    Stack[top++] = u;
//    Instack[u] = true;
//    for (int i = head[u]; i != -1; i = edge[i].next)
//    {
//        v = edge[i].to;
//        if (!DFN[v])
//        {
//            Tarjan(v);
//            if (Low[u] > Low[v])
//            {
//                Low[u] = Low[v];
//            }
//        }
//        else if (Instack[v] && Low[u] > DFN[v])
//        {
//            Low[u] = DFN[v];
//        }
//    }
//    if (Low[u] == DFN[u])
//    {
//        scc++;
//        do
//        {
//            v = Stack[--top];
//            Instack[v] = false;
//            Belong[v] = scc; num[scc]++;
//        }
//        while (v != u);
//    }
//    return ;
//}
//
//void solve(int N)
//{
//    memset(DFN, 0, sizeof(DFN));
//    memset(Instack, false, sizeof(Instack));
//    memset(num, 0, sizeof(num));
//    Index = scc = top = 0;
//    for (int i = 1; i <= N; i++)
//    {
//        if (!DFN[i])
//        {
//            Tarjan(i);
//        }
//    }
//    return ;
//}
//
//void init()
//{
//    tot = 0;
//    memset(head, -1, sizeof(head));
//    return ;
//}

//  Kosaraju

/*
 *  复杂度O(N+M)
 */
const int MAXN = 20010;
const int MAXM = 50010;

struct Edge
{
    int to, next;
} edge1[MAXM], edge2[MAXM];     //  edge1是原图G,edge2是逆图GT

int head1[MAXN], head2[MAXN];
bool mark1[MAXN], mark2[MAXN];
int tot1, tot2;
int cnt1, cnt2;
int st[MAXN];       //  对原图进行dfs,点的结束时间从小到大排序
int Belong[MAXN];   //  每个点属于哪个连通分量(0~cnt2-1)
int num;            //  中间变量,用来数某个连通分量中点的个数
int setNum[MAXN];   //  强连通分量中点的个数,编号0~cnt2-1

void addedge(int u, int v)
{
    edge1[tot1].to = v;
    edge1[tot1].next = head1[u];
    head1[u] = tot1++;
    edge2[tot2].to = u;
    edge2[tot2].next = head2[v];
    head2[v] = tot2++;
    return ;
}

void DFS1(int u)
{
    mark1[u] = true;
    for (int i = head1[u]; i != -1; i = edge1[i].next)
    {
        if(!mark1[edge1[i].to])
        {
            DFS1(edge1[i].to);
        }
    }
    st[cnt1++] = u;
    return ;
}

void DFS2(int u)
{
    mark2[u] = true;
    num++;
    Belong[u] = cnt2;
    for (int i = head2[u]; i != -1; i = edge2[i].next)
    {
        if(!mark2[edge2[i].to])
        {
            DFS2(edge2[i].to);
        }
    }
    return ;
}

void solve(int n)   //  点的编号从1开始
{
    memset(mark1, false, sizeof(mark1));
    memset(mark2, false, sizeof(mark2));
    cnt1 = cnt2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!mark1[i])
        {
            DFS1(i);
        }
    }
    for (int i = cnt1 - 1; i >= 0; i--)
    {
        if (!mark2[st[i]])
        {
            num = 0;
            DFS2(st[i]);
            setNum[cnt2++] = num;
        }
    }
    return ;
}


int main(int argc, const char * argv[])
{
    
    std::cout << "Hello, World!\n";
    return 0;
}
