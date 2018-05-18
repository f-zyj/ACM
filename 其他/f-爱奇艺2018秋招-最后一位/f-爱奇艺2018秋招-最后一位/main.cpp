//
//  main.cpp
//  f-爱奇艺2018秋招-最后一位
//
//  Created by ZYJ on 2018/3/23.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

long long sum;

long long get_sum(long long x)
{
    long long sum = 0;
    while (x != 0)
    {
        sum += x;
        x /= 10;
    }
    return sum;
}

int main(int argc, const char * argv[])
{
    cin >> sum;
    
    long long l = 0, r = sum, m;
    while (l < r)
    {
        m = (l + r) >> 1;
        long long tmp = get_sum(m);
        if (tmp == sum)
        {
            cout << m << '\n';
            return 0;
        }
        else if (tmp < sum)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    
    if (get_sum(l) == sum)
    {
        cout << l << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    
    return 0;
}
