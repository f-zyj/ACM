//
//  main.cpp
//  f-51Nod-1419-最小公倍数挑战
//
//  Created by ZYJ on 16/9/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    long long n;
    
    while (cin >> n)
    {
        if (n == 1 || n == 2)
        {
            cout << n << '\n';
        }
        else
        {
            if (n % 2)
            {
                cout << (n - 2) * (n - 1) * n << '\n';
            }
            else if (!(n % 3))
            {
                cout << (n - 3) * (n - 2) * (n - 1) << '\n';
            }
            else
            {
                cout << (n - 3) * (n - 1) * n << '\n';
            }
        }
    }
    
    return 0;
}
