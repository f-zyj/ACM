//
//  main.c
//  f-51Nod-1013-3的幂的和
//
//  Created by ZYJ on 16/4/23.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//#define _MAXSIZE 100000000
//#define _MOD 1000000007
//long long POW[_MAXSIZE] = {0};
//
//int main(int argc, const char * argv[])
//{
//    int N, i;
//    long long ans = 0;
//    scanf("%d", &N);
//    POW[0] = 1;
//    POW[1] = 3;
//    for (i = 2; i <= N; i++)
//    {
//        if (i % 2)
//        {
//            POW[i] = POW[i / 2] * POW[i / 2 + 1] % _MOD;
//        }
//        else
//        {
//            POW[i] = POW[i / 2] * POW[i / 2] % _MOD;
//        }
//    }
//    for (i = 0; i <= N; i++)
//    {
//        ans = (ans + POW[i]) % _MOD;
//    }
//    printf("%lld\n", ans);
//    return 0;
//}

//#include <stdio.h>
//
//#define _MOD 1000000007
//
//long long powToSum(long long x, int n)
//{
//    if (n == 0)
//    {
//        return 1;
//    }
//    else
//    {
//        while (!(n & 1))
//        {
//            n >>= 1;
//            x = x * x % _MOD;
//        }
//    }
//    long long result = x;
//    n >>= 1;
//    while (n != 0)
//    {
//        x = x * x % _MOD;
//        if ((n & 1))
//        {
//            result = result * x % _MOD;
//        }
//        n >>= 1;
//    }
//    return result;
//}
//
//int main(int argc, const char * argv[])
//{
//    int N, i;
//    long long ans = 0;
//    scanf("%d", &N);
//    for (i = 0; i <= N; i++)
//    {
//        ans = (ans + powToSum(3, i)) % _MOD;
//    }
//    
//
//    printf("%lld\n", ans);
//    return 0;
//}


//#include <stdio.h>
//#define _MOD 1000000007
//typedef long long ll;
//
//ll c;
//
////快速求幂
//ll power(ll a, ll b)
//{
//    ll ans = 1;
//    while (b)
//    {
//        if (b & 1)
//        {
//            ans = (ans * a) % _MOD;
//            b--;
//        }
//        b >>= 1;
//        a = (a * a) % _MOD;
//    }
//    return ans;
//}
//
//
//ll sum(ll a, ll k)
//{
//    if (k == 1)
//    {
//        return a;
//    }
//    c = sum(a, k >> 1); //前k／2个次幂的和
//    //ans等于前k/2个次幂的和加上接着的k/2个次幂的和（前k/2个次幂的和乘以第k/2个数的次幂）
//    ll ans = (c + c * power(a, (k >> 1))) % _MOD;
//    //加上最后一个奇数次方值
//    if (k & 1)
//    {
//        ans = (ans + power(a, k)) % _MOD;
//    }
//    return ans;
//}
//
//int main()
//{
//    ll n;
//    scanf("%lld", &n);
//    printf("%lld\n", ((sum(3, n) % _MOD)) + 1);
//    return 0;
//}


#include<stdio.h>
#define mod 1000000007
typedef long long ll;

ll mod_pow(ll x,ll n)
{
    ll res = 1;
    while(n > 0)
    {
        if(n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    ll n, ans;
    scanf("%lld", &n);
    n++;
    ans = (mod_pow(3, n) - 1) * 500000004 % mod;    //求2的逆元即可.因为2 * ? = 1 (mod 1000000007)  ? = 500000004
    printf("%lld", ans);
    return 0;
}