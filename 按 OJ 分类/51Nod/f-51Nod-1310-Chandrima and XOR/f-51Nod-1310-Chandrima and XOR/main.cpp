//
//  main.cpp
//  f-51Nod-1310-Chandrima and XOR
//
//  Created by ZYJ on 2017/4/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXF = 88;
const int MOD = 1e9 + 7;

long long Fib[MAXF] = {1, 1, 2};
long long Pow[MAXF] = {1, 2, 4};

int XOR[MAXF];
int maxPos = 0;

void init()
{
    for (int i = 3; i < MAXF; i++)
    {
        Fib[i] = Fib[i - 1] + Fib[i - 2];
        Pow[i] = Pow[i - 1] * 2 % MOD;
    }
}

long long BToD()
{
    long long res = 0;
    for (int i = 0; i < maxPos; i++)
    {
        res = (res + XOR[i] * Pow[i]) % MOD;
    }
    return res;
}

int main(int argc, const char * argv[])
{
    init();
    
    int N;
    cin >> N;
    
    long long s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        while (s != 0)
        {
            int l = 0, r = MAXF;
            while (l < r)
            {
                int mid = (l + r + 1) / 2;
                if (Fib[mid] > s)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid;
                }
            }
            XOR[l - 1] ^= 1;
            maxPos = max(maxPos, l);
            s -= Fib[l];
        }
    }
    
    cout << BToD() << '\n';
    
    return 0;
}
