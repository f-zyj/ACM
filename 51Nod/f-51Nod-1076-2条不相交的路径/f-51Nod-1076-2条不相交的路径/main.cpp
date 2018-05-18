//
//  main.cpp
//  f-51Nod-1076-2条不相交的路径
//
//  Created by ZYJ on 16/8/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 5e4 + 10;

int stack[MAXN];    //  每遍历一个点便入栈
int top;
bool inStack[MAXN]; //  判断某个点是否已经在栈里面

//  这两个数组至关重要
//  dfn[u]为节点u搜索的次序编号（时间戳）
//  low[u]为u或者u的子树能够追溯到的最早的栈中节点的次序号
int dfn[MAXN];
int low[MAXN];

int beLong[MAXN];   //  判断哪些点联通
int Bcnt, Dindex;   //  记录强连通个数和当前时间
vector<int> v[MAXN];    //  邻接表保存边
int N, M, Q;

void init()
{
    Bcnt = Dindex = top = 0;
    memset(dfn, -1, sizeof(dfn));
    memset(inStack, false, sizeof(inStack));
    for (int i = 0; i < MAXN; i++)
    {
        v[i].clear();
    }
    return ;
}

void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++Dindex;
    stack[++top] = u;
    inStack[u] = true;  //  入队列，置为true
    
    int u_size = (int)v[u].size();
    for (int i = 0; i < u_size; i++)
    {
        int k = v[u][i];
        
        if (dfn[k] == -1)               //  没有被访问过
        {
            tarjan(k, u);
            low[u] = min(low[u], low[k]);
        }
        else if (inStack[k] && k != fa) //  被访问过
        {
            low[u] = min(low[u], dfn[k]);
        }
    }
    if (dfn[u] == low[u])
    {
        Bcnt++;
        int tmp;
        do
        {
            tmp = stack[top--];
            beLong[tmp] = Bcnt;
            inStack[tmp] = false;   //  出队列，置为false
        } while (tmp != u);
    }
    return ;
}

void solve()
{
    for (int i = 1; i <= N; i++)
    {
        if (dfn[i] == -1)   //  没有搜索过则搜索
        {
            tarjan(i, -1);
        }
    }
}

int main(int argc, const char * argv[])
{
    init();
    
    cin >> N >> M;
    
    int a, b;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    solve();
    
    cin >> Q;
    while (Q--)
    {
        scanf("%d %d", &a, &b);
        if (beLong[a] == beLong[b])
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    
    return 0;
}
