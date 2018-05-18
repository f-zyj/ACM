//
//  main.cpp
//  f-HDU-2010-水仙花数
//
//  Created by ZYJ on 2017/10/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <stdio.h>

int m, n;

int main()
{
    while (scanf("%d%d", &m, &n) != EOF)
    {
        int b, s, g, t, flag = 1;
        for (int i = m; i <= n; i++)
        {
            t = i;
            g = t % 10;
            t /= 10;
            s = t % 10;
            t /= 10;
            b = t;
            
            if (g * g * g + s * s * s + b * b * b == i)
            {
                if (flag)
                {
                    printf("%d", i);
                }
                else
                {
                    printf(" %d", i);
                }
                flag = 0;
            }
        }
        
        if (flag)
        {
            printf("no");
        }
        printf("\n");
    }
    
    return 0;
}
