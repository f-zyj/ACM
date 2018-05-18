//
//  main.c
//  f-51Nod-1073-约瑟夫环
//
//  Created by ZYJ on 16/4/20.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>

//数学规律或者公式的方法实现
int main(int argc, const char * argv[])
{
    int N, K, P = 0, i = 2;
    scanf("%d %d", &N, &K);
    for (; i <= N; i++)
    {
        P = (P + K) % i;
    }
    printf("%d\n", P + 1);
    return 0;
}
