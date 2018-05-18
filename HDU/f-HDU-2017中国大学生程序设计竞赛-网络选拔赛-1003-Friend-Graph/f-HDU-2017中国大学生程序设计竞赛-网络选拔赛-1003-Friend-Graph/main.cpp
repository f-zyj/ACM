//
//  main.cpp
//  f-HDU-2017中国大学生程序设计竞赛-网络选拔赛-1003-Friend-Graph
//
//  Created by ZYJ on 2017/8/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 3e3 + 10;

int n;
int rt[MAXN];
bool vis[MAXN][MAXN];

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    while (T--)
    {
        scanf("%d", &n);
        
        int x;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                scanf("%d", &x);
                vis[i][j] = vis[j][i] = x;
            }
        }
        
        int flag = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                for (int k = j + 1; k <= n; k++)
                {
                    if (vis[i][j] && vis[j][k] && vis[k][i])
                    {
                        flag = 0;
                        break;
                    }
                    if (!(vis[i][j] || vis[j][k] || vis[k][i]))
                    {
                        flag = 0;
                        break;
                    }
                }
                if (!flag)
                {
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
        }
        
        if (flag)
        {
            puts("Great Team!");
        }
        else
        {
            puts("Bad Team!");
        }
    }
    
    return 0;
}

