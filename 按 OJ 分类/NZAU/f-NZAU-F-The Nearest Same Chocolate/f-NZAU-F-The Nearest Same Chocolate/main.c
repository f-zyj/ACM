//
//  main.c
//  f-NZAU-F-The Nearest Same Chocolate
//
//  Created by ZYJ on 16/5/14.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define INF 0x3f3f3f3f

int main(int argc, const char * argv[])
{
    int T;
    int n;
    int number[105];
    int ans;
    int len;
    scanf("%d", &T);
    
    while (T--)
    {
        ans = INF;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", number + i);
        }
        
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (number[i] == number[j])
                {
                    len = j - i;
                    if (len < ans)
                    {
                        ans = len;
                    }
                    break;
                }
            }
        }
        
        if (ans == INF)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", ans);
        }
    }
    
    return 0;
}

