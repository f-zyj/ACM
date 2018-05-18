//
//  main.cpp
//  f-SHU-“盛大游戏杯”第15届上海大学程序设计联赛夏季赛暨上海高校金马五校赛-J-膜一下将带给你好运
//
//  Created by ZYJ on 2017/7/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

#define clr(x,y) memset(x, y, sizeof(x))

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAGIC = 233;

int n;
int phi[MAGIC];

int get_phi(int x)
{
    unsigned i, res = x;    //  unsigned == unsigned int
    for (i = 2; i < (int)sqrt(x * 1.0) + 1; i++)
    {
        if (!(x % i))
        {
            res = res / i * (i - 1);
            while (!(x % i))
            {
                x /= i;     //  保证i一定是素数
            }
        }
    }
    if (x > 1)
    {
        res = res / x * (x - 1);
    }
    return res;
}

void init()
{
    for (int i = 1; i <= MAGIC; i++)
    {
        phi[i] = i;
    }
    for (int i = 2; i <= MAGIC; i += 2)
    {
        phi[i] /= 2;
    }
    for (int i = 3; i <= MAGIC; i += 2)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= MAGIC; j += i)
            {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

int main()
{
    init();
    
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int ans = (ll)n * (1 + n) / 2 % MOD;
        for (int i = 1; i < MAGIC; i++)
        {
            ans = (ans - (ll)phi[i] * (n / i) % MOD + MOD) % MOD;
        }
        for (int i = n; i > n - MAGIC; i--)
        {
            ans = (ans - (ll)get_phi(i) * (n / i) % MOD + MOD) % MOD;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
