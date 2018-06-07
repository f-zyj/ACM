//
//  main.cpp
//  f-牛客网-2018 美团 CodeM 编程大赛-资格赛
//
//  Created by ZYJ on 2018/6/7.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <iostream>

using namespace std;

const int MAXN = 15;

int n, m;
int a[MAXN], b[MAXN];
int c[MAXN], w[MAXN];

int main(int argc, const char * argv[])
{
    while (cin >> n >> m)
    {
        double sum = 0, ans1 = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i];
            sum += a[i];
            if (b[i])
            {
                ans1 += a[i] * 0.8;
            }
            else
            {
                ans1 += a[i];
            }
        }
        
        double ans2 = sum;
        for (int i = 1; i <= m; i++)
        {
            cin >> c[i] >> w[i];
            if (sum >= c[i] && ans2 > sum - w[i])
            {
                ans2 = sum - w[i];
            }
        }
        
        if (ans1 > ans2)
        {
            printf("%.2f\n", ans2);
        }
        else
        {
            printf("%.2f\n", ans1);
        }
    }
    
    return 0;
}
