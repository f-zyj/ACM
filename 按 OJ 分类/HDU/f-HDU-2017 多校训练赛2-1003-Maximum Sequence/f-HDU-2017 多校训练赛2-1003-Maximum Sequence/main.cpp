//
//  main.cpp
//  f-HDU-2017 多校训练赛2-1003-Maximum Sequence
//
//  Created by ZYJ on 2017/7/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

const int MAXN = 2e5 + 5e4 + 10;
const int MOD = 1e9 + 7;

int n;
int a[MAXN << 1];
int b[MAXN];
multiset<int> si;

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
    while (cin >> n)
    {
        si.clear();
        for (int i = 1; i <= n; i++)
        {
            scan_d(a[i]);
            a[i] -= i;
            si.insert(a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            scan_d(b[i]);
        }
        sort(b + 1, b + n + 1);
        
        long long sum = 0;
        for (int i = 1, j = 1; i <= n; i++)
        {
            for (; j < b[i]; j++)
            {
                auto it = si.find(a[j]);
                si.erase(it);
            }
            auto it = si.end();
            it--;
            sum += *it;
            sum %= MOD;
            a[i + n] = *it - i - n;
            si.insert(a[i + n]);
        }
        
        cout << sum << '\n';
    }
    
    return 0;
}
