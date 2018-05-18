//
//  main.cpp
//  f-51Nod-1451-合法三角形
//
//  Created by ZYJ on 2017/6/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

const int MAXN = 2222;
const int INF = 0x3f3f3f3f;
const double ESP = 1e-6;

ll n;
ll rep = 0;
ll x[MAXN], y[MAXN];
double slope[MAXN * MAXN];

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        int k = 0;
        for (int j = i + 1; j <= n; j++)
        {
            double x_ = x[j] - x[i];
            double y_ = y[j] - y[i];
            
            double res;
            if (x_ == 0)
            {
                res = INF;
            }
            else
            {
                res = y_ / x_;
            }
            slope[k++] = res;
        }
        
        sort(slope, slope + k);
        
        int last = 0, now = 1, tmp;
        for (; now < k; now++)
        {
            if (abs(slope[now] - slope[last]) > ESP)
            {
                tmp = now - last;
                rep += tmp * (tmp - 1) / 2;
                last = now;
            }
        }
        tmp = now - last;
        rep += tmp * (tmp - 1) / 2;
    }
}

int main()
{
    scanf("%lld", &n);
    
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &x[i], &y[i]);
    }
    
    solve();
    
    printf("%lld\n", n * (n - 1) * (n - 2) / 6 - rep);  //  C(n, 3) - rep
    
    return 0;
}
