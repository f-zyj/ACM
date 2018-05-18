//
//  main.c
//  f-51Nod-1118-机器人走方格
//
//  Created by ZYJ on 16/4/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//#define _MOD 1000000007
//
//int path(int M, int N)
//{
//    if (M == 1 || N == 1)
//    {
//        return 1;
//    }
//    return (path(M - 1, N) + path(M, N - 1)) % _MOD;
//}
//
//int main(int argc, const char * argv[])
//{
//    int M, N, ans;
//    while (~scanf("%d %d", &M, &N))
//    {
//        ans = path(M, N);
//        printf("%d\n", ans);
//    }
//    return 0;
//}

#include <stdio.h>
#include <string.h>
#define _MOD 1000000007
int map[1001][1001];

int path(int M, int N)
{
    if (map[M][N])
    {
        return map[M][N];
    }
    else if (M == 1 || N == 1)
    {
        map[M][N] = 1;
        return map[M][N];
    }
    map[M][N] = (path(M - 1, N) + path(M, N - 1)) % _MOD;
    return map[M][N];
}

int main(int argc, const char * argv[])
{
    int M, N, ans;
    
    while (~scanf("%d %d", &M, &N))
    {
        memset(map, 0, sizeof(int) * 1001 * 1001);
        ans = path(M, N);
        printf("%d\n", ans);
    }
    return 0;
}
