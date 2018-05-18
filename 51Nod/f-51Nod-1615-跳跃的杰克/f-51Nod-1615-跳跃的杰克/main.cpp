//
//  main.cpp
//  f-51Nod-1615-跳跃的杰克
//
//  Created by ZYJ on 2017/9/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <stdio.h>

int n;

int main()
{
    while (~scanf("%d", &n))
    {
        if (n < 0)
        {
            n = -n;
        }
        
        int now = 0, len = 1;
        int ans = 0;
        while (now < n || (now - n) % 2)
        {
            ans++;
            now += len;
            len++;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
