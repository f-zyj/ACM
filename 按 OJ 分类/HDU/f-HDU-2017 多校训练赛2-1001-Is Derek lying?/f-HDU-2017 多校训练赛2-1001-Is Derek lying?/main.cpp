//
//  main.cpp
//  f-HDU-2017 多校训练赛2-1001-Is Derek lying?
//
//  Created by ZYJ on 2017/7/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 8e5 + 7;

int n, x, y;
char s1[MAXN];
char s2[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d%d%d", &n, &x, &y);
        scanf("%s%s", s1, s2);
        
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == s2[i])
            {
                cnt1++;
            }
            else
            {
                cnt2++;
            }
        }
        
        if (cnt1 >= x && cnt1 >= y)
        {
            cnt1 = min(x, y);
            if (cnt1 + cnt2 < max(x, y))
            {
                printf("Lying\n");
            }
            else
            {
                printf("Not lying\n");
            }
        }
        else
        {
            if (cnt1 < x && cnt1 < y)
            {
                int num = n - x;
                if (num + cnt1 < y)
                {
                    printf("Lying\n");
                }
                else
                {
                    printf("Not lying\n");
                }
            }
            else
            {
                if (x > y)
                {
                    swap(x, y);
                }
                
                cnt1 = x;
                if (cnt1 + cnt2 < y)
                {
                    printf("Lying\n");
                }
                else
                {
                    printf("Not lying\n");
                }
            }
        }
    }
    
    return 0;
}

