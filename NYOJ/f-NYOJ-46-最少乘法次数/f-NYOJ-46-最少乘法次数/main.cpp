//
//  main.cpp
//  f-NYOJ-46-最少乘法次数
//
//  Created by ZYJ on 2016/11/24.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        int n;
        scanf("%d", &n);
        if (n == 1)
        {
            printf("0\n");
            continue;
        }
        
        int sum = 0;
        if (n & 1)
        {
            n -= 1;
            sum = 1;
        }
        while (n != 1)
        {
            n /= 2;
            if (n & 1 && n != 1)
            {
                n -= 1;
                sum++;
            }
            sum++;
        }
        printf("%d\n", sum);
    }
    
    return 0;
}
