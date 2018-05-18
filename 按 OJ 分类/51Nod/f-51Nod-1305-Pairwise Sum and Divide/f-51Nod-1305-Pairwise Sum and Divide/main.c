//
//  main.c
//  f-51Nod-1305-Pairwise Sum and Divide
//
//  Created by ZYJ on 16/5/14.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//超时...
//#include <stdio.h>
//
//int main(int argc, const char * argv[])
//{
//    int N;
//    int i, j;
//    long long A[100001];
//    long long sum = 0;
//    scanf("%d", &N);
//    
//    for (i = 0; i < N; i++)
//    {
//        scanf("%lld", A + i);
//    }
//    
//    for (i = 0; i < N; i++)
//    {
//        for (j = i + 1; j < N; j++)
//        {
//            sum += ((A[i] + A[j]) / (A[i] * A[j]));
//        }
//    }
//    
//    printf("%lld\n", sum);
//    return 0;
//}


//AC...
//#include <stdio.h>
//
//int main(int argc, const char * argv[])
//{
//    int N;
//    int i, j = 0;
//    long long A[100001];
//    long long sum = 0;
//    scanf("%d", &N);
//    
//    for (i = 0; i < N; i++)
//    {
//        scanf("%lld", A + i);
//        if (A[i] == 2)  //2单独处理
//        {
//            j++;
//        }
//        else if (A[i] == 1) //这里考虑到1和非1组合时结果为1、1和1组合时结果为2，
//        {                   //而1和1的组合会被利用两次，所以与前者归并在一起考虑
//            sum += N - 1;
//        }
//    }
//    
//    printf("%lld\n", sum + j * (j - 1) / 2);    //因为2和2组合会被利用两次
//    return 0;
//}



//超时......
//#include <stdio.h>
//
//int main(int argc, const char * argv[])
//{
//    int N;
//    int i, j;
//    long long A[100001];
//    long long sum = 0;
//    scanf("%d", &N);
//    
//    for (i = 0; i < N; i++)
//    {
//        scanf("%lld", A + i);
//    }
//    
//    for (i = 0; i < N - 1; i++)
//    {
//        for (j = i + 1; j < N; j++)
//        {
//            if (A[i] > A[j])
//            {
//                A[i] ^= A[j];
//                A[j] ^= A[i];
//                A[i] ^= A[j];
//            }
//        }
//    }
//    
//    for (i = 0; i < N; i++)
//    {
//        if (A[i] == 1)
//        {
//            for (j = i + 1; j < N; j++)
//            {
//                if (A[j] == 1)
//                {
//                    sum += 2;
//                }
//                else
//                {
//                    sum += 1;
//                }
//            }
//        }
//        else if (A[i] == 2)
//        {
//            for (j = i + 1; j < N && A[j] == 2; j++)
//            {
//                sum += 1;
//            }
//        }
//        else
//        {
//            break;
//        }
//    }
//    
//    printf("%lld\n", sum);
//    return 0;
//}
