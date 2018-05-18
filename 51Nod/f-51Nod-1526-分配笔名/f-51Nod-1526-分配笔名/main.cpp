//
//  main.cpp
//  f-51Nod-1526-分配笔名
//
//  Created by ZYJ on 2017/9/15.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 8e5 + 5;
const int MAGIC = 26;
const int LIMIT = 5e5;

int n, ans, cnt = 0;
char s[MAXN];
int tag[MAXN];
int dep[MAXN];
int c[MAXN][MAGIC];

void dfs(int x)
{
    for (int i = 0; i < MAGIC; i++)
    {
        if (c[x][i])
        {
            dfs(c[x][i]);
            
            if (tag[x] > 0 && tag[c[x][i]] < 0)
            {
                ans += min(tag[x], -tag[c[x][i]]) * dep[x];
            }
            else if (tag[x] < 0 && tag[c[x][i]] > 0)
            {
                ans += min(-tag[x], tag[c[x][i]]) * dep[x];
            }
            tag[x] += tag[c[x][i]];
        }
    }
}

int main()
{
    scanf("%d", &n);
    
    int mx = 0;
    for (int i = 1, len; i <= n; i++)
    {
        scanf("%s", s + 1);
        len = (int)strlen(s + 1);
        mx = max(mx, len);
        int x = 0;
        for (int i = 1; i <= len; i++)
        {
            if (!c[x][s[i] - 'a'])
            {
                c[x][s[i] - 'a'] = ++cnt;
                dep[cnt] = i;
            }
            x = c[x][s[i] - 'a'];
        }
        tag[x]++;
    }
    
    for (int i = 1, len; i <= n; i++)
    {
        scanf("%s", s + 1);
        len = (int)strlen(s + 1);
        mx = max(mx, len);
        int x = 0;
        for (int i = 1; i <= len; i++)
        {
            if (!c[x][s[i] - 'a'])
            {
                c[x][s[i] - 'a'] = ++cnt;
                dep[cnt] = i;
            }
            x = c[x][s[i] - 'a'];
        }
        
        if (tag[x] > 0)
        {
            ans += dep[x];
        }
        tag[x]--;
    }
    
    if (mx > LIMIT)
    {
        puts("1");
        return 0;
    }
    
    dfs(0);
    
    printf("%d\n", ans);
    
    return 0;
}
