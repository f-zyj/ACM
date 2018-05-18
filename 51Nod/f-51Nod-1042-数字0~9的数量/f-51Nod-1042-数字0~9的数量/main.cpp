//
//  main.cpp
//  f-51Nod-1042-数字0~9的数量
//
//  Created by ZYJ on 16/7/31.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstring>

//#pragma warning(disable:4996)

using namespace std;

typedef long long ll;

ll l, r;
ll dp[22];  //  前x位中1出现次数（0~9均是如此）

void init()
{
    memset(dp, 0, sizeof(dp));
    
    int i;
    for (i = 1; i <= 19; i++)
    {
        dp[i] = dp[i - 1] * 10 + pow(10, i - 1);    //  前x-1位出现1次数*10 + 第x位为1的情况数
    }
}

ll count(ll x, int place)   //  数是x，查询的数位是place
{
    ll result = 0;
    ll len = 0;
    ll digit = 0;
    ll radix = 1;
    ll tail = 0;
    ll nx = x;
    while (x != 0)
    {
        digit = x % 10;
        x = x / 10;
        
        ++len;
        
        if (digit > place)
        {                                           //  radix就代表10的多少多少次方
            result += radix + digit * dp[len - 1];  //  ex:241 result(200~241) += radix(百位为place）+ digit
        }                                           //  * dp[len - 1](0~199除去百位为place)
        else if (digit == place)
        {                                           //  +1是代表取的那个整数
            result += tail + 1 + digit * dp[len - 1];// ex:141 result(100~141除去百位的place) += tail(101~141百位
        }                                           //  为1) + 1(100的百位为place) + dp[len - 1](0~99)
        else if (digit < place)
        {
            result += digit * dp[len - 1];
        }
        tail = tail + digit * radix;                //  头为place个数
        radix *= 10;                                //  倍率
    }
    if (!place)                                     //  删除前缀是0的结果
    {
        ll m = 1;
        while (nx)
        {
            result -= m;
            m *= 10;
            nx = nx / 10;
        }
    }
    return result;
}

int main()
{
//    freopen("input.txt","r",stdin);
    //freopen("o.txt","w",stdout);
    
    init();
    
    cin >> l >> r;

    for (int i = 0; i < 10; i++)
    {
        cout << count(r, i) - count(l - 1, i) << '\n';
    }
    
    return 0;
}