//
//  main.cpp
//  f-集合划分问题
//
//  Created by ZYJ on 16/7/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 *  n元集合分划为k类的方案数记为S(n, k),称为第二类Stirling数。
 *  如{A,B,C}可以划分{{A}, {B}, {C}}, {{A, B}, {C}}, {{B, C}, {A}}, {{A, C}, {B}}, {{A, B, C}}。
 *  即一个集合可以划分为不同集合(1...n个)的种类数
 *  CALL: compute(N); 每当输入一个n,输出B[n]
 */
const int N = 2001;
int data[N][N], B[N];

void NGetM(int m, int n)    // m 个数 n 个集合
{
    //  data[i][j]: i个数分成j个集合
    int min, i, j;
    data[0][0] = 1;
    for (i = 1; i <= m; i++)
    {
        data[i][0] = 0;
    }
    for (i = 0; i <= m; i++)
    {
        data[i][i + 1] = 0;
    }
    for (i = 1; i <= m; i++)
    {
        if (i < n)
        {
            min = i;
        }
        else
        {
            min = n;
        }
        for (j = 1; j <= min; j++)
        {
                data[i][j] = (j * data[i - 1][j] + data[i - 1][j - 1]);
        }
    }
    return ;
}

void compute(int m)
{
    //  b[i]: Bell数
    NGetM(m, m);
    memset(B, 0, sizeof(B));
    int i, j;
    for (i=1; i <= m; i++)
    {
        for (j = 0; j <= i; j++)
        {
            B[i] += data[i][j];
        }
    }
    return ;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
