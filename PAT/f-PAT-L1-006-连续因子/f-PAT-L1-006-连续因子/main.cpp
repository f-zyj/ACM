//
//  main.cpp
//  f-PAT-L1-006-连续因子
//
//  Created by ZYJ on 2017/3/20.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    ll n, m;
    ll head, tail;
    ll ans, pro, temp;
    ll ansHead, ansTail;
    
    while (~scanf("%lld", &n))
    {
        m = sqrt(n) + 1;
        head = ansHead = 2;
        tail = ansTail = 3;
        ans = 1;
        pro = 6;    //  2 * 3
        int flag = 0;
        
        while (head != tail)
        {
            if (tail > m)
            {
                break;
            }
            
            if (n % pro == 0)
            {
                flag = 1;
                temp = tail - head + 1;
                if (ans < temp)
                {
                    ans = temp;
                    ansHead = head;
                    ansTail = tail;
                }
            }
            else if (pro > n)
            {
                pro /= head;
                head++;
                continue;
            }
            
            tail++;
            pro *= tail;
        }
        
        if (flag)
        {
            printf("%lld\n%lld", ans, ansHead);
            for (ll i = ansHead + 1; i <= ansTail; i++)
            {
                printf("*%lld", i);
            }
        }
        else
        {
            printf("1\n");
            if (n & 1)
            {
                int tag = 1;
                for (int i = 3; i < m; i += 2)
                {
                    if (n % i == 0)
                    {
                        tag = 0;
                        printf("%d", i);
                        break;
                    }
                }
                if (tag)
                {
                    printf("%lld", n);
                }
            }
            else
            {
                printf("2");
            }
        }
        puts("");
    }
    
    return 0;
}
