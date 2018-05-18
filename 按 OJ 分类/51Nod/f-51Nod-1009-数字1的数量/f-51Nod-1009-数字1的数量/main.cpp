//
//  main.cpp
//  f-51Nod-1009-数字1的数量
//
//  Created by ZYJ on 16/7/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cmath>
//#include <cstring>
//
////#pragma warning(disable:4996)
//
//using namespace std;
//
//typedef long long ll;
//
//ll s;
//ll dp[20];  //  前x位中1出现次数（0~9均是如此）
//
//void init()
//{
//    memset(dp, 0, sizeof(dp));
//    
//    int i;
//    for (i = 1; i <= 9; i++)
//    {
//        dp[i] = dp[i - 1] * 10 + pow(10, i - 1);    //  前x-1位出现1次数*10 + 第x位为1的情况数
//    }
//}
//
//ll count(ll x)
//{
//    ll result = 0;
//    ll len = 0;
//    ll digit = 0;
//    ll radix = 1;
//    ll tail = 0;
//    while (x != 0)
//    {
//        digit = x % 10;
//        x = x / 10;
//        
//        ++len;
//        
//        if (digit > 1)
//        {                                           //  radix就代表10的多少多少次方
//            result += radix + digit * dp[len - 1];  //  ex:241 result(200~241) += radix(百位为1）+ digit
//        }                                           //  * dp[len - 1](0~199除去百位为1)
//        else if (digit == 1)
//        {                                           //  +1是代表取的那个整数
//            result += tail + 1 + dp[len - 1];       //  ex:141 result(100~141除去百位的1) += tail(101~141百位
//        }                                           //  为1) + 1(100的百位为1) + dp[len - 1](0~99)
//        tail = tail + digit * radix;                //  头为1个数
//        radix *= 10;                                //  倍率
//    }
//    return result;
//}
//
//int main()
//{
//    //freopen("i.txt","r",stdin);
//    //freopen("o.txt","w",stdout);
//    
//    init();
//    
//    cin >> s;
//    cout << count(s)<<endl;
//    
//    return 0;
//}

#include<iostream>
#include<cstdio>

using namespace std;

int sum[20];
int getlen(int n)
{
    int num = 0;
    while (n)
    {
        n = n / 10;
        num++;
    }
    return num;
}

int main()
{
    int n, i, t1, t2, len, ans;
    cin >> n;
    len = getlen(n);
    sum[1] = n / 10;
    if (n % 10 >= 1)
    {
        sum[1]++;
    }
    for (i = 2, t1 = 10, t2 = 100; i <= len; i++, t1 = t1 * 10, t2 = t2 * 10)
    {
        if (n / t1 % 10 > 1)
        {
            sum[i] = n / t2 + 1;
            sum[i] = sum[i] * t1;
        }
        else if (n / t1 % 10 == 1)
        {
            sum[i] = n / t2;
            sum[i] = sum[i] * t1 + n % t1 + 1;
        }
        else
        {
            sum[i] = n / t2;
            sum[i] = sum[i] * t1;
        }
    }
    ans = 0;
    for (i = 1; i <= len; i++)
    {
        ans += sum[i];
    }
    cout << ans << endl;
    return 0;
}