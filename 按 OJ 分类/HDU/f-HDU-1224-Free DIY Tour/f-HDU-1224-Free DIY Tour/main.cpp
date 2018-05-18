//
//  main.cpp
//  f-HDU-1224-Free DIY Tour
//
//  Created by ZYJ on 2016/11/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>

const int MAXN = 110;

struct A
{
    int ans;
    int flag;
    int pre;
} E[MAXN];

int map[MAXN][MAXN];
int point[MAXN];
int ans[MAXN * MAXN];

int main()
{
    int T;
    int n, m;
    
    scanf("%d", &T);
    for(int key = 1; key <= T; key++)
    {
        scanf("%d", &n);
        int temp = n + 1;
        int max = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &point[i]);
            max = max > point[i] ? max : point[i];
        }
        point[n + 1] = max + 1;
        
        scanf("%d", &m);
        memset(map, 0, sizeof(map));
        
        int a, b;
        while (m--)
        {
            scanf("%d%d", &a, &b);
            int st = a > b ? b : a;
            int ed = a > b ? a : b;
            map[st][ed] = point[ed];
        }
        
        for (int i = 1; i <= temp; i++)
        {
            E[i].ans = 0;
            E[i].flag = 1;
            E[i].pre = i;
        }
        
        
        int k = 1;
        while (k)
        {
            E[k].flag = 0;
            for (int i = k + 1; i <= temp; i++)
            {
                if (map[k][i] == 0)
                {
                    continue;
                }
                if (E[k].ans + map[k][i] > E[i].ans)
                {
                    E[i].ans = E[k].ans + map[k][i];
                    E[i].pre = k;
                }
            }
            
            k = 0;
            for (int i = 1; i <= n; i++)
            {
                if (E[i].flag && E[i].ans)
                {
                    k = i;
                    break;
                }
            }
        }
        
        
        printf("CASE %d#\n", key);
        printf("points : %d\n", E[n + 1].ans - max - 1);
        printf("circuit : ");
        
        k = E[n + 1].pre;
        int i = 0;
        ans[i] = k;
        while (k != 1)
        {
            k = E[k].pre;
            ans[++i] = k;
        }
        for (; i >= 0; i--)
        {
            printf("%d->", ans[i]);
        }
        printf("1\n");
        
        if (key < T)
        {
            printf("\n");
        }
    }
    return 0;
}
