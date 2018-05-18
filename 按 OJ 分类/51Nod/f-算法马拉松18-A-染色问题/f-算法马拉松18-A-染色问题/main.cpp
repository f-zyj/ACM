//
//  main.cpp
//  f-算法马拉松18-A-染色问题
//
//  Created by ZYJ on 2016/9/25.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    int n;
    while (T--)
    {
        cin >> n;
        cout << n << '\n';
        if (n % 2 == 0)
        {
            puts("No solution");
        }
        else
        {
            int k = 0;
            for (int i = 1; i <= n; i++)
            {
                int pos = k;
                for (int j = i + 1; j <= n; j++)
                {
                    cout << i << ' ' << j << ' ' << pos % n + 1 << ' ';
                    pos++;
                }
                k += 2;
            }
            cout << '\n';
        }
    }

    return 0;
}
