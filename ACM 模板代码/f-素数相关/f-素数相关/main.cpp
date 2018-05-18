//
//  main.cpp
//  f-素数相关
//
//  Created by ZYJ on 16/6/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

//  素数筛选（判断小于MAXN的数是不是素数）

/*
 *  素数筛选，判断小于MAXN的数是不是素数
 *  notprime是一张表，false表示是素数，true表示不是
 */

//const int MAXN = 1000010;
//bool notprime[MAXN];
//
//void init()
//{
//    memset(notprime, false, sizeof(notprime));
//    notprime[0] = notprime[1] = true;
//    for (int i = 2; i < MAXN; i++)
//    {
//        if (!notprime[i])
//        {
//            if (i > MAXN / i)   //  阻止后边i * i溢出（或者i,j用long long)
//            {
//                continue;
//            }
//            //  直接从i * i开始就可以，小于i倍的已经筛选过了
//            for (int j = i * i; j < MAXN; j += i)
//            {
//                notprime[j] = true;
//            }
//        }
//    }
//}

//  素数筛选（查找出小于等于MAXN的素数）

/*
 *  素数筛选，查找出小于等于MAXN的素数
 *  prime[0]存素数的个数
 */

//const int MAXN = 100000;
//int prime[MAXN + 1];
//
//void getPrime()
//{
//    memset(prime, 0, sizeof(prime));
//    for (int i = 2; i <= MAXN; i++)
//    {
//        if (!prime[i])
//        {
//            prime[++prime[0]] = i;
//        }
//        for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++)
//        {
//            prime[prime[j] * i] = 1;
//            if (i % prime[j] == 0)
//            {
//                break;
//            }
//        }
//    }
//}

//  大区间素数筛选(POJ 2689)

/*
 *  POJ 2689 Prime Distance
 *  给出一个区间[L, U]，找出区间内相邻的距离最近的两个素数
 *  和距离最远的两个素数
 *  1 ≤ L < U ≤ 2,147,483,647  区间长度不超过1,000,000
 *  就是筛选出[L, U]之间的素数
 */

//const int MAXN = 100010;
//int prime[MAXN + 1];
//
////  预处理
//void getPrime()
//{
//    memset(prime, 0, sizeof(prime));
//    for (int i = 2; i <= MAXN; i++)
//    {
//        if (!prime[i])
//        {
//            prime[++prime[0]] = i;
//        }
//        for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++)
//        {
//            prime[prime[j] * i] = 1;
//            if (i % prime[j] == 0)
//            {
//                break;
//            }
//        }
//    }
//}
//
//bool notPrime[1000010];
//int primes[1000010];
//
//void getPrimes(int L, int R)
//{
//    memset(notPrime, false, sizeof(notPrime));
//    if (L < 2)
//    {
//        L = 2;
//    }
//    for (int i = 1; i <= prime[0] && (long long)prime[i] * prime[i] <= R; i++)
//    {
//        int s = L / prime[i] + (L % prime[i] > 0);  //  进一法获取起始位置
//        if (s == 1)
//        {
//            s = 2;
//        }
//        for (int j = s; (long long)j * prime[i] <= R; j++)
//        {
//            if ((long long)j * prime[i] >= L)
//            {
//                notPrime[j * prime[i] - L] = true;
//            }
//        }
//    }
//    primes[0] = 0;
//    for (int i = 0; i <= R - L; i++)
//    {
//        if (!notPrime[i])
//        {
//            primes[++primes[0]] = i + L;            //  将素数统一存入primes数组
//        }
//    }
//}
//
//int main(int argc, const char * argv[])
//{
//    //  预处理
//    getPrime();
//    int L, U;
//    while (cin >> L >> U)
//    {
//        getPrimes(L, U);
//        if (primes[0] < 2)
//        {
//            cout << "There are no adjacent primes.\n";
//        }
//        else
//        {
//            int xOne = 0, xTwo = 100000000, yOne = 0, yTwo = 0;
//            for (int i = 1; i < primes[0]; i++)
//            {
//                if (primes[i + 1] - primes[i] < xTwo - xOne)    //  排查最近的素数
//                {
//                    xOne = primes[i];
//                    xTwo = primes[i + 1];
//                }
//                if (primes[i + 1] - primes[i] > yTwo - yOne)
//                {
//                    yOne = primes[i];
//                    yTwo = primes[i + 1];
//                }
//            }
//            cout << xOne << ',' << xTwo << "are closest," << yOne << ',' << yTwo << "are most distant.\n";
//        }
//    }
//
//    return 0;
//}

/*
 *  随机素数测试（伪素数原理）
 *  CALL: bool res = miller(n);
 *  快速测试n是否满足素数的“必要”条件，出错概率极低
 *  对于任意奇数n > 2和正整数s，算法出错概率≤2^(-s)
 */

int witness(int a, int n)
{
    int x, d = 1;
    int i = ceil(log(n - 1.0) / log(2.0)) - 1;
    for (; i >= 0; i--)
    {
        x = d;
        d = (d * d) % n;
        if (d == 1 && x != 1 && x != n - 1)
        {
            return 1;
        }
        if (((n - 1) & (1 << i)) > 0)
        {
            d = (d * a) % n;
        }
    }
    return (d == 1 ? 0 : 1);
}

int miller(int n, int s = 50)
{
    if (n == 2)     //  质数返回1
    {
        return 1;
    }
    if (n % 2 == 0) //  偶数返回0
    {
        return 0;
    }
    int j, a;
    for (j = 0; j < a; j++)
    {
        a = rand() * (n - 2) / RAND_MAX + 1;
        //  rand()只能随机产生[0, RAND_MAX)内的整数
        //  而且这个RAND_MAX只有32768直接%n的话是永远
        //  也产生不了[RAND_MAX, n)之间的数
        if (witness(a, n))
        {
            return 0;
        }
    }
    return 1;
}
