//
//  main.c
//  f-NYOJ-32-组合数
//
//  Created by ZYJ on 16/5/25.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
int flag[10];
int n, r;

void dfs(int place, int rule, int num)  //非全排列，保持高位始终大于低位
{
    if (place == 0)
    {
        printf("%d\n", num);
    }
    for (int i = rule; i > 0; i--)
    {
        if (!flag[i])
        {
            flag[i] = 1;
            dfs(place - 1, i - 1, num + i * pow(10, place - 1));
            flag[i] = 0;
        }
    }
    return ;
}

int main(int argc, const char * argv[])
{
    while (~scanf("%d %d", &n, &r))
    {
        memset(flag, 0, sizeof(flag));
        
        dfs(r, n, 0);
    }
    return 0;
}
