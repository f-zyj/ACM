//
//  main.cpp
//  f-CCF模拟-2-ISBN号码
//
//  Created by ZYJ on 2016/12/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10;
const int MOD = 11;

int ISBN[MAXN];
char X;

int main(int argc, const char * argv[])
{
    
    scanf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%c",
          ISBN + 0, ISBN + 1, ISBN + 2, ISBN + 3, ISBN + 4, ISBN + 5,
          ISBN + 6, ISBN + 7, ISBN + 8, &X);
    
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        sum += ISBN[i] * (i + 1);
    }
    sum %= MOD;
    int num = X == 'X' ? 10 : X - '0';
    
    if (num == sum)
    {
        cout << "Right\n";
    }
    else
    {
        cout << ISBN[0] << '-';
        cout << ISBN[1] << ISBN[2] << ISBN[3] << '-';
        cout << ISBN[4] << ISBN[5] << ISBN[6] << ISBN[7] << ISBN[8] << '-';
        if (sum == 10)
        {
            cout << "X\n";
        }
        else
        {
            cout << sum << '\n';
        }
    }
    
    return 0;
}
