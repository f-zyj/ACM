//
//  main.cpp
//  f-CF-Codeforces Round #483 (Div. 2)-B-Minesweeper
//
//  Created by ZYJ on 2018/5/15.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 111;
const int DIR[][2] =
{
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
    {0, 1}, {1, -1}, {1, 0}, {1, 1}
};

struct cell
{
    int dig;
    int cnt;
    int flag;
} C[MAXN][MAXN];

int n, m;

bool judge(int x, int y)
{
    if (x >= 0 && y >= 0 && x < n && y < m)
    {
        return 1;
    }
    
    return 0;
}

void change(int x, int y)
{
    C[x][y].flag = 1;
    int x_, y_;
    for (int i = 0; i < 8; i++)
    {
        x_ = x + DIR[i][0];
        y_ = y + DIR[i][1];
        if (judge(x_, y_))
        {
            C[x_][y_].cnt++;
        }
    }
}

int main(int argc, const char * argv[])
{
    while (cin >> n >> m)
    {
        getchar();
        
        memset(C, 0, sizeof(C));
        
        char x;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                x = getchar();
                if (x == '.')
                {
                    x = '0';
                }
                if (x >= '0' && x < '9')
                {
                    C[i][j].dig = x - '0';
                }
                if (x == '*')
                {
                    change(i, j);
                }
            }
            getchar();
        }
        
        int tag = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!C[i][j].flag && C[i][j].dig != C[i][j].cnt)
                {
                    cout << "NO\n";
                    tag = 0;
                    break;
                }
            }
            if (!tag)
            {
                break;
            }
        }
        
        if (tag)
        {
            cout << "YES\n";
        }
    }
    
    return 0;
}
