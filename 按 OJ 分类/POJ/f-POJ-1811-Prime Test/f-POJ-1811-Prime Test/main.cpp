//
//  main.cpp
//  f-POJ-1811-Prime Test
//
//  Created by ZYJ on 16/7/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 *  Miller_Rabin算法进行素数测试
 *  速度快，可以判断一个n(< 2 ^ 63)的数是不是素数
 */

const int S = 8;    //  随机算法判定次数，一般8～10次就够了

//  计算ret = (a * b) % c a, b, c < 2 ^ 63
long long mult_mod(long long a, long long b, long long c)
{
    a %= c;
    b %= c;
    long long ret = 0;
    long long tmp = a;
    while (b)
    {
        if (b & 1)
        {
            ret += tmp;
            if (ret > c)
            {
                ret -= c;   //  直接取模慢很多
            }
        }
        tmp <<= 1;
        if (tmp > c)
        {
            tmp -= c;
        }
        b >>= 1;
    }
    return ret;
}

//  计算ret = (a ^ n) % mod
long long pow_mod(long long a, long long n, long long mod)
{
    long long ret = 1;
    long long temp = a % mod;
    while (n)
    {
        if (n & 1)
        {
            ret = mult_mod(ret, temp, mod);
        }
        temp = mult_mod(temp, temp, mod);
        n >>= 1;
    }
    return ret;
}

//  通过a ^ (n - 1) = 1(mod n)来判断n是不是素数
//  n - 1 = x * 2 ^ t中间使用二次判断
//  是合数返回true，不一定是合数返回false
bool check(long long a, long long n, long long x, long long t)
{
    long long ret = pow_mod(a, x, n);
    long long last = ret;
    for (int i = 1; i <= t; i++)
    {
        ret = mult_mod(ret, ret, n);
        if (ret == 1 && last != 1 && last != n - 1)
        {
            return true;            //  合数
        }
        last = ret;
    }
    if (ret != 1)
    {
        return true;                //  合数
    }
    else
    {
        return false;               //  不一定是合数
    }
}

//  Miller_Rabin算法
//  是素数返回true，（可能是伪素数）
//  不是素数返回false

bool Miller_Rabin(long long n)
{
    if (n < 2)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }
    if ((n & 1) == 0)
    {
        return false;   //  偶数（合数）
    }
    long long x = n - 1;
    long long t = 0;
    while ((x & 1) == 0)
    {
        x >>= 1;
        t++;
    }
    srand((int)time(NULL));
    
    for (int i = 0; i < S; i++)
    {
        long long a = rand() % (n - 1) + 1;
        if (check(a, n, x, t))
        {
            return false;
        }
    }
    return true;
}

/*
 *  pollard_rho算法进行质因数分解
 */
long long factor[100];  //  质因数分解结果（刚返回时是无序的）
int tol = 0;            //  质因数的个数，编号0～tol-1

long long gcd(long a, long b)
{
    long long t;
    while (b)
    {
        t = a;
        a = b;
        b = t % b;
    }
    if (a >= 0)
    {
        return a;
    }
    else
    {
        return -a;
    }
}

//  找出一个因子
long long pollard_rho(long long x, long long c)
{
    long long i = 1;
    long long k = 2;
    srand((int)time(NULL));
    long long x0 = rand() % (x - 1) + 1;
    long long y = x0;
    while (1)
    {
        i++;
        x0 = (mult_mod(x0, x0, x) + c) % x;
        long long d = gcd(y - x0, x);
        if (d != 1 && d != x)
        {
            return d;
        }
        if (y == x0)
        {
            return x;
        }
        if (i == k)
        {
            y = x0;
            k += k;
        }
    }
}

//  对n进行质因子分解，存入factor，k设置为107左右即可
void findfac(long long n, int k)
{
    if (n == 1)
    {
        return ;
    }
    if (Miller_Rabin(n))
    {
        factor[tol++] = n;
        return ;
    }
    long long p = n;
    int c = k;
    while (p >= n)
    {
        p = pollard_rho(p, c--);    //  值变化，防止死循环
    }
    findfac(p, k);
    findfac(n / p, k);
    return ;
}

//  给出一个N(2 ≤ N < 2 ^ 64)，如果是素数，输出“Prime”，否则输出最小的质因子
int main(int argc, const char * argv[])
{
    int T;
    long long n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        if (Miller_Rabin(n))
        {
            cout << "Prine\n";
        }
        else
        {
            tol = 0;
            findfac(n, 107);
            long long ans = factor[0];
            for (int i = 1; i < tol; i++)
            {
                ans = min(ans, factor[i]);
            }
            cout << ans << '\n';
        }
    }
    
    return 0;
}
