//
//  main.cpp
//  f-51Nod-1087-1 10 100 1000
//
//  Created by ZYJ on 16/7/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[])
{
    int T;
    int N;
    
    cin >> T;
    while (T--)
    {
        scanf("%d", &N);
        double m = sqrt((N - 1) * 2);
        if ((int)m * (int)(m + 1) == (N - 1) * 2)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    
    return 0;
}
