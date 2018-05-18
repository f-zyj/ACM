//
//  main.cpp
//  f-51Nod-1181-质数中的质数（质数筛法）
//
//  Created by ZYJ on 16/7/26.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

/*
 *  素数筛选，查找出小于等于MAXN的素数
 *  prime[0]存素数的个数
 */

const int MAXN = 10000000;
int prime[MAXN];

void getPrime()
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
}

int main(int argc, const char * argv[])
{
    int N;
    getPrime();
    
    while (cin >> N)
    {
        int flag = 0;
        for (int i = 1; i <= N; i++)
        {
            if (prime[i] >= N)
            {
                flag = i;
                break;
            }
        }
        for (int i = 1; i <= flag; i++)
        {
            if (prime[i] >= flag)
            {
                flag = i;
                break;
            }
        }
        cout << prime[prime[flag]] << '\n';
    }
    return 0;
}
