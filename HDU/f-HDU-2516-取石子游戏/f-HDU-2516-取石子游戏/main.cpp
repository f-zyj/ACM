//
//  main.cpp
//  f-HDU-2516-取石子游戏
//
//  Created by ZYJ on 2017/9/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 50;

int n;
long long fib[MAXN] = {0, 1, 1};

void init()
{
    for (int i = 3; i < MAXN; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main(int argc, const char * argv[])
{
    init();
    
    int flag;
    while (cin >> n && n)
    {
        flag = 1;
        for (int i = 3; i < MAXN; i++)
        {
            if (fib[i] == n)
            {
                flag = 0;
                puts("Second win");
            }
            if (fib[i] > n)
            {
                break;
            }
        }
        
        if (flag)
        {
            puts("First win");
        }
    }
    
    return 0;
}
