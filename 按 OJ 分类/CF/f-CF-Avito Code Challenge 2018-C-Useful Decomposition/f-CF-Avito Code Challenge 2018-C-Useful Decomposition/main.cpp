//
//  main.cpp
//  f-CF-Avito Code Challenge 2018-C-Useful Decomposition
//
//  Created by ZYJ on 2018/5/27.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 10;

int n;
int vis[MAXN];
vector<int> E[MAXN];

void dfs(int u, int pre)
{
    if (E[u].size() == 1)
    {
        printf("%d\n", u);
        return ;
    }
    
    for (int i = 0; i < E[u].size(); i++)
    {
        if (E[u][i] != pre)
        {
            dfs(E[u][i], u);
        }
    }
}

int main(int argc, const char * argv[])
{
    cin >> n;
    
    int u, v;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    
    int rt = 0, flag = 1;
    for (int i = 1; i <= n; i++)
    {
        if (E[i].size() > 2 && rt == 0)
        {
            rt = i;
        }
        else if (E[i].size() > 2)
        {
            flag = 0;
            break;
        }
    }
    
    if (!flag)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
        
        if (rt == 0)
        {
            rt = 1;
        }
        
        printf("%d\n", (int)E[rt].size());
        for (int i = 0; i < E[rt].size(); i++)
        {
            printf("%d ", rt);
            dfs(E[rt][i], rt);
        }
    }
    
    return 0;
}
