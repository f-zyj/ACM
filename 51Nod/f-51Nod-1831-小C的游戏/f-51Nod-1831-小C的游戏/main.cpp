//
//  main.cpp
//  f-51Nod-1831-小C的游戏
//
//  Created by ZYJ on 2017/7/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <cmath>
//
//using namespace std;
//
//int n;
//
//bool is_prime(int x)
//{
//    if (x < 2)
//    {
//        return false;
//    }
//    
//    int tmp = sqrt(x) + 1;
//    for (int i = 2; i < tmp; i++)
//    {
//        if (x % i == 0)
//        {
//            return false;
//        }
//    }
//    
//    return true;
//}
//
//
//int main()
//{
//    int T;
//    scanf("%d", &T);
//    
//    while (T--)
//    {
//        scanf("%d", &n);
//        bool flag = false;
//        if (is_prime(n))
//        {
//            if (n == 2 || n == 17)
//            {
//                flag = !flag;
//            }
//        }
//        else
//        {
//            if (n > 2 && n != 16 && n != 34 && n != 289)
//            {
//                flag = !flag;
//            }
//        }
//        
//        puts(flag ? "TAK" : "NIE");
//    }
//    
//    return 0;
//}


#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN = 10000;

bool flag[MAXN];

/*
 *  素数筛选，判断小于MAXN的数是不是素数
 *  notprime是一张表，false表示是素数，true表示不是
 */
bool notprime[MAXN];

void init()
{
    memset(notprime, false, sizeof(notprime));
    notprime[0] = notprime[1] = true;
    for (int i = 2; i < MAXN; i++)
    {
        if (!notprime[i])
        {
            if (i > MAXN / i)   //  阻止后边i * i溢出（或者i,j用long long)
            {
                continue;
            }
            //  直接从i * i开始就可以，小于i倍的已经筛选过了
            for (int j = i * i; j < MAXN; j += i)
            {
                notprime[j] = true;
            }
        }
    }
    
    memset(flag, 0, sizeof(flag));
    
    for (int i = 2; i < MAXN; i++)
    {
        flag[i] |= (!flag[i - 1]);
        if (flag[i])
        {
            continue;
        }
        
        int tmp = sqrt(i) + 1;
        for (int j = 2; j <= tmp; j++)
        {
            if (i % j == 0)
            {
                flag[i] |= (!flag[j]);
                flag[i] |= (!flag[i / j]);
                if (flag[i])
                {
                    break;
                }
            }
        }
    }
}

int main()
{
    init();
    
    for (int i = 0; i < MAXN; i++)
    {
        if (notprime[i] && flag[i] == 0)
        {
            printf("%d-%d\n", i, flag[i]);
        }
        else if (!notprime[i] && flag[i] == 1)
        {
            printf("%d-%d\n", i, flag[i]);
        }
    }
    
    return 0;
}
