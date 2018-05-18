//
//  main.c
//  f-ZZUACM-Tutti!
//
//  Created by ZYJ on 16/4/3.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
typedef int Status;
//边结构
typedef struct Edge
{
    int a, b, c;
} Edge[80005];
int i, j, k, MF, MC;
int dist[405], flag[405], pre[405];

//建立地图
void buildMap(int m, Edge E)
{
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &E[i].a, &E[i].b, &E[i].c);
    }
    return ;
}

//SPFA
//Status SPFA()
//{
//    memset(dist, 63, sizeof(dist));
//    int Q;
//    dist[1] = 0;
//    
//}

int main(int argc, const char * argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    Edge E;
    buildMap(m, E);
    printf("Hello, World!\n");
    return 0;
}
