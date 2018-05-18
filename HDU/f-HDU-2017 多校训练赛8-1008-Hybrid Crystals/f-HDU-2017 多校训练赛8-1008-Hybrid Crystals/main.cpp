//
//  main.cpp
//  f-HDU-2017 多校训练赛8-1008-Hybrid Crystals
//
//  Created by ZYJ on 2017/8/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 1111;

int n, k;
int A[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        
        int tmp1 = 0, tmp2 = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &A[i]);
        }
        
        char ch;
        for (int i = 1; i <= n; i++)
        {
            scanf("%c%c", &ch, &ch);
            if (ch == 'N')
            {
                tmp1 += A[i];
                tmp2 -= A[i];
            }
            else if (ch == 'L')
            {
                tmp1 += A[i];
            }
            else
            {
                tmp2 -= A[i];
            }
        }
        if (k > 0)
        {
            if (tmp1 >= k)
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
        else if (k < 0)
        {
            if (tmp2 <= k)
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
        else
        {
            printf("yes\n");
        }
    }
    
    return 0;
}
