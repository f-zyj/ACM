//
//  main.cpp
//  f-HDU-1005-Number Sequence
//
//  Created by ZYJ on 2016/10/11.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 300;
const int MOD = 7;

int f[MAXN] = {1, 1, 1};

int main(int argc, const char * argv[])
{
    int A, B, n;
    while (cin >> A >> B >> n)
    {
        if (A == 0 && B == 0 && n == 0)
        {
            break;
        }
        
        int beg = 1;
        int end = 1;
        int cycle = 1;
        bool flag = false;
        for (int i = 3; i <= n && !flag; i++)
        {
            f[i] = (A * f[i - 1] + B * f[i - 2]) % MOD;
            for (int j = 2; j < i; j++)
            {
                if (f[i] == f[j] && f[i - 1] == f[j - 1])
                {
                    cycle = i - j;
                    beg = j - 1;
                    end = i - 1;
                    flag = true;
                    break;
                }
            }
        }
        
        if (flag)
        {
            cout << f[beg + (n - end) % cycle] << '\n';
        }
        else
        {
            cout << f[n] << '\n';
        }
    }
    
    return 0;
}
