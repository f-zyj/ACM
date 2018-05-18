//
//  main.cpp
//  f-51Nod-1276-岛屿的数量
//
//  Created by ZYJ on 16/8/11.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 5e4 + 10;

int N, Q;
int question[MAXN];     //  存放对应指令的结果
int embz_island[MAXN];  //  表示各个位置的岛的淹没情况
                        //  embz_island[i]=1,表示位置为i的岛已经被淹没了
struct island
{
    int height;
    int pos;
} Island[MAXN];

struct query
{
    int val;
    int pos;
} Query[MAXN];

bool cmpI(island a, island b)
{
    return a.height < b.height;
}

bool cmpQ(query a, query b)
{
    return a.val < b.val;
}

void work()
{
    int i, j, ans, pos;
    memset(embz_island, 0, sizeof(embz_island));
    
    j = 0;      //  从高度为0的岛开始搜索
    ans = 1;    //  一开始有1个岛站立
    for (i = 0; i < Q; i++)
    {
        for (; j < N; j++)
        {
            if (Query[i].val >= Island[j].height)
            {
                pos = Island[j].pos;
                embz_island[pos] = 1;
                
                if (pos == 1)   //  第一个岛屿与第N个岛屿在边上，需要特殊判断
                {
                    if (embz_island[pos + 1] == 1)
                    {
                        ans--;
                    }
                    continue;
                }
                if (pos == N)
                {
                    if (embz_island[pos - 1] == 1)
                    {
                        ans--;
                    }
                    continue;
                }
                if (embz_island[pos - 1] == 0 && embz_island[pos + 1] == 0)     //  左右两边都没有被淹
                {
                    ans++;
                }
                else if (embz_island[pos - 1] == 1 && embz_island[pos + 1] == 1)//  左右两边都被淹了
                {
                    ans--;
                }
            }
            else
            {
                break;
            }
        }
        pos = Query[i].pos;
        question[pos] = ans;    //  转存指令查找结果
    }
    return ;
}

int main()
{
    int i;
    scanf("%d%d", &N, &Q);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &Island[i].height);
        Island[i].pos = i + 1;
    }
    sort(Island, Island + N, cmpI);
    
    for (i = 0; i < Q; i++)
    {
        scanf("%d", &Query[i].val);
        Query[i].pos = i;
    }
    sort(Query, Query + Q, cmpQ);
    
    work();
    
    for (i = 0; i < Q; i++)
    {
        printf("%d\n", question[i]);
    }
    
    return 0;
}
