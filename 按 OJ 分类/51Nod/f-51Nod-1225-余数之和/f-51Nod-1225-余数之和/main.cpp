//
//  main.cpp
//  f-51Nod-1225-余数之和
//
//  Created by ZYJ on 2017/4/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;
const int MOD_2 = 5e8 + 4;

int main(int argc, const char * argv[])
{
    long long N, M;
    cin >> N;
    M = N;
    
    long long res = 0;
    long long base = 1;
    long long st = 0;
    long long x, ed;
    
    while (M > 0)
    {
        x = (M - st) / (base + 1);
        if (x == 0)
        {
            break;
        }
        if ((base + 1) * x != M - st)    //  向上取整
        {
            x++;
        }
        
        ed = st + (x - 1) * base;
        
        res = (res + ((st + ed) % MOD * (x % MOD)) % MOD * MOD_2 % MOD) % MOD;
        
        M -= x;
        if (M == 0)
        {
            break;
        }
        
        st = (ed + base) % M;
        base++;
    }
    
    for (int i = 1; i <= M; i++)
    {
        res = (res + N % i) % MOD;
    }
    
    cout << res << '\n';
    
    return 0;
}
