//
//  main.c
//  f-NYOJ-20-吝啬的国度
//
//  Created by qingyun on 16/5/18.
//  Copyright © 2016年 qingyun. All rights reserved.
//

//#include <stdio.h>
//#include <string.h>
//#define MAXSIZE 100001
//
//int map[MAXSIZE][100];
//int toNum[MAXSIZE]; //toNum[i]从i出发可以直接到toNum[i]地点
//int from[MAXSIZE];  //前一个节点位置
//
//void solve(int S)
//{
//    if (toNum[S] == 1)
//    {
//        return ;
//    }
//    for (int i = 0; i < S; i++)
//    {
//        for (int j = 0; j < toNum[S]; j++)
//        {
//            if (map[S][j] != from[S])
//            {
//                from[map[S][j]] = S;
//                solve(map[S][j]);
//            }
//        }
//    }
//    return ;
//}
//
//int main(int argc, const char * argv[])
//{
//    int M, N, S;
//    int a, b;
//    scanf("%d", &M);
//    
//    while (M--)
//    {
//        memset(map, 0, sizeof(map));
//        memset(toNum, 0, sizeof(toNum));
//        memset(from, -1, sizeof(from));
//        scanf("%d %d", &N, &S);
//        
//        for (int i = 1; i < N; i++)
//        {
//            scanf("%d %d", &a, &b);
//            map[a][toNum[a]++] = b;
//            map[b][toNum[b]++] = a;
//        }
//        
//        solve(S);
//        
//        for (int i = 1; i < N; i++)
//        {
//            printf("%d ", from[i]);
//        }
//        printf("%d\n", from[N]);
//    }
//    
//    return 0;
//}


#include <stdio.h>
#include <string.h>
#define MAXSIZE 100001

int A[MAXSIZE], B[MAXSIZE];
int from[MAXSIZE];  //前一个节点位置
int super[MAXSIZE]; //最前驱是否为S

void solve(int key)
{
    if (key == 0)
    {
        return ;
    }
    
    int k = 0;
    for (int i = 0; i < key; i++)
    {
        if (super[A[i]] == -1)
        {
            super[B[i]] = -1;
            from[B[i]] = A[i];
        }
        else if (super[B[i]] == -1)
        {
            super[A[i]] = -1;
            from[A[i]] = B[i];
        }
        else
        {
            A[k] = A[i];
            B[k++] = B[i];
        }
    }
    
    solve(k);
    return ;
}

int main(int argc, const char * argv[])
{
    int M, N, S;
    int a, b;
    scanf("%d", &M);
    
    while (M--)
    {
        memset(from, -1, sizeof(from));
        memset(super, 0, sizeof(super));
        scanf("%d %d", &N, &S);
        super[S] = -1;
        int key = 0;
        for (int i = 1; i < N; i++)
        {
            scanf("%d %d", &a, &b);
            if (super[a] == -1)
            {
                super[b] = -1;
                from[b] = a;
            }
            else if (super[b] == -1)
            {
                super[a] = -1;
                from[a] = b;
            }
            else
            {
                A[key] = a;
                B[key++] = b;
            }
        }
        
        solve(key);
        
        for (int i = 1; i < N; i++)
        {
            printf("%d ", from[i]);
        }
        printf("%d\n", from[N]);
    }
    
    return 0;
}