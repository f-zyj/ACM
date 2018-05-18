//
//  main.cpp
//  f-蓝桥-ALGO-23-一元三次方程求解
//
//  Created by ZYJ on 2017/6/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//const int MAXN = 100;
//const double ESP = 1e-5;
//
//double a, b, c, d;
//
//double calculate(double x)
//{
//    return a * x * x * x + b * x * x + c * x + d;
//}
//
//int main(int argc, const char * argv[])
//{
//    cin >> a >> b >> c >> d;
//    
//    int cnt = 3;
//    for (double i = -MAXN; i <= MAXN && cnt; i += 0.01)
//    {
//        if (fabs(calculate(i)) < ESP)
//        {
//            if (cnt == 1)
//            {
//                printf("%.2f\n", i);
//            }
//            else
//            {
//                printf("%.2f ", i);
//            }
//            cnt--;
//        }
//    }
//    
//    return 0;
//}

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double ESP = 1e-5;
const int MAXN = 100;

double a, b, c, d;

double cal(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

int main()
{
    cin >> a >> b >> c >> d;
    
    int cnt = 3;
    for (int i = -MAXN; i <= MAXN; i++)
    {
        double l = i, r = l + 1;
        
        if (cal(l) == 0)
        {
            if (cnt > 1)
            {
                printf("%.2f ", l);
            }
            else if (cnt == 1)
            {
                printf("%.2f\n", l);
            }
            else
            {
                break;
            }
            cnt--;
        }
        else
        {
            if (cal(l) * cal(r) < 0)
            {
                while (r - l > ESP)
                {
                    double m = (l + r) / 2;
                    if (cal(l) * cal(m) <= 0)
                    {
                        r = m;
                    }
                    else
                    {
                        l = m;
                    }
                }
                
                if (cnt > 1)
                {
                    printf("%.2f ", l);
                }
                else if (cnt == 1)
                {
                    printf("%.2f\n", l);
                }
                else
                {
                    break;
                }
                cnt--;
            }
        }
    }
    
    return 0;
}
