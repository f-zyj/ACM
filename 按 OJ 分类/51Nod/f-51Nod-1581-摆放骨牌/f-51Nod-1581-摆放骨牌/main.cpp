//
//  main.cpp
//  f-51Nod-1581-摆放骨牌
//
//  Created by ZYJ on 2017/7/31.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

const int MAXN = 2005;
const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const char S1[6] = "<>^v";
const char S2[6] = "><v^";

int n, m;
char s[MAXN][MAXN];
char ans[MAXN][MAXN];
int deg[MAXN][MAXN];
int Q[MAXN * MAXN][2];

void BFS(int x, int y)
{
    Q[0][0] = x;
    Q[0][1] = y;
    
    int head = 0, tail = 1;
    while (head < tail)
    {
        x = Q[head][0];
        y = Q[head++][1];
        deg[x][y] = 0;
        
        for (int i = 0; i < 4; i++)
        {
            int x_ = x + d[i][0];
            int y_ = y + d[i][1];
            if (deg[x_][y_] == 0)
            {
                continue;
            }
            
            deg[x_][y_] = 0;
            ans[x][y] = S1[i];
            ans[x_][y_] = S2[i];
            for (int t = 0; t < 4; t++)
            {
                int a = x_ + d[t][0];
                int b = y_ + d[t][1];
                if (deg[a][b] == 0)
                {
                    continue;
                }
                
                deg[a][b]--;
                if (deg[a][b] == 1)
                {
                    Q[tail][0] = a;
                    Q[tail++][1] = b;
                }
            }
        }
    }
}

int main ()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i] + 1);
    }
 
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] == '.')
            {
                for (int t = 0; t < 4; t++)
                {
                    tmp++;
                    int x = i + d[t][0];
                    int y = j + d[t][1];
                    if (s[x][y] == '.')
                    {
                        deg[i][j]++;
                    }
                }
            }
        }
    }
    
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (deg[i][j] == 1)
            {
                BFS(i, j);
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] == '.' && ans[i][j] == 0)
            {
                flag = false;
                break;
            }
        }
    }
    
    if (flag)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (!ans[i][j])
                {
                    ans[i][j] = '*';
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%s\n", ans[i] + 1);
        }
    }
    else
    {
        printf("Not unique\n");
    }
    
    return 0;
}
