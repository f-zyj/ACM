//
//  main.cpp
//  f-51Nod-1031-骨牌覆盖
//
//  Created by ZYJ on 16/7/31.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 10;

unsigned int Fibonacci[MAXN];

int main(int argc, const char * argv[])
{
    Fibonacci[0] = Fibonacci[1] = 1;
    
    int n;
    cin >> n;
    
    for (int i = 2; i <= n; i++)
    {
        Fibonacci[i] = (Fibonacci[i - 1] + Fibonacci[i - 2]) % MOD;
    }
    std::cout << Fibonacci[n] << '\n';
    
    return 0;
}
