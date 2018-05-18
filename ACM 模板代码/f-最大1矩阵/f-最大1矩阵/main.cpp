//
//  main.cpp
//  f-最大1矩阵
//
//  Created by ZYJ on 16/7/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

//  最大1矩阵

const int N = 1000;

bool a[N][N];

int Run(const int &m, const int &n)     // a[1...m][1...n]
{                                       // O(m*n)
    int i, j, k, l, r, max=0;
    int col[N];
    for (j = 1; j <= n; j++)
    {
        if (a[1][j] == 0 )
        {
            col[j] = 0;
        }
        else
        {
            for (k = 2; k <= m && a[k][j] == 1; k++);
            col[j] = k - 1;
        }
    }
    for (i = 1; i <= m; i++)
    {
        if (i > 1)
        {
            for (j = 1; j <= n; j++)
            {
                if (a[i][j] == 0)
                {
                    col[j] = 0;
                }
                else
                {
                    if (a[i - 1][j] == 0)
                    {
                        for (k = i + 1; k <= m && a[k][j] == 1; k++);
                        col[j] = k-1;
                    }
                }
            }
        }
        for (j = 1; j <= n; j++)
        {
            if (col[j] >= i)
            {
                for (l = j - 1; l > 0 && col[l] >= col[j]; --l);
                l++;
                for (r = j + 1; r <= n && col[r] >= col[j]; ++r);
                r--;
                int res = (r - l + 1) * (col[j] - i + 1);
                if( res > max )
                {
                    max = res;
                }
            }
        }
    }
    return max;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
