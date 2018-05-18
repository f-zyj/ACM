//
//  main.cpp
//  ICPC Asia Regional Shenyang Online-1012-card card card
//
//  Created by ZYJ on 2017/9/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 1e6 + 7;

int n;
int p[MAXN << 1];
int w[MAXN << 1];

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", p + i);
            p[n + i] = p[i];
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", w + i);
            w[n + i] = w[i];
        }
        
        int l = 1, r = 1, sum = 0, cnt = 0, id = 0, ans = 0;
        while (l <= n)
        {
            while (sum + p[r] - w[r] >= 0 && r <= 2 * n && r - l + 1 <= n)
            {
                sum += p[r] - w[r];
                cnt += p[r];
                r++;
            }
            if (r - l + 1 > n)
            {
                id = l;
                break;
            }
            if (l == r)
            {
                l++;
                r++;
            }
            else
            {
                if (cnt > ans)
                {
                    ans = cnt;
                    id = l;
                    
                }
                cnt -= p[l];
                sum -= p[l] - w[l];
                l++;
            }
        }
        
        printf("%d\n", id - 1);
    }
    
    return 0;
}
