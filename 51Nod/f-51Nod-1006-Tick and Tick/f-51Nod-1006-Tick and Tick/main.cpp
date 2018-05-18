//
//  main.cpp
//  f-51Nod-1006-Tick and Tick
//
//  Created by ZYJ on 2016/10/14.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

const double MAXT = 43200.000001;   //  12小时

//  const double w_h = 1. / 120, w_m = 1. / 10, w_s = 6.0;  // 角速度
//  三根指针间的相对角速度
const double s_h = 719. / 120;
const double s_m = 59. / 10;
const double m_h = 11. / 120;

//  将相对角速度变成周期。（即两针间需要多久出现夹角的循环）
//  同样可求得三个周期的最小公倍数为43200秒，即12小时
const double tsh = 43200. / 719;
const double tsm = 3600. / 59;
const double tmh = 43200. / 11;

inline double MAX(double a, double b, double c)
{
    double max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    return max;
}

inline double MIN(double a, double b, double c)
{
    double min = a;
    if (b < min)
    {
        min = b;
    }
    if (c < min)
    {
        min = c;
    }
    return min;
}

int main()
{
    double D;
    
    while (~scanf("%lf", &D) && D != -1)
    {
        double bsm, bsh, bmh, esm, esh, emh, begin, end, total = 0;
        
        //  计算第一次满足条件的时间
        bsm = D / s_m;
        bsh = D / s_h;
        bmh = D / m_h;
        
        //  计算第一次不满足条件的时间
        esm = (360 - D) / s_m;    //  = tsm - bsm
        esh = (360 - D) / s_h;    //  = tsh - bsh
        emh = (360 - D) / m_h;    //  = tmh - bmh
        
        //  三重循环找出所有的时间总和，当然这三重循环的顺序是可以打乱的
        for (double bt3 = bsh, et3 = esh; et3 <= MAXT; bt3 += tsh, et3 += tsh)
        {
            for (double bt2 = bmh, et2 = emh; et2 <= MAXT; bt2 += tmh, et2 += tmh)
            {
                if (et2 < bt3)      //  这是为了提前判断是否有交集
                {
                    continue;
                }
                if (bt2 > et3)
                {
                    break;
                }
                for (double bt1 = bsm, et1 = esm; et1 <= MAXT; bt1 += tsm, et1 += tsm)
                {
                    if (et1 < bt2 || et1 < bt3)     //  和上述同理
                    {
                        continue;
                    }
                    if (bt1 > et2 || bt1 > et3)
                    {
                        break;
                    }
                    begin = MAX(bt1, bt2, bt3);     //  取它们的交集
                    end = MIN(et1, et2, et3);
                    total += (end - begin);
                }
            }
        }
        
        printf("%.3lf\n", total / 432);
    }
    
    return 0;
}
