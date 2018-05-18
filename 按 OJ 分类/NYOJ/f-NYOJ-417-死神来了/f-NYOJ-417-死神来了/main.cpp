//
//  main.cpp
//  f-NYOJ-417-死神来了
//
//  Created by ZYJ on 2017/9/28.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int n, m;

int main(int argc, const char * argv[])
{
    while (cin >> n >> m)
    {
        if (m > (n >> 1) + (n & 1))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    
    return 0;
}
