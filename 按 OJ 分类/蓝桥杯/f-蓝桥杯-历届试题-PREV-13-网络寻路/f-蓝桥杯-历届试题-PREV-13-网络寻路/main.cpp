//
//  main.cpp
//  f-蓝桥杯-历届试题-PREV-13-网络寻路
//
//  Created by ZYJ on 2017/3/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 10001;

int n, m, cnt = 0;
vector<int> graph[MAXN];

void dfs(int last, int st, int step)
{
    if (step == 0)
    {
        cnt++;
        return ;
    }
    for (int i = 0; i < graph[st].size(); i++)
    {
        if (graph[st][i] != last)
        {
            dfs(st, graph[st][i], step - 1);
        }
    }
}

int main(int argc, const char * argv[])
{
    cin >> n >> m;
    
    int a, b;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++)
    {
        dfs(-1, i, 3);
    }
    
    cout << cnt << '\n';
    
    return 0;
}
