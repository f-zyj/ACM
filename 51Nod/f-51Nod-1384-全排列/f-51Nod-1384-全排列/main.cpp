//
//  main.cpp
//  f-51Nod-1384-全排列
//
//  Created by ZYJ on 16/7/29.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//#define MAX_N 10
//
//char nums[MAX_N];
//int n, m;           //  共有n个数,其中互不相同的有m个
//char rcd[MAX_N];    //  记录每个位置填的数
//int used[MAX_N];    //  标记m个数可以使用的次数
//char num[MAX_N];    //  存放输入中互不相同的m个数
//
//void unrepeat_permutation(int l)
//{
//    int i;
//    if (l == n)     //  填完了n个数,则输出
//    {
//        for (i = 0; i < n; i++)
//        {
//            printf("%c", rcd[i]);
//        }
//        printf("\n");
//        return ;
//    }
//    for (i = 0; i < m; i++)             //  枚举m个本质不同的数
//    {
//        if (used[i] > 0)                //  若数num[i]还没被用完,则可使用次数减
//        {
//            used[i]--;
//            rcd[l] = num[i];            //  在l位置放上该数
//            unrepeat_permutation(l + 1);//  填下一个位置
//            used[i]++;                  //  可使用次数恢复
//        }
//    }
//}
//
//int read_data()
//{
//    int i, j;
//    char val;
//    if (scanf("%s", nums) == EOF)
//    {
//        return 0;
//    }
//    n = (int)strlen(nums);
//    m = 0;
//    for (i = 0; i < n; i++)
//    {
//        val = nums[i];
//        for (j = 0; j < m; j++)
//        {
//            if (num[j] == val)
//            {
//                used[j]++;
//                break;
//            }
//        }
//        if (j == m)
//        {
//            num[m] = val;
//            used[m++] = 1;
//        }
//    }
//    for (i = 0; i < m - 1; i++)
//    {
//        for (j = i + 1; j < m; j++)
//        {
//            if (num[i] > num[j])
//            {
//                swap(num[i], num[j]);
//                swap(used[i], used[j]);
//            }
//        }
//    }
//    return 1;
//}
//
//int main()
//{
//    while (read_data())
//    {
//        unrepeat_permutation(0);
//    }
//    return 0;
//}

#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
    char ch[10];
    scanf("%s",ch);
    int len = (int)strlen(ch);
    sort(ch, ch + len);
    
    int cnt;
    do
    {
        printf("%s\n", ch);
        cnt = -1;
        for (int i = len - 1; i > 0; i--)
        {
            if (ch[i] > ch[i - 1])
            {
                cnt = i - 1;
                for (int j = len - 1; j >= 0; j--)
                {
                    if (ch[j] > ch[cnt])
                    {
                        char tmp = ch[j] ^ ch[cnt];
                        ch[j] ^= tmp;
                        ch[cnt] ^= tmp;
                        for (int k = i; k <= (i + len - 1) / 2; k++)    //  ch[cnt]和ch[j]置换后变大，后边的为递
                        {                                               //  减，所以需要倒置，变为递增
                            tmp = ch[k] ^ ch[len - 1 + i - k];
                            ch[k] ^= tmp;
                            ch[len - 1 + i - k] ^= tmp;
                        }
                        break;
                    }
                }
                break;
            }
        }
    } while (cnt != -1);
    
    return 0;
}