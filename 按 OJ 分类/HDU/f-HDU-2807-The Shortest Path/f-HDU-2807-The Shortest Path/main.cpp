//
//  main.cpp
//  f-HDU-2807-The Shortest Path
//
//  Created by ZYJ on 2016/11/25.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef int Type;
const int INF = 0x3f3f3f3f;
const int MAXN = 100;

/*
 *  AB == C ???
 */
struct Matrix
{
    Type mat[MAXN][MAXN];
    int n, m;
    Matrix()
    {
        n = m = MAXN;
        memset(mat, 0, sizeof(mat));
    }
    Matrix(const Matrix &a)
    {
        set_size(a.n, a.m);
        memcpy(mat, a.mat, sizeof(a.mat));
    }
    Matrix & operator = (const Matrix &a)
    {
        set_size(a.n, a.m);
        memcpy(mat, a.mat, sizeof(a.mat));
        return *this;
    }
    void set_size(int row, int column)
    {
        n = row;
        m = column;
    }
    friend Matrix operator * (const Matrix &a, const Matrix &b)
    {
        Matrix ret;
        ret.set_size(a.n, b.m);
        for (int i = 0; i < a.n; ++i)
        {
            for (int k = 0; k < a.m; ++k)
            {
                if (a.mat[i][k])
                {
                    for (int j = 0; j < b.m; ++j)
                    {
                        if (b.mat[k][j])
                        {
                            ret.mat[i][j] = ret.mat[i][j] + a.mat[i][k] * b.mat[k][j];
                        }
                    }
                }
            }
        }
        return ret;
    }
    friend bool operator == (const Matrix &a, const Matrix &b)
    {
        if (a.n != b.n || a.m != b.m)
        {
            return false;
        }
        for (int i = 0; i < a.n; ++i)
        {
            for (int j = 0; j < a.m; ++j)
            {
                if (a.mat[i][j] != b.mat[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

Matrix mat[MAXN];
int n, m;
int city[MAXN][MAXN];

void init()
{
    memset(city, 0x3f, sizeof(city));
}

void floyd()
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (city[i][k] != INF && city[k][j] != INF)
                {
                    city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
                }
            }
        }
    }
}

int main()
{
    while (~scanf("%d%d", &n, &m) && n + m)
    {
        init();
        for (int i = 0; i < n; ++i)
        {
            mat[i].set_size(m, m);
            for (int j = 0; j < m; ++j)
            {
                for (int k = 0; k < m; ++k)
                {
                    scanf("%d", &mat[i].mat[j][k]);
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i != j)
                {
                    Matrix ret = mat[i] * mat[j];
                    for (int k = 0; k < n; ++k)
                    {
                        if (k != j && k != i)
                        {
                            if (ret == mat[k])
                            {
                                city[i][k] = 1;
                            }
                        }
                    }
                }
            }
        }
        
        floyd();
        
        scanf("%d", &m);
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            --u, --v;
            if (city[u][v] != INF)
            {
                printf("%d\n", city[u][v]);
            }
            else
            {
                puts("Sorry");
            }
        }
    }
    
    return 0;
}
