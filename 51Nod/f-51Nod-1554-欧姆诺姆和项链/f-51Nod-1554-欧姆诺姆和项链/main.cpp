//
//  main.cpp
//  f-51Nod-1554-欧姆诺姆和项链
//
//  Created by ZYJ on 2017/7/22.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>

int const MAXN = 1e6 + 5;

int n, k;
char s[MAXN];
char ans[MAXN];
int nt[MAXN];

void get_nt()
{
    nt[0] = -1;
    for (int i = 1, j = -1; i < n; i++)
    {
        while (j != -1 && s[j + 1] != s[i])
        {
            j = nt[j];
        }
        if (s[j + 1] == s[i])
        {
            j++;
        }
        nt[i] = j;
    }
}

int main()
{
    scanf("%d%d%s", &n, &k, s);
    
    get_nt();
    
    for(int i = 0; i < n; i++)
    {
        int len = i - nt[i];
        int num = (i + 1) / len;
        int t = num % k;
        if (t == 0)
        {
            ans[i] = '1';
        }
        else
        {
            if (len * num != i + 1)
            {
                t++;
            }
            if (num / k >= t)
            {
                ans[i] = '1';
            }
            else
            {
                ans[i] = '0';
            }
        }
    }
    printf("%s\n", ans);
    
    return 0;
}
