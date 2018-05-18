//
//  main.cpp
//  f-图灵杯-第四届“图灵杯”NEUQ-ACM 程序设计竞赛-D-简单图形输出
//
//  Created by ZYJ on 2017/6/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 11;
const int MAXM = 1100;
const int MAXR = 2100;

char map[MAXN][MAXM][MAXR] = {{}, {" /\\ ",
                                   "/__\\"}};

void init()
{
    for (int i = 2; i < MAXN; i++)
    {
        int col = 1 << (i - 1);
        int row = 1 << i;
        
        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < col; k++)
            {
                map[i][j][k] = map[i][j][k + col + row] = ' ';
            }
        }
        
        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < row; k++)
            {
                map[i][j][col + k] = map[i - 1][j][k];
            }
        }
        
        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < row; k++)
            {
                map[i][col + j][k] = map[i][col + j][k + row] = map[i - 1][j][k];
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    init();
    
    int n;
    while (cin >> n, n)
    {
        int col = 1 << n;
        int row = (1 << n) + 1;
        for (int i = 0; i < col; i++, row++)
        {
            for (int j = 0; j < row; j++)
            {
                printf("%c", map[n][i][j]);
            }
            putchar(10);
        }
        putchar(10);
    }
    
    return 0;
}
