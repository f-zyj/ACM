//
//  main.cpp
//  f-51Nod-1105-第K大的数
//
//  Created by ZYJ on 16/8/19.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

/*
 *  二分套二分
 *  数组A同数组B组合乘积，二分查找第K大
 */
typedef long long ll;

using namespace std;

const int MAXN = 5e4 + 10;

ll N, K;

ll A[MAXN];
ll B[MAXN];

//  查找小于x的元素个数
ll check(ll x)
{
    ll j = N, ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (; j > 0;)
        {
            if (A[i] * B[j] > x)
            {
                j--;
            }
            else
            {
                break;
            }
        }
        ans += j;
    }
    return ans;
}

int main(int argc, const char * argv[])
{
    cin >> N >> K;
    
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld %lld", A + i, B + i);
    }
    sort(A + 1, A + N + 1);
    sort(B + 1, B + N + 1);
    
    ll ans = 0;
    ll key = N * N - K + 1;
    ll low = A[1] * B[1];   //  初始最小值
    ll high = A[N] * A[N];  //  初始最大值
    
    while (high - low > 1)
    {
        ll mid = (low + high) >> 1;
        if (check(mid) >= key)
        {
            ans = mid;
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
