//
//  main.cpp
//  f-51Nod-1060-最复杂的数
//
//  Created by ZYJ on 16/8/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

typedef long long ll;

using namespace std;

const int MAXP = 16;
const int prime[MAXP] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

ll n, res, ans;

void dfs(ll cur, ll num, int key, ll pre)  //  当前值/当前约数数量/当前深度/上一个数
{
    if (key >= MAXP)
    {
        return ;
    }
    else
    {
        if (num > ans)
        {
            res = cur;
            ans = num;
        }
        else if (num == ans)    //  如果约数数量相同，则取较小的数
        {
            res = min(cur, res);
        }
        
        ll i;
        for ( i = 1; i <= pre; i++)
        {
            if (cur <= n / prime[key])  //  cur*prime[key]<=n
            {
                cur *= prime[key];
                dfs(cur, num * (i + 1), key + 1, i);
            }
            else
            {
                break;
            }
        }
    }
}

void solve()
{
    res = 1;
    ans = 1;
    
    dfs(1, 1, 0, 15);
    cout << res << ' ' << ans << endl;
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> n;
        solve();
    }
    return 0;
}

