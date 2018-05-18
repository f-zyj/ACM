//
//  main.cpp
//  f-HDU-5874-Friends and Enemies
//
//  Created by ZYJ on 2017/5/18.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int M, N;
    while (cin >> M >> N)
    {
        if (M * M / 4 > N)
        {
            puts("F");
        }
        else
        {
            puts("T");
        }
    }
    return 0;
}
