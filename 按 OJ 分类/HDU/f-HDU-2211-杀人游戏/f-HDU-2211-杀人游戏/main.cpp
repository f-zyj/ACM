//
//  main.cpp
//  f-HDU-2211-杀人游戏
//
//  Created by ZYJ on 2017/9/6.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>

using namespace std;

int n, k;

int f(int n)
{
    if (n == k)
    {
        return k;
    }
    
    int x = f(n - n / k);
    return (x - 1) / (k - 1) + x;
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d%d", &n, &k);
        printf("%d\n", f(n));
    }
    
    return 0;
}
