//
//  main.c
//  f-51Nod-1003-阶乘后面的0的数量
//
//  Created by ZYJ on 16/5/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    int fivePow[] = {1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625};
    int n;
    while (~scanf("%d", &n))
    {
        int sum = 0;
        for (int i = 1; i < 13; i++)
        {
            sum += n / fivePow[i];
        }
        printf("%d\n", sum);
    }
    return 0;
}