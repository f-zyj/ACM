//
//  main.cpp
//  f-51Nod-1040-最大公约数之和
//
//  Created by ZYJ on 2016/10/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

/*
 *  单独求解的本质是公式的应用
 */
unsigned euler(unsigned x)
{
    unsigned i, res = x;    //  unsigned == unsigned int
    for (i = 2; i < (int)sqrt(x * 1.0) + 1; i++)
    {
        if (!(x % i))
        {
            res = res / i * (i - 1);
            while (!(x % i))
            {
                x /= i;     //  保证i一定是素数
            }
        }
    }
    if (x > 1)
    {
        res = res / x * (x - 1);
    }
    return res;
}

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    long long sum = 0;
    
    for (int i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            int tmp = N / i;
            sum += euler(tmp) * i;
            if (i != tmp)
            {
                sum += euler(i) * tmp;
            }
        }
    }
    
    cout << sum << '\n';
    
    return 0;
}
