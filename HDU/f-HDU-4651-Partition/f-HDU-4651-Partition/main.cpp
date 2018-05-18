//
//  main.cpp
//  f-HDU-4651-Partition
//
//  Created by ZYJ on 16/7/6.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

#define f(x) (((x) * (3 * (x) - 1)) >> 1)
#define g(x) (((x) * (3 * (x) + 1)) >> 1)

using namespace std;

//  整数拆分

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int ans[MAXN];

void init()
{
    memset(ans, 0, sizeof(ans));
    ans[0] = 1;
    for (int i = 1; i < MAXN; ++i)
    {
        for (int j = 1; f(j) <= i; ++j)
        {
            if (j & 1)
            {
                ans[i] = (ans[i] + ans[i - f(j)]) % MOD;
            }
            else
            {
                ans[i] = (ans[i] - ans[i - f(j)] + MOD) % MOD;
            }
        }
        for (int j = 1; g(j) <= i; ++j)
        {
            if (j & 1)
            {
                ans[i] = (ans[i] + ans[i - g(j)]) % MOD;
            }
            else
            {
                ans[i] = (ans[i] - ans[i - g(j)] + MOD) % MOD;
            }
        }
    }
    return ;
}

int main(int argc, const char * argv[])
{
    init();
    
    int T, n;
    
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << ans[n] << '\n';
    }
    
    return 0;
}
