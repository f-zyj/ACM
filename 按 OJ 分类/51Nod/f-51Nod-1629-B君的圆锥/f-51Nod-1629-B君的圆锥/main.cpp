//
//  main.cpp
//  f-51Nod-1629-B君的圆锥
//
//  Created by ZYJ on 16/8/4.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include<iostream>
#include<cmath>
#include<cstdio>

#define PI 3.1415926

using namespace std;

int main()
{
    int s;
    cin >> s;
    double res = s * sqrt(s / (72.0 * PI));
    printf("%f\n", res);
    
    return 0;
}