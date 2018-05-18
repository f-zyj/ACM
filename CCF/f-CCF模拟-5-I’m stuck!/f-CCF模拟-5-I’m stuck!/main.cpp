//
//  main.cpp
//  f-CCF模拟-5-I’m stuck!
//
//  Created by ZYJ on 2016/12/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXR = 55;
const int MAXC = MAXR;
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int R, C;
char map[MAXR][MAXC];
int visS[MAXR][MAXC];
int visT[MAXR][MAXC];
bool flag;

void dfsS(int x, int y)
{
    visS[x][y] = 1;
    
    switch (map[x][y])
    {
        case '+':
            for (int i = 0; i < 4; i++)
            {
                if (x + dir[i][0] >= 0 && x + dir[i][0] < R &&
                    y + dir[i][1] >= 0 && y + dir[i][1] < C &&
                    map[x + dir[i][0]][y + dir[i][1]] != '#' &&
                    visS[x + dir[i][0]][y + dir[i][1]] == 0)
                {
                    dfsS(x + dir[i][0], y + dir[i][1]);
                }
            }
            break;
        case '-':
            for (int i = 2; i < 4; i++)
            {
                if (x + dir[i][0] >= 0 && x + dir[i][0] < R &&
                    y + dir[i][1] >= 0 && y + dir[i][1] < C &&
                    map[x + dir[i][0]][y + dir[i][1]] != '#' &&
                    visS[x + dir[i][0]][y + dir[i][1]] == 0)
                {
                    dfsS(x + dir[i][0], y + dir[i][1]);
                }
            }
            break;
        case '|':
            for (int i = 0; i < 2; i++)
            {
                if (x + dir[i][0] >= 0 && x + dir[i][0] < R &&
                    y + dir[i][1] >= 0 && y + dir[i][1] < C &&
                    map[x + dir[i][0]][y + dir[i][1]] != '#' &&
                    visS[x + dir[i][0]][y + dir[i][1]] == 0)
                {
                    dfsS(x + dir[i][0], y + dir[i][1]);
                }
            }
            break;
        case '.':
            if (x + 1 < R && map[x + 1][y] != '#' && visS[x + 1][y] == 0)
            {
                dfsS(x + 1, y);
            }
            break;
    }
}

void dfsT(int x, int y, int preX, int preY)
{
    if (visT[x][y] || map[x][y] == '#')
    {
        return ;
    }
    
    if (map[x][y] == '.' && preX == x + 1 && preY == y)
    {
        visT[x][y] = 1;
    }
    else if (map[x][y] == '-' && preX == x)
    {
        visT[x][y] = 1;
    }
    else if (map[x][y] == '|' && preY == y)
    {
        visT[x][y] = 1;
    }
    else if (map[x][y] == '+')
    {
        visT[x][y] = 1;
    }
    
    if (visT[x][y] == 0)
    {
        return ;
    }

    if (x - 1 >= 0)
    {
        dfsT(x - 1, y, x, y);
    }
    if (x + 1 < R)
    {
        dfsT(x + 1, y, x, y);
    }
    if (y - 1 >= 0)
    {
        dfsT(x, y - 1, x, y);
    }
    if (y + 1 < C)
    {
        dfsT(x, y + 1, x, y);
    }
}

int main(int argc, const char * argv[])
{
    memset(visS, 0, sizeof(visS));
    memset(visT, 0, sizeof(visT));

    cin >> R >> C;
    
    int xS = 0, xT = 0, yS = 0, yT = 0;
    for (int i = 0; i < R; i++)
    {
        scanf("%s", map[i]);
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] == 'S')
            {
                xS = i;
                yS = j;
                map[i][j] = '+';
            }
            else if (map[i][j] == 'T')
            {
                xT = i;
                yT = j;
                map[i][j] = '+';
            }
        }
    }
    
    dfsS(xS, yS);
    
    if (visS[xT][yT] == 0)
    {
        cout << "I'm stuck!\n";
        return 0;
    }
    
    dfsT(xT, yT, xT, yT);
    
    int counts = 0;
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] != 'S' && map[i][j] != 'T' &&
                visS[i][j]  && !visT[i][j])
            {
                counts++;
            }
        }
    }
    
    std::cout << counts << '\n';
    
    return 0;
}
