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

const int MAXN = 1e4 + 10;

int n, m, k;
int a[MAXN], b[MAXN];

int main(int argc, const char * argv[])
{
    while (cin >> n >> m >> k)
    {
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i] >> b[i];
        }
        
        int pos = 1;
        double p = 1.0 * m / n;
        double ans = p * a[1] + (1.0 - p) * b[1];
        for (int i = 2; i <= k; i++)
        {
            double tmp = p * a[i] + (1.0 - p) * b[i];
            if (tmp >= ans)
            {
                ans = tmp;
                pos = i;
            }
        }
        
        for (int i = 1; i <= k; i++)
        {
            printf("%d%c", i == pos ? n : 0, i == k ? '\n' : ' ');
        }
    }
    
    return 0;
}
