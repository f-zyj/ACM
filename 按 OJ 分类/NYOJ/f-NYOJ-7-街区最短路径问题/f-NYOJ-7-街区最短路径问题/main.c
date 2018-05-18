//
//  main.c
//  f-NYOJ-7-街区最短路径问题
//
//  Created by ZYJ on 16/5/11.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//曼哈顿距离
#include <stdio.h>
#include <string.h>

int x[21], y[21];

int main(int argc, const char * argv[])
{
    int n;
    scanf("%d", &n);
    
    while (n--)
    {
        int m = 0;
        scanf("%d", &m);
        
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", x + i, y + i);
        }
        
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                if (x[i] > x[j])
                {
                    x[i] ^= x[j];
                    x[j] ^= x[i];
                    x[i] ^= x[j];
                }
                if (y[i] > y[j])
                {
                    y[i] ^= y[j];
                    y[j] ^= y[i];
                    y[i] ^= y[j];
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m / 2; i++)
        {
            ans += x[m - 1 - i] - x[i] + y[m - 1 - i] - y[i];
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}