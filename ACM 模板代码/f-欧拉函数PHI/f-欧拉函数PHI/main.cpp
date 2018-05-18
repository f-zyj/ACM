//
//  main.cpp
//  f-欧拉函数PHI
//
//  Created by ZYJ on 16/6/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

//  递推求解

//using namespace std;
//
//const int MAXN = 100;
//int phi[MAXN + 2];
//
//int main(int argc, const char * argv[])
//{
//    for (int i = 1; i <= MAXN; i++)
//    {
//        phi[i] = i;
//    }
//    for (int i = 2; i <= MAXN; i += 2)
//    {
//        phi[i] /= 2;
//    }
//    for (int i = 3; i <= MAXN; i += 2)
//    {
//        if (phi[i] == i)
//        {
//            for (int j = i; j <= MAXN; j += i)
//            {
//                phi[j] = phi[j] / i * (i - 1);
//            }
//        }
//    }
//
//    return 0;
//}

//  单独求解

/*
 *  单独求解的本质是公式的应用
 */

//using namespace std;
//
//const int MAXN = 100;
//int phi[MAXN + 2];
//
//unsigned euler(unsigned x)
//{
//    unsigned i, res = x;    //  unsigned == unsigned int
//    for (i = 2; i < (int)sqrt(x * 1.0) + 1; i++)
//    {
//        if (!(x % i))
//        {
//            res = res / i * (i - 1);
//            while (!(x % i))
//            {
//                x /= i;     //  保证i一定是素数
//            }
//        }
//    }
//    if (x > 1)
//    {
//        res = res / x * (x - 1);
//    }
//    return res;
//}

//  分解质因数

/*
 *  分解质因数求欧拉函数
 */

//int main(int argc, const char * argv[])
//{
//    //  ...
//    getFactors(n);
//    int ret = n;
//    for (int i = 0; i < fatCnt; i++)
//    {
//        ret = ret / factor[i][0] * (factor[i][0] - 1);
//    }
//    return 0;
//}

//  线性筛

/*
 *  同时得到欧拉函数和素数表
 */
const int MAXN = 10000000;
bool check[MAXN + 10];
int phi[MAXN + 10];
int prime[MAXN + 10];
int tot;    //  素数个数

void phi_and_prime_table(int N)
{
    memset(check, false, sizeof(check));
    phi[1] = 1;
    tot = 0;
    for (int i = 2; i <= N; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > N)
            {
                break;
            }
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
            {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
    return ;
}