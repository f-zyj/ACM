//
//  main.cpp
//  f-CF-Codeforces Round #420 (Div. 2)-B-Okabe and Banana Trees
//
//  Created by ZYJ on 2017/6/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

ll m, b;

int main(int argc, const char * argv[])
{
    cin >> m >> b;
    
    ll ans = 0;
    for (int i = 0; i <= b; i++)
    {
        ll x = (b - i) * m;
        ll s = i * (i + 1) >> 1;
        ll e = s + x * (i + 1);
        ans = max(ans, (s + e) * (x + 1) >> 1);
    }
    
    cout << ans << '\n';
    
    return 0;
}
