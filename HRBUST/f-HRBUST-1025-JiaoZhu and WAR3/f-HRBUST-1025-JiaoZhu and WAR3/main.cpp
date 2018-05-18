//
//  main.cpp
//  f-HRBUST-1025-JiaoZhu and WAR3
//
//  Created by ZYJ on 2017/2/23.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 55;
const int MAXM = 10000;

struct circle
{
    float x;
    float y;
    float r;
} C[MAXN];

int main(int argc, const char * argv[])
{
    int N;
    float a, b, c;
    
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%f%f%f", &a, &b, &c);
            C[i].x = a * 1000;
            C[i].y = b * 1000;
            C[i].r = c * 1000;
        }
        
        int cnt = MAXM;
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                float x = -495 + i * 10;
                float y = -495 + j * 10;
                for (int k = 0; k < N; k++)
                {
                    if (sqrt(pow(C[k].x - x, 2) + pow(C[k].y - y, 2)) <= C[k].r)
                    {
                        cnt--;
                        break;
                    }
                }
            }
        }
        
        float res = cnt * 1.0 / MAXM;
        printf("%.3f\n", res);
    }
    
    return 0;
}
