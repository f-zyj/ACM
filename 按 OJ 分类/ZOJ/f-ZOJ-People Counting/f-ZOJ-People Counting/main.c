//
//  main.c
//  f-ZOJ-People Counting
//
//  Created by ZYJ on 16/4/23.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#define MAX(a, b) a > b ? a : b

int main(int argc, const char * argv[])
{
    int N, H, W, max, i, sum, tag;
    char S[101];
    scanf("%d", &N);
    
    while (N--)
    {
        max = 0;
        scanf("%d %d", &H, &W);
        while (H--)
        {
            sum = 1;
            tag = 0;
            scanf("%s", S);
            for (i = 1; i < W; i++)
            {
                if (S[i] == 'O' && S[i - 1] == '.' && i > tag)
                {
                    continue;
                }
                else if (S[i] == '.' && S[i - 1] == 'O' && i > tag)
                {
                    tag = i + 1;
                    continue;
                }
                else if (S[i] == '|' && S[i - 1] == '/' && i > tag)
                {
                    continue;
                }
                else if (S[i] == '\\' && S[i - 1] == '|' && i > tag)
                {
                    tag = i + 1;
                    continue;
                }
                else if (S[i] == '.' && S[i - 1] == '(' && i > tag)
                {
                    continue;
                }
                else if (S[i] == ')' && S[i - 1] == '.' && i > tag)
                {
                    tag = i + 1;
                    continue;
                }
                sum++;
            }
            max = MAX(max, sum);
        }
        printf("%d\n", max);
    }
    
    return 0;
}
