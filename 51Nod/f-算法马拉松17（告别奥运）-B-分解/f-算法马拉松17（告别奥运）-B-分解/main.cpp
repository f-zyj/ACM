//
//  main.cpp
//  f-算法马拉松17（告别奥运）-B-分解
//
//  Created by ZYJ on 16/8/27.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const long long MAXN = 2;
const long long MOD_ = 1e9 + 7;

struct Matrix
{
    long long line;
    long long a[MAXN + 1][MAXN + 1];
    Matrix()
    {
        line = 2;
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 1;
        a[1][1] = 1;
    }
};

//  矩阵初始化
Matrix isit(Matrix x, long long c)
{
    for (long long i = 0; i < MAXN; i++)
    {
        for (long long j = 0; j < MAXN; j++)
        {
            x.a[i][j] = c;
        }
    }
    return x;
}

//   矩阵乘法
Matrix Matlab(Matrix x, Matrix s)
{
    Matrix ans;
    ans.line = x.line;
    ans = isit(ans,0);
    for (long long i = 0; i < x.line; i++)
    {
        for (long long j = 0; j < x.line; j++)
        {
            for (long long k = 0; k < s.line; k++)
            {
                ans.a[i][j] = (ans.a[i][j] + x.a[i][k] * s.a[k][j]) % MOD_;
                ans.a[i][j] = (ans.a[i][j] + MOD_) % MOD_;
            }
        }
    }
    return ans;
}

long long FastMatrix(Matrix tmp, long long n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 1;
    }
    if (n == 2)
    {
        return 3;
    }
    n--;
    Matrix ans, ch;
    ans.line = 2;
    ans.a[0][0] = 1;
    ans.a[0][1] = 0;
    ans.a[1][0] = 1;
    ans.a[1][1] = 0;
    while (n > 0)
    {
        if (n % 2)
        {
            ans = Matlab(ans, tmp);
        }
        tmp = Matlab(tmp, tmp);
        n /= 2;
    }
    return (ans.a[0][0] + ans.a[0][1]) % MOD_;
}

int main()
{
    Matrix T;
    long long n;
    cin >> n;
    
    long long x = FastMatrix(T, n);
    cout << (x * x + (n & 1)) % MOD_ << endl;
    
    return 0;
}
