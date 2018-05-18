//
//  main.cpp
//  f-蓝桥-ALGO-26-麦森数
//
//  Created by ZYJ on 2017/6/4.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <string.h>

const int MAXBIT = 501;

int num[MAXBIT];
int tmp[MAXBIT];
int tep[MAXBIT];

void multiply(int a[], int b[])
{
    memset(tep, 0, sizeof(tep));
    
    for (int i = MAXBIT - 1; i >= 1; i--)
    {
        for (int j = MAXBIT - 1, k = i; j >= 1; j--)
        {
            tep[k--] += a[i] * b[j];
            if (k == 0)
            {
                break;
            }
        }
    }
    
    for (int i = MAXBIT - 1; i >= 1; i--)
    {
        if (tep[i] >= 10)
        {
            tep[i - 1] += tep[i] / 10;
            tep[i] %= 10;
        }
        a[i] = tep[i];
    }
}

void msss(int power)
{
    if (power <= 1)
    {
        num[MAXBIT - 1] *= 2;
        return ;
    }
    else
    {
        msss(power / 2);
        multiply(num, num);
        if (power % 2 != 0)
        {
            multiply(num, tmp);
        }
    }
}

int main()
{
    int p;
    scanf("%d", &p);
    
    num[MAXBIT - 1] = 1;
    tmp[MAXBIT - 1] = 2;
    msss(p);
    num[MAXBIT - 1]--;
    
    printf("%d\n", (int)(p * log10(2)) + 1);
    for (int i = 1; i < MAXBIT; i++)
    {
        printf("%d", num[i]);
        if (i % 50 == 0)
        {
            printf("\n");
        }
    }
    
    return 0;
}
