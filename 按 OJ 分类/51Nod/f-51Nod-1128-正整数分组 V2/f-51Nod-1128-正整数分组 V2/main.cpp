//
//  main.cpp
//  f-51Nod-1128-正整数分组 V2
//
//  Created by ZYJ on 2017/3/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 5e4 + 10;

int N, K;

ll A[MAXN];

int check(ll num)
{
    int m = K;
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (sum + A[i] > num)
        {
            sum = A[i];
            m--;
        }
        else
        {
            sum += A[i];
        }
    }
    if (m > 0)
    {
        return 1;
    }
    return 0;
}

ll bs(ll l, ll r)
{
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

int main()
{
    cin >> N >> K;
    
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
        sum += A[i];
    }
    cout << bs(1, sum) << endl;
    
    return 0;
}
