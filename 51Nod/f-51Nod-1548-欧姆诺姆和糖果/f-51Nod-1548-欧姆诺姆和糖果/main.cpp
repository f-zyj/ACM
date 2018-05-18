//
//  main.cpp
//  f-51Nod-1548-欧姆诺姆和糖果
//
//  Created by ZYJ on 2017/2/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

struct candy
{
    int w;
    int h;
    float v;
};

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
//    freopen("/Users/zyj/Desktop/output.txt", "w", stdout);
    
    int C;
    candy R, B;
    cin >> C >> R.h >> B.h >> R.w >> B.w;
    
    ll ans = 0, res;
    ll temp = sqrt(C) + 1;
    
    for (ll i = 0; i < temp; i++)
    {
        if (i * R.w <= C)
        {
            res = i * R.h + (C - i * R.w) / B.w * B.h;
            if (res > ans)
            {
                ans = res;
            }
        }
        if (i * B.w <= C)
        {
            res = i * B.h + (C - i * B.w) / R.w * R.h;
            if (res > ans)
            {
                ans = res;
            }
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}
