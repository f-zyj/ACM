//
//  main.c
//  f-轻院选拔赛-最后一题
//
//  Created by ZYJ on 16/4/13.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char strOne[10000];
char strTwo[1000000];

int seek()
{
    int ans = 0, lenOne, lenTwo;
    int i = 0, j = 0, k = 0, l = 0;
    lenOne = (int)strlen(strOne);
    lenTwo = (int)strlen(strTwo);
    for (; i <= lenTwo - lenOne; i++)
    {
        if (strOne[0] == strTwo[i] && strOne[lenOne - 1] == strTwo[i + lenOne - 1])
        {
            k = 1;
            l = 2;
            for (j = 1; j < lenOne - 1; j++)
            {
                if (strOne[j] != strTwo[i + k++])
                {
                    break;
                }
                l++;
            }
            if (l == lenOne)
            {
                ans++;
            }
        }
    }
    return ans;
}

int main(int argc, const char * argv[])
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s %s", strOne, strTwo);
        printf("%d\n", seek());
    }
    return 0;
}
