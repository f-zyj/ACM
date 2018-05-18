//
//  main.c
//  f-51Nod-1004-n^n的末位数字
//
//  Created by ZYJ on 16/5/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    scanf("%d", &a);
    b = a % 10;
    //幂的末尾数字规律为4个一循环
    c = a % 4;
    //c等于0时为第四个
    if (c == 0)
        c = 4;
    c = pow(b, c);
    printf("%d",c % 10);
    return 0;
}