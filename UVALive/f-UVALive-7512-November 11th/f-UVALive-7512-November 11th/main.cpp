//
//  main.cpp
//  f-UVALive-7512-November 11th
//
//  Created by ZYJ on 2017/11/22.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1111;

int T;
int r, c;
int seat[MAXN][MAXN];

int main()
{
    scanf("%d", &T);
    
    for (int ce = 1; ce <= T; ce++)
    {
        scanf("%d%d", &r, &c);
        memset(seat, 0, sizeof(seat));
        
        int m;
        scanf("%d", &m);
        
        int br, bc;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &br, &bc);
            seat[br][bc] = 1;
        }
        
        int ans_more = 0;
        int ans_less = 0;
        for (int i = 0; i < r; ++i)
        {
            int cur = 0;
            for (int j = 0; j < c; ++j)
            {
                if (seat[i][j] == 0)
                {
                    ++cur;
                }
                
                if (seat[i][j] == 1 || j == c - 1)
                {
                    if (cur == 1)
                    {
                        ++ans_more;
                        ++ans_less;
                    }
                    else
                    {
                        if (cur % 2 == 0)
                        {
                            ans_more += cur / 2;
                        }
                        else
                        {
                            ans_more += cur / 2 + 1;
                        }
                        
                        if (cur % 3)
                        {
                            ans_less += cur / 3 + 1;
                        }
                        else
                        {
                            ans_less += cur / 3;
                        }
                    }
                    
                    cur = 0;
                }
            }
        }
        
        printf("Case #%d: %d %d\n", ce, ans_more, ans_less);
    }
    
    return 0;
}
