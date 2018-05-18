//
//  main.cpp
//  f-HDU-2017 多校训练赛6-1002-Mindis
//
//  Created by ZYJ on 2017/8/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef pair<double, double> point;

const double eps = 1e-8;

double r;
point p1, p2;

double get_dis(const point &P1, const point &P2)
{
    double dx = P1.first - P2.first;
    double dy = P1.second - P2.second;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%lf", &r);
        scanf("%lf%lf", &p1.first, &p1.second);
        scanf("%lf%lf", &p2.first, &p2.second);
        
        double C = get_dis(p1, p2) / 2.0;
        double D = get_dis(point(0, 0), p1);
        
        if (D < eps)
        {
            printf("%.7f\n", r * 2.0);
            continue;
        }
        
        double d = sqrt(D * D - C * C);
        double a = C * r / D;
        double y = d * (a * a - C * C) / (C * C);
        if (y < r - d)
        {
            printf("%.7f\n", a * 2.0);
            continue;
        }
    
        printf("%.7f\n", sqrt(C * C + (r - d) * (r - d)) * 2.0);
    }
    
    return 0;
}
