//
//  main.cpp
//  f-51Nod-算法马拉松16-A-B君的连通
//
//  Created by ZYJ on 16/7/29.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

const int _MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

/*
 * deBug
ll c[50][50];

void init()
{
    for(int i=0; i<50; i++)
        c[i][0] = 1;
    for(int i=1; i<50; i++)
    {
        for(int j=1; j<=i; j++)
        {
            c[i][j] = c[i-1][j]+c[i-1][j-1];
        }
    }
    for(int i=1; i<=20; i++)
    {
        ll sum = 0;
        for(int j=0; j<=i; j++)
        {
            sum += (j+1)*c[i-1][j];
        }
        cout<<"i = "<<i<<" : "<<sum<<endl;
    }
}
 */

ll ans[MAXN];

//快速求幂
ll power(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % _MOD;
            b--;
        }
        b >>= 1;
        a = (a * a) % _MOD;
    }
    return ans;
}

void init()
{
    ans[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        ans[i] = 2 * ans[i - 1] + power(2, i - 2);
        ans[i] %= _MOD;
    }
}


int main(int argc, const char * argv[])
{
    init();
    
    int n, x, y;
    while (cin >> n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            cin >> x >> y;
        }
        cout << ans[n] << '\n';
    }
    
    return 0;
}
