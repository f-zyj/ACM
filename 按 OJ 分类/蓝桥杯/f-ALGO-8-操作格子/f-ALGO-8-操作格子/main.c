//
//  main.c
//  f-ALGO-8-操作格子
//
//  Created by ZYJ on 16/3/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//#define _Max 100000
//int k = 0, answer[_Max];
//void sum(int x, int y, int *p);
//void max(int x, int y, int *p);
//
//int main()
//{
//    int n, m, Quan[_Max], P[_Max], X[_Max], Y[_Max], i = 0;
//    scanf("%d %d", &n, &m);
//    for (; i < n; i++)
//    {
//        scanf("%d", &Quan[i]);     //初始化序列
//    }
//    for (i = 0; i < _Max; i++)
//    {
//        answer[i] = -1;
//    }
//    for (i = 0; i < m; i++)
//    {
//        scanf("%d %d %d", &P[i], &X[i], &Y[i]);         //键入操作
//        switch(P[i])
//        {
//            case 1 : Quan[X[i] - 1] = Y[i];
//                break;
//            case 2 : sum(X[i], Y[i], Quan);
//                break;
//            default : max(X[i], Y[i], Quan);
//                break;
//        }
//    }
//    
//    for (i = 0; i < m && answer[i] != -1; i++)
//    {
//        printf("%d\n", answer[i]);
//    }
//    return 0;
//}
//
//void sum(int x, int y, int *p)
//{
//    int i = x - 1, s = 0;
//    for (; i < y; i++)
//    {
//        s += p[i];
//    }
//    answer[k++] = s;
//    return ;
//}
//
//void max(int x, int y, int *p)
//{
//    int i = x -1, m = 0;
//    for (; i < y - 1; i++)
//    {
//        m = p[i] > m ? p[i] : m;
//    }
//    answer[k++] = m;
//    return ;
//}

