//
//  main.c
//  f-计算对角线元素之和
//
//  Created by ZYJ on 16/4/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int i, j;
    int sum = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == j || i == j - 2 || j == i - 2)
            {
                sum += arr[i][j];
            }
        }
//        sum = 25;
    }
    
    printf("对角线元素之和是：%d\n", sum);
    
    return 0;
}
