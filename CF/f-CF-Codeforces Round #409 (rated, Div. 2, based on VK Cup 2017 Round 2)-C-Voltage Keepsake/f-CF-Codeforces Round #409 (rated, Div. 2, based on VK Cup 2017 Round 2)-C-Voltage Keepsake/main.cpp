//
//  main.cpp
//  f-CF-Codeforces Round #409 (rated, Div. 2, based on VK Cup 2017 Round 2)-C-Voltage Keepsake
//
//  Created by ZYJ on 2017/4/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;
const int INF = 0x3f3f3f3f;

struct device
{
    int a, b;
    double c;
    
    bool operator < (const device &b) const
    {
        return c < b.c;
    }
} dev[MAXN];

int n, p;

int main(int argc, const char * argv[])
{
    cin >> n >> p;
    
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &dev[i].a, &dev[i].b);
        dev[i].c = dev[i].b * 1.0 / dev[i].a;
        sum += dev[i].a;
    }
    if (p >= sum)
    {
        cout << "-1\n";
        return 0;
    }
    
    sort(dev, dev + n);
    
    dev[n].c = INF;
    long long sumA = 0, sumB = 0;
    for (int i = 0; i < n; i++)
    {
        sumA += dev[i].a;
        sumB += dev[i].b;
        if (sumA <= p)
        {
            continue;
        }
        if (sumB * 1.0 / (sumA - p) <= dev[i + 1].c)
        {
            printf("%.10lf\n", sumB * 1.0 / (sumA - p));
            return 0;
        }
    }
    
    printf("%.10lf\n", sumB * 1.0 / (sumA - p));
    
    return 0;
}
