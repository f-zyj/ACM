//
//  main.cpp
//  f-HDU-5984-Pocky
//
//  Created by ZYJ on 2017/10/16.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double L, d;

int main()
{
    int N;
    cin >> N;
    
    while (N--)
    {
        cin >> L >> d;
        
        if (L <= d)
        {
            cout << "0.000000\n";
        }
        else
        {
            printf("%.6f\n", 1 + log(L / d));
        }
    }
    
    return 0;
}

