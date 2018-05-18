//
//  main.cpp
//  f-PAT-天梯赛习题集-L3-013-非常弹的球
//
//  Created by ZYJ on 2017/3/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int ENERGY = 1000;
const double G = 9.8;
const double ESP = 0.0001;

int main(int argc, const char * argv[])
{
    double w, p;
    cin >> w >> p;
    w /= 100;
    p = (100 - p) / 100;
    
    double ene = ENERGY;
    double res = 0;
    double v = 1;
    
    while (v > ESP)
    {
        v = sqrt(2 * ene / w);
        double vc = v * sqrt(2) / 2;
        double t = vc / G;
        res += vc * t * 2;
        ene *= p;
    }
    
    printf("%.3lf\n", res);

    return 0;
}
