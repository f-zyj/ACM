//
//  main.c
//  f-PREV-2-打印十字图
//
//  Created by ZYJ on 16/3/9.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
int i = 0, j = 0;
char Graph[125][125];
void centre(int n)
{
    Graph[2 * n + 3][2 * n + 3] = '$';
    Graph[2 * n + 2][2 * n + 3] = '$';
    Graph[2 * n + 1][2 * n + 3] = '$';
    Graph[2 * n + 4][2 * n + 3] = '$';
    Graph[2 * n + 5][2 * n + 3] = '$';
    Graph[2 * n + 3][2 * n + 1] = '$';
    Graph[2 * n + 3][2 * n + 2] = '$';
    Graph[2 * n + 3][2 * n + 4] = '$';
    Graph[2 * n + 3][2 * n + 5] = '$';
    return ;
}
void vertical(int n)
{
    for (i = 1; i < 2 * n; i += 2)
    {
        for (j = i + 2; j <= 5 + 4 * n - 1 - i; j++)
        {
            Graph[j][i] = '$';
            Graph[6 + 4 * n - j][6 + 4 * n - i] = '$';
        }
    }
    return ;
}
void horizontal(int n)
{
    for (i = 1; i < 2 * n; i += 2)
    {
        for (j = i + 2; j <= 5 + 4 * n - 1 - i; j++)
        {
            Graph[i][j] = '$';
            Graph[6 + 4 * n - i][6 + 4 * n - j] = '$';
        }
    }
    return ;
}
void corner(int n)
{
    for (i = 1; i <= n; i++)
    {
        Graph[2 * i + 1][2 * i +1] = '$';
        Graph[2 * i][2 * i + 1] = '$';
        Graph[2 * i + 1][2 * i] = '$';
        Graph[2 * i + 1][5 + 4 * n - 2 * i] = '$';
        Graph[2 * i][5 + 4 * n - 2 * i] = '$';
        Graph[2 * i + 1][6 + 4 * n - 2 * i] = '$';
        Graph[5 + 4 * n - 2 * i][2 * i + 1] = '$';
        Graph[5 + 4 * n - 2 * i][2 * i] = '$';
        Graph[6 + 4 * n - 2 * i][2 * i + 1] = '$';
        Graph[5 + 4 * n - 2 * i][5 + 4 * n - 2 * i] = '$';
        Graph[5 + 4 * n - 2 * i][6 + 4 * n - 2 * i] = '$';
        Graph[6 + 4 * n - 2 * i][5 + 4 * n - 2 * i] = '$';
    }
    return ;
}
int main(int argc, const char * argv[])
{
    int n;
    scanf("%d", &n);
    //初始化图形
    for (i = 1; i <= 5 + 4 * n; i++)
    {
        for (j = 1; j <= 5 + 4 * n; j++)
        {
            Graph[i][j] = '.';
        }
    }
    //修正图形
    centre(n);
    vertical(n);
    horizontal(n);
    corner(n);
    //输出图形
    for (i = 1; i <= 5 + 4 * n; i++)
    {
        for (j = 1; j <= 5 + 4 * n; j++)
        {
            printf("%c", Graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}
