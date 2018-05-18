//
//  main.cpp
//  f-HDU-1573-X问题
//
//  Created by ZYJ on 2017/9/5.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 11;

ll extgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - a / b * y;
    return d;
}

int n, m;
int a[MAXN], b[MAXN];

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        
        ll ax = a[0], bx = b[0], x, y;
        int flag = 0;
        for (int i = 1; i < m; i++)
        {
            ll d = extgcd(ax, a[i], x, y);
            if ((b[i] - bx) % d != 0)
            {
                flag = 1;   //  无整数解
                break;
            }
            
            ll tmp = a[i] / d;
            x = x * (b[i] - bx) / d;    //  约分
            x = (x % tmp + tmp) % tmp;
            bx = bx + ax * x;
            ax = ax * tmp;              //  ax = ax * a[i] / d
        }
        
        if (flag == 1 || n < bx)
        {
            puts("0");
        }
        else
        {
            ll ans = (n - bx) / ax + 1;
            if (bx == 0)
            {
                ans--;
            }
            printf("%lld\n", ans);
        }
    }
    
    return 0;
}
