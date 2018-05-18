//
//  main.cpp
//  f-POJ-3744-Scout YYF I
//
//  Created by ZYJ on 2017/10/31.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 15;

struct Matrix
{
    double mat[2][2];
};

Matrix mul(Matrix a, Matrix b)
{
    Matrix ret;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ret.mat[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                ret.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            }
        }
    }
    
    return ret;
}

Matrix QPow_M(Matrix a, int n)
{
    Matrix ret;
    memset(ret.mat, 0, sizeof(ret.mat));
    
    for (int i = 0; i < 2; i++)
    {
        ret.mat[i][i] = 1;
    }
    
    Matrix tmp = a;
    while (n)
    {
        if (n & 1)
        {
            ret = mul(ret, tmp);
        }
        tmp = mul(tmp, tmp);
        n >>= 1;
    }
    
    return ret;
}

int n;
double p;
int x[MAXN];

int main(int argc, const char * argv[])
{
    while (cin >> n >> p)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", x + i);
        }
        sort(x, x + n);
        
        double ans;
        Matrix m, t;
        m.mat[0][0] = p;
        m.mat[0][1] = 1 - p;
        m.mat[1][0] = 1;
        m.mat[1][1] = 0;
        
        t = QPow_M(m, x[0] - 1);
        ans = (1 - t.mat[0][0]);
        
        for (int i = 1; i < n; i++)
        {
            if (x[i] == x[i - 1])
            {
                continue;
            }
            t = QPow_M(m, x[i] - x[i - 1] - 1);
            ans *= (1 - t.mat[0][0]);
        }
        
        printf("%.7lf\n", ans);
    }
    
    return 0;
}
