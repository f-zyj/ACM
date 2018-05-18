//
//  main.cpp
//  f-51Nod-1108-距离之和最小 V2
//
//  Created by ZYJ on 16/8/6.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e4 + 10;

int PX[MAXN];
int PY[MAXN];
int PZ[MAXN];

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> PX[i] >> PY[i] >> PZ[i];
    }
    sort(PX, PX + N);
    sort(PY, PY + N);
    sort(PZ, PZ + N);
    
    long long sum = 0;
    int flag = N - 1;
    for (int i = 0; i < flag; i++, flag--)
    {
        sum += PX[flag] - PX[i] + PY[flag] - PY[i] + PZ[flag] - PZ[i];
    }
    
    std::cout << sum << '\n';
    return 0;
}