//
//  main.cpp
//  f-HDU-1010-Tempter of the Bone
//
//  Created by ZYJ on 2016/10/20.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 9;
const int DIR[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int N, M, T;
int xD, yD;
int xS, yS;
bool flag;
char maze[MAXN][MAXN];
int vis[MAXN][MAXN];


void init()
{
    xD = yD = xS = yS = 0;
    flag = true;
    memset(vis, 0, sizeof(vis));
    
    for (int i = 1; i <= N; i++)
    {
        scanf("%s", maze[i] + 1);
        
        for (int j = 1; j <= M; j++)
        {
            if (maze[i][j] == 'X')
            {
                vis[i][j] = 1;
            }
            else if (maze[i][j] == 'D')
            {
                xD = i;
                yD = j;
            }
            else if (maze[i][j] == 'S')
            {
                xS = i;
                yS = j;
                vis[i][j] = 1;
            }
        }
    }
    
    return ;
}

void dfs(int x, int y, int steps)
{
    if (!flag)
    {
        return ;
    }
    if (steps == T)
    {
        if (maze[x][y] == 'D')
        {
            printf("YES\n");
            flag = false;
        }
        return ;
    }
    //  (x, y)距离出口的最少步数
    int temp = abs(x - xD) + abs(y - yD);
    temp = T - steps - temp;
    //  奇偶剪枝
    if (temp < 0 || temp & 1)
    {
        return ;
    }
    
    for (int i = 0; i < 4; i++)
    {
        int x_ = x + DIR[i][0];
        int y_ = y + DIR[i][1];
        if (!vis[x_][y_] && x_ > 0 && x_ <= N && y_ > 0 && y_ <= M)
        {
            vis[x_][y_] = 1;
            dfs(x_, y_, steps + 1);
            vis[x_][y_] = 0;
        }
    }
    return ;
}

int main(int argc, const char * argv[])
{
    while (cin >> N >> M >> T && (N || M || T))
    {
        init();
        
        dfs(xS, yS, 0);
        if (flag)
        {
            printf("NO\n");
        }
    }
    
    return 0;
}
