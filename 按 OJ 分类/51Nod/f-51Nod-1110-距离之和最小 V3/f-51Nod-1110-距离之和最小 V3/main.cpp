//
//  main.cpp
//  f-51Nod-1110-距离之和最小 V3
//
//  Created by ZYJ on 16/8/6.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e4 + 10;

struct point
{
    int P;
    int power;
} P[MAXN];

bool cmp(point a, point b)
{
    return a.P < b.P;
}

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> P[i].P >> P[i].power;
    }
    sort(P, P + N, cmp);
    
    long long sum = 0;
    int flag = N - 1;
    long long power;
    for (int i = 0; i < flag;)
    {
        power = P[flag].power > P[i].power ? P[i].power : P[flag].power;
        sum += (P[flag].P - P[i].P) * power;    //  BUG 防止int * int溢出，所以power定义为long long
        P[flag].power -= power;
        P[i].power -= power;
        if (!(P[flag].power))
        {
            flag--;
        }
        if (!(P[i].power))
        {
            i++;
        }
    }
    
    std::cout << sum << '\n';
    return 0;
}