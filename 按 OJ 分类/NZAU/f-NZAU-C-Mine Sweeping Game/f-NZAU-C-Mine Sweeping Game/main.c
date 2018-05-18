//
//  main.c
//  f-NZAU-C-Mine Sweeping Game
//
//  Created by ZYJ on 16/5/14.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define BANNER 10

int main(int argc, const char * argv[])
{
    int T;
    int N, M, K;
    int map[12][12];
    int key[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    scanf("%d", &T);
    
    while (T--)
    {
        int x, y;
        memset(map, 0, sizeof(map));
        scanf("%d %d %d", &N, &M, &K);
        
        for (int i = 1; i <= K; i++)
        {
            scanf("%d %d", &x, &y);
            map[x][y] = BANNER;
            
            for (int j = 0; j < 8; j++)
            {
                map[x + key[j][0]][y + key[j][1]]++;
            }
        }
        
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (map[i][j] >= BANNER)
                {
                    printf("M");
                }
                else if (map[i][j] == 0)
                {
                    printf(".");
                }
                else
                {
                    printf("%d", map[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n");
        
    }

    return 0;
}
