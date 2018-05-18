//
//  main.cpp
//  f-乐视2017实习-偶数大翻转
//
//  Created by ZYJ on 2018/3/23.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int flip(int x)
{
    if (x & 1)
    {
        return x;
    }
    
    int n = 0;
    while (x)
    {
        n = (n << 1) | (x & 1);
        x >>= 1;
    }
    
    return n;
}

int N, x;

int main(int argc, const char * argv[])
{
    while (cin >> N)
    {
        for (int i = 0; i < N; i++)
        {
            cin >> x;
            cout << flip(x);
            if (i != N - 1)
            {
                cout << ' ';
            }
            else
            {
                cout << '\n';
            }
        }
    }
    
    return 0;
}
