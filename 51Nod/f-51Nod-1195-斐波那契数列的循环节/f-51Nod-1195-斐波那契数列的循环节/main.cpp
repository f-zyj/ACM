//
//  main.cpp
//  f-51Nod-1195-斐波那契数列的循环节
//
//  Created by ZYJ on 2017/2/4.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 40;

long long Fib[MAXN] = {0, 1, 1};
long long FibX[MAXN];

void getFib()
{
    for (int i = 3; i < MAXN; i++)
    {
        Fib[i] = Fib[i - 1] + Fib[i - 2];
    }
}

int main(int argc, const char * argv[])
{
//    int T;
//    cin >> T;
    getFib();
    
    for (int i = 2; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            FibX[j] = Fib[j] % i;
            if (j > 1 && FibX[j] == 1 && FibX[j - 1] == 0)
            {
                break;
            }
            cout << ' ' << FibX[j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
