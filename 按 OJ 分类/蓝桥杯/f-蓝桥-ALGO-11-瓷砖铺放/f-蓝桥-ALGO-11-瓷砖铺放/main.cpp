//
//  main.cpp
//  f-蓝桥-ALGO-11-瓷砖铺放
//
//  Created by ZYJ on 2017/6/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int N;

int solve(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return solve(n - 1) + solve(n - 2);
}

int main(int argc, const char * argv[])
{
    while (cin >> N)
    {
        cout << solve(N) << '\n';
    }
    
    return 0;
}
