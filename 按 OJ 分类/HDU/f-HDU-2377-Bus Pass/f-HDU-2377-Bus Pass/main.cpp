//
//  main.cpp
//  f-HDU-2377-Bus Pass
//
//  Created by ZYJ on 2016/12/8.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e4 + 10;

int dis[MAXN];
int id[MAXN];
int maxDis[MAXN];
bool vis[MAXN];
vector<int> vec[MAXN];
int nz, nr, mz;

bool cmp(int a, int b)
{
    return a < b;
}

void spfa(int st)
{
    queue<int> Q;
    while (!Q.empty())
    {
        Q.pop();
    }
    memset(vis, false, sizeof(vis));
    memset(dis, INF, sizeof(dis));
    
    Q.push(st);
    dis[st] = 0;
    vis[st] = true;
    while(!Q.empty())
    {
        int temp=Q.front();
        Q.pop();
        vis[temp]=false;
        for(int i=0;i<vec[temp].size();i++)
        {
            if(dis[temp]+1<dis[vec[temp][i]])
            {
                dis[vec[temp][i]]=dis[temp]+1;
                if(!vis[vec[temp][i]])
                {
                    vis[vec[temp][i]]=true;
                    Q.push(vec[temp][i]);
                }
            }
        }
    }
}

void buildGraph()
{
    memset(maxDis, 0, sizeof(maxDis));
    for (int i = 1; i <= MAXN; i++)
    {
        vec[i].clear();
    }
    
    int v;
    scanf("%d%d", &nz, &nr);
    for (int i = 1; i <= nz; i++)
    {
        scanf("%d%d", &id[i], &mz);
        for (int j = 1; j <= mz; j++)
        {
            scanf("%d", &v);
            vec[id[i]].push_back(v);
        }
    }
}


int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        buildGraph();
        
        while (nr--)
        {
            scanf("%d", &mz);
            while (mz--)
            {
                int st;
                scanf("%d", &st);
                spfa(st);
                for (int i = 1; i <= nz; i++)
                {
                    if (dis[id[i]] > maxDis[id[i]])
                    {
                        maxDis[id[i]] = dis[id[i]];
                    }
                }
            }
        }
        
        int ans = INF, ansID = 0;
        sort(id + 1, id + 1 + nz, cmp);
        for (int i = 1; i <= nz; i++)
        {
            if (maxDis[id[i]] < ans)
            {
                ans = maxDis[id[i]];
                ansID = id[i];
            }
        }
        printf("%d %d\n", ans + 1, ansID);
    }
    
    return 0;
}
