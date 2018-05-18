//
//  main.cpp
//  f-51Nod-1454-升排列
//
//  Created by ZYJ on 2017/6/26.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 55;

int n;
int res[MAXN];
ll k;
ll fib[MAXN];

int main(int argc, const char * argv[])
{
    cin >> n >> k;
    
    fib[n] = 1;
    fib[n + 1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        fib[i] = fib[i + 1] + fib[i + 2];
        res[i] = i + 1;
    }
    
    for (int i = 0; i < n - 1 && k; i++)
    {
        if (k > fib[i + 1])
        {
            k -= fib[i + 1];
            swap(res[i], res[i + 1]);
            i++;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", res[i]);
    }
    putchar(10);
    
    return 0;
}
