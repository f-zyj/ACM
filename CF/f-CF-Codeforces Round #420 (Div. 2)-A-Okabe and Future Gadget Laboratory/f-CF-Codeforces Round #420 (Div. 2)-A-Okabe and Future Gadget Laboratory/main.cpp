//
//  main.cpp
//  f-CF-Codeforces Round #420 (Div. 2)-A-Okabe and Future Gadget Laboratory
//
//  Created by ZYJ on 2017/6/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 55;

int n;
int A[MAXN][MAXN];
int vis[MAXN][MAXN];

int main(int argc, const char * argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", A[i] + j);
        }
    }
    
    for (int x = 0; x < n; x++)
    {
        for (int s = 0; s < n; s++)
        {
            int t1 = A[x][s];
            for (int t = 0; t < n; t++)
            {
                for (int y = 0; y < n; y++)
                {
                    int t2 = A[t][y];
                    if (t1 + t2 == A[x][y])
                    {
                        vis[x][y] = 1;
                    }
                }
            }
        }
    }
    
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j] && A[i][j] != 1)
            {
                flag = 0;
                break;
            }
        }
        if (!flag)
        {
            break;
        }
    }
    
    if (flag)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    
    return 0;
}
