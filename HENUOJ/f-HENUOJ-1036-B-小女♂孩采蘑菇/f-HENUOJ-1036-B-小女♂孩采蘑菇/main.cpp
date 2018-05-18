//
//  main.cpp
//  f-HENUOJ-1036-B-小女♂孩采蘑菇
//
//  Created by ZYJ on 16/8/29.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;

int n, t;
int a[MAXN];
ll sum[MAXN];
ll ans = 0;

int main(int argc, const char * argv[])
{
    cin >> n >> t;
    
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        sum[i] = sum[i - 1] + a[i];
    }
    
    for (int i = 1; i < n; i++)
    {
        if (t + 1 < i)
        {
            break;
        }
        ll res = sum[i] + (t - i + 1) / 2 * a[i] + (t - i + 2) / 2 * a[i + 1];
        if (res > ans)
        {
            ans = res;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
