//
//  main.cpp
//  f-HDU-2007-平方和与立方和
//
//  Created by ZYJ on 2017/10/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <stdio.h>

int st, ed;

int main()
{
    while (scanf("%d%d", &st, &ed) != EOF)
    {
        if (st > ed)
        {
            int t = st;
            st = ed;
            ed = t;
        }
        
        int sum_0 = 0, sum_1 = 0;
        for (int i = st; i <= ed; i++)
        {
            if (i % 2 == 1)
            {
                sum_1 = sum_1 + i * i * i;
            }
            else
            {
                sum_0 = sum_0 + i * i;
            }
        }
        
        printf("%d %d\n", sum_0, sum_1);
    }
    
    return 0;
}
