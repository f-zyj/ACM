//
//  main.c
//  f-ALGO-5-最短路
//
//  Created by ZYJ on 16/3/8.
//  Copyright © 2016年 ZYJ. All rights reserved.
//
/*************************************************************************************************/
//                                           直接爆内存和超时
//#include <stdio.h>
////typedef char VertexType;            //顶点类型
//typedef int EdgeType;               //边上权值类型
//#define MAXVEX 5                   //不小于最大顶点数的一个合适大小的数
//#define INFINITY 10001              //用10001表示无穷大（因为题中数据范围最大取到10000）
//
//typedef struct
//{
//    //VertexType vexs[MAXVEX];        //顶点表
//    EdgeType arc[MAXVEX][MAXVEX];   //邻接矩阵，可看作边表
//    int numVertexes, numEdges;      //图中当前的顶点数和边数
//}MGraph;
//typedef int Pathmatirx[MAXVEX];     //用于存储最短路径下标的数组
//typedef int ShortPathTable[MAXVEX]; //用于存储到各点最短路径的权值和
//
///*建立有向图网的邻接矩阵*/
//void CreateMGraph(MGraph *G)
//{
//    int i, j, k, w;
//    scanf("%d %d", &G->numVertexes, &G->numEdges);   //输入顶点数和边数
//    for (i = 0; i < G->numVertexes; i++)             //初始化邻接矩阵
//    {
//        for (j = 0; j < G->numVertexes; j++)
//        {
//            if (i == j)
//            {
//                G->arc[i][j] = 0;
//            }
//            else
//            {
//                G->arc[i][j] = INFINITY;
//            }
//        }
//    }
//    for (k = 0; k < G->numEdges; k++)                //读入numEdge条边，建立邻接矩阵
//    {
//        scanf("%d %d %d", &i, &j, &w);               //输入边（vi，vj）上的权w
//        G->arc[i - 1][j - 1] = w;
//    }
//}
//
///*Dijkstra算法，求有向网G的vZero顶点到其余各顶点V最短路径P[V]及带权长度D[V]*/
///*P[V]的值为前驱顶点下标，D[V]表示vZero到V的最短路径长度和*/
//void ShortestPath_Dijkstra(MGraph G, int vZero, Pathmatirx *P, ShortPathTable *D)
//{
//    int v, w, k = 0, min = INFINITY;
//    int final[MAXVEX];                                //final[w] = 1表示求得顶点vZero至v[w]的最短路径
//    for (v = 0; v < G.numVertexes; v++)               //初始化数据
//    {
//        final[v] = 0;                                 //全部顶点初始化为未知最短路径状态
//        (*D)[v] = G.arc[vZero][v];                    //将与vZero有连线的顶点加上权值
//        (*P)[v] = 0;                                  //初始化路径数组P为0
//    }
//    (*D)[vZero] = 0;                                  //vZero至vZero路径为0
//    final[vZero] = 1;                                 //vZero至vZero不需要求路径
//    //开始主循环，每次求得vZero到某个顶点v的最短路径
//    for (v = 1; v < G.numVertexes; v++)
//    {
//        min = INFINITY;
//        for (w = 0; w < G.numVertexes; w++)
//        {
//            if (!final[w] && (*D)[w] < min)
//            {
//                k = w;
//                min = (*D)[w];                        //w顶点离顶点更近
//            }
//        }
//        final[k] = 1;                                 //将目前找到的最近的顶点置为1
//        for (w = 0; w < G.numVertexes; w++)           //修正当前最短路径及距离
//        {
//            //如果经过v顶点的路径比现在这条路径的长度短的话
//            if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
//            {
//                //说明找到了更短的路径，修改D[w]和P[w]
//                (*D)[w] = min + G.arc[k][w];          //修改当前路径长度
//                (*P)[w] = k;
//            }
//        }
//    }
//}
//
//int main(int argc, const char * argv[])
//{
//    int i = 1;
//    MGraph G;
//    Pathmatirx P;
//    ShortPathTable D;
//    CreateMGraph(&G);
//    ShortestPath_Dijkstra(G, 0, &P, &D);
//    for (; i < G.numVertexes; i++)
//    {
//        printf("%d\n", D[i]);
//    }
//    return 0;
//}
/*************************************************************************************************/
//                                          SPFA(暂时不知道C如何实现)
//#include <stdio.h>
//#include <stdlib.h>
//#define _MAX 20010
//#define MAX 10001
//#define OK 1
//#define ERROE 0
//#define max(a, b) a < b ? a : b
////关于队列的操作函数
//typedef int QElemType;               //QElemType类型为int型
//typedef int Status;                  //Status类型为int型
////循环队列的顺序存储结构
//typedef struct
//{
//    QElemType data[_MAX];
//    int front;      //头指针
//    int rear;       //尾指针
//} SqQueue;
////初始化一个空队列
//Status InitQueue(SqQueue *Q)
//{
//    Q->front = 0;
//    Q->rear = 0;
//    return OK;
//}
////循环队列的入队列操作（插入到队尾）
//Status EnQueue(SqQueue *Q, QElemType e)
//{
//    if ((Q->rear + 1) % _MAX == Q->front)   //队列满的判断
//    {
//        return ERROE;
//    }
//    Q->data[Q->rear] = e;                   //将元素e赋值给队尾
//    Q->rear = (Q->rear + 1) % _MAX;         //rear指针向后移动一位置，若到最后则转到数组头部
//    return OK;
//}
////获取头元素
//Status GetHead(SqQueue *Q, QElemType e)
//{
//    if (Q->front != Q->rear)
//    {
//        return Q->data[Q->front];
//    }
//    else
//    {
//        return ERROE;
//    }
//}
//
//struct point
//{
//    int v, cap, next;
//} edge[_MAX * 10];
//
//int head[_MAX];
//
//int d[_MAX];
//int vis[_MAX];                       //0为假，1为真
//
//int M, n = 0, m;
//
//void addEdge(int from, int to, int cap)
//{
//    edge[M].v = to;
//    edge[M].cap = cap;
//    edge[M].next = head[from];
//    head[from] = M++;
//}
//
//void spaf(int start)
//{
//    int i, x, v;
//    SqQueue Q;
//    InitQueue(&Q);
//    for (i = 0; i <= n; i++)
//    {
//        d[i] = _MAX;
//        vis[i] = 0;
//    }
//    EnQueue(&Q, start);
//    d[start] = 0;
//    vis[start] = 1;
//    while (Q.front == Q.rear)
//    {
//        x =
//    }
//}
/*************************************************************************************************/