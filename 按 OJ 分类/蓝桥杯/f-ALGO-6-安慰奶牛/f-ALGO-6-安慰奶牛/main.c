//
//  main.c
//  f-ALGO-6-安慰奶牛
//
//  Created by ZYJ on 16/3/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>     //qsort()头文件

#define M 100002

typedef struct Edge     //边
{
    int S;      //牧场S
    int E;      //牧场E
    int L;      //通过时间L
} Edge;

Edge e[M];      //实例化边

int far[M];     //结点根指向
int C[M];       //和奶牛谈话时间
int sum = 0;
int N, P;       //N个结点，P条边

//qsort()需要调用的指针
int cmp(const void *a, const void *b)
{
    Edge *c = (Edge *)a;        //将指针void *a强制转换成(Edge *)a并赋给指针Edge *c
    Edge *d = (Edge *)b;        //将指针void *b强制转换成(Edge *)b并赋给指针Edge *d
    return c->L - d->L;         //由小到大排列
}

//寻找根结点，并将中间结点的标记都指向根结点
int find(int x)
{
    int i, k, r;
    r = x;
    //寻找根结点
    while (far[r] >= 0)
        r = far[r];
    k = x;
    //让由x结点一直到根结点中间所有的结点的下一个结点标记都指向根结点
    while (k != r)
    {
        i = far[k];
        far[k] = r;
        k = i;
    }
    //返回根结点
    return r;
}

//将两个结点联结
void Union(int S, int E)
{
    int rS, rE;
    int num;
    rS = find(S);
    rE = find(E);
    num = far[rS] + far[rE];        //必为负数
    //结点联结
    if(far[rS] < far[rE])
    {
        far[rE] = rS;
        far[rS] = num;
    }
    else
    {
        far[rS] = rE;
        far[rE] = num;
    }
}

//Kruskal算法，最小生成树
int Kruskal()
{
    int i;
    int S, E;
    int sumweight = 0, count = 0;
    for(i = 0; i < N; i++)      //初始化far
        far[i] = -1;
    qsort(e, P, sizeof(e[0]), cmp);     //对边的权进行由小到大排序
    for(i = 0; i < P; i++)
    {
        S = e[i].S;
        E = e[i].E;
        //如果S的根结点不等于E的根结点，说明没有生成回路，则选取这条边
        if(find(S) != find(E))
        {
            sumweight += e[i].L;
            Union(S, E);
            count++;        //边数
            if(count >= N - 1)
            {
                break;
            }
        }
    }
    return sumweight;
}

int main ()
{
    int i, min = M;
    int S, E, L;        //牧场S，牧场E，通过时间L
    
    scanf ("%d %d", &N, &P);
    
    for (i = 0; i < N; i++)
    {
        scanf ("%d", &C[i]);
        //选取睡觉的地方
        if (C[i] < min)
            min = C[i];
    }
    
    for (i = 0; i < P; i++)
    {
        scanf("%d %d %d",&S, &E, &L);
        //结点是从0开始存储，所以所有输入的结点需要减一存储
        e[i].S = S - 1;
        e[i].E = E - 1;
        //最小生成树，所以想要按要求安慰所有的奶牛，就必须考虑到来回
        e[i].L = L * 2 + C[S - 1] + C[E - 1];       //从一个结点到另一个结点再返回所用时间（包括谈话时间）
    }
    
    printf ("%d\n", min + Kruskal());       //在睡觉的牧场会多谈一次话
    return 0;
}