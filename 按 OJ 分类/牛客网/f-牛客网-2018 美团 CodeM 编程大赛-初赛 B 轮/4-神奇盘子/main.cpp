//
//  main.cpp
//  f-牛客网-2018 美团 CodeM 编程大赛-初赛 B 轮
//
//  Created by ZYJ on 2018/6/23.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <iostream>
#include <cmath>

using namespace std;

const double ESP = 1e-3;
const double CIR = 360;
const double PI = 3.1415926;

int r;
double x, y, xx, yy;

double dis(double x, double y, double x1, double y1)
{
    return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}

int main(int argc, const char * argv[])
{
    cin >> r;
    cin >> x >> y;
    cin >> xx >> yy;
    
    double ans = dis(x, y, xx, yy), x_, y_;
    for (double i = 0; i <= CIR; i += ESP)
    {
        x_ = r * cos((i * PI / 180));
        y_ = r * sin( (i * PI / 180));
        ans = min(ans, dis(x, y, x_, y_) + dis(xx, yy, -x_, -y_));
    }
    
    printf("%.12lf\n", ans);
    
    return 0;
}
