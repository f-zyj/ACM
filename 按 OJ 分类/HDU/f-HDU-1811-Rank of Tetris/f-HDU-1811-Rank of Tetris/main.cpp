//
//  main.cpp
//  f-HDU-1811-Rank of Tetris
//
//  Created by ZYJ on 2016/11/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cstring>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 1e4 + 10;
//
//int flag;
//int root;
//int pre[MAXN];
//
//int find(int x)
//{
//    int r = x;
//    while (pre[r] != r)
//    {
//        r = pre[r];
//    }
//    
//    int i = x, j;
//    while (i != r)
//    {
//        j = pre[i];
//        pre[i] = r;
//        i = j;
//    }
//    return r;
//}
//
//void join(int x, int y)
//{
//    int fx = find(x);
//    int fy = find(y);
//    
//    if (fx != fy)
//    {
//        pre[fx] = fy;
//    }
//    
//    return ;
//}
//
///*
// *  拓扑排序
// *  INIT:edge[][]置为图的邻接矩阵;cnt[0...i...n-1]:顶点i的入度。
// */
//const int MAXV = 1001;
//
//int edge[MAXV][MAXV];
//int cnt[MAXV];
//
//void TopoOrder(int n)
//{
//    int i, top = -1;
//    for (i = 0; i < n; ++i)
//    {
//        if (cnt[i] == 0)
//        {
//            if (top != 0)
//            {
//                root--;
//            }
//            //  下标模拟堆栈
//            cnt[i] = top;
//            top = i;
//        }
//    }
//    for (i = 0; i < n; i++)
//    {
//        if (top == -1)
//        {
//            flag = 1;
//            return ;
//        }
//        else
//        {
//            int j = top;
//            top = cnt[top];
////            printf("%d", j);
//            for (int k = 0; k < n; k++)
//            {
//                if (edge[j][k] && (--cnt[k]) == 0)
//                {
//                    if (top == 0)
//                    {
//                        root++;
//                        //  不冲突但是信息不全
//                        if (root > 1 && !flag)
//                        {
//                            flag = 2;
//                        }
//                    }
//                    cnt[k] = top;
//                    top = k;
//                }
//            }
//        }
//    }
//}
//
//int main(int argc, const char * argv[])
//{
//    int n, m;
//    int a, b;
//    char c;
//    while (cin >> n >> m)
//    {
//        memset(edge, 0x3f, sizeof(edge));
//        memset(cnt, 0, sizeof(cnt));
//        
//        for (int i = 0; i <= n; i++)
//        {
//            pre[i] = i;
//        }
//        for (int i = 0; i < m; i++)
//        {
//            scanf("%d %c %d", &a, &c, &b);
//            if (c == '=')
//            {
//                join(a, b);
//                edge[a][b] = 1;
//                edge[b][a] = 1;
//                cnt[a]++;
//                cnt[b]++;
//            }
//            else if (c == '<')
//            {
//                edge[a][b] = 1;
//                cnt[b]++;
//            }
//            else
//            {
//                edge[b][a] = 1;
//                cnt[a]++;
//            }
//        }
//        
//        //  判断冲突（大于小于和等于冲突）
//        //  判断信息不全（入度为0的点个数大于1）
//        flag = 0;   //  1:冲突、2:信息不全
//        root = 0;
//        for (int i = 0; i < n; i++)
//        {
//            if (cnt[i] == 0)
//            {
//                root++;
//                if (root > 1)
//                {
//                    flag = 2;
//                }
//            }
//            for (int j = 0; j < n; j++)
//            {
//                if (edge[i][j] == 1)
//                {
//                    int fx = find(i);
//                    int fy = find(j);
//                    if (fx == fy)
//                    {
//                        flag = 1;
//                    }
//                }
//            }
//        }
//        if (flag == 1)
//        {
//            cout << "CONFLICT\n";
//            continue;
//        }
//        
//        TopoOrder(n);
//        
//        if (flag == 1)
//        {
//            cout << "CONFLICT\n";
//        }
//        else if (flag == 2)
//        {
//            cout << "UNCERTAIN\n";
//        }
//        else
//        {
//            cout << "OK\n";
//        }
//    }
//    
//    return 0;
//}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 10010;
const int MAXM = 20010;

int head[MAXN];
int cnt[MAXN];  //  入度

struct node
{
    int v, next;
} edge[MAXM];

int pre[MAXN];
int edgeNum;

int find(int u)
{
    if (pre[u] != u)
    {
        pre[u] = find(pre[u]);
    }
    return pre[u];
}

void join(int a, int b)
{
    int fx = find(a);
    int fy = find(b);
    if (fx != fy)
    {
        pre[fx] = fy;
    }
}

void addEdge(int a, int b)
{
    edge[edgeNum].v = b;
    edge[edgeNum].next = head[a];
    head[a] = edgeNum++;
}

struct rel
{
    int a;
    char c;
    int b;
} REL[MAXM];

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        int flag = 0, flag_ = 0;
        for (int i = 0; i <= n; i++)
        {
            pre[i] = i;
            head[i] = -1;
            cnt[i] = 0;
        }
        
        edgeNum = 0;
        int tag = n;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %c %d", &REL[i].a, &REL[i].c, &REL[i].b);
            
            if (REL[i].c == '=')
            {
                tag--;
                join(REL[i].a, REL[i].b);
            }
        }
        
        for (int i = 0; i < m; i++)
        {
            if (REL[i].c == '=')
            {
                continue;
            }
            int fx = find(REL[i].a);
            int fy = find(REL[i].b);
            if (fx == fy)
            {
                flag = 1;
                break;
            }
            if (REL[i].c == '<')
            {
                addEdge(fy, fx);
                cnt[fx]++;
            }
            else
            {
                addEdge(fx, fy);
                cnt[fy]++;
            }
        }
        
        if (flag)
        {
            printf("CONFLICT\n");
            continue;
        }
        
        queue<int> que;
        for (int i = 0; i < n; i++)
        {
            //  把入度为0的入队列
            int temp = find(i);
            if (!cnt[temp] && temp == i)
            {
                que.push(temp);
            }
        }
        while (!que.empty())
        {
            int tmp = que.front();
            que.pop();
            tag--;
            //  说明入度为0的根数目大于1
            if (!que.empty())
            {
                flag_ = 1;
            }
            for (int i = head[tmp]; i != -1; i = edge[i].next)
            {
                cnt[edge[i].v]--;
                if (!cnt[edge[i].v])
                {
                    que.push(edge[i].v);
                }
            }
        }
        
        if (tag > 0)
        {
            printf("CONFLICT\n");
        }
        else if (flag_)
        {
            printf("UNCERTAIN\n");
        }
        else
        {
            printf("OK\n");
        }
    }
    
    return 0;
}
