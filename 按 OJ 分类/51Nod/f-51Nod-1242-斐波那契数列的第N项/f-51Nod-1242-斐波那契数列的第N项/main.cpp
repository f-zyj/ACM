//
//  main.cpp
//  f-51Nod-1242-斐波那契数列的第N项
//
//  Created by ZYJ on 16/7/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

#define mod(a, m) ((a) % (m) + (m)) % (m)

const int MOD = 1e9 + 9;

struct MATRIX
{
    long long a[2][2];
};

MATRIX a;
long long f[2];

void ANS_Cf(MATRIX a)
{
    f[0] = mod(a.a[0][0] + a.a[1][0], MOD);
    f[1] = mod(a.a[0][1] + a.a[1][1], MOD);
    return ;
}

MATRIX MATRIX_Cf(MATRIX a, MATRIX b)
{
    MATRIX ans;
    int k;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ans.a[i][j] = 0;
            k = 0;
            while (k < 2)
            {
                ans.a[i][j] += a.a[k][i] * b.a[j][k];
                ans.a[i][j] = mod(ans.a[i][j], MOD);
                ++k;
            }
        }
    }
    return ans;
}

MATRIX MATRIX_Pow(MATRIX a, long long n)
{
    MATRIX ans;
    ans.a[0][0] = 1;
    ans.a[1][1] = 1;
    ans.a[0][1] = 0;
    ans.a[1][0] = 0;
    while (n)
    {
        if (n & 1)
        {
            ans = MATRIX_Cf(ans, a);
        }
        n = n >> 1;
        a = MATRIX_Cf(a, a);
    }
    return ans;
}

int main()
{
    long long n;
    while (cin >> n)
    {
        if (n == 1)
        {
            cout << '1' << '\n';
            continue;
        }
        a.a[0][0] = a.a[0][1] = a.a[1][0] = 1;
        a.a[1][1] = 0;
        a = MATRIX_Pow(a, n - 2);
        ANS_Cf(a);
        cout << f[0] << '\n';
    }
    return 0;
}