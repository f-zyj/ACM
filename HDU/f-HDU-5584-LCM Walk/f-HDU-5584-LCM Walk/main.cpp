//
//  main.cpp
//  f-HDU-5584-LCM Walk
//
//  Created by ZYJ on 2017/11/20.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}

int x, y;

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++)
    {
        scanf("%d%d", &x, &y);
        if (x > y)
        {
            swap(x, y);
        }
        
        int cnt = 1;
        int k = gcd(x, y);
        while (y % (x + k) == 0)
        {
            cnt++;
            y = y / (x / k + 1);
            if (x > y)
            {
                swap(x, y);
            }
            k = gcd(x, y);
        }
        
        printf("Case #%d: %d\n", t, cnt);
    }
    
    return 0;
}
