//
//  main.cpp
//  f-蓝桥-ALGO-33-数列
//
//  Created by ZYJ on 2017/6/5.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1111;

int k, n;
long long A[MAXN];

int main()
{
    while (cin >> k >> n)
    {
        int cnt = 0, now = 1;
        while (cnt < n)
        {
            int tmp = cnt;
            A[cnt++] = now;
            for (int i = 0; i < tmp && cnt < n; i++)
            {
                A[cnt++] = now + A[i];
            }
            now *= k;
        }
        cout << A[n - 1] << endl;
    }
    
    return 0;
}
