//
//  main.cpp
//  f-蓝桥-ALGO-12-幂方分解
//
//  Created by ZYJ on 2017/6/2.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

const int MAXN = 16;

string s;
int POWER[MAXN];

void init()
{
    POWER[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        POWER[i] = POWER[i - 1] * 2;
    }
}

void solve(int n, int k)
{
    for (int i = k; i >= 0; i--)
    {
        if (POWER[i] <= n)
        {
            n -= POWER[i];
            cout << '2';
            if (i == 1)
            {
                if (n == 0)
                {
                    continue;
                }
                cout << '+';
                continue;
            }
            cout << '(';
            
            if (i == 0)
            {
                cout << '0';
            }
            else
            {
                solve(i, 4);
            }
            cout << ')';
            if (n == 0)
            {
                continue;
            }
            cout << '+';
        }
    }
}

int main(int argc, const char * argv[])
{
    init();
    
    int N;
    while (cin >> N)
    {
        solve(N, 15);
    }
    
    return 0;
}


