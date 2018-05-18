//
//  main.cpp
//  f-51Nod-1383-整数分解为2的幂
//
//  Created by ZYJ on 2017/6/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

int n;
int f[MAXN] = {1, 1};

void init()
{
    for (int i = 2; i < MAXN; i++)
    {
        if (i % 2)
        {
            f[i] = f[i - 1];
        }
        else
        {
            f[i] = (f[i - 1] + f[i >> 1]) % MOD;
        }
    }
}

int main(int argc, const char * argv[])
{
    init();
    
    while (cin >> n)
    {
        cout << f[n] << '\n';
    }
    
    return 0;
}
