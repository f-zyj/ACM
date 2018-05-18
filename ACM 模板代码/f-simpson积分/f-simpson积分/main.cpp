//
//  main.cpp
//  f-simpson积分
//
//  Created by ZYJ on 16/7/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

//  自适应simpson积分

const double eps = 1e-6;    //  积分精度

//  被积函数
double F(double x)
{
    double ans;
    //  被积函数
    //  ...
    //    ans = x * exp(x);       //  椭圆为例
    return ans;
}

//  三点simpson法，这里要求F是一个全局函数
double simpson(double a, double b)
{
    double c = a + (b - a) / 2;
    return (F(a) + 4 * F(c) + F(b)) * (b - a) / 6;
}

//  自适应simpson公式（递归过程），已知整个区间[a, b]上的三点simpson指A
double asr(double a, double b, double eps, double A)
{
    double c = a + (b - a) / 2;
    double L = simpson(a, c), R = simpson(c, b);
    if (fabs(L + R - A) <= 15 * eps)
    {
        return L + R + (L + R - A) / 15.0;
    }
    return asr(a, c, eps / 2, L) + asr(c, b, eps / 2, R);
}

//  自适应simpson公式（主过程）
double asr(double a, double b, double eps)
{
    return asr(a, b, eps, simpson(a, b));
}

int main(int argc, const char * argv[])
{
    //    std::cout << asr(1, 2, eps) << '\n';
    return 0;
}
