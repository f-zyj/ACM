//
//  main.cpp
//  f-51Nod-1431-快乐排队
//
//  Created by ZYJ on 2017/6/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 10;

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

int n;
int a[MAXN];

int main(int argc, const char * argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scan_d(a[i]);
        a[i] += i;
    }
    sort(a, a + n);
    int t = int(unique(a, a + n) - a);
//    cout << t << '\n';
    if (t == n)
    {
        cout << "Happy\n";
    }
    else
    {
        cout << "Sad\n";
    }
    
    return 0;
}
