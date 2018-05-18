//
//  main.cpp
//  f-HDU-5933-ArcSoft's Office Rearrangement
//
//  Created by ZYJ on 2017/10/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 10;

long long N, K;
long long a[MAXN];
queue<long long> qi;

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int case_ = 1; case_ <= T; case_++)
    {
        printf("Case #%d: ", case_);
        
        scanf("%lld%lld", &N, &K);
        
        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%lld", a + i);
            sum += a[i];
        }
        
        if (sum % K)
        {
            puts("-1");
            continue;
        }
        
        while (!qi.empty())
        {
            qi.pop();
        }
        
        long long ans = 0, unit = sum / K, t;
        for (int i = 0; i < N; i++)
        {
            if (!qi.empty())
            {
                t = qi.front();
                qi.pop();
                a[i] += t;
                ans++;
            }
            
            if (a[i] > unit)
            {
                t = a[i] / unit;
                ans += t;
                t = a[i] % unit;
                if (t)
                {
                    qi.push(t);
                }
                else
                {
                    ans--;
                }
            }
            else if (a[i] < unit)
            {
                qi.push(a[i]);
            }
        }
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
