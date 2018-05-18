//
//  main.cpp
//  f-模线性方程（组）
//
//  Created by ZYJ on 16/6/29.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

//  模线性方程

/*
 *  模线性方程 a * x = b (% n)
 */

int extgcd(int a, int b, int &x, int &y)    //  扩展GCD
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = extgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return d;
}

void modeq(int a, int b, int n)
{
    int e, i, d, x, y;
    d = extgcd(b, a % b, x, y);
    if (b % d > 0)
    {
        cout << "No answer!\n";
    }
    else
    {
        e = (x * (b / d)) % n;
        for (i = 0; i < d; i++)
        {
            cout << i + 1 << "-th ans:" << (e + i * (n / d)) % n << '\n';
        }
    }
    return ;
}

//  模线性方程组

/*
 *  模线性方程组
 *  a = B[1](% W[1]); a = B[2](% W[2]); ... a = B[k](% W[k]);
 *  其中W，B已知，W[i] > 0且W[i]与W[j]互质，求a（中国剩余定理）
 */

int china(int b[], int w[], int k)
{
    int i, d, x, y, m, a = 0, n = 1;
    for (i = 0; i < k; i++)
    {
        n *= w[i];  //  注意不能overflow
    }
    for (i = 0; i < k; i++)
    {
        m = n / w[i];
        d = extgcd(w[i], m, x, y);
        a = (a + y * m * b[i]) % n;
    }
    if (a > 0)
    {
        return a;
    }
    else
    {
        return (a + n);
    }
}


int main(int argc, const char * argv[])
{
    
    std::cout << "Hello, World!\n";
    return 0;
}