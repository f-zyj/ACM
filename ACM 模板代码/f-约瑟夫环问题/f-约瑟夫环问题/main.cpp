//
//  main.cpp
//  f-约瑟夫环问题
//
//  Created by ZYJ on 16/7/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

//  约瑟夫环问题（数学方法）

/*
 *  n个人(编号 1...n),先去掉第m个数,然后从m+1个开始报1,
 *  报到k的退出,剩下的人继续从1开始报数.求胜利者的编号.
 */

int main(int argc, const char * argv[])
{
    int n, k, m;
    while (cin >> n >> k >> m, n || k || m)
    {
        int i, d, s = 0;
        for (i = 2; i <= n; i++)
        {
            s = (s + k) % i;
        }
        k = k % n;
        if (k == 0)
        {
            k = n;
        }
        d = (s + 1) + (m - k);
        if (d >= 1 && d <= n)
        {
            cout << d << '\n';
        }
        else if ( d < 1 )
        {
            cout << n + d << '\n';
        }
        else if ( d > n )
        {
            cout << d % n << '\n';
        }
    }
    return 0;
}
