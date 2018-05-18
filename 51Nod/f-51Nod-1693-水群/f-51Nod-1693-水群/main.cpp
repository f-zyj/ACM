//
//  main.cpp
//  f-51Nod-1693-水群
//
//  Created by ZYJ on 2017/8/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e6 + 10;
const int MAGIC = 5;

int n;
int dis[MAXN];
int vis[MAXN];
int prime[] = {6, 2, 3, 5, 7, 11, 13};

int spfa_bfs(int n)
{
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));

    dis[1] = 0;
    vis[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int j = 1; j <= prime[0] && x * prime[j] < n + MAGIC; j++)
        {
            int y = x * prime[j], cost = prime[j];
            if (dis[x] + cost < dis[y])
            {
                dis[y] = dis[x] + cost;
                if (!vis[y])
                {
                    vis[y] = 1;
                    q.push(y);
                }
            }
        }
        int y = x - 1, cost = 1;
        if (dis[x] + cost < dis[y])
        {
            dis[y] = dis[x] + cost;
            if (!vis[y])
            {
                vis[y] = 1;
                q.push(y);
            }
        }
    }
    
    return dis[n];
}

int main()
{
    scanf("%d", &n);
    
    printf("%d\n", spfa_bfs(n));
    
    return 0;
}
