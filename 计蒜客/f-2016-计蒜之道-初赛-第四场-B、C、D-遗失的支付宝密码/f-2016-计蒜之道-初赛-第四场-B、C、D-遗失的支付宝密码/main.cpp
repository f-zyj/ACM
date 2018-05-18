//
//  main.cpp
//  f-2016-计蒜之道-初赛-第四场-B、C、D-遗失的支付宝密码
//
//  Created by ZYJ on 16/6/11.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

typedef long long LL;
LL MOD = 4294967296;
LL n, m;
LL A[101];

int main(int argc, const char * argv[])
{
    while (std::cin >> n >> m)
    {
        A[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2)
            {
                A[i] = A[i - 1] * m % MOD;
            }
            else
            {
                A[i] = (A[i - 1] * m - A[i / 2]) % MOD;
            }
        }
        LL ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = (ans + A[i]) % MOD;
        }
        std::cout << ans << std::endl;
    }
    
    return 0;
}
