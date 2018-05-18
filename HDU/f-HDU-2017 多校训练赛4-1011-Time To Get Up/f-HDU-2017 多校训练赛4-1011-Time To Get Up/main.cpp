//
//  main.cpp
//  f-HDU-2017 多校训练赛4-1011-Time To Get Up
//
//  Created by ZYJ on 2017/8/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 8;
const int MAXM = 22;

char map[MAXN][MAXM];
char tmp[MAXN][MAXN];

int check()
{
    if (tmp[4][2] == 'X')
    {
        if (tmp[3][1] == '.' && tmp[5][1] == 'X' && tmp[3][4] == 'X' && tmp[5][4] == '.')
        {
            return 2;
        }
        else if (tmp[3][1] == '.' && tmp[5][1] == '.' && tmp[3][4] == 'X' && tmp[5][4] == 'X')
        {
            return 3;
        }
        else if (tmp[3][1] == 'X' && tmp[5][1] == '.' && tmp[3][4] == 'X' && tmp[5][4] == 'X' && tmp[1][3] == '.')
        {
            return 4;
        }
        else if (tmp[3][1] == 'X' && tmp[5][1] == '.' && tmp[3][4] == '.' && tmp[5][4] == 'X')
        {
            return 5;
        }
        else if (tmp[3][1] == 'X' && tmp[5][1] == 'X' && tmp[3][4] == '.' && tmp[5][4] == 'X')
        {
            return 6;
        }
        else if (tmp[3][1] == 'X' && tmp[5][1] == 'X' && tmp[3][4] == 'X' && tmp[5][4] == 'X')
        {
            return 8;
        }
        else
        {
            return 9;
        }
    }
    else
    {
        if (tmp[3][1] == 'X' && tmp[5][1] == 'X' && tmp[3][4] == 'X' && tmp[5][4] == 'X')
        {
            return 0;
        }
        if (tmp[3][1] == '.' && tmp[5][1] == '.' && tmp[3][4] == 'X' && tmp[5][4] == 'X' && tmp[1][3] == '.')
        {
            return 1;
        }
        else
        {
            return 7;
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    while (T--)
    {
        for (int i = 1; i < MAXN; i++)
        {
            scanf("%s", map[i] + 1);
        }
        
        for (int i = 1; i < MAXN; i++)
        {
            for (int j = 1; j < 5; j++)
            {
                tmp[i][j] = map[i][j];
            }
        }
        int A = check();
        
        for (int i = 1; i < MAXN; i++)
        {
            for (int j = 6, k = 1; j < 10; j++, k++)
            {
                tmp[i][k] = map[i][j];
            }
        }
        int B = check();
        
        for (int i = 1; i < MAXN; i++)
        {
            for (int j = 13, k = 1; j < 17; j++, k++)
            {
                tmp[i][k] = map[i][j];
            }
        }
        int C = check();
        
        for (int i = 1; i < MAXN; i++)
        {
            for (int j = 18, k = 1; j < 22; j++, k++)
            {
                tmp[i][k] = map[i][j];
            }
        }
        int D = check();
        
        printf("%d%d:%d%d\n", A, B, C, D);
    }
    
    return 0;
}
