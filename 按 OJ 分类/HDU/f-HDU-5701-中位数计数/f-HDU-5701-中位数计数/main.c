//
//  main.c
//  f-HDU-5701-中位数计数
//
//  Created by ZYJ on 16/6/1.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 8008

int num[MAXSIZE];
int arr[MAXSIZE];
int cnt[MAXSIZE];
int sum[MAXSIZE * 2];

//输入LL
void scanfDiy(int *ret)
{
    char c;
    *ret = 0;
    while((c = getchar()) < '0' || c > '9');
    while(c >= '0' && c <= '9')
        *ret = (*ret) * 10 + (c - '0'), c = getchar();
    return ;
}

//符合规则的区间分为以下几种
//      i       (1)
//  j---i       (2)
//      i---j   (3)
//  j'--i--j"   (4)

int main(int argc, const char * argv[])
{
    int n;
    
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
        {
            scanfDiy(num + i);
        }
        
        for (int i = 1; i <= n; i++)
        {
            int temp = num[i];
            memset(arr, 0, sizeof(arr));
            memset(sum, 0, sizeof(sum));
            int res = 0;
            
            //存num[i]左边区间比num[i]大小情况
            for (int j = i - 1; j >= 1; j--)
            {
                arr[j] = arr[j + 1] + ((num[j] > temp) ? -1 : 1);
                sum[arr[j] + n]++;  //防止越界  相同情况出现的次数
                if (arr[j] == 0)    //为0时，从j到i区间符合规则
                {
                    res++;          //(2)
                }
            }
            //存num[i]右边区间比num[i]大小情况
            for (int j = i + 1; j <= n; j++)
            {
                arr[j] = arr[j - 1] + ((num[j] > temp) ? 1 : -1);
                if (sum[arr[j] + n] > 0)            //左右匹配
                {
                    res = res + sum[arr[j] + n];    //(4)
                }
                if (arr[j] == 0)                    //为0时，从i到j区间符合规则
                {
                    res++;                          //(3)
                }
            }
            cnt[i] = res + 1;                       //此处+1的情况为(1)
        }
        
        for (int i = 1; i < n; i++)
        {
            printf("%d ", cnt[i]);
        }
        printf("%d\n", cnt[n]);
    }
    
    return 0;
}