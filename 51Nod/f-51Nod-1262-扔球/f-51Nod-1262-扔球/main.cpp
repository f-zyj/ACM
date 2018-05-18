//
//  main.cpp
//  f-51Nod-1262-扔球
//
//  Created by ZYJ on 2017/4/15.
//  Copyright © 2017年 ZYJ. All rights reserved.
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
    
    while (cin >> N)
    {
        if (N == 1)
        {
            printf("1\n");
            continue;
        }
        
        N++;
        int res = euler(N);
        
        printf("%d\n", res);
    }
    
    return 0;
}
