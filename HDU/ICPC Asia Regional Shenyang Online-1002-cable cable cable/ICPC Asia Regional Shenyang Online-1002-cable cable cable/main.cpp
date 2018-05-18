//
//  main.cpp
//  ICPC Asia Regional Shenyang Online-1002-cable cable cable
//
//  Created by ZYJ on 2017/9/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

long long n, k;

int main()
{
    while (~scanf("%lld%lld", &n, &k))
    {
        printf("%lld\n", (n - k) * k + k);
    }
    
    return 0;
}
