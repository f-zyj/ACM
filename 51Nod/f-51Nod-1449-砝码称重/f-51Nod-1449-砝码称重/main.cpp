//
//  main.cpp
//  f-51Nod-1449-砝码称重
//
//  Created by ZYJ on 16/9/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>

int w, m;

int main()
{
    scanf("%d%d", &w, &m);
    
    if (w <= 3)
    {
        puts("YES");
        return 0;
    }
    
    while (m)
    {
        if (m % w == 1 || m % w == 0)
        {
            m = m / w;
        }
        else if (m % w == w - 1)
        {
            m = m / w + 1;
        }
        else
        {
            puts("NO");
            return 0;
        }
    }
    
    puts("YES");
    
    return 0;
}