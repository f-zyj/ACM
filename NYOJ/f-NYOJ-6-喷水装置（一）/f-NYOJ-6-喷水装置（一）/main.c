//
//  main.c
//  f-NYOJ-6-喷水装置（一）
//
//  Created by ZYJ on 16/5/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    int m, n;
    int ans;
    float sum;
    float ri[601];
    scanf("%d", &m);
    
    while (m--)
    {
        sum = 0;
        ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%f", ri + i);
        }
        
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (ri[i] < ri[j])
                {
                    float temp = ri[i];
                    ri[i] = ri[j];
                    ri[j] = temp;
                }
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            sum += sqrt(ri[i] * ri[i] - 1);
            ans++;
            if (sum >= 10)
            {
                printf("%d\n", ans);
                break;
            }
        }
    }

    return 0;
}
