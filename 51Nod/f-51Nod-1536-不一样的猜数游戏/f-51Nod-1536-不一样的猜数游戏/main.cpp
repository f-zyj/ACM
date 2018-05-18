//
//  main.cpp
//  f-51Nod-1536-不一样的猜数游戏
//
//  Created by ZYJ on 2017/1/20.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

/*
 *  素数筛选，查找出小于等于MAXN的素数
 *  prime[0]存素数的个数
 */

const int MAXN = 1001;

int prime[MAXN + 1];

void getPrime(int n)
{
    memset(prime, 0, sizeof(prime));
    
    for (int i = 2; i <= n; i++)
    {
        if (!prime[i])
        {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && prime[j] <= n / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}

int flag[MAXN];

int main(int argc, const char * argv[])
{
    int n;
    
    while (cin >> n)
    {
        getPrime(n);
        
        memset(flag, 0, sizeof(flag));
        
        int res = 0;
        for (int i = 1; i <= prime[0]; i++)
        {
            for (int j = 2; j < 10; j++)
            {
                if (pow(prime[i], j) <= n)
                {
                    res++;
                }
            }
        }
        
        printf("%d\n", prime[0] + res);
    }
    
    return 0;
}
