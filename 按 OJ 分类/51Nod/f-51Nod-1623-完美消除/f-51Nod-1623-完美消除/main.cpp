//
//  main.cpp
//  f-51Nod-1623-完美消除
//
//  Created by ZYJ on 2017/7/22.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

#define clr(a, b) memset(a, b, sizeof(a))

using namespace std;

typedef long long ll;

const int MAXN = 1024;
const int MAXK = 20;

ll L, R, k;
ll res[MAXK][MAXK][MAXN];
int dig[MAXK];

int change(int s, int x)
{
    for (int i = 0; i < 10; i++)
    {
        if ((i > x) && (s >> i & 1))
        {
            s ^= (1 << i);
        }
    }
    return s | (1 << x);
}

//  len: x 的二进制长度，cnt: 栈中数的个数，tag: 二进制维护栈中的数，flag: 标记是否为最高位
ll dfs(int len, int cnt, int tag, int flag)
{
    if (len == 0)
    {
        return cnt == k;
    }
    if (!flag && res[len][cnt][tag] != -1)
    {
        return res[len][cnt][tag];
    }
    
    int u = flag == 1 ? dig[len] : 9;
    ll ans = 0;
    for (int i = 0; i <= u; i++)
    {
        if (tag >> i & 1)
        {
            ans += dfs(len - 1, cnt, change(tag, i), i == u && flag);
        }
        else
        {
            ans += dfs(len - 1, cnt + 1, change(tag, i), i == u && flag);
        }
    }
    
    if (!flag)
    {
        res[len][cnt][tag] = ans;
    }
    
    return ans;
}

ll solve(ll x)
{
    int len = 0;
    while (x)
    {
        len++;
        dig[len] = x % 10;
        x /= 10;
    }
    
    clr(res, -1);
    return dfs(len, 0, 1, 1);
}

int main()
{
    cin >> L >> R >> k;
    cout << solve(R) - solve(L - 1) << endl;
    
    return 0;
}
