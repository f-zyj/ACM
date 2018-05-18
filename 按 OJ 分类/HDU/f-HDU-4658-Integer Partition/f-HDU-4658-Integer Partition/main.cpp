//
//  main.cpp
//  f-HDU-4658-Integer Partition
//
//  Created by ZYJ on 2016/10/13.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

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
        ans[i] = 0;
        for (int j = 1; ; j++)
        {
            int tmp = (3 * j - 1) * j / 2;
            if (tmp > i)
            {
                break;
            }
            int tmp_ = ans[i - tmp];
            if (tmp + j <= i)
            {
                tmp_ = (tmp_ + ans[i - tmp - j]) % MOD;
            }
            if (j & 1)
            {
                ans[i] = (ans[i] + tmp_) % MOD;
            }
            else
            {
                ans[i] = (ans[i] - tmp_ + MOD) % MOD;
            }
        }
    }
    
    return ;
}

int solve(int n, int k)
{
    int res = ans[n];
    for (int i = 1; ; i++)
    {
        int tmp = k * i * (3 * i - 1) / 2;
        if (tmp > n)
        {
            break;
        }
        int tmp_ = ans[n - tmp];
        if (tmp + i * k <= n)
        {
            tmp_ = (tmp_ + ans[n - tmp - i * k]) % MOD;
        }
        if (i & 1)
        {
            res = (res - tmp_ + MOD) % MOD;
        }
        else
        {
            res = (res + tmp_) % MOD;
        }
    }
    return res;
}

int main(int argc, const char * argv[])
{
    init();
    
    int T, n, k;
    
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
    
    return 0;
}
