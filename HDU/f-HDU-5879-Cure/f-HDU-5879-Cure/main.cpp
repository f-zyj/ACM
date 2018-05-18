//
//  main.cpp
//  f-HDU-5879-Cure
//
//  Created by ZYJ on 2017/6/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>

using namespace std;

const int MAXN = 1e6 + 10;
const double LIMIT = 1.64493;

double A[MAXN] = {0, 1};

void init()
{
    for (int i = 2; i < MAXN; i++)
    {
        A[i] = A[i - 1] + 1.0 / (i * 1.0 * i);
    }
}

long long n;

int main()
{
    init();
    
    while (~scanf("%lld", &n))
    {
        if (n < MAXN)
        {
            printf("%.5f\n", A[n]);
        }
        else
        {
            printf("%.5f\n", LIMIT);
        }
    }
    
    return 0;
}



