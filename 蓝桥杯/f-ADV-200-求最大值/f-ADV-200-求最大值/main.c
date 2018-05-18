//
//  main.c
//  f-ADV-200-求最大值
//
//  Created by ZYJ on 16/2/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define MAX(a, b) a > b ? a : b
int p[101] = {0};
int ai[101], bi[101];
int key = 1;
int ans = 0;

void swap(int a, int b)
{
    a ^= b;
    b ^= a;
    a ^= b;
    return ;
}

void solve(int i, int d, int aiSum, int biSum)
{
    if (i == key)
    {
        if (ans < d && aiSum > 0 && biSum > 0)
        {
            ans = d;
        }
        return ;
    }
    if (d < 0)
    {
        return ;
    }
    solve(i + 1, d + p[i], aiSum + ai[i], biSum + bi[i]);
    solve(i + 1, d, aiSum, biSum);
    return ;
}

int main(int argc, const char * argv[])
{
    int i, j, n, a, b;
    int aiSum;
    int biSum;
    scanf("%d",&n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d %d", &a, &b);
        if (a > 0 && b > 0)
        {
            aiSum += a;
            biSum += b;
        }
        else if (a > 0 || b > 0)
        {
            ai[key] = a;
            bi[key] = b;
            p[key] = ai[key] + bi[key];
            key++;
        }
    }
    p[0] = aiSum + biSum;
    
    for (i = 1; i < key - 1; i++)
    {
        for (j = i + 1; j < key; j++)
        {
            if (p[i] < p[j])
            {
                swap(p[i], p[j]);
                swap(ai[i], ai[j]);
                swap(bi[i], bi[j]);
            }
        }
    }

    solve(1, p[0], aiSum, biSum);
    
    printf("%d\n", ans);
    return 0;
}
