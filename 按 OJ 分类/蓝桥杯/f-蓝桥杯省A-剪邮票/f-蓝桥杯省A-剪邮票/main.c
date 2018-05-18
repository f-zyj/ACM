//
//  main.c
//  f-蓝桥杯省A-剪邮票
//
//  Created by ZYJ on 16/4/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int stamps[12] = {0};
int ans = 0;

void test(int i, int j, int k, int q, int w)
{
    //上下左右四个方向
    int dir[4] = {-4, 4, -1 , 1};
    int r = 0, edge = 0, flagI = 0, flagJ = 0, flagK = 0, flagQ = 0, flagW = 0;
    for (; r < 4; r++)
    {
        if (!((i == 3 || i == 7) && r == 3) && !((i == 4 || i == 8) && r == 2) && stamps[i + dir[r]] == 1)
        {
            edge++;
            flagI = 1;
        }
        if (!((j == 3 || j == 7) && r == 3) && !((j == 4 || j == 8) && r == 2) && stamps[j + dir[r]] == 1)
        {
            edge++;
            flagJ = 1;
        }
        if (!((k == 3 || k == 7) && r == 3) && !((k == 4 || k == 8) && r == 2) && stamps[k + dir[r]] == 1)
        {
            edge++;
            flagK = 1;
        }
        if (!((q == 3 || q == 7) && r == 3) && !((q == 4 || q == 8) && r == 2) && stamps[q + dir[r]] == 1)
        {
            edge++;
            flagQ = 1;
        }
        if (!((w == 3 || w == 7) && r == 3) && !((w == 4 || w == 8) && r == 2) && stamps[w + dir[r]] == 1)
        {
            edge++;
            flagW = 1;
        }
    }
    
    if (edge >= 8 && flagI == 1 && flagJ == 1 && flagK == 1 && flagQ == 1 && flagW == 1)
    {
        ans++;
    }
    return ;
}

void vid()
{
    int i, j, k, q, w;
    for (i = 0; i < 8; i++)
    {
        stamps[i] = 1;
        for (j = i + 1; j < 9; j++)
        {
            stamps[j] = 1;
            for (k = j + 1; k < 10; k++)
            {
                stamps[k] = 1;
                for (q = k + 1; q < 11; q++)
                {
                    stamps[q] = 1;
                    for (w = q + 1; w < 12; w++)
                    {
                        stamps[w] = 1;
                        test(i, j, k, q, w);
                        stamps[w] = 0;
                    }
                    stamps[q] = 0;
                }
                stamps[k] = 0;
            }
            stamps[j] = 0;
        }
        stamps[i] = 0;
    }
    return ;
}

int main(int argc, const char * argv[])
{
    vid();
    printf("%d\n", ans);
    return 0;
}
