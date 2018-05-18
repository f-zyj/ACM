//
//  main.cpp
//  f-PAT-天梯赛习题集-L3-015-球队“食物链”
//
//  Created by ZYJ on 2017/3/29.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 25;

char achi[MAXN][MAXN];

int N;
int flag = 1;
int L[MAXN];
bool vis[MAXN];

void dfs(int n, int last)
{
    if (n > N)
    {
        if (achi[L[N]][L[1]] == 'W' || achi[L[1]][L[N]] == 'L')
        {
            flag = 0;
        }
        return ;
    }
    
    int tag = 1;
    for (int i = 1; i <= N; i++)
    {
        if (!vis[i] && (achi[i][L[1]] == 'W' || achi[L[1]][i] == 'L'))
        {
            tag = 0;
            break;
        }
    }
    if (tag)
    {
        return ;
    }
    
    for (int i = 1; i <= N && flag; i++)
    {
        if (!vis[i] && flag && (achi[last][i] == 'W' || achi[i][last] == 'L'))
        {
            vis[i] = 1;
            L[n] = i;
            dfs(n + 1, i);
            vis[i] = 0;
        }
    }
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    cin >> N;
    
    for (int i = 1; i <= N; i++)
    {
        scanf("%s", achi[i] + 1);
    }
    
    for (int i = 1; i <= N && flag; i++)
    {
        vis[i] = 1;
        L[1] = i;
        dfs(2, i);
        vis[i] = 0;
    }
    
    if (flag)
    {
        cout << "No Solution\n";
    }
    else
    {
        printf("%d", L[1]);
        for (int i = 2; i <= N; i++)
        {
            printf(" %d", L[i]);
        }
        puts("");
    }
    
    return 0;
}
