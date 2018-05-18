//
//  main.c
//  f-NYOJ-28-大数阶乘
//
//  Created by ZYJ on 16/5/25.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define PLACE 1000000000000
long long num[1361];    //实验证明1360即可存完5000的阶乘

int main(int argc, const char * argv[])
{
    int m;
    
    while (~scanf("%d", &m))
    {
        memset(num, 0, sizeof(num));
        num[0] = 1;
        int key = 0;
        long long temp;
        
        for (int i = 1; i <= m; i++)
        {
            temp = 0;
            for (int j = 0; j <= key; j++)
            {
                num[j] = num[j] * i + temp;
                temp = num[j] / PLACE;
                num[j] %= PLACE;
            }
            if (temp > 0)
            {
                num[++key] = temp;
            }
        }

        printf("%lld", num[key]);
        for (int i = key - 1; i >= 0; i--)
        {
            printf("%.12lld", num[i]);
        }
        printf("\n");
    }
    
    return 0;
}
