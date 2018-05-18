//
//  main.cpp
//  f-51Nod-1283-最小周长
//
//  Created by ZYJ on 16/7/31.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[])
{
    int S;
    while (cin >> S)
    {
        double s = sqrt(S);
        for (int i = (int)s; i > 0; i--)
        {
            double res = S * 1.0 / i;
            if (res == (int)res)
            {
                int ans = i + i + res + res;    //  cout << i + i + res + res << '\n';如此会WA，需要将结果格式化
                printf("%d\n", ans);
                break;
            }
        }
    }
    
    return 0;
}
