//
//  main.cpp
//  f-SHU-“盛大游戏杯”第15届上海大学程序设计联赛夏季赛暨上海高校金马五校赛-D-添加好友
//
//  Created by ZYJ on 2017/7/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;

ll QPow(ll x, ll n)
{
    ll ret = 1;
    ll tmp = x % MOD;
    
    while (n)
    {
        if (n & 1)
        {
            ret = (ret * tmp) % MOD;
        }
        tmp = tmp * tmp % MOD;
        n >>= 1;
    }
    
    return ret;
}

int n;

int main(int argc, const char * argv[])
{
    while (cin >> n)
    {
        cout << QPow(2, n) - 1 << '\n';
    }
    
    return 0;
}
