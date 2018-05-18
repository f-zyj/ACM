//
//  main.c
//  f-NOIP-2009-分数线划定
//
//  Created by ZYJ on 16/5/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>

struct people
{
    int signNum;
    int report;
} p[5001];

int main(int argc, const char * argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &p[i].signNum, &p[i].report);
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].report < p[j].report)
            {
                p[i].report ^= p[j].report;
                p[j].report ^= p[i].report;
                p[i].report ^= p[j].report;
                p[i].signNum ^= p[j].signNum;
                p[j].signNum ^= p[i].signNum;
                p[i].signNum ^= p[j].signNum;
            }
            else if (p[i].report == p[j].report && p[i].signNum > p[j].signNum)
            {
                p[i].report ^= p[j].report;
                p[j].report ^= p[i].report;
                p[i].report ^= p[j].report;
                p[i].signNum ^= p[j].signNum;
                p[j].signNum ^= p[i].signNum;
                p[i].signNum ^= p[j].signNum;
            }
        }
    }
    
    m = (int)(m * 1.5);
    int fraLine = p[m - 1].report;
    for (int i = m; i < n; i++)
    {
        if (p[m].report == p[m - 1].report)
        {
            m++;
        }
    }
    printf("%d %d\n", fraLine, m);
    for (int i = 0; i < m; i++)
    {
        printf("%d %d\n", p[i].signNum, p[i].report);
    }
    return 0;
}
