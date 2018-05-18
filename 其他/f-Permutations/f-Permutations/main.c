//
//  main.c
//  f-Permutations
//
//  Created by ZYJ on 16/4/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define _MAX 100001
int main()
{
    int A[_MAX], B[_MAX];
    int N, i = 0, j = 0, count = 0, k;
    scanf("%d", &N);
    for (; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    for (; j < N; j++)
    {
        scanf("%d", &B[j]);
    }
    
    //    for (i = 0; i < N; i++)
    //    {
    //        if (A[i] != B[i])
    //        {
    //            for (j = i + 1; j < N; j++)
    //            {
    //                if (A[j] == B[i])
    //                {
    //                    count++;
    //                    temp = A[j];
    //                    for (k = j; k > i; k--)
    //                    {
    //                        A[k] = A[k - 1];
    //                    }
    //                    A[i] = temp;
    //                    i--;
    //                }
    //            }
    //        }
    //    }
    
    for (i = 0, j = 0; i < N && j < N; )
    {
        if (A[i] == B[j])
        {
            i++;
            j++;
        }
        else if (A[i] == -1)
        {
            i++;
        }
        else
        {
            for (k = i + 1; k < N; k++)
            {
                if (A[k] == B[j])
                {
                    count++;
                    A[k] = -1;
                    j++;
                    break;
                }
            }
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}

//#include <stdio.h>
//int main()
//{
//    int n, a[200010], b[200010], i, j, k, flag;
//    scanf("%d", &n);
//    k = -1;
//    for(i = 0; i < n; i++)
//        scanf("%d", &a[i]);
//    for(i = 0; i < n; i++)
//        scanf("%d", &b[i]);
//
//    for(i = 0; i < n; i++)
//    {
//        flag = 0;
//        for(j = k + 1; j < n; j++)
//        {
//            if(a[i] == b[j])
//            {
//                flag = 1;
//                k = j;
//                break;
//            }
//        }
//        if(!flag)
//            break;
//    }
//    printf("%d\n", n - i);
//}
