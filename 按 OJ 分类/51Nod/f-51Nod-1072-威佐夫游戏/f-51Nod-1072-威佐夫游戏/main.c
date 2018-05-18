//
//  main.c
//  f-51Nod-1072-威佐夫游戏
//
//  Created by ZYJ on 16/4/20.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main()
{
    int t, a, b, m, k;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &a, &b);
        if (a > b)
        {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        m = b - a;
        k = (int)(m * (1 + sqrt(5)) / 2.0);
        //m = ? * a
        //k = m / ?
        //?:黄金分割数
        //如果a == k，则为后手赢，否则先手赢（奇异局）
        printf("%s\n", a == k ? "B" : "A");
    }
    return 0;
}