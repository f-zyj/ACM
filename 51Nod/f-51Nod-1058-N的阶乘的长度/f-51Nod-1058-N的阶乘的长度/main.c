//
//  main.c
//  f-51Nod-1058-N的阶乘的长度
//
//  Created by ZYJ on 16/4/19.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//#define _MAX 1000000000000
//int main()
//{
//    int n, i, j, m;
//    long long a[100000], c;
//    scanf("%d",&n);
//    
//    m = 0;
//    a[0] = 1;
//    for(i = 1; i <= n; i++)
//    {
//        c = 0;
//        for(j = 0; j <= m; j++)
//        {
//            a[j] = a[j] * i + c;
//            c = a[j] / _MAX;
//            a[j] %= _MAX;
//        }
//        if(c > 0)
//        {
//            m++;
//            a[m] = c;
//        }
//    }
//    if (a[m] == 0)
//    {
//        printf("%d\n", 12 * m);
//        return 0;
//    }
//    for (i = 0; i < 12; i++)
//    {
//        a[m] /= 10;
//        if (a[m] == 0)
//        {
//            break;
//        }
//    }
//    printf("%d\n", 12 * m + i + 1);
//    return 0;
//}



#include <stdio.h>
#include <math.h>
//斯特林公式n!=sqrt(2*PI*n)*(n/e)^n
#define PI 3.1415926

int main()
{
    int n, a;
    while(~scanf("%d",&n))
    {
        a = (int)((0.5 * log(2 * PI * n) + n * log(n) - n) / log(10));
        printf("%d\n", a + 1);
    }
    return 0;
}