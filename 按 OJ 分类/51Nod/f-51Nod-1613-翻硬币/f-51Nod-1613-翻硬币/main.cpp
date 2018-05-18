//
//  main.cpp
//  f-51Nod-1613-翻硬币
//
//  Created by ZYJ on 2017/7/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>

using namespace std;

int n, k;

int main ()
{
    scanf("%d%d", &n, &k);
    
    int t = n / k;
    int r = n % k;
    if (r == 0)
    {
        printf("%d\n", t);
        return 0;
    }
    
    if (t > 1)
    {
        if ((r & 1) == (k & 1))
        {
            printf("%d\n", t + 1);
        }
        else
        {
            if (r & 1)
            {
                puts("-1");
            }
            else
            {
                printf("%d\n", t + 2);
            }
        }
    }
    else
    {
        if (r & 1)
        {
            if (k & 1)
            {
                if ((r << 2) >= n)
                {
                    puts("4");
                }
                else
                {
                    int a = r << 1;
                    int b = n / a;
                    int ans;
                    if (b > 1)
                    {
                        ans = (b + (n % a ? 1 : 0)) << 1;
                    }
                    else
                    {
                        ans = 6;
                    }
                    printf("%d\n", ans);
                }
            }
            else
            {
                puts("-1");
            }
        }
        else
        {
            puts("3");
        }
    }
    
    return 0;
}
