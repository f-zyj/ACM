//
//  main.cpp
//  f-51Nod-1333-无聊的数学家们
//
//  Created by ZYJ on 16/9/6.
//  Copyright ? 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//
//const int MAXN = 5e6 + 5;
//
//int prime[MAXN];
//bool prime_[MAXN];
//bool num[MAXN];
//long long ans[MAXN];
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
//    return ;
//}
//
//void init()
//{
//    memset(num, true, sizeof(num));
//    memset(prime_, true, sizeof(prime_));
//    num[0] = num[1] = false;
//    
//    getPrime();
//    for (int i = 1; i <= prime[0]; i++)
//    {
//        num[prime[i]] = false;
//        prime_[prime[i]] = false;
//    }
//    
//    for (int i = 4; i < MAXN; i++)
//    {
//        if (num[i])
//        {
//            for (int j = 1; prime[j] <= i / prime[j]; j++)
//            {
//                if (i % prime[j] == 0)
//                {
//                    if (prime_[prime[j] + i / prime[j] - 1])
//                    {
//                        num[i] = false;
//                        break;
//                    }
//                    int k = 2;
//                    while (k * prime[j] <= i / (k * prime[j]))
//                    {
//                        if (i % (k * prime[j]) == 0 && prime_[k * prime[j] + i / (k * prime[j]) - 1])
//                        {
//                            num[i] = false;
//                            break;
//                        }
//                        k++;
//                    }
//                }
//            }
//        }
//    }
//    return ;
//}
//
//void solve()
//{
//    memset(ans, 0, sizeof(ans));
//    
//    for (int i = 1; i < MAXN; i++)
//    {
//        if (num[i])
//        {
//            ans[i] = ans[i - 1] + i + 1;
//        }
//        else
//        {
//            ans[i] = ans[i - 1];
//        }
//    }
//}
//
//int main(int argc, const char * argv[])
//{
//    init();
//    solve();
//    
//    int T;
//    scanf("%d", &T);
//    while (T--)
//    {
//        int L, R;
//        scanf("%d %d", &L, &R);
//        printf("%lld\n", ans[R - 1] - ans[L == 1 ? 0 : L - 2]);
//    }
//    
//    return 0;
//}

#include <stdio.h>
#include <math.h>

#define SIZE 5000001

bool isPrime[SIZE];
bool isAnswer[SIZE];

void getPrime()
{
    int i, j, tmp;
    //  合数为true，素数为false
    for (i = 2; i < SIZE; i += 2)
    {
        isPrime[i] = true;
    }
    for (i = 1; i < SIZE; i += 2)
    {
        isPrime[i] = false;
    }
    isPrime[0] = false; //  方便赋值给isAnswer
    isPrime[2] = false;
    for (i = 3; i <= sqrt(SIZE); i++)
    {
        if (!isPrime[i])
        {
            tmp = i << 1;
            for (j = i * i; j < SIZE; j += tmp)
            {
                isPrime[j] = true;
            }
        }
    }
    return;
}

int main()
{
    int i, j, L, R, T, tmp1, tmp2;
    long long sum;
    getPrime();
    
    for (i = 0; i < SIZE - 1; i++)
    {
        isAnswer[i] = isPrime[i];
    }
    //  用isPrime保存质数加1的状态
    tmp1 = SIZE - 1;
    for (i = 3; i < tmp1; i++)
    {
        if (!isPrime[i])
        {
            isPrime[i] = true;
            isPrime[i + 1] = false;
            i++;
        }
    }
    
    tmp1 = sqrt(tmp1);
    for (i = 2; i <= tmp1; i++)
    {
        tmp2 = (SIZE - 2) / i;
        for (j = i; j <= tmp2; j++)
        {
            if (isPrime[i + j])
            {
                isAnswer[i * j] = false;
            }
        }
    }
    //  更新为s的状态
    for (i = SIZE - 2; i > 0;i--)
    {
        if (isAnswer[i])
        {
            isAnswer[i] = false;
            isAnswer[i + 1] = true;
        }
    }
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d", &L, &R);
        sum = 0;
        for (i = L; i <= R; i++)
        {
            if (isAnswer[i])
            {
                sum += i;
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}