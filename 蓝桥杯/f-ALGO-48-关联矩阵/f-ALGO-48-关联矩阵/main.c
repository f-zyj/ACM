//
//  main.c
//  f-ALGO-48-关联矩阵
//
//  Created by ZYJ on 16/3/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//关联矩阵
#include <stdio.h>
#define _Max 1000
int main(int argc, const char * argv[])
{
    int n, m, a[_Max], b[_Max], i = 0, j = 0, Matrix[105][_Max];
    scanf("%d %d", &n, &m);
    for (; i < m; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
        Matrix[a[i] - 1][i] = 1;
        Matrix[b[i] - 1][i] = -1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m - 1; j++)
        {
            printf("%d ", Matrix[i][j]);
        }
        printf("%d\n", Matrix[i][j]);
    }
    return 0;
}
