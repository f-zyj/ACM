//
//  main.cpp
//  f-蓝桥-ALGO-10-集合运算
//
//  Created by ZYJ on 2017/6/1.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 2222;
const int INF = 0x7fffffff;

int A[MAXN], B[MAXN];
int C[MAXN], D[MAXN];
set<int> E;

int main(int argc, const char * argv[])
{
    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }
    sort(A, A + n);
    sort(B, B + m);
    A[n] = B[m] = INF;
    
    int i = 0, j = 0;
    int cntC = 0, cntD = 0;
    if (A[0] < B[0])
    {
        while (i < n)
        {
            D[cntD++] = A[i];
            while (j < m && B[j] < A[i + 1])
            {
                if (B[j] != A[i])
                {
                    D[cntD++] = B[j];
                }
                else
                {
                    C[cntC++] = B[j];
                }
                j++;
            }
            i++;
        }
        while (j < m)
        {
            D[cntD++] = B[j];
            j++;
        }
    }
    else
    {
        while (j < m)
        {
            D[cntD++] = B[j];
            while (i < n && A[i] < B[j + 1])
            {
                if (B[j] != A[i])
                {
                    D[cntD++] = A[i];
                }
                else
                {
                    C[cntC++] = A[i];
                }
                i++;
            }
            j++;
        }
        while (i < n)
        {
            D[cntD++] = A[i];
            i++;
        }
    }
    
    for (int i = 0; i < cntC; i++)
    {
        cout << C[i] << ' ';
        E.insert(C[i]);
    }
    cout << '\n';
    for (int i = 0; i < cntD; i++)
    {
        cout << D[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++)
    {
        if (!E.count(A[i]))
        {
            cout << A[i] << ' ';
        }
    }
    cout << '\n';
    
    return 0;
}
