//
//  main.cpp
//  f-51Nod-1765-谷歌的恐龙
//
//  Created by ZYJ on 2017/7/4.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

#include <stdio.h>

long long n, m;

int main(int argc, const char * argv[])
{
    scanf("%lld%lld", &n, &m);
    printf("%.6f\n", n * 1.0 * (n - 1) / 2 / m);
    
    return 0;
}
