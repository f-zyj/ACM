//
//  main.cpp
//  f-51Nod-1596-搬货物
//
//  Created by ZYJ on 2016/12/26.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 1e6 + 111;

int W[MAXN];

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int main(int argc, const char * argv[])
{
    memset(W, 0, sizeof(W));
    
    int n;
    cin >> n;
    
    int w, MAXW = 0;
    for (int i = 0; i < n; i++)
    {
        scan_d(w);
        MAXW = max(w, MAXW);
        W[w]++;
    }
    
    int res = 0;
    for (int i = 0; i < MAXW + 100; i++)
    {
        if (W[i] > 1)
        {
            W[i + 1] += W[i] / 2;
            W[i] %= 2;
        }
        res += W[i];
    }
    
    cout << res << '\n';
    
    return 0;
}
