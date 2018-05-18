//
//  main.cpp
//  f-计蒜客-2017 ACM-ICPC 亚洲区（乌鲁木齐赛区）网络赛-E-Half-consecutive Numbers
//
//  Created by ZYJ on 2017/9/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 111;
const ll INF = 1e16;

ll n;
ll t[MAXN];

void init()
{
    t[0] = 0, t[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        t[i] = 6 * t[i - 1] - t[i - 2] + 2;
        if (t[i] > INF)
        {
            break;
        }
    }
}

int main()
{
    init();
    
    int T;
    cin >> T;
    
    for (int i = 1, j; i <= T; i++)
    {
        scanf("%lld", &n);
        
        j = 0;
        while (true)
        {
            if (t[j] >= n)
            {
                printf("Case #%d: %lld\n", i, t[j]);
                break;
            }
            j++;
        }
    }
    
    return 0;
}
