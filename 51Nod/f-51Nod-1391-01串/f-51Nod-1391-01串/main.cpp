//
//  main.cpp
//  f-51Nod-1391-01串
//
//  Created by ZYJ on 16/9/15.
//  Copyright ? 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 1e6 + 10;

char S[MAXN];

int sum_0[MAXN], sum_1[MAXN];

int head[MAXN];

int main()
{
    while (~scanf("%s", S))
    {
        int cur = 0;
        int len = (int)strlen(S);
        memset(sum_1, 0, sizeof(sum_1));
        memset(sum_0, 0, sizeof(sum_0));
        memset(head, -1, sizeof(head));
        
        for (int i = 0; i < len; i++)
        {
            if (S[i] == '0')
            {
                cur += -1;
            }
            else
            {
                cur += 1;
            }
            if (cur < 0)
            {
                sum_0[i] = i + 1;
            }
            else
            {
                if (head[cur + 1] != -1)
                {
                    sum_0[i] = i - head[cur + 1];
                }
                else
                {
                    head[cur] = i;
                    sum_0[i] = 0;
                }
            }
        }
        memset(head, -1, sizeof(head));
        cur = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            if (S[i] == '0')
            {
                cur += -1;
            }
            else
            {
                cur += 1;
            }
            if (cur > 0)
            {
                sum_1[i] = len - i;
            }
            else
            {
                if (head[-(cur - 1)] != -1)
                {
                    sum_1[i] = head[-(cur - 1)] - i;
                }
                else
                {
                    sum_1[i] = 0;
                    head[-(cur)] = i;
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < len - 1; i++)
        {
            if (sum_0[i] > 0 && sum_1[i + 1] > 0)
            {
                ans = max(ans, sum_0[i] + sum_1[i + 1]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}