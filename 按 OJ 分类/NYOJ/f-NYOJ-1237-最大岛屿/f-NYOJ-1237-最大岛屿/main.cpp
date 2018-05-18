//
//  main.cpp
//  f-NYOJ-1237-最大岛屿
//
//  Created by ZYJ on 2017/5/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 505;
const int DIR[8][2] = {{0, 1}, {0, -1},
                       {1, 0}, {-1, 0},
                       {1, 1}, {1, -1},
                      {-1, 1}, {-1, -1}};

int m, n, t;
int tmp;

char g[MAXN][MAXN];

void dfs(int x, int y)
{
    tmp++;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + DIR[i][0];
        int ny = y + DIR[i][1];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n || g[nx][ny] == '0')
        {
            continue;
        }
        g[nx][ny] = '0';
        dfs(nx, ny);
    }
}

int main()
{
    cin >> m >> n >> t;
    
    for (int i = 0; i < m; i++)
    {
        cin >> g[i];
        int len = (int)strlen(g[i]);
        while (len < n)
        {
            cin >> (g[i] + len);
            len = (int)strlen(g[i]);
        }
    }
    
    int ans = 0, cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == '1')
            {
                g[i][j] = '0';
                tmp = 0;
                cnt++;
                dfs(i, j);
                ans = max(ans, tmp);
            }
        }
    }
    
    cout << cnt << " " << ans * t << endl;
    
    return 0;
} 
