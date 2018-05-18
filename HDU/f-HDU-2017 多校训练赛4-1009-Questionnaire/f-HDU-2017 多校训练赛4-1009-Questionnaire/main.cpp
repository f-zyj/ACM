//
//  main.cpp
//  f-HDU-2017 多校训练赛4-1009-Questionnaire
//
//  Created by ZYJ on 2017/8/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int n;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int cnt1 = 0, cnt0 = 0, num;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &num);
            if (num & 1)
            {
                cnt1++;
            }
            else
            {
                cnt0++;
            }
        }
        
        if (cnt1 > cnt0)
        {
            printf("2 1\n");
        }
        else
        {
            printf("2 0\n");
        }
    }
    
    return 0;
}
