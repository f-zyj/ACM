//
//  main.cpp
//  f-莫比乌斯反演
//
//  Created by ZYJ on 16/7/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 *  莫比乌斯反演公式
 *  ￼￼￼￼￼￼￼线性筛法求解积性函数（莫比乌斯函数）
 */
const int MAXN = 1000000;
bool check[MAXN + 10];
int prime[MAXN + 10];
int mu[MAXN + 10];

void Moblus()
{
    memset(check, false, sizeof(check));
    mu[1] = 1;
    int tot = 0;
    for (int i = 2; i <= MAXN; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > MAXN)
            {
                break;
            }
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
            {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    
    std::cout << "Hello, World!\n";
    return 0;
}
