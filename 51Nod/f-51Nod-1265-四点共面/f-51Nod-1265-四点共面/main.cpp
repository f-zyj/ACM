//
//  main.cpp
//  f-51Nod-1265-四点共面
//
//  Created by ZYJ on 16/7/29.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

struct  point
{
    double x, y, z;
    point  operator - (point &o)
    {
        point  ans;
        ans.x = this->x - o.x;
        ans.y = this->y - o.y;
        ans.z = this->z - o.z;
        return ans;
    }
};

double  dot_product(const point &a, const point &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

point cross_product(const point &a, const point &b)
{
    point  ans;
    ans.x = a.y * b.z - a.z * b.y;
    ans.y = a.z * b.x - a.x * b.z;
    ans.z = a.x * b.y - a.y * b.x;
    return ans;
}

int main()
{
    point p[4];
    int T;
    for (scanf("%d", &T); T--;)
    {
        for (int i = 0; i < 4; ++i)
        {
            scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
        }
        puts(dot_product(p[3] - p[0], cross_product(p[2] - p[0], p[1] - p[0])) == 0.0 ? "Yes\n" : "No\n");
    }
    return 0;
}