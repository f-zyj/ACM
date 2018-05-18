//
//  main.cpp
//  f-CF-Codeforces Round #377 (Div. 2)-A-Buy a Shovel
//
//  Created by ZYJ on 2016/10/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 10000;

int main(int argc, const char * argv[])
{
    int k, r;
    
    while (cin >> k >> r)
    {
        for (int i = 1; i < MAXN; i++)
        {
            if (k * i % 10 == r || k * i % 10 == 0)
            {
                cout << i << '\n';
                return 0;
            }
        }
    }
    
    return 0;
}
