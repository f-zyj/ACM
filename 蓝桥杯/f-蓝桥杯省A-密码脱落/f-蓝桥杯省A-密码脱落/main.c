//
//  main.c
//  f-蓝桥杯省A-密码脱落
//
//  Created by ZYJ on 16/4/6.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
void code(char *s)
{
    int i = 0, n = 0, ti, tj;
    int j = (int)strlen(s) - 1;
    
    while (i <= j)
    {
        //第一种情况  如果前后相等，则像中间靠拢
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        //如果不相等  则又分两种情况
        else
        {
            ti = i;
            tj = j;
            //以右边为标记  左边为游标  寻找相等的情况
            while (s[ti] != s[j] && ti < j)
            {
                ti++;
            }
            //以左边为标记  右边为游标  寻找相等的情况
            while (s[i] != s[tj] && i <= tj)
            {
                tj--;
            }
            //比较这个游标移动的距离，取小的距离
            if ((ti - i) < (j - tj))
            {
                n += ti - i;
                i = ti;     //将i置为新的起点
            }
            else
            {
                n += j - tj;
                j = tj;     //将j置为新的终点
            }
        }
    }
    printf("%d\n", n);
    return ;
}

int main(int argc, const char * argv[])
{
    char s[1000];
    scanf("%s", s);
    //处理密码
    code(s);
    return 0;
}

//#include <stdio.h>
//#include <string.h>
//char s[1000];
//int min = 0, num = 0;
//
//void fcode(int left, int right, int num)
//{
//    if (left >= right)
//    {
//        min = min < num ? min : num;
//    }
//    else
//    {
//        if (s[left] == s[right])
//        {
//            fcode(left + 1, right - 1, num);
//        }
//        else
//        {
//            fcode(left + 1, right, num + 1);
//            fcode(left, right - 1, num + 1);
//        }
//    }
//    return ;
//}
//
//int main(int argc, const char * argv[])
//{
//    scanf("%s", s);
//    min = (int)strlen(s);
//    //处理密码
//    fcode(0, min - 1, 0);
//    printf("%d\n", min);
//    return 0;
//}
