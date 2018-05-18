//
//  main.cpp
//  f-51Nod-1377-最慢的快排
//
//  Created by ZYJ on 2017/6/16.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 5e4 + 10;

int n, k;
int ans[MAXN];
int high[MAXN];
int r[MAXN];

int main()
{
    while (cin >> n >> k)
    {
        memset(ans, 0, sizeof ans);
        
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &r[i]);
        }
        
        for (int i = 1; i <= n; i++)
        {
            high[i] = i;
        }
        
        int L = 1, R = n, deep = 1;
        for (int i = 0; i < n; i++)
        {
            int x = r[i % k] % (n - i);
            x = x + L;
            
            if (high[x] == deep)
            {
                ans[high[x]] = L;
                swap(high[x], high[L]);
                L++;
                while (ans[deep])
                {
                    deep++;
                }
            }
            else
            {
                ans[high[x]] = R;
                swap(high[x], high[L]);
                swap(high[L], high[R]);
                R--;
            }
        }
        
        for (int i = 1; i <= n; i++)
        {
            printf("%d\n", ans[i]);
        }
    }
    
    return 0;
}
