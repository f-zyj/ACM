//
//  main.c
//  f-NYOJ-24-素数距离问题
//
//  Created by ZYJ on 16/5/24.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//#define _MAX 1000100
//int a[_MAX + 1] = {1, 1};   //1表示不是质数，0表示是质数
//int p[_MAX];    //1-1000100的所有质数
//
//int main(int argc, const char * argv[])
//{
//    int N, M;
//    scanf("%d", &N);
//    int key = 0;
//    for (int i = 2; i <= _MAX; i++)
//    {
//        if (!a[i])
//        {
//            p[key++] = i;
//        }
//        for (int j = 0; j < key && i * p[j] <= _MAX; j++)
//        {
//            a[i * p[j]] = 1;
//            if (!(i % p[j]))    //i不是质数，终止循环，减少重复的不必要赋值
//            {
//                break;
//            }
//        }
//    }
//    
//    while (N--)
//    {
//        scanf("%d", &M);
//        if (M == 0 || M == 1)
//        {
//            printf("2 %d\n", 2 - M);
//        }
//        else if (M <= 1000000)
//        {
//            if (!a[M])
//            {
//                printf("%d 0\n", M);
//            }
//            else
//            {
//                int A = 0, B = 0;
//                for (int i = M - 1; i > 0; i--)
//                {
//                    if (!a[i])
//                    {
//                        A = i;
//                        break;
//                    }
//                }
//                for (int j = M + 1; j <= 1000100; j++)
//                {
//                    if (!a[j])
//                    {
//                        B = j;
//                        break;
//                    }
//                }
//                if (M - A > B - M)
//                {
//                    printf("%d %d\n", B, B - M);
//                }
//                else
//                {
//                    printf("%d %d\n", A, M - A);
//                }
//            }
//        }
//    }
//    return 0;
//}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int table[1001000] = {1, 1};    //1非质数0质数

int main()
{
    for (int i = 4; i < 1001000; i += 2)
    {
        table[i] = 1;
    }
    for (int i = 3; i <= 1001; i += 2)
    {
        if (!table[i])
        {
            for (int j = i * i; j < 1001000; j += 2 * i)
            {
                table[j] = 1;
            }
        }
    }
    
    int t, x;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &x);
        for (int i = 0; ; i++)
        {
            if (!table[x - i] && x > i)
            {
                printf("%d %d\n", x - i, i);
                break;
            } else if (!table[x + i])
            {
                printf("%d %d\n", x + i, i);
                break;
            }
        }
    }
    return 0;
}