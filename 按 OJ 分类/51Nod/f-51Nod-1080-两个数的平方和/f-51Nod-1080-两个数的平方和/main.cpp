//
//  main.cpp
//  f-51Nod-1080-两个数的平方和
//
//  Created by ZYJ on 16/7/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[])
{
    int N;
    while (cin >> N)
    {
        int A;
        double B;
        double flag = N;
        bool tag = true;
        if (N == 1)
        {
            cout << "0 1\n";
            tag = false;
        }
        for (A = 1; A < flag; A++)
        {
            B = sqrt(N - A * A);
            flag = B;
            if (B == (int)B)
            {
                cout << A << ' ' << B << '\n';
                tag = false;
            }
        }
        if (tag)
        {
            cout << "No Solution\n";
        }
    }
    
    return 0;
}
