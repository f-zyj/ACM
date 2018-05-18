//
//  main.cpp
//  f-51Nod-1179-最大的最大公约数
//
//  Created by ZYJ on 16/8/13.
//  Copyright ? 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 1e6 + 10;

int S[MAXN];

int main()
{
    int n;
    
    while (~scanf("%d", &n))
    {
        memset(S, 0, sizeof(S));

        int MAXA = 0, x;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            S[x]++;
            if (x > MAXA)
            {
                MAXA = x;
            }
        }
        
        int ans = 1;
        for (int j = MAXA; j >= 1; j--)
        {
            int cnt = 0;
            for (int i = j; i <= MAXA; i += j)
            {
                cnt += S[i];
                if (cnt >= 2)
                {
                    ans = j;
                    goto out;
                }
            }
        }
    out:
        printf("%d\n", ans);
    }
    
    return 0;
}