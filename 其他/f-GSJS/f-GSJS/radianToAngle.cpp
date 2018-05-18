//
//  radianToAngle.cpp
//  f-GSJS
//
//  Created by ZYJ on 2017/10/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include "radianToAngle.hpp"

#include <iostream>
#include <cmath>

#define PI acos(-1)

double RTA(double ra)
{
    double angle = ra * 100 / PI;
    return angle;
}
