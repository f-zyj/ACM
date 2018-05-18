//
//  main.cpp
//  f-HDU-1021-Fibonacci Again
//
//  Created by ZYJ on 2016/10/12.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int n;
    while (cin >> n)
    {
        if ((n - 1) % 4 == 1)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    
    return 0;
}
