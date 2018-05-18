//
//  main.cpp
//  f-51Nod-1742-开心的小Q
//
//  Created by ZYJ on 2017/7/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 4e4;

int a, b;
int mul[MAXN];
int vis[MAXN];
int prime[MAXN];

//  素数筛
void getPrime()
{
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i <= MAXN; i++)
    {
        if (!prime[i])
        {
            prime[++prime[0]] = i;
            mul[i] = -1;
        }
        for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}

//  mul
void init()
{
    getPrime();
    
    mul[1] = 1;
    for (int i = 2; 2 * i <= MAXN; i++)
    {
        for (int j = 1; j <= prime[0] && prime[j] * i < MAXN; j++)
        {
            if (i % prime[j] == 0)
            {
                mul[prime[j] * i] = 0;
                break;
            }
            mul[prime[j] * i] = -mul[i];
        }
    }
}

ll F(int n)
{
    if (n == 0)
    {
        return 0;
    }
    ll ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans -= mul[i] * (n / (i * i));
    }
    
    return ans;
}

ll S(int n)
{
    ll ans = 0;
    int r, cnt = 1;
    for (int i = 1; i < n && cnt; i += cnt)
    {
        r = n / i;
        cnt = n / r - n / (r + 1);
        ans += cnt * F(r);
    }
    
    return ans;
}

int main()
{
    init();
    
    cin >> a >> b;
    cout << S(b) - S(a - 1) << endl;
    
    return 0;
}
