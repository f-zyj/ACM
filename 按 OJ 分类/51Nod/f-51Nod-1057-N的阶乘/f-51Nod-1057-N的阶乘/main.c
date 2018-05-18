//
//  main.c
//  f-51Nod-1057-N的阶乘
//
//  Created by ZYJ on 16/4/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//#include <string.h>
//#define _MAX 6
//#define MAX_ 10000000
//int product[MAX_];
//int pro[MAX_], num[_MAX];
//int rank = 1;
//
////递归进位函数
//void Carrying(int tag,int i,int j,int *p)
//{
//    p[i+j]+=tag;
//    if (i + j + 1 > rank || (i + j + 1 == rank && p[i + j] > 9))
//    {
//        rank++;
//    }
//    if (p[i+j]>9)
//    {
//        tag=p[i+j]/10;
//        p[i+j] %=10;
//        Carrying(tag, i+1, j, p);                                //写成Carrying(tag, i, j+1, p);也成立，为了让i+j递增而已
//    }
//    return ;
//}
//
////乘法
//void multiplication(int N)
//{
//    int i=0,j=0,numLen,productLen,tag;
//    for (i = 0; N > 0; i++)
//    {
//        num[i] = N % 10;
//        N /= 10;
//    }
//    numLen = i;
//    productLen = rank;
//    for (i = 0; i < productLen; i++)
//    {
//        pro[i] = product[i];
//    }
//    memset(product, 0, sizeof(int) * MAX_);
//    
//    //逐位相乘
//    for (i=0; i<productLen; i++)
//    {
//        for (j=0; j<numLen; j++)
//        {
//            tag= pro[i] *  num[j];
//            Carrying(tag, i, j, product);                          //递归
//        }
//    }
//    return ;
//}
//
//int main()
//{
//    int N, i = 2, j;
//    scanf("%d", &N);
//    memset(product, 0, sizeof(int) * MAX_);                    //初始化product数据为0
//    product[0] = 1;
//    for (; i <= N; i++)
//    {
//        multiplication(i);
//    }
//    //倒序输出结果
//    for (j = rank - 1; j >= 0; j--)
//    {
//        printf("%d",product[j]);
//    }
//    printf("\n");
//}

#include <stdio.h>
#define _MAX 100000000
int main()
{
    int n, i, j, m;
    long long a[10000], c;
    scanf("%d",&n);
    
    m = 0;
    a[0] = 1;
    for(i = 1; i <= n; i++)
    {
        c = 0;
        for(j = 0; j <= m; j++)
        {
            a[j] = a[j] * i + c;
            c = a[j] / _MAX;
            a[j] %= _MAX;
        }
        if(c > 0)
        {
            m++;
            a[m] = c;
        }
    }
    printf("%lld", a[m]);
    for(i = m - 1; i >= 0; i--)
        printf("%0.8lld", a[i]);
    printf("\n");
    return 0;
}

//#include <stdio.h>
//int main()
//{
//    int a = 0;
//    printf("%0.4d\n", a);
//    return 0;
//}
