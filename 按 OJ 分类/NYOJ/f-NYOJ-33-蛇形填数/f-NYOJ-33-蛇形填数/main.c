//
//  main.c
//  f-NYOJ-33-蛇形填数
//
//  Created by ZYJ on 16/5/25.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//#include <string.h>
//int map[101][101];
//
//int main(int argc, const char * argv[])
//{
//    int N;
//    int i, j;
//    
//    while (~scanf("%d", &N))
//    {
//        memset(map, 0, sizeof(map));
//        map[0][0] = 1;
//        
//        for (i = 1; i < N * 1.0 / 2; i++)
//        {
//            map[i][i] = map[i - 1][i - 1] + (N - 2 * (i - 1) - 1) * 4;
//        }
//        for (j = 0; j < N / 2; j++)
//        {
//            for (i = j + 1; i < N - j; i++)
//            {
//                map[i][j] = map[i - 1][j] + 1;
//            }
//        }
//        for (i = N - 1; i > N / 2 - 0.5; i--)
//        {
//            for (j = N - i; j < i + 1; j++)
//            {
//                map[i][j] = map[i][j - 1] + 1;
//            }
//        }
//        for (j = N - 1; j >= N / 2; j--)
//        {
//            for (i = j - 1; i > N - j - 2; i--)
//            {
//                map[i][j] = map[i + 1][j] + 1;
//            }
//        }
//        for (i = 0; i < N / 2; i++)
//        {
//            for (j = N - i - 2; j > i; j--)
//            {
//                map[i][j] = map[i][j + 1] + 1;
//            }
//        }
//        
//        for (i = 0; i < N; i++)
//        {
//            for (j = N - 1; j > 0; j--)
//            {
//                printf("%d ", map[i][j]);
//            }
//            printf("%d\n", map[i][0]);
//        }
////        for (i=0; i<N; i++)
////        {
////            for (j=0; j<N; j++)
////            {
////                printf("%d\t",map[i][j]);
////            }
////            printf("\n");
////        }
//    }
//
//    return 0;
//}


#include <stdio.h>
#include <string.h>
#define MaxSize 100

int main()
{
    int a[MaxSize][MaxSize];
    int n, x = 0, y, tot=0;
    
    scanf("%d",&n);
    y = n - 1;
    memset(a, 0, sizeof(a));
    
    tot = a[x][y] = 1;
    while(tot < n * n)
    {
        while(x + 1 < n && !a[x+1][y])
            a[++x][y] = ++tot;
        while(y - 1 >= 0 && !a[x][y-1])
            a[x][--y] = ++tot;
        while(x - 1 >= 0 && !a[x - 1][y])
            a[--x][y] = ++tot;
        while(y + 1 < n && !a[x][y+1])
            a[x][++y] = ++tot;
    }
    
    for(x = 0; x < n; x++)
    {
        for(y = 0; y < n; y++)
            printf("%5d", a[x][y]);
        printf("\n");
    }
    
    return 0;
}
