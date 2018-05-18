//
//  main.cpp
//  f-"玲珑杯“ ACM热身赛 # 0.5-A-Alarm
//
//  Created by ZYJ on 16/8/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

typedef long long ll;

using namespace std;

const int MAXN_ = 1e4 + 10;

ll K[MAXN_];

/*
 *  素数筛选，查找出小于等于MAXN的素数
 *  prime[0]存素数的个数
 */

const int MAXN = 1e5 + 1e4;
ll prime[MAXN + 1];

void getPrime()
{
    memset(prime, 0, sizeof(prime));
    for (ll i = 2; i <= MAXN; i++)
    {
        if (!prime[i])
        {
            prime[++prime[0]] = i;
        }
        for (ll j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++)
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

void init()
{
    getPrime();
    for (int i = 1; i < MAXN_; i++)
    {
        K[i] = prime[i] * prime[i] - i;
//        cout << i << ' ' << K[i] << '\n';
    }
}

int main(int argc, const char * argv[])
{
    init();
    
    int T;
    cin >> T;
    
    int N;
    while (T--)
    {
        cin >> N;
        cout << K[N] << '\n';
    }
    
    return 0;
}
