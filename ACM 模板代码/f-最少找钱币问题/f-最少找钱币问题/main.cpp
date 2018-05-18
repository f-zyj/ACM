//
//  main.cpp
//  f-最少找钱币问题
//
//  Created by ZYJ on 16/7/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

/*
 *  贪心策略-深度搜索
 */

int value[7] = {100, 50, 20, 10, 5, 2, 1};
int count[7];   //  count[i]:value[i]硬币的个数
int res[7];
bool flag;

void DFS(int total, int p);

int main()
{
    int pay = 0;
    scanf("%d", &pay);
    //...
    flag = false;   //  标识是否已经找到结果
    for (int i = 0; i < 7; ++i)
    {
        res[i] = 0;
    }
    DFS(pay, 0);    //  pay为要找的钱数
    if (flag)
    {
        printf("Accept\n%d", res[0]);
        for (int i = 1; i < 7; ++i)
        {
            printf(" %d", res[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Refuse\n");     //  无法正好找钱
    }
}

void DFS(int total, int p)
{
    if (flag)
    {
        return ;
    }
    if (p == 7)
    {
        if (total == 0)
        {
            flag = true;
        }
        return ;
    }
    int i, max = total / value[p];
    if (max > count[p])
    {
        max = count[p];
    }
    for (i = max; i >= 0; --i)
    {
        res[p] = i;
        DFS(total - i * value[p], p + 1);
        if (flag)
            return ;
    }
    return ;
}