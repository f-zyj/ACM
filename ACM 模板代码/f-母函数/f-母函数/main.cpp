//
//  main.cpp
//  f-母函数
//
//  Created by ZYJ on 2017/9/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 *  母函数
 *  c1是保存各项质量砝码可以组合的数目
 *  c2是中间量，保存每一次的情况
 */
const int MAXN = 1e4 + 10;

int n;
int c1[MAXN];
int c2[MAXN];

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i <= n; ++i)
        {
            c1[i] = 1;
            c2[i] = 0;
        }
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                for (int k = 0; k + j <= n; k += i)
                {
                    c2[j + k] += c1[j];
                }
            }
            for (int j = 0; j <= n; ++j)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        
        cout << c1[n] << endl;
    }
    
    return 0;
}
