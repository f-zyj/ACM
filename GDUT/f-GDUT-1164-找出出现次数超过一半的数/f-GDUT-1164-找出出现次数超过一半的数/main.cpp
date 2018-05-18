//
//  main.cpp
//  f-GDUT-1164-找出出现次数超过一半的数
//
//  Created by ZYJ on 2017/1/4.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAXN 10000005
#define BASE 1000

using namespace std;

int A[MAXN];
int cnt[MAXN / 10];
int deep[BASE + 10];

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        memset(cnt, 0, sizeof(cnt));
        memset(deep, 0, sizeof(deep));
        
        int n, a, b, res = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", A + i);
            b = A[i] / BASE;
            cnt[b]++;
            res = (cnt[res] < cnt[b]) ? b : res;
        }
        
        int g = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] / BASE == res)
            {
                a = A[i] % BASE;
                deep[a]++;
                g = (deep[g] < deep[a]) ? a : g;
            }
        }
        printf("%d\n", g + res * 1000);
    }
    
    return 0;
}
