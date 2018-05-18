//
//  main.c
//  f-HDOJ-2066-一个人的旅行
//
//  Created by ZYJ on 16/5/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include<stdio.h>
//#include <string.h>
//#define MAXSIZE 1000
//#define INF 0x3f3f3f3f  //表示无穷大
//#define MAX(a, b) a > b ? a : b
//#define MIN(a, b) a < b ? a : b
//
//int map[MAXSIZE][MAXSIZE];
//
//void init()
//{
//    //初始化为无穷大
//    memset(map, 0x3f, sizeof(map));
//    
//    for (int i = 1; i < MAXSIZE; i++)
//    {
//        map[i][i] = 0;
//    }
//    
//    return ;
//}
//
////佛洛依德算法，最短路
//void floyd(int n)
//{
//    int i, j, k;
//    for (k = 1; k <= n; k++)
//    {
//        for (i = 1; i <= n; i++)
//        {
//            if (map[i][k] != INF)
//            {
//                for (j = 1; j <= n; j++)
//                {
//                    map[i][j] = MIN(map[i][j], map[i][k] + map[k][j]);
//                }
//            }
//        }
//    }
//    return ;
//}
//
//int main()
//{
//    int T, S, D;
//    int a, b, time;
//    int neiCity[MAXSIZE], goCity[MAXSIZE];
//    int i, j, n, min;
//    while (~scanf("%d %d %d", &T, &S, &D))
//    {
//        init();
//        n = -1;
//        
//        while (T--)
//        {
//            scanf("%d %d %d", &a, &b, &time);
//            
//            if (map[a][b] > time)
//            {
//                map[a][b] = map[b][a] = time;
//            }
//            
//            n = MAX(MAX(n, a), b);
//        }
//        
//        for (i = 0; i < S; i++)
//        {
//            scanf("%d", neiCity + i);
//        }
//        
//        for (i = 0; i < D; i++)
//        {
//            scanf("%d", goCity + i);
//        }
//        
//        floyd(n);
//        
//        min = INF;
//        
//        for (i = 0; i < S; i++)
//        {
//            for (j = 0; j < D; j++)
//            {
//                min = MIN(min, map[i][goCity[j]]);
//            }
//        }
//        
//        printf("%d\n", min);
//    }
//    return 0;
//}


#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 1000
#define INF 0x3f3f3f3f  //表示无穷大
//#define MAX(a, b) a > b ? a : b
//#define MIN(a, b) a < b ? a : b
typedef void Status;
typedef int QElemType;

struct node
{
    int from;
    int to;
    int time;
    int next;
} edge[10 * MAXSIZE];

int head[MAXSIZE];
int vis[MAXSIZE];
int map[MAXSIZE];
int b[MAXSIZE];
int e[MAXSIZE];
int edgeNum, T;

//循环队列顺序存储结构
typedef struct
{
    QElemType data[MAXSIZE];
    int front;  //头指针
    int reat;   //尾指针，若队列不空，指向队列尾元素的下一个位置
} SqQueue;

//初始化一个空队列
Status InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->reat = 0;
    return ;
}

//返回Q的元素个数，也就是队列当前长度
int QueueLength(SqQueue Q)
{
    return (Q.reat - Q.front + MAXSIZE) % MAXSIZE;
}

//若队列未满，则插入元素e为Q新队尾元素
Status EnQueue(SqQueue *Q, QElemType e)
{
    if ((Q->reat + 1) % MAXSIZE == Q->front)
    {
        return ;
    }
    
    Q->data[Q->reat] = e;
    Q->reat = (Q->reat + 1) % MAXSIZE;
    return ;
}

//若队列不空，则删除Q中队头元素
Status DeQueue(SqQueue *Q)
{
    if (Q->front == Q->reat)
    {
        return ;
    }
    Q->front = (Q->front + 1) % MAXSIZE;
    return ;
}

void init()
{
    //初始化为-1
    memset(map, -1, sizeof(map));
    
    edgeNum = 0;
    return ;
}

void add(int a, int b, int time)
{
    struct node E = {a, b, time, head[a]};
    edge[edgeNum] = E;
    head[a] = edgeNum++;
    return ;
}

//佛洛依德算法，最短路
void spfa(int neiCity)
{
    SqQueue Q;
    InitQueue(&Q);
    memset(vis, 0, sizeof(vis));
    memset(map, 0x3f, sizeof(map));
    
    vis[neiCity] = 1;
    map[neiCity] = 0;
    
    EnQueue(&Q, neiCity);
    
    while (QueueLength(Q))
    {
        int u = Q.front, i;
        DeQueue(&Q);
        vis[u] = 0;
        for (i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if (map[v] > map[u] + edge[i].time)
            {
                map[v] = map[u] + edge[i].time;
                if (!vis[v])
                {
                    vis[v] = 1;
                    EnQueue(&Q, v);
                }
            }
        }
    }
    return ;
}

int main()
{
    int T, S, D;
    int a, b, time;
    int neiCity[MAXSIZE], goCity[MAXSIZE];
    int i, j, min;
    
    while (~scanf("%d %d %d", &T, &S, &D))
    {
        init();
        
        while (T--)
        {
            scanf("%d %d %d", &a, &b, &time);
            
            add(a, b, time);
            add(b, a, time);    //双向图
        }
        
        for (i = 0; i < S; i++)
        {
            scanf("%d", neiCity + i);
        }
        
        for (i = 0; i < D; i++)
        {
            scanf("%d", goCity + i);
        }
        
        min = INF;
        
        for (i = 0; i < S; i++)
        {
            spfa(neiCity[i]);
            for (j = 0; j < D; j++)
            {
                if (min > map[goCity[j]])
                {
                    min = map[goCity[j]];
                }
            }
        }
        printf("%d\n", min);
    }
    return 0;
}