//
//  main.cpp
//  f-2016-计蒜之道-初赛-第五场-A-腾讯的一笔画游戏
//
//  Created by ZYJ on 16/6/11.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>
const double PI = 3.1415926;
double K[22];

int main(int argc, const char * argv[])
{
    int n, k;
    while (std::cin >> n >> k)
    {
        std::cin >> K[0];
        double degree = 180 - (360.0 / n);
        for (int i = 1; i <= k; i++)
        {
            K[i] = sqrt(K[i - 1] * K[i - 1] / 2 * (1 - cos(degree * PI / 180)));
        }
        double ans = 0;
        for (int i = 0; i < k; i++)
        {
            ans += K[i] * (n - 0.5);
        }
        ans += K[k] * (n - 1);
        printf("%f\n", ans);
    }
    
    return 0;
}
