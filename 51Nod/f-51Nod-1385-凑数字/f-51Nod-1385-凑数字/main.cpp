//
//  main.cpp
//  f-51Nod-1385-凑数字
//
//  Created by ZYJ on 2017/6/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <string.h>

const int MAXN = 1e4 + 10;

char n[MAXN];

int main()
{
    scanf("%s", n);
    int len = (int)strlen(n);
    int res = 0;
    res += 10 * (len - 1);  //  低位都需要对应找到 0 ~ 9
    res += n[0] - '1';      //  n 最高位肯定不需要加 0 的可能，也需要特判一下是否需要加 n[0] 的可能
    int flag = 1;
    for (int i = 1; i < len; i++)
    {
        if (n[i] == n[i - 1])
        {
            continue;
        }
        else if (n[i] > n[i - 1])
        {
            break;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        res++;
    }
    printf("%d\n", res);
    
    return 0;
}
