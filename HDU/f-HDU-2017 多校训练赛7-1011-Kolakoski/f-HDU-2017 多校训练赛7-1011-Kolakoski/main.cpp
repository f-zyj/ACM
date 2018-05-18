//
//  main.cpp
//  f-HDU-2017 多校训练赛7-1011-Kolakoski
//
//  Created by ZYJ on 2017/8/15.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 1e7 + 10;

int n;
int a[MAXN] = {0, 1, 2};

void init()
{
    int t = 2;
    for (int i = 2; i < MAXN; i++)
    {
        for (int j = t + 1; j <= t + a[i] - 1; j++)
        {
            a[j] = a[j - 1];
        }
        t = t + a[i];
        if (a[t - 1] == 1)
        {
            a[t] = 2;
        }
        else
        {
            a[t] = 1;
        }
        if (t > MAXN)
        {
            break;
        }
    }
}

int main(int argc, const char * argv[])
{
    init();
    
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << a[n] << '\n';
    }
    
    return 0;
}
