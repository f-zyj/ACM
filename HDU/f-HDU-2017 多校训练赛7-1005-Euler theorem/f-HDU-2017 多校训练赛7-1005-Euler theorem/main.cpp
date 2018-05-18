//
//  main.cpp
//  f-HDU-2017 多校训练赛7-1005-Euler theorem
//
//  Created by ZYJ on 2017/8/15.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int a;

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> a;
        if (a & 1)
        {
            cout << (a >> 1) + 2 << '\n';
        }
        else
        {
            cout << (a >> 1) + 1 << '\n';
        }
    }
    
    return 0;
}
