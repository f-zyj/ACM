//
//  main.cpp
//  f-51Nod-1557-两个集合
//
//  Created by ZYJ on 2017/3/6.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

#define YES 1
#define NO 0

using namespace std;

const int MAXN = 1e5 + 10;

int p[MAXN];

int bs(int l, int h, int v)
{
    int m;
    while (l < h)
    {
        m = (l + h) >> 1;
        if (p[m] == v)
        {
            return YES;
        }
        if (p[m] < v)
        {
            l = m + 1;
        }
        else
        {
            h = m;
        }
    }
    return NO;
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int n, a, b;
    cin >> n >> a >> b;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }
    sort(p, p + n);
    
    for (int i = 0; i < n; i++)
    {
        bool A = bs(0, n, a - p[i]);
        bool B = bs(0, n, b - p[i]);
        if (!A && !B)
        {
            cout << "NO\n";
            return 0;
        }
        if (A && B)
        {
            bool A_ = bs(0, n, a - b + p[i]);
            bool B_ = bs(0, n, b - a + p[i]);
            if (!A_ && !B_)
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    
    cout << "YES\n";
    
    return 0;
}
