//
//  main.cpp
//  f-51Nod-1109-01组成的N的倍数
//
//  Created by ZYJ on 16/8/21.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 5e6;

struct node
{
    int x;
    int per;
} ans[MAXN];

bool vis[MAXN]; //  表示余数状态0表示未出现过，1表示出现过

int n, num;

void DFS(int pos)
{
    int res = ans[pos].per;
    if (res <= 0)
    {
        printf("1");
        return;
    }
    DFS(res);
    printf("%d", ans[res].x);
    return ;
}

void BFS()
{
    num = 1;
    memset(vis, 0, sizeof(vis));
    node cur, tmp;
    cur.x = 1, cur.per = 0;
    queue<node> q;
    ans[0].x = 1;
    ans[0].per = 0;
    q.push(cur);    //  M>0
    
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        for (int i = 0; i <= 1; i++)
        {
            cur.x = tmp.x * 10 + i;
            cur.x %= n;         //  表示余数
            if (!vis[cur.x])    //  剪枝，如果前边已经出现过cur.x，剪去这种情况
            {
                cur.per = num;
                vis[cur.x] = 1; //  标记
                ans[num].x = i;
                ans[num].per = tmp.per;
                q.push(cur);
                if (cur.x == 0)
                {
                    DFS(num);
                    printf("%d\n", i);
                    return;
                }
                num++;
            }
        }
    }
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        if (n == 1)
        {
            printf("1\n");
            continue;
        }
        BFS();
    }
    return 0;
}