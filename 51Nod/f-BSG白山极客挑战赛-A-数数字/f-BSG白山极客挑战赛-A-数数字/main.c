//
//  main.c
//  f-BSG白山极客挑战赛-A-数数字
//
//  Created by ZYJ on 16/5/20.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
int num[5], value[5];

int main(int argc, const char * argv[])
{
    int T;
    int a, b, d, n;
    
    scanf("%d", &T);
    
    while (T--)
    {
        int sum = 0;
        scanf("%d %d %d %d", &a, &b, &d, &n);
        if (n == 1)
        {
            int q = a * b;
            if (q % 10 == d)
            {
                sum++;
            }
            if (q / 10 == d && d != 0)
            {
                sum++;
            }
            printf("%d\n", sum);
            continue;
        }
        num[1] = 1;
        value[1] = a * b % 10;
        num[2] = 1;
        value[2] = (value[1] + a * b / 10) % 10;
        num[3] = n - 2;
        value[3] = (value[1] + a * b / 10 + (value[1] + a * b / 10) / 10) % 10;
        num[4] = 1;
        value[4] = a * b / 10 + (value[1] + a * b / 10) / 10;
        if (value[4] == 0)
        {
            value[4] = -1;
        }
        for (int i = 1; i < 5; i++)
        {
            if (value[i] == d)
            {
                sum += num[i];
            }
        }
        
        printf("%d\n", sum);
    }
    
    return 0;
}