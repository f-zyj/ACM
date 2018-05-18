//
//  main.cpp
//  f-CF-Tinkoff Challenge-Elimination Round-A-Oleg and shares
//
//  Created by ZYJ on 2017/4/24.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 1e5 + 10;
const int INF = 1e9 + 10;

int a[MAXN];

int main(int argc, const char * argv[])
{
    int n, k;
    while (cin >> n >> k)
    {
        long long ans = 0;
        int minA = INF;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            minA = a[i] < minA ? a[i] : minA;
        }
        
        int flag = 1;
        for (int i = 0; i < n; i++)
        {
            if ((a[i] - minA) % k)
            {
                flag = 0;
                break;
            }
            ans += (a[i] - minA) / k;
        }
        
        if (flag)
        {
            cout << ans << '\n';
        }
        else
        {
            cout << "-1\n";
        }
    }
    
    return 0;
}
