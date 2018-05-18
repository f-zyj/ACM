//
//  main.cpp
//  f-BNU Training 2016.07.29 Div. 2-B-Levko and Table
//
//  Created by ZYJ on 16/7/29.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>

int main()
{
    int n, m;
    int a[100][100] = {0};
    int i, j = 0;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        a[i][j] = m;
        j++;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i][0]);
        for (j = 1 ; j < n; j++)
        {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
