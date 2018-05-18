//
//  main.c
//  f-NYOJ-27-水池数目
//
//  Created by ZYJ on 16/5/24.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define MAXSIZE 101
int dir[4][2] = {0, -1, 0, 1, -1, 0, 1, 0};
int map[MAXSIZE][MAXSIZE];

//填湖造陆
void fill_pond(int i, int j)
{
    map[i][j] = 0;
    for (int k = 0; k < 4; k++)
    {
        if (map[i + dir[k][0]][j + dir[k][1]])
        {
            fill_pond(i + dir[k][0], j + dir[k][1]);
        }
    }
    return ;
}

int main(int argc, const char * argv[])
{
    int N;
    scanf("%d", &N);
    
    while (N--)
    {
        int m, n;
        int ans = 0;
        scanf("%d %d", &m, &n);
        
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", map[i] + j);
            }
        }
        
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (map[i][j])
                {
                    ans++;
                    fill_pond(i, j);
                }
            }
        }
        
        printf("%d\n", ans);
        
    }
    
    return 0;
}

