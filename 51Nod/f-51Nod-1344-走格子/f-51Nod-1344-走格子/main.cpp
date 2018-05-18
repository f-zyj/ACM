//
//  main.cpp
//  f-51Nod-1344-走格子
//
//  Created by ZYJ on 16/7/31.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[])
{
    freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n;
    long long A;
    long long res = 0;
    long long energy = 0;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &A);
        energy += A;
        if (energy < 0)
        {
            res += -energy;
            energy = 0;
        }
    }
    
    cout << res << '\n';
    return 0;
}
