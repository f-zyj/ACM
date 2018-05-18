//
//  main.cpp
//  f-51Nod-1509-加长棒
//
//  Created by ZYJ on 2016/9/29.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

ll Solve(ll a, ll b, ll c, ll L)    //  a是三边之间最大的
{
    ll tmp = a + b + c + L;
    ll ans = 0;
    for (ll i = 0; i <= L; i++)
    {
        ll tmp_ = min(tmp - a - i, i + a);
        if (b + c <= tmp_)
        {
            ans += (tmp_ - b - c + 2) * (tmp_ - b - c + 1) / 2;
        }
    }
    return ans;
}

int main()
{
    ll a, b, c, L;
    while (cin >> a >> b >> c >> L)
    {
        //  挡板法求所有可能数
        ll ans = (L + 3) * (L + 2) * (L + 1) / 6;
        ans -= Solve(a, b, c, L);
        ans -= Solve(b, a, c, L);
        ans -= Solve(c, a, b, L);
        cout<< ans <<endl;
    }
    return 0;
}
