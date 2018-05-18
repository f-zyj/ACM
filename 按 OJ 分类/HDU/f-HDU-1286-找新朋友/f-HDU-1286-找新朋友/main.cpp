//
//  main.cpp
//  f-HDU-1286-找新朋友
//
//  Created by ZYJ on 2017/9/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

//  AC 模版通过
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int n;

/*
 *  同时得到欧拉函数和素数表
 */
const int MAXN = 40000;

bool check[MAXN + 10];
int phi[MAXN + 10];
int prime[MAXN + 10];
int tot;    //  素数个数

void phi_and_prime_table(int N)
{
    memset(check, false, sizeof(check));
    phi[1] = 1;
    tot = 0;
    for (int i = 2; i <= N; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > N)
            {
                break;
            }
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
            {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
    return ;
}

int main(int argc, const char * argv[])
{
    phi_and_prime_table(MAXN);
    
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> n;
        cout << phi[n] << '\n';
    }
    
    return 0;
}
