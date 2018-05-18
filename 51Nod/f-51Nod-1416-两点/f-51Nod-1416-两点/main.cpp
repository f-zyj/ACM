//
//  main.cpp
//  f-51Nod-1416-两点
//
//  Created by ZYJ on 16/8/13.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXMN = 55;

int n, m;
char map[MAXMN][MAXMN];
int flag[MAXMN][MAXMN]; //  标记访问状态
bool ans = false;

void solve(int x, int y, int tag)
{
    if (x > n || x < 1)
    {
        return ;
    }
    else if (y > m || y < 1)
    {
        return ;
    }
    flag[x][y] = 1;
    //  一号路径
    if (map[x][y] == map[x + 1][y] && tag != 2)
    {
        if (flag[x + 1][y])
        {
            ans = true;
            return ;
        }
        solve(x + 1, y, 1);
    }
    //  二号路径
    if (map[x][y] == map[x - 1][y] && tag != 1)
    {
        if (flag[x - 1][y])
        {
            ans = true;
            return ;
        }
        solve(x - 1, y, 2);
    }
    //  三号路径
    if (map[x][y] == map[x][y + 1] && tag != 4)
    {
        if (flag[x][y + 1])
        {
            ans = true;
            return ;
        }
        solve(x, y + 1, 3);
    }
    //  四号路径
    if (map[x][y] == map[x][y - 1] && tag != 3)
    {
        if (flag[x][y - 1])
        {
            ans = true;
            return ;
        }
        solve(x, y - 1, 4);
    }
    return ;
}

int main(int argc, const char * argv[])
{
    while (cin >> n >> m)
    {
        memset(flag, 0, sizeof(flag));
        
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", map[i] + 1);
        }
        for (int i = 1; i <= n; i++)
        {
            if (ans)
            {
                break;
            }
            for (int j = 1; j <= m; j++)
            {
                if (ans)
                {
                    break;
                }
                if (!flag[i][j])
                {
                    solve(i, j, 0);
                }
            }
        }
        if (ans)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    
    return 0;
}
