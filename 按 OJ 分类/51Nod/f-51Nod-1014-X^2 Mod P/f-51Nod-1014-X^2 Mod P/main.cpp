//
//  main.cpp
//  f-51Nod-1014-X^2 Mod P
//
//  Created by ZYJ on 16/7/31.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

typedef long long ll;

using namespace std;

int main(int argc, const char * argv[])
{
    int P, A;
    ll X;
    while (cin >> P >> A)
    {
        bool flag = true;
        for (X = 0; X < P; X++)
        {
            if (X * X % P == A)
            {
                cout << X << ' ';
                flag = false;
            }
        }
        if (flag)
        {
            cout << "No Solution\n";
        }
    }
    
    return 0;
}
