//
//  main.cpp
//  f-牛客网-2018 美团 CodeM 编程大赛-初赛 A 轮
//
//  Created by ZYJ on 2018/6/9.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <iostream>

using namespace std;

const int MAXN = 1e5 + 10;

int n;
int x[MAXN], y[MAXN];

int main(int argc, const char * argv[])
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", x + i);
        }
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", y + j);
        }
        
        long long ans = 0, sum = 0;
        for (int i = n; i >= 2; i--)
        {
            sum += y[i] - x[i];
            if (sum > 0)
            {
                ans += sum * (i - 1);
                sum = 0;
            }
            else
            {
                ans -= sum;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
