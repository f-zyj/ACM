//
//  main.cpp
//  f-51Nod-1535-深海探险
//
//  Created by ZYJ on 2017/3/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 105;

int n, m;
int flag[MAXN] = {1, 1};
int graph[MAXN][MAXN];

void dfs(int st)
{
    for (int i = 2; i <= n; i++)
    {
        if (graph[st][i] && !flag[i])
        {
            flag[i] = 1;
            dfs(i);
        }
    }
}

int main(int argc, const char * argv[])
{
    cin >> n >> m;
    
    int st, ed;
    for (int i = 0; i < m; i++)
    {
        cin >> st >> ed;
        graph[st][ed] = graph[ed][st] = 1;
    }
    
    if (n != m)
    {
        puts("NO");
        return 0;
    }
    
    dfs(1);
    
    for (int i = 1; i <= n; i++)
    {
        if (!flag[i])
        {
            puts("NO");
            return 0;
        }
    }
    
    cout << "FHTAGN!\n";
    
    return 0;
}
