//
//  main.cpp
//  f-51Nod-1650-穿越无人区
//
//  Created by ZYJ on 2017/12/7.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    double a, b, x1, x2, y1, y2;
    
    while (~scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &x1, &y1, &x2, &y2))
    {
        int n = abs(ceil((x1 + y1) / (2 * a)) - ceil((x2 + y2) / (2 * a)));
        int m = abs(ceil((x1 - y1) / (2 * b)) - ceil((x2 - y2) / (2 * b)));
        printf("%d\n", max(n, m));
    }
    
    return 0;
}
