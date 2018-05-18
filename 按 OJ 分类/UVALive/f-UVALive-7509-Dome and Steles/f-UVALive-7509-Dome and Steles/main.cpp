//
//  main.cpp
//  f-UVALive-7509-Dome and Steles
//
//  Created by ZYJ on 2017/11/23.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1e5 + 10;
const double EPS = 1e-14;

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int n;
double w[MAXN];

double calc(double x)
{
    double x1 = x, x2 = 1 - x;
    if (x1 > x2)
    {
        swap(x1, x2);
    }
    
    double ans = w[n] + x2 * x2;
    for (int i = 1; i < n; i++)
    {
        if (i & 1)
        {
            x1++;
            ans = max(ans, w[n - i] + x1 * x1);
        }
        else
        {
            x2++;
            ans = max(ans, w[n - i] + x2 * x2);
        }
    }
    
    return sqrt(ans);
}

int main()
{
    int T;
    scan_d(T);
    
    for (int ce = 1; ce <= T; ce++)
    {
        printf("Case #%d: ", ce);
        
        scan_d(n);
        double a, b;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf%lf", &a, &b);
            if (a > b)
            {
                swap(a, b);
            }
            
            w[i] = a * a + (b / 2) * (b / 2);
        }
        
        sort(w + 1, w + n + 1);
        
        double l = 0, r = 1;
        while (l < r)
        {
            double m = (l + r) / 2;
            double _m = (m + r) / 2;
            if (calc(_m) < calc(m))
            {
                l = m + EPS;
            }
            else
            {
                r = _m - EPS;
            }
        }
        
        printf("%.10f\n", calc(l));
    }
    
    return 0;
}
