//
//  main.c
//  f-NYOJ-16-矩形嵌套
//
//  Created by ZYJ on 16/5/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//


//问题代码，此写法有点像贪心，存在后效应性，需要用动态规划取消后效应性
//从大到小开始查找，这里我们选择的不是尺寸最大的，而是可以包含（嵌套）矩形数最多的
//#include <stdio.h>
//#define MAX(a, b) a > b ? a : b
//#define MAXSIZEN 1001
//int t[MAXSIZEN] = {0};
//int ans;
//typedef struct
//{
//    int a;
//    int b;
//} rec;  //矩形
//rec R[MAXSIZEN];
//
////检索小于a[i]和b[i]的最大矩形对应的t[j]
//void retrieve(int p, int n)
//{
//    int q, i;
//    q = 0;
//    for(i = 1; i <= n; i++)
//    {
//        if(R[p].a > R[i].a && R[p].b > R[i].b)
//        {
//            if(t[i] > t[q])
//            {
//                q = i;
//            }
//        }
//    }
//    ans++;
//    if(t[q])
//    {
//        retrieve(q, n);
//    }
//}
//
//int main(int argc, const char * argv[])
//{
//    int N;
//    scanf("%d", &N);
//    
//    while (N--)
//    {
//        ans = 1;
//        int n, a, b;
//        scanf("%d", &n);
//        for (int i = 1; i <= n; i++)
//        {
//            scanf("%d %d", &a, &b);
//            //调整矩形方向
//            if (a > b)
//            {
//                R[i].a = b;
//                R[i].b = a;
//            }
//            else
//            {
//                R[i].a = a;
//                R[i].b = b;
//            }
//        }
//        
//        int p = 0;
//        for(int i = 1; i <= n; i++)
//        {
//            for(int j = 1; j <= n; j++)
//            {
//                if(R[i].a > R[j].a && R[i].b > R[j].b)
//                {
//                    t[i]++;
//                }
//            }
//            if(t[i] > t[p])
//            {
//                p = i;
//            }
//        }
//        
//        retrieve(p, n);
//        
//        printf("%d\n", ans);
//    }
//
//    
//    return 0;
//}

//动归
#include <stdio.h>
#include <string.h>
#define MAX(a, b) a > b ? a : b
#define MAXSIZEN 1001
int dp[MAXSIZEN];   //dp[i]当排好序的前i个矩形符合条件的包括第i个时的最大值
int ans;
typedef struct
{
    int a;
    int b;
} rec;  //矩形

int main(int argc, const char * argv[])
{
    int N;
    scanf("%d", &N);
    rec R[MAXSIZEN];
    
    while (N--)
    {
        ans = 1;
        memset(dp, 0, sizeof(dp));
        int n, a, b;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d", &a, &b);
            //调整矩形方向
            if (a > b)
            {
                R[i].a = b;
                R[i].b = a;
            }
            else
            {
                R[i].a = a;
                R[i].b = b;
            }
        }
        
        //按一条边排序
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (R[i].a > R[j].a || (R[i].a == R[j].a && R[i].b > R[j].b))
                {
                                        R[i].a ^= R[j].a;
                                        R[j].a ^= R[i].a;
                                        R[i].a ^= R[j].a;
//                    R[i].a ^= R[j].a ^= R[i].a ^= R[j].a;
                                        R[i].b ^= R[j].b;
                                        R[j].b ^= R[i].b;
                                        R[i].b ^= R[j].b;
//                    R[i].b ^= R[j].b ^= R[i].b ^= R[j].b;
                }
            }
        }
        
        int flag;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = 1;
            flag = 0;
            for (int j = 1; j < i; j++)
            {
                if (R[j].a < R[i].a && R[j].b < R[i].b && dp[j] > flag)
                {
                    flag = dp[j];
                }
            }
            dp[i] += flag;
        }
        
        for (int i = 1; i <= n; i++)
        {
            if (ans < dp[i])
            {
                ans = dp[i];
            }
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
