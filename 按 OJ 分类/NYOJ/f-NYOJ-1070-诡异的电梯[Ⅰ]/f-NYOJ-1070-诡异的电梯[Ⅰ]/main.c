//
//  main.c
//  f-NYOJ-1070-诡异的电梯[Ⅰ]
//
//  Created by ZYJ on 16/5/3.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAXSIZE 100005
#define MIN(a, b) a < b ? a : b

int main(int argc, const char * argv[])
{
    int T;
    int N, M, A, B;
    int to;
    int wantTo[MAXSIZE];
    int i, key = 0;
    int cost[MAXSIZE];
    
    scanf("%d", &T);
    while (T--)
    {
        key++;
        memset(wantTo, 0, sizeof(wantTo));
        memset(cost, 0x3F, sizeof(cost));
        
        scanf("%d %d %d %d", &N, &M, &A, &B);
        for (i = 0; i < M; i++)
        {
            scanf("%d", &to);
            wantTo[to]++;
        }
        
        int temp;
        int min = MIN(A, B);
        cost[0] = cost[1] = cost[2] = 0;
        for (i = 3; i <= N; i++)
        {
            cost[i] = MIN(cost[i], cost[i - 2] + wantTo[i - 1] * min);
            /*
             
             + i层
             + ⬆️
             + (i - 1)层
             + ⬇️
             + (i - 2)层
             
             */
            
            if (i - 3 > 0)
            {
                temp = MIN(wantTo[i - 1] * A + wantTo[i - 2] * 2 * A, wantTo[i - 1] * 2 * B + wantTo[i - 2] * B);
                /*
                 
                 + i层
                 + ⬆️   ／
                 + (i - 1)层
                 + ⬆️⬆️ ／ ⬇️⬇️
                 + (i - 2)层
                 +      ／ ⬇️
                 + (i - 3)层
                 
                 */
                
                temp = MIN(temp, wantTo[i - 1] * A + wantTo[i - 2] * B);
                /*
                 
                 + i层
                 + ⬆️
                 + (i - 1)层
                 + (i - 2)层
                 + ⬇️
                 + (i - 3)层
                 
                 */
                
                temp = MIN(temp, wantTo[i -1] * 2 * B + wantTo[i - 2] * 2 * A);
                /*
                 
                 + i层
                 + (i - 1)层
                 + ⬇️⬇️⬆️⬆️
                 + (i - 2)层
                 + (i - 3)层
                 
                 */
                
                cost[i] = MIN(cost[i], cost[i - 3] + temp);
            }
        }
        
        printf("Case %d: %d\n", key, cost[N]);
    }

    return 0;
}
