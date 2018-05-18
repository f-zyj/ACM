//
//  main.cpp
//  f-HDU-5881-Tea
//
//  Created by ZYJ on 2017/6/28.
//  Copyright &#169; 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

ll L, R;

ll solve(ll l, ll r)
{
    if (r <= 1)
    {
        return 0;
    }
    if (r <= 2)
    {
        return 1;
    }
    if (l == r || l == r - 1)
    {
        return 2;
    }
    if (l < 1)
    {
        l = 1;
    }
    return (r - l) / 2 + 1;
}

int main()
{
    while (~scanf("%lld%lld", &L, &R))
    {
        printf("%lld\n", solve(L, R));
    }
    
    return 0;
}
