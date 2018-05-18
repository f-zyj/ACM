//
//  main.cpp
//  f-POJ-2185-Milking Grid
//
//  Created by ZYJ on 2017/10/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e4 + 10;
const int MAXM = 100;

int r, c, R, C;
int nxt[MAXN];
int cnt[MAXM];
char a[MAXM];
char s[MAXN][MAXM];

int main(int argc, const char * argv[])
{
    memset(cnt, 0, sizeof(cnt));
    
    scanf("%d%d", &r, &c);
    
    for (int i = 0; i < r; i++)
    {
        scanf("%s", s[i]);
        strcpy(a, s[i]);
        
        for (int j = c - 1; j > 0; j--)
        {
            a[j] = 0;
            int x = 0, y = 0;
            for (; s[i][y]; x++, y++)
            {
                if (!a[x])
                {
                    x = 0;
                }
                if (a[x] != s[i][y])
                {
                    break;
                }
            }
            if (!s[i][y])
            {
                cnt[j]++;
            }
        }
    }
    
    for (int i = 0; i < c; i++)
    {
        if (cnt[i] == r)
        {
            C = i;
            break;
        }
    }
    
    for (int i = 0; i < r; i++)
    {
        s[i][C] = 0;
    }
    
    nxt[0] = -1;
    for (int i = 1, j = -1; i < r; i++)
    {
        while (j != -1 && strcmp(s[j + 1], s[i]))
        {
            j = nxt[j];
        }
        
        if (!strcmp(s[j + 1], s[i]))
        {
            j++;
        }
        nxt[i] = j;
    }
    R = r - nxt[r - 1] - 1;
    
    printf("%d\n", R * C);
    
    return 0;
}
