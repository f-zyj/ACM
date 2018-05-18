//
//  main.c
//  f-POJ-机加工表面
//
//  Created by ZYJ on 16/2/21.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    int N, answer[100], as, minspacesum = 0, i = 0, j = 0, k = 0, L = 0, tag = 0, sum = 0;  //tag为临时空格数，sum为X字符的数目
    char imagelift[25], imageRight[25];
    
    while (scanf("%d", &N) && N != 0)
    {
        //初始化
        minspacesum = 25;
        sum = 0;
        //逐行输入图像，并作相关数据统计
        for (i = 0; i<N; i++)
        {
            //初始化
            for (j = 0; j < 25; j++)
            {
                imagelift[j] = '\0';
                imageRight[j] = '\0';
            }
            scanf("%s", imagelift);
            //printf("%s\n%c\n", imagelift, imagelift[0]);
            if (imagelift[24] != 'X')
            {
                scanf("%s", imageRight);
            }
            //左侧X数目
            j = 0;
            while (imagelift[j] == 'X')
            {
                j++;
            }
            sum += j;
            //临时空格数设置为0
            tag = 0;
            //右侧的数目
            if (j != 25)
            {
                k = 0;
                while (imageRight[k] == 'X')
                {
                    k++;
                }
                sum += k;
                tag = 25 - k - j;   //临时空格数
            }
            //更新最小空格数目
            minspacesum = minspacesum < tag ? minspacesum : tag;
            //printf("%d\n", minspacesum);
        }
        
        //每一部分答案
        as = (25 - minspacesum) * N - sum;
        //存答案
        answer[L] = as;
        L++;
    }
    //输出答案
    for (i = 0; i < L; i++)
    {
        printf("%d\n", answer[i]);
    }
    printf("Hello, World!\n");
    return 0;
}
