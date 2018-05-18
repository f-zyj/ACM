//
//  main.cpp
//  f-HDU-1009-FatMouse' Trade
//
//  Created by ZYJ on 2016/10/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1010;

struct room
{
    int J;
    int F;
    double value;
} R[MAXN];

bool cmp(room a, room b)
{
    return a.value > b.value;
}

int main(int argc, const char * argv[])
{
    int M, N;
    while (cin >> M >> N && (M != -1 || N != -1))
    {
        for (int i = 0; i < N; i++)
        {
            cin >> R[i].J >> R[i].F;
            R[i].value = R[i].J * 1. / R[i].F;
        }
        
        sort(R, R + N, cmp);
        
        double res = 0;
        for (int i = 0; i < N; i++)
        {
            if (R[i].F <= M)
            {
                res += R[i].J;
                M -= R[i].F;
            }
            else
            {
                res += R[i].value * M;
                break;
            }
        }
        
        printf("%.3lf\n", res);
    }
    
    return 0;
}
