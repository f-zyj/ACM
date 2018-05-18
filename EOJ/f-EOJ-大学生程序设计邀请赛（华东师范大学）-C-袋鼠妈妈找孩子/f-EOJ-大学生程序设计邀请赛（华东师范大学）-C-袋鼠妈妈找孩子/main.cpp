//
//  main.cpp
//  f-EOJ-大学生程序设计邀请赛（华东师范大学）-C-袋鼠妈妈找孩子
//
//  Created by ZYJ on 2017/5/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10;
const int DIR[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, m;
int x, y, limit;
char map[MAXN][MAXN];

bool dfs(int x, int y, int lim)
{
    if (x == 1 && y == 1)
    {
        return lim >= limit;
    }
    for (int i = 0; i < 4; i++)
    {
        int x_ = x + DIR[i][0];
        int y_ = y + DIR[i][1];
        if (!x_ || !y_ || x_ > n || y_ > m || map[x_][y_] != '*')
        {
            continue;
        }
        int cnt = 0;
        for (int j = 0; j < 4; j++)
        {
            int u = x_ + DIR[j][0];
            int v = y_ + DIR[j][1];
            if (map[u][v] == '.')
            {
                cnt++;
            }
        }
        if (cnt > 1)
        {
            continue;
        }
        map[x_][y_] = '.';
        if (dfs(x_, y_, lim + 1))
        {
            return true;
        }
        map[x_][y_] = '*';
    }
    
    return false;
}

int main()
{
    while (cin >> n >> m)
    {
        cin >> x >> y >> limit;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                map[i][j] = '*';
            }
        }
        map[x][y] = '.';
        
        dfs(x, y, 0);
        
        for (int i = 1; i <= n; i++)
        {
            puts(map[i] + 1);
        }
    }
    
    return 0;
}
