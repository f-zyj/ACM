//
//  main.cpp
//  f-CF-Tinkoff Challenge-Elimination Round-B-Igor and his way to work
//
//  Created by ZYJ on 2017/4/24.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1010;
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};   //  右，左，下，上

int n, m;
int flag = 0;
char s[MAXN][MAXN];
int vis[MAXN][MAXN];
int sx, sy, tx, ty;

int main(int argc, const char * argv[])
{
    memset(vis, 0, sizeof(vis));
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s[i]);
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'S')
            {
                sx = i;
                sy = j;
                vis[sx][sy] = 1;
            }
            else if (s[i][j] == 'T')
            {
                tx = i;
                ty = j;
            }
        }
    }
    
    int x, y;
    for (int i = 0; i < 4; i++)
    {
        x = sx + dir[i][0];
        y = sy + dir[i][1];
        while (0 <= x && x < n && 0 <= y && y < m && s[x][y] != '*')
        {
            vis[x][y] = 1;
            x += dir[i][0];
            y += dir[i][1];
        }
    }
    if (vis[tx][ty])
    {
        cout << "YES\n";
        return 0;
    }
    
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            cout << vis[i][j];
//        }
//        cout << endl;
//    }

    for (int i = 0; i < 4; i++)
    {
        x = tx + dir[i][0];
        y = ty + dir[i][1];
        while (0 <= x && x < n && 0 <= y && y < m && s[x][y] != '*')
        {
            if (vis[x][y])
            {
                cout << "YES\n";
                return 0;
            }
            int j = i < 2 ? 2 : 0;
            int x_ = x + dir[j][0];
            int y_ = y + dir[j][1];
            while (0 <= x_ && x_ < n && 0 <= y_ && y_ < m && s[x_][y_] != '*')
            {
                if (vis[x_][y_])
                {
                    cout << "YES\n";
                    return 0;
                }
                x_ += dir[j][0];
                y_ += dir[j][1];
            }
            j++;
            x_ = x + dir[j][0];
            y_ = y + dir[j][1];
            while (0 <= x_ && x_ < n && 0 <= y_ && y_ < m && s[x_][y_] != '*')
            {
                if (vis[x_][y_])
                {
                    cout << "YES\n";
                    return 0;
                }
                x_ += dir[j][0];
                y_ += dir[j][1];
            }
            x += dir[i][0];
            y += dir[i][1];
        }
    }

    cout << "NO\n";
    
    return 0;
}
