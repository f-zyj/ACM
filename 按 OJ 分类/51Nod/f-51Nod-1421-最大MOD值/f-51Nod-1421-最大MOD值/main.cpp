//
//  main.cpp
//  f-51Nod-1421-最大MOD值
//
//  Created by ZYJ on 2017/6/23.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 2e5 + 10;

int n;
int a[MAXN];

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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scan_d(a[i]);
    }
    
    sort(a, a + n);
    
    int res, tmp, j;
    j = res = tmp = 0;
    for (int i = 1; i < n; i++)
    {
        tmp = a[i] % a[i - 1];
        if (tmp > a[i] % a[j])
        {
            while (tmp > a[i] % a[j])
            {
                j++;
            }
        }
        
        while (a[i] % a[j + 1] > a[i] % a[j])
        {
            j++;
        }
        tmp = a[i] % a[j];
        
        res = max(res, tmp);
    }
    
    cout << res << endl;
    
    return 0;
}
