//
//  main.cpp
//  f-51Nod-1257-背包问题 V3
//
//  Created by ZYJ on 2017/4/14.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 5e4 + 10;
const double ESP = 1e-6;

int N, K;

struct article
{
    int W, P;
    double unit;
} atc[MAXN];

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int cmp(article a, article b)
{
    return a.unit > b.unit;
}

int charge(int &x, int &y, double m)
{
    for (int i = 0; i < N; i++)
    {
        atc[i].unit = atc[i].P - atc[i].W * m;
    }
    sort(atc, atc + N, cmp);
    
    x = y = 0;
    double temp = 0;
    for (int i = 0; i < K; i++)
    {
        x += atc[i].P;
        y += atc[i].W;
        temp += atc[i].unit;
    }
    
    if (temp >= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, const char * argv[])
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &atc[i].W, &atc[i].P);
    }
    
    double left = 0, right = MAXN, mid;
    int z = 0, m = 0, x, y;
    while (fabs(right - left) > ESP)
    {
        mid = (left + right) / 2;
        if (charge(x, y, mid))
        {
            left = mid;
            z = x;
            m = y;
        }
        else
        {
            right = mid;
        }
    }
    
    int temp = gcd(z, m);
    z /= temp;
    m /= temp;
    printf("%d/%d\n", z, m);
    
    return 0;
}
