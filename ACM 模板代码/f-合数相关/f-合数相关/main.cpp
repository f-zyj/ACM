//
//  main.cpp
//  f-合数相关
//
//  Created by ZYJ on 16/7/1.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;
//  合数分解

/*
 *  合数的分解需要先进行素数的筛选
 */

const int MAXN = 10000;

int prime[MAXN + 1];

//  获取素数
void gerPrime()
{
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i <= MAXN; i++)
    {
        if (!prime[i])
        {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    return ;
}

long long factor[100][2];
int fatCnt;

//  合数分解
int gerFactors(long long x)
{
    fatCnt = 0;
    long long tmp = x;
    for (int i = 1; prime[i] <= tmp / prime[i]; i++)
    {
        factor[fatCnt][1] = 0;
        if (tmp % prime[i] == 0)
        {
            factor[fatCnt][0] = prime[i];
            while (tmp % prime[i] == 0)
            {
                factor[fatCnt][1]++;
                tmp /= prime[i];
            }
            fatCnt++;
        }
    }
    if (tmp != 1)
    {
        factor[fatCnt][0] = tmp;
        factor[fatCnt++][1] = 1;
    }
    return fatCnt;
}

int main(int argc, const char * argv[])
{
    std::cout << "Hello, World!\n";
    return 0;
}
